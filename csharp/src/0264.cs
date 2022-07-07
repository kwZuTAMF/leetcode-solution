using System;
using System.Diagnostics;

public class Solution {

    public int NthUglyNumber(int n) {
        var dp = new int[n];
        int i2 = 0, i3 = 0, i5 = 0;
        dp[0] = 1;
        for (var i = 1; i < n; i++) {
            int n2 = dp[i2] * 2, n3 = dp[i3] * 3, n5 = dp[i5] * 5;
            int next = Math.Min(n2, Math.Min(n3, n5));
            if (next == n2) i2++;
            if (next == n3) i3++;
            if (next == n5) i5++;
            dp[i] = next;
        }
        return dp[n - 1];
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.NthUglyNumber(1) == 1);
        Debug.Assert(o.NthUglyNumber(10) == 12);

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.NthUglyNumber(1);
            o.NthUglyNumber(10);
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
