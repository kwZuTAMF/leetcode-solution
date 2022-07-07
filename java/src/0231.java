import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.isPowerOfTwo(1)).isTrue();
        assertThat(o.isPowerOfTwo(2)).isTrue();
        assertThat(o.isPowerOfTwo(3)).isFalse();
        assertThat(o.isPowerOfTwo(4)).isTrue();
        assertThat(o.isPowerOfTwo(5)).isFalse();
        assertThat(o.isPowerOfTwo(6)).isFalse();
        assertThat(o.isPowerOfTwo(7)).isFalse();
        assertThat(o.isPowerOfTwo(8)).isTrue();
        assertThat(o.isPowerOfTwo(9)).isFalse();
        assertThat(o.isPowerOfTwo(10)).isFalse();
        assertThat(o.isPowerOfTwo(11)).isFalse();
        assertThat(o.isPowerOfTwo(12)).isFalse();
        assertThat(o.isPowerOfTwo(13)).isFalse();
        assertThat(o.isPowerOfTwo(14)).isFalse();
        assertThat(o.isPowerOfTwo(15)).isFalse();
        assertThat(o.isPowerOfTwo(16)).isTrue();

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.isPowerOfTwo(1);
            o.isPowerOfTwo(2);
            o.isPowerOfTwo(3);
            o.isPowerOfTwo(4);
            o.isPowerOfTwo(5);
            o.isPowerOfTwo(6);
            o.isPowerOfTwo(7);
            o.isPowerOfTwo(8);
            o.isPowerOfTwo(9);
            o.isPowerOfTwo(10);
            o.isPowerOfTwo(11);
            o.isPowerOfTwo(12);
            o.isPowerOfTwo(13);
            o.isPowerOfTwo(14);
            o.isPowerOfTwo(15);
            o.isPowerOfTwo(16);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
