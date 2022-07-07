import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public boolean isUgly(int n) {
        if (n <= 10) return n > 0 && n != 7;
        while (n % 5 == 0) n /= 5;
        while (n % 3 == 0) n /= 3;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.isUgly(0)).isFalse();
        assertThat(o.isUgly(1)).isTrue();
        assertThat(o.isUgly(2)).isTrue();
        assertThat(o.isUgly(3)).isTrue();
        assertThat(o.isUgly(4)).isTrue();
        assertThat(o.isUgly(5)).isTrue();
        assertThat(o.isUgly(6)).isTrue();
        assertThat(o.isUgly(7)).isFalse();
        assertThat(o.isUgly(8)).isTrue();
        assertThat(o.isUgly(9)).isTrue();
        assertThat(o.isUgly(10)).isTrue();
        assertThat(o.isUgly(11)).isFalse();
        assertThat(o.isUgly(12)).isTrue();
        assertThat(o.isUgly(13)).isFalse();
        assertThat(o.isUgly(14)).isFalse();
        assertThat(o.isUgly(15)).isTrue();
        assertThat(o.isUgly(16)).isTrue();
        assertThat(o.isUgly(17)).isFalse();
        assertThat(o.isUgly(18)).isTrue();
        assertThat(o.isUgly(19)).isFalse();

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.isUgly(0);
            o.isUgly(1);
            o.isUgly(2);
            o.isUgly(3);
            o.isUgly(4);
            o.isUgly(5);
            o.isUgly(6);
            o.isUgly(7);
            o.isUgly(8);
            o.isUgly(9);
            o.isUgly(10);
            o.isUgly(11);
            o.isUgly(12);
            o.isUgly(13);
            o.isUgly(14);
            o.isUgly(15);
            o.isUgly(16);
            o.isUgly(17);
            o.isUgly(18);
            o.isUgly(19);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
