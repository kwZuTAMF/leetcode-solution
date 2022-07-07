import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public void rotate(int[] nums, int k) {
        var n = nums.length;
        if ((k %= n) > 0) {
            reverse(nums, 0, n - 1);
            reverse(nums, 0, k - 1);
            reverse(nums, k, n - 1);
        }
    }

    private void reverse(int[] nums, int i, int j) {
        for (int x; i < j; i++, j--) {
            x = nums[i];
            nums[i] = nums[j];
            nums[j] = x;
        }
    }

    public static void main(String[] args) {
        var o = new Solution();

        {
            var nums = new int[] { 1, 2, 3, 4, 5, 6, 7 };
            var k = 3;
            o.rotate(nums, k);
            assertThat(nums).isEqualTo(new int[] { 5, 6, 7, 1, 2, 3, 4 });
        }
        {
            var nums = new int[] { -1, -100, 3, 99 };
            var k = 2;
            o.rotate(nums, k);
            assertThat(nums).isEqualTo(new int[] { 3, 99, -1, -100 });
        }

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.rotate(new int[] { 1, 2, 3, 4, 5, 6, 7 }, 3);
            o.rotate(new int[] { -1, -100, 3, 99 }, 2);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
