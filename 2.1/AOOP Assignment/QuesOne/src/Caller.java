public class Caller implements Runnable{
    Sorting s;
    Thread t;
    int[] array;
    int startIndex;
    int lastIndex;
    int totalIndex;
    String threadName;

    Caller(Sorting s,int[]array,int startIndex,int lastIndex,int totalIndex,String threadName){
        this.s = s;
        this.array = array;
        this.startIndex = startIndex;
        this.lastIndex = lastIndex;
        this.totalIndex = totalIndex;
        this.threadName = threadName;
        t = new Thread(this);
        t.setName(threadName);
        t.start();
    }

    @Override
    public void run() {
        synchronized (s){
            System.out.println("\nThread "+t.getName()+ " is sorting from index "+startIndex+" to "+(lastIndex-1)+"...");
            s.arraySort(array,startIndex,lastIndex);
            s.arrayPrintAfterSort(array,totalIndex);
            System.out.println("\nThread "+t.getName()+ " has finished its activities.");
            try{Thread.sleep(2000);}catch (Exception e){e.printStackTrace();}
        }
    }
}
