using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

public class Solution {
    public int NthSuperUglyNumber(int n, int[] primes) {
        var ugly = 1;
        var nums = new SortedSet<int>() { 1 };
        for (var i = 0; i < n; i++) {
            ugly = nums.Min();
            nums.Remove(ugly);
            foreach (var prime in primes) {
                nums.Add(ugly * prime);
            }
        }
        return ugly;
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.NthSuperUglyNumber(12, new[] { 2, 7, 13, 19 }) == 32);
        Debug.Assert(o.NthSuperUglyNumber(1, new[] { 2, 3, 5 }) == 1);

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 10000; i++) {
            o.NthSuperUglyNumber(12, new[] { 2, 7, 13, 19 });
            o.NthSuperUglyNumber(1, new[] { 2, 3, 5 });
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
