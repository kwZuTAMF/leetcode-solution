import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        var map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                return new int[] { map.get(target - nums[i]), i };
            } else {
                map.put(nums[i], i);
            }
        }
        throw new IllegalArgumentException("Solution either does not exist or is not unique");
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.twoSum(new int[] { 2, 7, 11, 15 }, 9)).isEqualTo(new int[] { 0, 1 });
        assertThat(o.twoSum(new int[] { 3, 2, 4 }, 6)).isEqualTo(new int[] { 1, 2 });
        assertThat(o.twoSum(new int[] { 3, 3 }, 6)).isEqualTo(new int[] { 0, 1 });

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.twoSum(new int[] { 2, 7, 11, 15 }, 9);
            o.twoSum(new int[] { 3, 2, 4 }, 6);
            o.twoSum(new int[] { 3, 3 }, 6);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
