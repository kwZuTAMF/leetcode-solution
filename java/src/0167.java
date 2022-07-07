import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        var i = 0;
        var j = numbers.length - 1;
        while (i < j) {
            var s = numbers[i] + numbers[j];
            if (s < target) {
                i++;
            } else if (s > target) {
                j--;
            } else {
                return new int[] { i + 1, j + 1 };
            }
        }
        throw new IllegalArgumentException("Solution either does not exist or is not unique");
    }

    // public int[] twoSum(int[] numbers, int target) {
    //     var n = numbers.length;
    //     for (var i = 0; i < n; i++) {
    //         var p = i + 1;
    //         var q = n - 1;
    //         while (p <= q) {
    //             var m = (p + q) >>> 1;
    //             if (numbers[m] < target - numbers[i]) {
    //                 p++;
    //             } else if (numbers[m] > target - numbers[i]) {
    //                 q--;
    //             } else {
    //                 return new int[] { i + 1, m + 1 };
    //             }
    //         }
    //     }
    //     throw new IllegalArgumentException("Solution either does not exist or is not unique");
    // }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.twoSum(new int[] { 2, 7, 11, 15 }, 9)).isEqualTo(new int[] { 1, 2 });
        assertThat(o.twoSum(new int[] { 2, 3, 4 }, 6)).isEqualTo(new int[] { 1, 3 });
        assertThat(o.twoSum(new int[] { -1, 0 }, -1)).isEqualTo(new int[] { 1, 2 });

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.twoSum(new int[] { 2, 7, 11, 15 }, 9);
            o.twoSum(new int[] { 2, 3, 4 }, 6);
            o.twoSum(new int[] { -1, 0 }, -1);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
