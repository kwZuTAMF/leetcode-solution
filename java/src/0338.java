import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public int[] countBits(int n) {
        var dp = new int[n + 1];
        for (var i = 1; i <= n; i++)
            dp[i] = dp[i >> 1] + (i & 1);
        return dp;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.countBits(0)).isEqualTo(new int[] { 0 });
        assertThat(o.countBits(1)).isEqualTo(new int[] { 0, 1 });
        assertThat(o.countBits(2)).isEqualTo(new int[] { 0, 1, 1 });
        assertThat(o.countBits(3)).isEqualTo(new int[] { 0, 1, 1, 2 });
        assertThat(o.countBits(4)).isEqualTo(new int[] { 0, 1, 1, 2, 1 });
        assertThat(o.countBits(5)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2 });
        assertThat(o.countBits(6)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2, 2 });
        assertThat(o.countBits(7)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2, 2, 3 });
        assertThat(o.countBits(8)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2, 2, 3, 1 });
        assertThat(o.countBits(9)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2 });
        assertThat(o.countBits(10)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2 });
        assertThat(o.countBits(11)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3 });
        assertThat(o.countBits(12)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2 });
        assertThat(o.countBits(13)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3 });
        assertThat(o.countBits(14)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3 });
        assertThat(o.countBits(15)).isEqualTo(new int[] { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 });

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.countBits(0);
            o.countBits(1);
            o.countBits(2);
            o.countBits(3);
            o.countBits(4);
            o.countBits(5);
            o.countBits(6);
            o.countBits(7);
            o.countBits(8);
            o.countBits(9);
            o.countBits(10);
            o.countBits(11);
            o.countBits(12);
            o.countBits(13);
            o.countBits(14);
            o.countBits(15);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
