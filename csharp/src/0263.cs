using System;
using System.Diagnostics;

public class Solution {
    public bool IsUgly(int n) {
        if (n <= 10) return n > 0 && n != 7;
        while (n % 5 == 0) n /= 5;
        while (n % 3 == 0) n /= 3;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.IsUgly(0) == false);
        Debug.Assert(o.IsUgly(1) == true);
        Debug.Assert(o.IsUgly(2) == true);
        Debug.Assert(o.IsUgly(3) == true);
        Debug.Assert(o.IsUgly(4) == true);
        Debug.Assert(o.IsUgly(5) == true);
        Debug.Assert(o.IsUgly(6) == true);
        Debug.Assert(o.IsUgly(7) == false);
        Debug.Assert(o.IsUgly(8) == true);
        Debug.Assert(o.IsUgly(9) == true);
        Debug.Assert(o.IsUgly(10) == true);
        Debug.Assert(o.IsUgly(11) == false);
        Debug.Assert(o.IsUgly(12) == true);
        Debug.Assert(o.IsUgly(13) == false);
        Debug.Assert(o.IsUgly(14) == false);
        Debug.Assert(o.IsUgly(15) == true);
        Debug.Assert(o.IsUgly(16) == true);
        Debug.Assert(o.IsUgly(17) == false);
        Debug.Assert(o.IsUgly(18) == true);
        Debug.Assert(o.IsUgly(19) == false);

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.IsUgly(0);
            o.IsUgly(1);
            o.IsUgly(2);
            o.IsUgly(3);
            o.IsUgly(4);
            o.IsUgly(5);
            o.IsUgly(6);
            o.IsUgly(7);
            o.IsUgly(8);
            o.IsUgly(9);
            o.IsUgly(10);
            o.IsUgly(11);
            o.IsUgly(12);
            o.IsUgly(13);
            o.IsUgly(14);
            o.IsUgly(15);
            o.IsUgly(16);
            o.IsUgly(17);
            o.IsUgly(18);
            o.IsUgly(19);
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
