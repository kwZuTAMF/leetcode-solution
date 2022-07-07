using System;
using System.Diagnostics;

public class Solution {

    public int StrStr(string haystack, string needle) {
        int n = haystack.Length;
        int m = needle.Length;
        if (m == 0) return 0;
        int[] next = new int[m];
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) j = next[j - 1];
            if (needle[i] == needle[j]) j++;
            next[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) j = needle[j - 1];
            if (haystack[i] == needle[j]) j++;
            if (j == m) return i - m + 1;
        }
        return -1;
    }

    static void Main(string[] args) {
        var o = new Solution();

        Debug.Assert(o.StrStr("hello", "ll") == 2);
        Debug.Assert(o.StrStr("aaaaa", "bba") == -1);

        var timer = new Stopwatch();
        timer.Start();
        for (var i = 0; i < 1000000; i++) {
            o.StrStr("hello", "ll");
            o.StrStr("aaaaa", "bba");
        }
        timer.Stop();
        Console.WriteLine(timer.Elapsed.TotalMilliseconds);
    }
}
