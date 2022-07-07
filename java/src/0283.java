import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public void moveZeroes(int[] nums) {
        for (int i = 0, j = 0, n = nums.length; i < n; i++) {
            if (i != j && nums[i] != 0) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                j++;
            }
        }
    }

    public static void main(String[] args) {
        var o = new Solution();

        {
            var nums = new int[] { 0, 1, 0, 3, 12 };
            o.moveZeroes(nums);
            assertThat(nums).isEqualTo(new int[] { 1, 3, 12, 0, 0 });
        }
        {
            var nums = new int[] { 0 };
            o.moveZeroes(nums);
            assertThat(nums).isEqualTo(new int[] { 0 });
        }

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            {
                var nums = new int[] { 0, 1, 0, 3, 12 };
                o.moveZeroes(nums);
            }
            {
                var nums = new int[] { 0 };
                o.moveZeroes(nums);
            }
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
