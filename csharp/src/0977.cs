using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

public class Solution {

    public int[] SortedSquares(int[] nums) {
        var n = nums.Length;
        var squares = new int[n];
        for (int i = 0, j = n - 1, k = n - 1; i <= j; k--) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                squares[k] = a;
                i++;
            } else {
                squares[k] = b;
                j--;
            }
        }
        return squares;
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.SortedSquares(new[] { -4, -1, 0, 3, 10 }).SequenceEqual(new[] { 0, 1, 9, 16, 100 }));
        Debug.Assert(o.SortedSquares(new[] { -7, -3, 2, 3, 11 }).SequenceEqual(new[] { 4, 9, 9, 49, 121 }));

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.SortedSquares(new[] { -4, -1, 0, 3, 10 });
            o.SortedSquares(new[] { -7, -3, 2, 3, 11 });
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
