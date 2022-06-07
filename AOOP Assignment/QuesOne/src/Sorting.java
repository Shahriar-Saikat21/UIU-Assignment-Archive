public class Sorting {

    void arraySort(int[]array,int startIndex,int lastIndex){
        for (int i = startIndex; i < lastIndex-1; i++) {
            for (int j = i+1; j < lastIndex; j++) {
                if(array[i]>array[j]){
                    int temp = array[i];
                    array[i]=array[j];
                    array[j] = temp;
                }
            }
        }
        try{Thread.sleep(5000);}catch (Exception e){e.printStackTrace();}
    }

    void arrayPrintAfterSort(int[]array,int totalIndex){
        System.out.print("Array after sorting by this thread : ");
        for (int i = 0; i < totalIndex; i++) {
            System.out.print(array[i]+ " ");
        }
        try{Thread.sleep(3000);}catch (Exception e){e.printStackTrace();}
    }

    void sortingArray(int[]array,int totalIndex){
        for (int i = 0; i < totalIndex-1; i++) {
            for (int j = i+1; j < totalIndex; j++) {
                if(array[i]>array[j]){
                    int temp = array[i];
                    array[i]=array[j];
                    array[j] = temp;
                }
            }
        }
        System.out.println("\nArray after sorting : ");
        for (int i = 0; i < totalIndex; i++) {
            System.out.print(array[i]+" ");
        }
    }

}
