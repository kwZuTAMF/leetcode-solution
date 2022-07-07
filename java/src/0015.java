import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        var n = nums.length;
        var ans = new ArrayList<List<Integer>>();
        if (n < 3) {
            return ans;
        }
        Arrays.sort(nums);
        if (nums[0] > 0 || nums[n - 1] < 0) {
            return ans;
        }
        for (var i = 0; i < n - 2 && nums[i] <= 0; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                var p = i + 1;
                var q = n - 1;
                while (p < q) {
                    var s = nums[i] + nums[p] + nums[q];
                    if (s < 0) {
                        p++;
                    } else if (s > 0) {
                        q--;
                    } else {
                        ans.add(List.of(nums[i], nums[p], nums[q]));
                        do {
                            p++;
                        } while (p < q && nums[p] == nums[p - 1]);
                        do {
                            q--;
                        } while (p < q && nums[q] == nums[q + 1]);
                    }
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.threeSum(new int[] { -1, 0, 1, 2, -1, -4 }))
                .isEqualTo(List.of(List.of(-1, -1, 2), List.of(-1, 0, 1)));
        assertThat(o.threeSum(new int[] {})).isEqualTo(List.of());
        assertThat(o.threeSum(new int[] { 0 })).isEqualTo(List.of());

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.threeSum(new int[] { -1, 0, 1, 2, -1, -4 });
            o.threeSum(new int[] {});
            o.threeSum(new int[] { 0 });
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
