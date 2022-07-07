import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        var n = nums.length;
        var x = Integer.MIN_VALUE;
        var j = 0;
        var res = new int[n - k + 1];
        for (var i = 0; i < k; i++) {
            x = Math.max(x, nums[i]);
        }
        res[j++] = x;
        for (var i = k; i < n; i++) {
            res[j++] = (x = Math.max(x, nums[i]));
        }
        return res;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.maxSlidingWindow(new int[] { 1, 3, -1, -3, 5, 3, 6, 7 }, 3))
                .isEqualTo(new int[] { 3, 3, 5, 5, 6, 7 });
        assertThat(o.maxSlidingWindow(new int[] { 1 }, 1)).isEqualTo(new int[] { 1 });

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.maxSlidingWindow(new int[] { 1, 3, -1, -3, 5, 3, 6, 7 }, 3);
            o.maxSlidingWindow(new int[] { 1 }, 1);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
