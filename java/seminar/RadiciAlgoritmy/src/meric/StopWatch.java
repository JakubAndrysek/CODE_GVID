///**
// * source: https://gist.github.com/EdHurtig/78cbe307c1c85db12af7
// */
//
//package meric;
//
///**
// * A simple java stopwatch
// */
//public class StopWatch {
//    /**
//     * Whether the stopwatch is running
//     */
//    private boolean running;
//
//    /**
//     * Whether the Stopwatch has been paused... not actively counting but the start time should be preserved
//     */
//    private boolean paused;
//
//    /**
//     * The start time in microseconds
//     */
//    private long start;
//
//    /**
//     * The Start time for the current paused time
//     */
//    private long pausedStart;
//
//    /**
//     * The end time
//     */
//    private long end;
//
//    /**
//     * Default Constructor
//     */
//    public StopWatch() {
//        this.pausedStart = 0;
//        this.start = 0;
//        this.end = 0;
//    }
//
//    /**
//     * Determines if the Stopwatch is running (could be paused)
//     *
//     * @return Whether the stopwatch is currently running
//     */
//    public boolean isRunning() {
//        return running;
//    }
//
//    /**
//     * Whether this stopwatch is paused
//     *
//     * @return true if it is currently paused
//     */
//    public boolean isPaused() {
//        return paused;
//    }
//
//    /**
//     * Starts the Stopwatch
//     */
//    public void start() {
//        start = System.nanoTime();
//        running = true;
//        paused = false;
//        pausedStart = -1;
//    }
//
//    /**
//     * Stops the stopwatch and returns the time elapsed
//     *
//     * @return Stops the StopWatch
//     */
//    public long stop() {
//        if (!isRunning()) {
//            return -1;
//        } else if (isPaused()) {
//            running = false;
//            paused = false;
//
//            return pausedStart - start;
//        } else {
//            end = System.nanoTime();
//            running = false;
//            return end - start;
//        }
//    }
//
//    /**
//     * Pauses the Stopwatch
//     *
//     * @return The time elapsed so far
//     */
//    public long pause() {
//        if (!isRunning()) {
//            return -1;
//        } else if (isPaused()) {
//            return (pausedStart - start);
//        } else {
//            pausedStart = System.nanoTime();
//            paused = true;
//            return (pausedStart - start);
//        }
//    }
//
//    /**
//     * Resumes the StopWatch from it's paused state
//     */
//    public void resume() {
//        if (isPaused() && isRunning()) {
//            start = System.nanoTime() - (pausedStart - start);
//            paused = false;
//        }
//    }
//
//    /**
//     * Returns the total time elapsed
//     *
//     * @return The total time elapsed
//     */
//    public long elapsed() {
//        if (isRunning()) {
//            if (isPaused())
//                return (pausedStart - start);
//            return (System.nanoTime() - start);
//        } else
//            return (end - start);
//    }
//
//    /**
//     * Returns the number of seconds this Stopwatch has elapsed
//     *
//     * @return The String of the number of seconds
//     */
//    public String toString() {
//        long enlapsed = elapsed();
//        return ((double) enlapsed / 1000000000.0) + " Seconds";
//    }
//
//}
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
        return formatTime(avg) + " (" + Integer.toString(runs) + " run" + (runs > 1 ? "s" : "") + ") min: " + formatTime(this.min/1000000000) + ", max: " + formatTime(this.max/1000000000) + "\n";
    }
}
