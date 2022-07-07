import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public int strStr(String haystack, String needle) {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0)
            return 0;
        int next[] = new int[m];
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle.charAt(i) != needle.charAt(j))
                j = next[j - 1];
            if (needle.charAt(i) == needle.charAt(j))
                j++;
            next[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack.charAt(i) != needle.charAt(j))
                j = next[j - 1];
            if (haystack.charAt(i) == needle.charAt(j))
                j++;
            if (j == m)
                return i - m + 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.strStr("hello", "ll")).isEqualTo(2);
        assertThat(o.strStr("aaaaa", "bba")).isEqualTo(-1);

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.strStr("hello", "ll");
            o.strStr("aaaaa", "bba");
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
