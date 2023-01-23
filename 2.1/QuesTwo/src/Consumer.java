public class Consumer implements Runnable{
    Container container;
    Thread t;

    Consumer(Container container){
        this.container = container;
        t = new Thread(this);
        t.start();
    }

    @Override
    public void run() {
        while(true){
            container.get();
        }
    }
}
