#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

int x, y, z;

sem_t computer, customer, readyToBill, notifyCustomer;
pthread_mutex_t consoleMtx, doorMtx;
queue<int> q;

void *computerAccess(void *arg)
{
    while (true)
    {
        sem_wait(&computer);
        pthread_mutex_lock(&consoleMtx);
        sleep(2);
        cout << "Compter ready" << endl;
        pthread_mutex_unlock(&consoleMtx);
        sem_post(&customer);
        sleep(1);
    }
}

void *customerAccess(void *arg)
{
    int p = (int)(intptr_t)arg;
    pthread_mutex_lock(&consoleMtx);
    cout << "Customer - " << p << " has arrived" << endl;
    pthread_mutex_unlock(&consoleMtx);
    pthread_mutex_lock(&doorMtx);
    pthread_mutex_lock(&consoleMtx);
    cout << "Customer - " << p << " successfully entered" << endl;
    cout << "Customer - " << p << " waiting for computer" << endl;
    pthread_mutex_unlock(&consoleMtx);
    pthread_mutex_unlock(&doorMtx);
    sem_wait(&customer);
    pthread_mutex_lock(&consoleMtx);
    cout << "Customer - " << p << " has got access to computer" << endl;
    pthread_mutex_unlock(&consoleMtx);
    sleep(6);
    sem_post(&computer);
    sem_post(&readyToBill);
    pthread_mutex_lock(&consoleMtx);
    q.push(p);
    cout << "Customer - " << p << " completed and waiting in line for payment" << endl;
    pthread_mutex_unlock(&consoleMtx);
    sem_wait(&notifyCustomer);
    pthread_mutex_lock(&consoleMtx);
    cout << "Customer - " << p << " has paid the bill and is leaving the cafe" << endl;
    pthread_mutex_unlock(&consoleMtx);
    pthread_exit(NULL);
}

void *counterAccess(void *arg)
{
    int p = (int)(intptr_t)arg;
    pthread_mutex_lock(&consoleMtx);
    cout << "Cashier - " << p << " has arrived" << endl;
    pthread_mutex_unlock(&consoleMtx);
    pthread_mutex_lock(&doorMtx);
    pthread_mutex_lock(&consoleMtx);
    cout << "Cashier - " << p << " successfully entered" << endl;
    pthread_mutex_unlock(&consoleMtx);
    pthread_mutex_unlock(&doorMtx);

    while (true)
    {
        sem_wait(&readyToBill);
        pthread_mutex_lock(&consoleMtx);
        int a = q.front();
        q.pop();
        cout << "Cashier - " << p << " is processing bill of Customer " << a << endl;
        pthread_mutex_unlock(&consoleMtx);
        sleep(4);
        pthread_mutex_lock(&consoleMtx);
        cout << "Cashier - " << p << " has completed the billing process of Customer " << a << endl;
        pthread_mutex_unlock(&consoleMtx);
        sem_post(&notifyCustomer);
    }
}

void *createComputer(void *arg)
{
    int total_computer = x;

    for (int i = 1; i <= total_computer; i++)
    {
        pthread_t thread;
        pthread_create(&thread, NULL, computerAccess, (void *)i);
        sleep(5);
    }
    pthread_exit(NULL);
}

void *createCustomer(void *arg)
{
    int total_customer = z;
    pthread_t thread[total_customer];

    for (int i = 1; i <= total_customer; i++)
    {
        pthread_create(&thread[i - 1], NULL, customerAccess, (void *)i);
        sleep(5);
    }

    for (int i = 1; i <= total_customer; i++)
    {
        pthread_join(thread[i - 1], NULL);
    }
}

void *createCounter(void *arg)
{
    int total_counter = y;

    for (int i = 1; i <= total_counter; i++)
    {
        pthread_t thread;
        pthread_create(&thread, NULL, counterAccess, (void *)i);
        sleep(5);
    }
    pthread_exit(NULL);
}

void semaphore_init()
{
    sem_init(&computer, 0, x);
    sem_init(&customer, 0, 0);
    sem_init(&readyToBill, 0, 0);
    sem_init(&notifyCustomer, 0, 0);
    pthread_mutex_init(&consoleMtx, NULL);
    pthread_mutex_init(&doorMtx, NULL);
}

int main()
{
    cout << "Enter number of Computer,Cashier & Customer" << endl;
    cin >> x >> y >> z;
    semaphore_init();

    pthread_t comT, cusT, couT;
    pthread_create(&comT, NULL, createComputer, NULL);
    pthread_create(&cusT, NULL, createCustomer, NULL);
    pthread_create(&couT, NULL, createCounter, NULL);

    pthread_join(cusT, NULL);

    cout << "Cyber cafe is closed for today" << endl;
}