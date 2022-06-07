public class Producer implements Runnable{
    Container container;
    Thread t;

    Producer(Container container){
        this.container = container;
        t = new Thread(this);
        t.start();
    }

    @Override
    public void run() {
        while(true){
            container.put();
        }
    }
}
