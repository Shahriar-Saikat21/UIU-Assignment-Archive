public class StatictisProcess {
    public int processId;
    public int arrivalTime;
    public int burstTime;
    public int completeTime;

    public StatictisProcess(int processId,int arrivalTime,int burstTime){
        this.processId = processId;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
    }

    public void setCompleteTime(int completeTime) {
        this.completeTime = completeTime;
    }

    public int turnAroundTime (){
        return completeTime - arrivalTime;
    }

    public int waitingTime (){
        return (completeTime - arrivalTime) - burstTime;
    }
}
