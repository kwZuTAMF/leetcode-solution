import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public int countPrimes(int n) {
        if (n < 3)
            return 0;
        var count = n >> 1;
        var sieve = new boolean[n];
        for (var i = 3; i * i < n; i += 2) {
            if (!sieve[i]) {
                for (var j = i * i; j < n; j += i << 1) {
                    if (!sieve[j]) {
                        sieve[j] = true;
                        count--;
                    }
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.countPrimes(0)).isEqualTo(0);
        assertThat(o.countPrimes(1)).isEqualTo(0);
        assertThat(o.countPrimes(2)).isEqualTo(0);
        assertThat(o.countPrimes(3)).isEqualTo(1);
        assertThat(o.countPrimes(4)).isEqualTo(2);
        assertThat(o.countPrimes(5)).isEqualTo(2);
        assertThat(o.countPrimes(6)).isEqualTo(3);
        assertThat(o.countPrimes(7)).isEqualTo(3);
        assertThat(o.countPrimes(8)).isEqualTo(4);
        assertThat(o.countPrimes(9)).isEqualTo(4);
        assertThat(o.countPrimes(10)).isEqualTo(4);
        assertThat(o.countPrimes(11)).isEqualTo(4);
        assertThat(o.countPrimes(12)).isEqualTo(5);
        assertThat(o.countPrimes(13)).isEqualTo(5);
        assertThat(o.countPrimes(14)).isEqualTo(6);
        assertThat(o.countPrimes(15)).isEqualTo(6);
        assertThat(o.countPrimes(10000)).isEqualTo(1229);
        assertThat(o.countPrimes(499979)).isEqualTo(41537);
        assertThat(o.countPrimes(999983)).isEqualTo(78497);
        assertThat(o.countPrimes(1500000)).isEqualTo(114155);

        var start = Instant.now();
        for (var i = 0; i < 100; i++) {
            o.countPrimes(0);
            o.countPrimes(1);
            o.countPrimes(2);
            o.countPrimes(3);
            o.countPrimes(4);
            o.countPrimes(5);
            o.countPrimes(6);
            o.countPrimes(7);
            o.countPrimes(8);
            o.countPrimes(9);
            o.countPrimes(10);
            o.countPrimes(11);
            o.countPrimes(12);
            o.countPrimes(13);
            o.countPrimes(14);
            o.countPrimes(15);
            o.countPrimes(10000);
            o.countPrimes(499979);
            o.countPrimes(999983);
            o.countPrimes(1500000);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
