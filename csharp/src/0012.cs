using System;
using System.Diagnostics;

public class Solution {
    public string IntToRoman(int num) {
        return (
            (num / 1000) switch {
                1 => "M",
                2 => "MM",
                3 => "MMM",
                _ => "",
            } +
            (num % 1000 / 100) switch {
                1 => "C",
                2 => "CC",
                3 => "CCC",
                4 => "CD",
                5 => "D",
                6 => "DC",
                7 => "DCC",
                8 => "DCCC",
                9 => "CM",
                _ => "",
            } +
            (num % 100 / 10) switch {
                1 => "X",
                2 => "XX",
                3 => "XXX",
                4 => "XL",
                5 => "L",
                6 => "LX",
                7 => "LXX",
                8 => "LXXX",
                9 => "XC",
                _ => "",
            } +
            (num % 10) switch {
                1 => "I",
                2 => "II",
                3 => "III",
                4 => "IV",
                5 => "V",
                6 => "VI",
                7 => "VII",
                8 => "VIII",
                9 => "IX",
                _ => "",
            });
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.IntToRoman(3) == "III");
        Debug.Assert(o.IntToRoman(58) == "LVIII");
        Debug.Assert(o.IntToRoman(1994) == "MCMXCIV");

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.IntToRoman(3);
            o.IntToRoman(58);
            o.IntToRoman(1994);
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
