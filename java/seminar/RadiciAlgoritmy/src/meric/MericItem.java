package meric;

public class MericItem {
    StopWatch stopWatch;
    String sortName;
    String sortType;
    Boolean isSorted;

    public MericItem(String sortName, StopWatch stopWatch, String sortType, Boolean isSorted) {
        this.sortName = sortName;
        this.stopWatch = stopWatch;
        this.sortType = sortType;
        this.isSorted = isSorted;
    }

    public StopWatch getStopWatch() {
        return stopWatch;
    }

    public String getSortName() {
        return sortName;
    }

    public Boolean getIsSorted() {
        return isSorted;
    }

    public String getSortType() {
        return sortType;
    }

    public void setIsSorted(Boolean isSorted) {
        this.isSorted = isSorted;
    }

    @Override
    public String toString() {
        if(isSorted == false) {
            return "SORT: " + sortType + " - " + sortName + " -> " + "NOT SORTED";
        } else {
            return "SORT: " + sortType + " - " + sortName + " -> " + stopWatch;
        }
    }
}