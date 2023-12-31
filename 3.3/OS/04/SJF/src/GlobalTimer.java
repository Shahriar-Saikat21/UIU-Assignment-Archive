public class GlobalTimer {
    private int time;
    public GlobalTimer(int initialTime){
        this.time=initialTime;
    }
    public void TimeAdvance(){
        this.time += 1;
    }
    public int getGlobalTime(){
        return this.time;
    }
}