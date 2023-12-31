public class Process {
    int id;
    int arrivalTime;
    int duration;
    GlobalTimer globalTimer;
    public Process(int id,int arrivalTime, int duration, GlobalTimer globalTimer){
        this.id=id;
        this.arrivalTime=arrivalTime;
        this.duration=duration;
        this.globalTimer=globalTimer;
    }
    public void runProcess(){
        System.out.println("Process "+ getId() + " is running");
        duration-= 1;
        System.out.println("Global time: " + globalTimer.getGlobalTime());
        globalTimer.TimeAdvance();
    }

    public int getId() {
        return id;
    }
    public int getArrivalTime() {
        return arrivalTime;
    }
    public int getDuration() {
        return duration;
    }
    public GlobalTimer getGlobalTimer() {
        return globalTimer;
    }
}
