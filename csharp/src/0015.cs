using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        var n = nums.Length;
        var ans = new List<IList<int>>();
        if (n < 3) {
            return ans;
        }
        Array.Sort(nums);
        if (nums[0] > 0 || nums[n - 1] < 0) {
            return ans;
        }
        for (var i = 0; i < n - 2 && nums[i] <= 0; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                var p = i + 1;
                var q = n - 1;
                while (p < q) {
                    var s = nums[i] + nums[p] + nums[q];
                    if (s < 0) {
                        do {
                            p++;
                        } while (p < q && nums[p] == nums[p - 1]);
                    } else if (s > 0) {
                        do {
                            q--;
                        } while (p < q && nums[q] == nums[q + 1]);
                    } else {
                        ans.Add(new List<int> { nums[i], nums[p], nums[q] });
                        do {
                            p++;
                        } while (p < q && nums[p] == nums[p - 1]);
                        do {
                            q--;
                        } while (p < q && nums[q] == nums[q + 1]);
                    }
                }
            }
        }
        return ans;
    }

    static void Main(string[] args) {
        var o = new Solution();

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.ThreeSum(new[] { -1, 0, 1, 2, -1, -4 });
            o.ThreeSum(new int[] { });
            o.ThreeSum(new int[] { 0 });
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
