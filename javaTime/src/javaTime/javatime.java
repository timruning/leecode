package javaTime;
 
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
 
public class javatime {
    static class Context {
        Lock lock = new ReentrantLock();
 
        long msg;
 
        boolean pingSent;
        Condition pingSentCond = lock.newCondition();
 
        boolean pongSent;
        Condition pongSentCond = lock.newCondition();
    }
 
    static class Ping implements Runnable {
 
        public Context ctx;
        public long curVal = 1;
        public long limit;
 
        public Ping(Context ctx, long limit) {
            this.ctx = ctx;
            this.limit = limit;
        }
 
        @Override
        public void run() {
            try {
                ctx.lock.lock();
                while (true) {
                    // send
                    ctx.msg = curVal;
                    ctx.pingSent = true;
                    ctx.pingSentCond.signalAll();
 
                    // receive
                    while (!ctx.pongSent) {
                        ctx.pongSentCond.await(); // implicit unlock
                    }
                    ctx.pongSent = false;
                    long newVal = ctx.msg;
 
                    // update
                    curVal = newVal + 1;
 
                    // exit
                    if (newVal >= limit) { // last message and exit
                        ctx.msg = -1L;
                        ctx.pingSent = true;
                        ctx.pingSentCond.signalAll();
 
                        break; // exit
                    }
                }
            } catch (InterruptedException e) {
                System.out.println("[ping] Interrupted. This should not happen.");
                e.printStackTrace(System.out);
            } finally {
                ctx.lock.unlock();
            }
        }
    }
 
    static class Pong implements Runnable {
 
        public Context ctx;
        public long curVal;
 
        public Pong(Context ctx) {
            this.ctx = ctx;
        }
 
        @Override
        public void run() {
            try {
                ctx.lock.lock();
                while (true) {
                    // receive
                    while (!ctx.pingSent) {
                        ctx.pingSentCond.await(); // implicit unlock
                    }
                    ctx.pingSent = false;
                    long newVal = ctx.msg;
 
                    // update
                    curVal = newVal + 1;
 
                    // exit
                    if (newVal == -1) { // exit on demand
                        break; // exit
                    }
 
                    // send
                    ctx.msg = curVal;
                    ctx.pongSent = true;
                    ctx.pongSentCond.signalAll();
                }
            } catch (InterruptedException e) {
                System.out.println("[pong] Interrupted. This should not happen.");
                e.printStackTrace(System.out);
            } finally {
                ctx.lock.unlock();
            }
        }
    }
 
    public static void main(String[] args) throws Exception {
        Context ctx = new Context();
        Ping ping = new Ping(ctx, 5000000L);
        Pong pong = new Pong(ctx);
        Thread pingThr = new Thread(ping);
        Thread pongThr = new Thread(pong);
         
        long t1 = System.currentTimeMillis();
        pingThr.start();
        pongThr.start();
        pingThr.join();
        pongThr.join();
        long t2 = System.currentTimeMillis();
         
        System.out.printf("time: %dms\n", t2-t1);
        System.out.printf("ping.curVal = %d\n", ping.curVal);
    }
 
}