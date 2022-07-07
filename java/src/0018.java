import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        var n = nums.length;
        var ans = new ArrayList<List<Integer>>();
        if (n < 4) {
            return ans;
        }
        Arrays.sort(nums);
        for (var i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (0L + nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) {
                continue;
            }
            if (0L + nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            for (var j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (0L + nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) {
                    continue;
                }
                if (0L + nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                var p = j + 1;
                var q = n - 1;
                while (p < q) {
                    var s = 0L + nums[i] + nums[j] + nums[p] + nums[q];
                    if (s < target) {
                        do {
                            p++;
                        } while (p < q && nums[p] == nums[p - 1]);
                    } else if (s > target) {
                        do {
                            q--;
                        } while (p < q && nums[q] == nums[q + 1]);
                    } else {
                        ans.add(List.of(nums[i], nums[j], nums[p], nums[q]));
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

        assertThat(o.fourSum(new int[] { 1, 0, -1, 0, -2, 2 }, 0))
                .isEqualTo(List.of(List.of(-2, -1, 1, 2), List.of(-2, 0, 0, 2), List.of(-1, 0, 0, 1)));
        assertThat(o.fourSum(new int[] { 2, 2, 2, 2, 2 }, 8)).isEqualTo(List.of(List.of(2, 2, 2, 2)));
        assertThat(o.fourSum(new int[] { 0, 0, 0, 0 }, 0)).isEqualTo(List.of(List.of(0, 0, 0, 0)));
        assertThat(o.fourSum(new int[] { -1000000000, -1000000000, -1000000000, -1000000000 }, 0)).isEqualTo(List.of());
        assertThat(o.fourSum(new int[] { 1000000000, 1000000000, 1000000000, 1000000000 }, 0)).isEqualTo(List.of());
        assertThat(o.fourSum(new int[] { 0, 0, 0, 1000000000, 1000000000, 1000000000, 1000000000 }, 1000000000))
                .isEqualTo(List.of(List.of(0, 0, 0, 1000000000)));
        assertThat(o.fourSum(new int[] { 1, -2, -5, -4, -3, 3, 3, 5 }, -11)).isEqualTo(List.of(List.of(-5, -4, -3, 1)));

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.fourSum(new int[] { 1, 0, -1, 0, -2, 2 }, 0);
            o.fourSum(new int[] { 2, 2, 2, 2, 2 }, 8);
            o.fourSum(new int[] { 0, 0, 0, 0 }, 0);
            o.fourSum(new int[] { -1000000000, -1000000000, -1000000000, -1000000000 }, 0);
            o.fourSum(new int[] { 1000000000, 1000000000, 1000000000, 1000000000 }, 0);
            o.fourSum(new int[] { 0, 0, 0, 1000000000, 1000000000, 1000000000, 1000000000 }, 1000000000);
            o.fourSum(new int[] { 1, -2, -5, -4, -3, 3, 3, 5 }, -11);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
