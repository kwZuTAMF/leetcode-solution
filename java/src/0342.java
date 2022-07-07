import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public boolean isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) == n;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.isPowerOfFour(0)).isFalse();
        assertThat(o.isPowerOfFour(1)).isTrue();
        assertThat(o.isPowerOfFour(2)).isFalse();
        assertThat(o.isPowerOfFour(3)).isFalse();
        assertThat(o.isPowerOfFour(4)).isTrue();
        assertThat(o.isPowerOfFour(5)).isFalse();
        assertThat(o.isPowerOfFour(6)).isFalse();
        assertThat(o.isPowerOfFour(7)).isFalse();
        assertThat(o.isPowerOfFour(8)).isFalse();
        assertThat(o.isPowerOfFour(9)).isFalse();
        assertThat(o.isPowerOfFour(10)).isFalse();
        assertThat(o.isPowerOfFour(11)).isFalse();
        assertThat(o.isPowerOfFour(12)).isFalse();
        assertThat(o.isPowerOfFour(13)).isFalse();
        assertThat(o.isPowerOfFour(14)).isFalse();
        assertThat(o.isPowerOfFour(15)).isFalse();
        assertThat(o.isPowerOfFour(16)).isTrue();
        assertThat(o.isPowerOfFour(32)).isFalse();
        assertThat(o.isPowerOfFour(64)).isTrue();
        assertThat(o.isPowerOfFour(128)).isFalse();
        assertThat(o.isPowerOfFour(256)).isTrue();
        assertThat(o.isPowerOfFour(512)).isFalse();
        assertThat(o.isPowerOfFour(1024)).isTrue();
        assertThat(o.isPowerOfFour(2048)).isFalse();
        assertThat(o.isPowerOfFour(4096)).isTrue();
        assertThat(o.isPowerOfFour(8192)).isFalse();

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.isPowerOfFour(0);
            o.isPowerOfFour(1);
            o.isPowerOfFour(2);
            o.isPowerOfFour(3);
            o.isPowerOfFour(4);
            o.isPowerOfFour(5);
            o.isPowerOfFour(6);
            o.isPowerOfFour(7);
            o.isPowerOfFour(8);
            o.isPowerOfFour(9);
            o.isPowerOfFour(10);
            o.isPowerOfFour(11);
            o.isPowerOfFour(12);
            o.isPowerOfFour(13);
            o.isPowerOfFour(14);
            o.isPowerOfFour(15);
            o.isPowerOfFour(16);
            o.isPowerOfFour(32);
            o.isPowerOfFour(64);
            o.isPowerOfFour(128);
            o.isPowerOfFour(256);
            o.isPowerOfFour(512);
            o.isPowerOfFour(1024);
            o.isPowerOfFour(2048);
            o.isPowerOfFour(4096);
            o.isPowerOfFour(8192);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
