import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class SJF {
    static PriorityQueue<Process> processQueue = new PriorityQueue<Process>(10, new Comparator<Process>() {
        public int compare(Process process1, Process process2) {
            return (int)(process1.getArrivalTime()-process2.getArrivalTime());
        }
    });
    static PriorityQueue<Process> readyQueue = new PriorityQueue<Process>(10, new Comparator<Process>() {
        public int compare(Process process1, Process process2) {
            return (int)(process1.getDuration()-process2.getDuration());
        }
    });
    static StatictisProcess[] statArray = new StatictisProcess[100];
    static int i = 0;
    static GlobalTimer globalTimer = new GlobalTimer(0);
    static  boolean isRunning = false;
    static Process runningProcess = null;

    public static void main(String[] args) {
        processQueue.add(new Process(1,1,6,globalTimer));
        processQueue.add(new Process(2,3,2,globalTimer));
        processQueue.add(new Process(3,1,4,globalTimer));
        processQueue.add(new Process(4,6,3,globalTimer));
        processQueue.add(new Process(5,20,2,globalTimer));
        processQueue.add(new Process(6,18,3,globalTimer));

        while(globalTimer.getGlobalTime() < 35){
            if(checkIfNewProcessArrived()){
                Process p = processQueue.poll();
                statArray[i] = new StatictisProcess(p.id,p.arrivalTime,p.duration);
                i++;
                readyQueue.add(p);
            }

            if(!readyQueue.isEmpty() || isRunning){
                runProcessInCpu();
            }else{
                System.out.println("No process is in Ready Queue");
                System.out.println("Global time: " + globalTimer.getGlobalTime());
                globalTimer.TimeAdvance();
            }
        }

        calculation();
    }

    public static boolean checkIfNewProcessArrived(){
        if(!processQueue.isEmpty()){
            int currentTime = globalTimer.getGlobalTime();
            Process p = processQueue.peek();
            int processTime = p.getArrivalTime();
            if(currentTime == processTime) {return true;}
        }
        return false;
    }

    public static void runProcessInCpu(){
        if(!isRunning){
            runningProcess = readyQueue.poll();
            isRunning = true;
        }else{
            runningProcess.runProcess();
            if(runningProcess.getDuration()==0){
                for(int j = 0; j < statArray.length; j++){
                    if(statArray[j].processId == runningProcess.id){
                        statArray[j].setCompleteTime(globalTimer.getGlobalTime());
                        break;
                    }
                }
                System.out.println("********Process Id: "+ runningProcess.getId() +" completed its job********");
                isRunning = false;
            }
        }
    }

    public static void calculation(){
        System.out.println("----------Simulation ended-----------");

        float totalWaitingTime = 0;
        float totalTAT = 0;

        int minWait = 99999;
        int maxWait = 0;

        StatictisProcess min_s = null;
        StatictisProcess max_s = null;

        Queue<StatictisProcess> minqueue = new LinkedList<>();
        Queue<StatictisProcess> maxqueue = new LinkedList<>();

        for (int k = 0; k<i; k++){
            totalWaitingTime += statArray[k].turnAroundTime();
            totalTAT += statArray[k].waitingTime();
            if(statArray[k].waitingTime() <= minWait){
                minWait = statArray[k].waitingTime();
                min_s = statArray[k];
                minqueue.add(statArray[k]);
            }
            if(statArray[k].waitingTime() >= maxWait){
                maxWait = statArray[k].waitingTime();
                max_s = statArray[k];
                while(!maxqueue.isEmpty()){
                    maxqueue.remove();
                }
                maxqueue.add(statArray[k]);
            }
        }

        System.out.println("Average waiting time : " + (totalWaitingTime/i));
        System.out.println("Average turnaround time : " + (totalTAT/i));
        System.out.print("Min wait time: " + minWait + " processID: ");
        while(!minqueue.isEmpty()){
            StatictisProcess a = minqueue.remove();
            if(a.waitingTime() == minWait){
                System.out.print(a.processId+" ");
            }
        }

        System.out.println();

        System.out.print("Max wait time: " + maxWait+ " processID: ");
        while(!maxqueue.isEmpty()){
            StatictisProcess b = maxqueue.remove();
            if(b.waitingTime() == maxWait){
                System.out.print(b.processId+" ");
            }
        }
    }
}
