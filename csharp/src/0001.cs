using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var m = new Dictionary<int, int>();
        for (var i = 0; i < nums.Length; i++) {
            if (m.ContainsKey(target - nums[i])) {
                return new[] { m[target - nums[i]], i };
            } else {
                m.Add(nums[i], i);
            }
        }
        throw new ArgumentException("Solution either does not exist or is not unique");
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.TwoSum(new[] { 2, 7, 11, 15 }, 9).SequenceEqual(new[] { 0, 1 }));
        Debug.Assert(o.TwoSum(new[] { 3, 2, 4 }, 6).SequenceEqual(new[] { 1, 2 }));
        Debug.Assert(o.TwoSum(new[] { 3, 3 }, 6).SequenceEqual(new[] { 0, 1 }));

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.TwoSum(new[] { 2, 7, 11, 15 }, 9);
            o.TwoSum(new[] { 3, 2, 4 }, 6);
            o.TwoSum(new[] { 3, 3 }, 6);
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
