using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

public class Solution {
    public IList<string> FizzBuzz(int n) {
        var ans = new List<string>(n);
        for (var i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                ans.Add(i % 5 == 0 ? "FizzBuzz" : "Fizz");
            } else {
                ans.Add(i % 5 == 0 ? "Buzz" : i.ToString());
            }
        }
        return ans;
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.FizzBuzz(3).SequenceEqual(new[] { "1", "2", "Fizz" }));
        Debug.Assert(o.FizzBuzz(5).SequenceEqual(new[] { "1", "2", "Fizz", "4", "Buzz" }));
        Debug.Assert(o.FizzBuzz(15).SequenceEqual(new[] { "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz" }));

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.FizzBuzz(3);
            o.FizzBuzz(5);
            o.FizzBuzz(15);
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
