using System;
using System.Diagnostics;

public class Solution {

    public int MinSubArrayLen(int target, int[] nums) {
        int n = nums.Length;
        int m = int.MaxValue;
        int s = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            s += nums[j++];
            while (s >= target) {
                s -= nums[i++];
                m = Math.Min(m, j - i + 1);
            }
        }
        return m == int.MaxValue ? 0 : m;
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.MinSubArrayLen(7, new[] { 2, 3, 1, 2, 4, 3 }) == 2);
        Debug.Assert(o.MinSubArrayLen(4, new[] { 1, 4, 4 }) == 1);
        Debug.Assert(o.MinSubArrayLen(11, new[] { 1, 1, 1, 1, 1, 1, 1, 1 }) == 0);

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.MinSubArrayLen(7, new[] { 2, 3, 1, 2, 4, 3 });
            o.MinSubArrayLen(4, new[] { 1, 4, 4 });
            o.MinSubArrayLen(11, new[] { 1, 1, 1, 1, 1, 1, 1, 1 });
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
