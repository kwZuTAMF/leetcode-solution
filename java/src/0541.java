import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public String reverseStr(String s, int k) {
        char[] value = s.toCharArray();
        for (int i = 0, n = s.length(); i < n; i += k << 1) {
            for (int p = i, q = Math.min(n - 1, i + k - 1); p < q; p++, q--) {
                char t = value[p];
                value[p] = value[q];
                value[q] = t;
            }
        }
        return new String(value);
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.reverseStr("abcdefg", 2)).isEqualTo("bacdfeg");
        assertThat(o.reverseStr("abcd", 2)).isEqualTo("bacd");

        var start = Instant.now();
        for (var i = 0; i < 10000; i++) {
            o.reverseStr("abcdefg", 2);
            o.reverseStr("abcd", 2);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
