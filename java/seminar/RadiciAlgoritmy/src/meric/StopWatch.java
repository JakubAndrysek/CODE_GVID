package meric;

import java.text.DecimalFormat;

/**
 * The Stopwatch class provides a simple way to record the real-world time taken
 * by an operation, averaged over multiple runs, and report the result easily in
 * logs.
 *
 * An example use case would be timing JDBC calls to a relational database.
 *
 * This code does not measure CPU time or pay any attention to whether a thread
 * or process is active or not. For that, you need to use a profiler.
 *
 * @author mathew <meta@pobox.com>
 *
 * Placed into the public domain.
 */
public class StopWatch {

    private static final DecimalFormat format = new DecimalFormat("#.##");

    private long tstart;
    private long tstop;
    private long min;
    private long max;
    private long total = 0;
    private int runs = 0;

    /**
     * Start a new run of timing something. If the Stopwatch is already timing
     * something, that existing run is canceled.
     */
    public void start() {
        tstart = System.nanoTime();
    }

    /**
     * Stop the current timing run. Does nothing if no existing run is active.
     */
    public void stop() {
        tstop = System.nanoTime();
        long diff = tstop - tstart;
        if(runs == 0) {
            min = diff;
            max = diff;
        }
        if (tstart != 0) {
            tstop = System.nanoTime();
            min = Math.min(min, diff);
            max = Math.max(max, diff);
            total += diff;
            runs += 1;
            tstart = 0;
        }
    }

    /**
     * @return the total number of elapsed seconds recorded by this Stopwatch
     * object in all runs.
     */
    public double getTotalSeconds() {
        return ((double) total) / 1000000000;
    }

    /**
     * @return the average number of seconds per run recorded by this Stopwatch
     * object.
     */
    public double getAverageSeconds() {
        if (runs == 0) {
            return 0;
        }
        return ((double) total) / 1000000000 / runs;
    }

    /**
     * @return the number of runs completed.
     */
    public int getRuns() {
        return runs;
    }

    public long getMin() {
        return min;
    }

    public long getMax() {
        return max;
    }

    public String formatTime(final double num) {
        int pow = (int) Math.round(-Math.log10(num));
        double mult;
        String unit;
        if (pow < 0) {
            pow = 0;
        }
        if (pow < 2) {
            unit = "s";
            mult = 1.0;
        } else if (pow < 4) {
            unit = "ms";
            mult = 1000.0;
        } else if (pow < 7) {
            unit = "µs";
            mult = 1000000.0;
        } else {
            unit = "ns";
            mult = 1000000000.0;
        }
        return format.format(mult * num) + unit;
    }

    /**
     * @return a string representation of the Stopwatch object suitable for
     * output to humans. e.g. "1.46ms (87 runs)"
     */
    @Override
    public String toString() {
        final double avg = this.getAverageSeconds();
        return formatTime(avg) + " (" + Integer.toString(runs) + " run" + (runs > 1 ? "s" : "") + ") min: " + formatTime(this.min/1000000000) + ", max: " + formatTime(this.max/1000000000);
    }
}
