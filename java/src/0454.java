import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.HashMap;

class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        var count = 0;
        var counter = new HashMap<Integer, Integer>();
        for (var x : nums1)
            for (var y : nums2)
                counter.put(x + y, counter.getOrDefault(x + y, 0) + 1);
        for (var x : nums3)
            for (var y : nums3)
                count += counter.getOrDefault(-x - y, 0);
        return count;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.fourSumCount(new int[] { 1, 2 }, new int[] { -2, -1 }, new int[] { -1, 2 }, new int[] { 0, 2 }))
                .isEqualTo(2);
        assertThat(o.fourSumCount(new int[] { 0 }, new int[] { 0 }, new int[] { 0 }, new int[] { 0 })).isEqualTo(1);
        assertThat(o.fourSumCount(
                new int[] { 268435456, 268435456, 268435456, 268435456 },
                new int[] { 268435456, 268435456, 268435456, 268435456 },
                new int[] { 268435456, 268435456, 268435456, 268435456 },
                new int[] { 268435456, 268435456, 268435456, 268435456 })).isEqualTo(0);

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.fourSumCount(new int[] { 1, 2 }, new int[] { -2, -1 }, new int[] { -1, 2 }, new int[] { 0, 2 });
            o.fourSumCount(new int[] { 0 }, new int[] { 0 }, new int[] { 0 }, new int[] { 0 });
            o.fourSumCount(new int[] { 268435456, 268435456, 268435456, 268435456 },
                    new int[] { 268435456, 268435456, 268435456, 268435456 },
                    new int[] { 268435456, 268435456, 268435456, 268435456 },
                    new int[] { 268435456, 268435456, 268435456, 268435456 });
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
