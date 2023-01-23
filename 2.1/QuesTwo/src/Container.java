import java.util.Random;

public class Container {
    int[] array =new int[5];
    boolean isEmpty = true;
    Random randomNumber = new Random();

    synchronized void put(){
       if(!isEmpty){
           try{wait();}catch (Exception e){e.printStackTrace();}
       }

       for (int i = 0; i < 5; i++) {
           array[i] = randomNumber.nextInt(99);
           System.out.println("Put "+array[i]+" in the container.");
           try{Thread.sleep(2000);}catch (Exception e){e.printStackTrace();}
       }
       isEmpty = false;
       notify();
    }

    synchronized void get(){
        if(isEmpty){
            try{wait();}catch (Exception e){e.printStackTrace();}
        }
        int index = 4;
        while(index>=0){
            System.out.println("Got "+array[index]+" from the container.");
            try{Thread.sleep(1000);}catch (Exception e){e.printStackTrace();}
            index--;
        }
        isEmpty = true;
        index = 4;
        notify();
    }
}
