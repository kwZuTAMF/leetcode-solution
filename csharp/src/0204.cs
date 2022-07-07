using System;
using System.Diagnostics;

public class Solution {
    public int CountPrimes(int n) {
        if (n < 3) {
            return 0;
        }
        var count = n >> 1;
        var sieve = new bool[n];
        for (var i = 3; i * i < n; i += 2) {
            if (!sieve[i]) {
                for (var j = i * i; j < n; j += i << 1) {
                    if (!sieve[j]) {
                        sieve[j] = true;
                        count--;
                    }
                }
            }
        }
        return count;
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.CountPrimes(0) == 0);
        Debug.Assert(o.CountPrimes(1) == 0);
        Debug.Assert(o.CountPrimes(2) == 0);
        Debug.Assert(o.CountPrimes(3) == 1);
        Debug.Assert(o.CountPrimes(4) == 2);
        Debug.Assert(o.CountPrimes(5) == 2);
        Debug.Assert(o.CountPrimes(6) == 3);
        Debug.Assert(o.CountPrimes(7) == 3);
        Debug.Assert(o.CountPrimes(8) == 4);
        Debug.Assert(o.CountPrimes(9) == 4);
        Debug.Assert(o.CountPrimes(10) == 4);
        Debug.Assert(o.CountPrimes(11) == 4);
        Debug.Assert(o.CountPrimes(12) == 5);
        Debug.Assert(o.CountPrimes(13) == 5);
        Debug.Assert(o.CountPrimes(14) == 6);
        Debug.Assert(o.CountPrimes(15) == 6);
        Debug.Assert(o.CountPrimes(10000) == 1229);
        Debug.Assert(o.CountPrimes(499979) == 41537);
        Debug.Assert(o.CountPrimes(999983) == 78497);
        Debug.Assert(o.CountPrimes(1500000) == 114155);

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 100; i++) {
            o.CountPrimes(0);
            o.CountPrimes(1);
            o.CountPrimes(2);
            o.CountPrimes(3);
            o.CountPrimes(4);
            o.CountPrimes(5);
            o.CountPrimes(6);
            o.CountPrimes(7);
            o.CountPrimes(8);
            o.CountPrimes(9);
            o.CountPrimes(10);
            o.CountPrimes(11);
            o.CountPrimes(12);
            o.CountPrimes(13);
            o.CountPrimes(14);
            o.CountPrimes(15);
            o.CountPrimes(10000);
            o.CountPrimes(499979);
            o.CountPrimes(999983);
            o.CountPrimes(1500000);
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
