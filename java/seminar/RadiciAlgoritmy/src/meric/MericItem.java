package meric;

public class MericItem {
    StopWatch stopWatch;
    String sortName;
    
    public MericItem(StopWatch stopWatch, String sortName) {
        this.stopWatch = stopWatch;
        this.sortName = sortName;
    }

    public StopWatch getStopWatch() {
        return stopWatch;
    }

    public String getSortName() {
        return sortName;
    }    
}