import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public int missingNumber(int[] nums) {
        var n = nums.length;
        var x = switch (n % 4) {
            case 0 -> n;
            case 1 -> 1;
            case 2 -> n + 1;
            default -> 0;
        };
        for (var i = 0; i < n; i++)
            x ^= nums[i];
        return x;
    }

    // public int missingNumber(int[] nums) {
    //     var n = nums.length;
    //     var s = 0;
    //     for (var i = 0; i < n; i++)
    //         s += nums[i];
    //     return (n * (n + 1) >> 1) - s;
    // }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.missingNumber(new int[] { 3, 0, 1 })).isEqualTo(2);
        assertThat(o.missingNumber(new int[] { 0, 1 })).isEqualTo(2);
        assertThat(o.missingNumber(new int[] { 9, 6, 4, 2, 3, 5, 7, 0, 1 })).isEqualTo(8);

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.missingNumber(new int[] { 3, 0, 1 });
            o.missingNumber(new int[] { 0, 1 });
            o.missingNumber(new int[] { 9, 6, 4, 2, 3, 5, 7, 0, 1 });
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
