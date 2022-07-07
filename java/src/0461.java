import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    private static final int[] TABLE = new int[] {
            0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
    };

    public int hammingDistance(int x, int y) {
        int n = x ^ y;
        return (TABLE[(n >> 0x00) & 0xff] +
                TABLE[(n >> 0x08) & 0xff] +
                TABLE[(n >> 0x10) & 0xff] +
                TABLE[(n >> 0x18) & 0xff]);
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.hammingDistance(1, 4)).isEqualTo(2);
        assertThat(o.hammingDistance(3, 1)).isEqualTo(1);
        assertThat(o.hammingDistance(1, 255)).isEqualTo(7);
        assertThat(o.hammingDistance(1, 65535)).isEqualTo(15);
        assertThat(o.hammingDistance(255, 65535)).isEqualTo(8);
        assertThat(o.hammingDistance(1, 16777215)).isEqualTo(23);
        assertThat(o.hammingDistance(65535, 16777215)).isEqualTo(8);
        assertThat(o.hammingDistance(1, 2147483647)).isEqualTo(30);
        assertThat(o.hammingDistance(16777215, 2147483647)).isEqualTo(7);

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.hammingDistance(1, 4);
            o.hammingDistance(3, 1);
            o.hammingDistance(1, 255);
            o.hammingDistance(1, 65535);
            o.hammingDistance(255, 65535);
            o.hammingDistance(1, 16777215);
            o.hammingDistance(65535, 16777215);
            o.hammingDistance(1, 2147483647);
            o.hammingDistance(16777215, 2147483647);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
