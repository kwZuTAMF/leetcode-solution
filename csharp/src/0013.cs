using System;
using System.Diagnostics;

#pragma warning disable CS8509
public class Solution {
    public int RomanToInt(string s) {
        var n = 0;
        var p = '\0';
        foreach (var c in s) {
            n += c switch {
                'M' => p == 'C' ? 800 : 1000,
                'D' => p == 'C' ? 300 : 500,
                'C' => p == 'X' ? 80 : 100,
                'L' => p == 'X' ? 30 : 50,
                'X' => p == 'I' ? 8 : 10,
                'V' => p == 'I' ? 3 : 5,
                _ => 1,
            };
            p = c;
        }
        return n;
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.RomanToInt("III") == 3);
        Debug.Assert(o.RomanToInt("LVIII") == 58);
        Debug.Assert(o.RomanToInt("MCMXCIV") == 1994);

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.RomanToInt("III");
            o.RomanToInt("LVIII");
            o.RomanToInt("MCMXCIV");
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
