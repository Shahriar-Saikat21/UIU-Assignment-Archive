import java.util.Scanner;

public class QuesOne {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int[] array = new int[100];

        System.out.print("Enter Number of Element of the array :");
        int numberOfElement= s.nextInt();

        System.out.print("Enter array's elements : ");
        for (int i = 0; i < numberOfElement; i++) {
            array[i] = s.nextInt();
        }

        System.out.print("Enter the number you want to divide the array: ");
        int numberOfDivide = s.nextInt();

        Sorting sort = new Sorting();

        int divideCount=1;
        int elementEachDivision = numberOfElement/numberOfDivide;
        int startIndex = 0;
        int lastIndex = elementEachDivision;


        while(divideCount<=numberOfDivide){

            String threadName = divideCount + "";
            Caller c1 = new Caller(sort,array,startIndex,lastIndex,numberOfElement,threadName);
            try{c1.t.join();}catch (Exception e){e.printStackTrace();}

            startIndex = lastIndex;
            if(divideCount== (numberOfDivide-1)){
                lastIndex = numberOfElement;
            }else{
                lastIndex += elementEachDivision;
            }

            divideCount++;
        }

        sort.sortingArray(array,numberOfElement);

    }
}
