import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public void reverseString(char[] s) {
        for (int i = 0, j = s.length - 1; i < j; i++, j--) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }

    public static void main(String[] args) {
        var o = new Solution();

        {
            var s = new char[] { 'h', 'e', 'l', 'l', 'o' };
            o.reverseString(s);
            assertThat(s).isEqualTo(new char[] { 'o', 'l', 'l', 'e', 'h' });
        }
        {
            var s = new char[] { 'H', 'a', 'n', 'n', 'a', 'h' };
            o.reverseString(s);
            assertThat(s).isEqualTo(new char[] { 'h', 'a', 'n', 'n', 'a', 'H' });
        }

        var start = Instant.now();
        for (var i = 0; i < 10000; i++) {
            o.reverseString(new char[] { 'h', 'e', 'l', 'l', 'o' });
            o.reverseString(new char[] { 'H', 'a', 'n', 'n', 'a', 'h' });
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
