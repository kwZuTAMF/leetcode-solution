import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public boolean isPowerOfThree(int n) {
        return n > 0 && (1162261467 % n) == 0;
    }

    // public boolean isPowerOfThree(int n) {
    //     return switch (n) {
    //         case 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467 -> true;
    //         default -> false;
    //     };
    // }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.isPowerOfThree(0)).isFalse();
        assertThat(o.isPowerOfThree(1)).isTrue();
        assertThat(o.isPowerOfThree(2)).isFalse();
        assertThat(o.isPowerOfThree(3)).isTrue();
        assertThat(o.isPowerOfThree(4)).isFalse();
        assertThat(o.isPowerOfThree(5)).isFalse();
        assertThat(o.isPowerOfThree(6)).isFalse();
        assertThat(o.isPowerOfThree(7)).isFalse();
        assertThat(o.isPowerOfThree(8)).isFalse();
        assertThat(o.isPowerOfThree(9)).isTrue();
        assertThat(o.isPowerOfThree(10)).isFalse();
        assertThat(o.isPowerOfThree(27)).isTrue();
        assertThat(o.isPowerOfThree(45)).isFalse();
        assertThat(o.isPowerOfThree(81)).isTrue();
        assertThat(o.isPowerOfThree(243)).isTrue();
        assertThat(o.isPowerOfThree(729)).isTrue();
        assertThat(o.isPowerOfThree(2187)).isTrue();
        assertThat(o.isPowerOfThree(6561)).isTrue();
        assertThat(o.isPowerOfThree(19683)).isTrue();

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.isPowerOfThree(0);
            o.isPowerOfThree(1);
            o.isPowerOfThree(2);
            o.isPowerOfThree(3);
            o.isPowerOfThree(4);
            o.isPowerOfThree(5);
            o.isPowerOfThree(6);
            o.isPowerOfThree(7);
            o.isPowerOfThree(8);
            o.isPowerOfThree(9);
            o.isPowerOfThree(10);
            o.isPowerOfThree(27);
            o.isPowerOfThree(45);
            o.isPowerOfThree(81);
            o.isPowerOfThree(243);
            o.isPowerOfThree(729);
            o.isPowerOfThree(2187);
            o.isPowerOfThree(6561);
            o.isPowerOfThree(19683);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
