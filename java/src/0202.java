import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public boolean isHappy(int n) {
        while (true) {
            switch (n) {
                case 1:
                    return true;
                case 4, 16, 20, 37, 42, 58, 89, 145:
                    return false;
                default: {
                    int s = 0;
                    while (n != 0) {
                        int m = n % 10;
                        n /= 10;
                        s += m * m;
                    }
                    n = s;
                    break;
                }
            }
        }
    }

    // private int next(int n) {
    //     int s = 0;
    //     while (n != 0) {
    //         int m = n % 10;
    //         n /= 10;
    //         s += m * m;
    //     }
    //     return s;
    // }

    // public boolean isHappy(int n) {
    //     int fast = n, slow = n;
    //     while (true) {
    //         slow = next(slow);
    //         fast = next(fast);
    //         fast = next(fast);
    //         if (fast == 1) {
    //             return true;
    //         }
    //         if (slow == fast) {
    //             return slow == 1;
    //         }
    //     }
    // }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.isHappy(19)).isTrue();
        assertThat(o.isHappy(2)).isFalse();

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.isHappy(19);
            o.isHappy(2);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
