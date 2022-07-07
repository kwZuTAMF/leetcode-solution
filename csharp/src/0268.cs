using System;
using System.Diagnostics;

public class Solution {
    public int MissingNumber(int[] nums) {
        var n = nums.Length;
        var s = 0;
        foreach (var i in nums) {
            s += i;
        }
        return (n * (n + 1) >> 1) - s;
    }

    // public int MissingNumber(int[] nums) {
    //     var n = nums.Length;
    //     var x = (n % 4) switch {
    //         0 => n,
    //         1 => 1,
    //         2 => n + 1,
    //         _ => 0,
    //     };
    //     foreach (var i in nums) {
    //         x ^= i;
    //     }
    //     return x;
    // }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.MissingNumber(new[] { 3, 0, 1 }) == 2);
        Debug.Assert(o.MissingNumber(new[] { 0, 1 }) == 2);
        Debug.Assert(o.MissingNumber(new[] { 9, 6, 4, 2, 3, 5, 7, 0, 1 }) == 8);

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.MissingNumber(new[] { 3, 0, 1 });
            o.MissingNumber(new[] { 0, 1 });
            o.MissingNumber(new[] { 9, 6, 4, 2, 3, 5, 7, 0, 1 });
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
