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

    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        return (TABLE[(n >> 0x00) & 0xff] +
                TABLE[(n >> 0x08) & 0xff] +
                TABLE[(n >> 0x10) & 0xff] +
                TABLE[(n >> 0x18) & 0xff]);
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.hammingWeight(0b11111111111111111111111111111101)).isEqualTo(31);
        assertThat(o.hammingWeight(0b00000000000000000000000000001011)).isEqualTo(3);
        assertThat(o.hammingWeight(0b00000000000000000000000010000000)).isEqualTo(1);
        assertThat(o.hammingWeight(0b11111111111111111111111111111101)).isEqualTo(31);
        assertThat(o.hammingWeight(0b00000000000000000000000000000000)).isEqualTo(0);
        assertThat(o.hammingWeight(0b00000000000000000000000000000001)).isEqualTo(1);
        assertThat(o.hammingWeight(0b00000000000000000000000000000011)).isEqualTo(2);
        assertThat(o.hammingWeight(0b00000000000000000000000000101010)).isEqualTo(3);
        assertThat(o.hammingWeight(0b00000000000000000000000001111111)).isEqualTo(7);
        assertThat(o.hammingWeight(0b00000000000000000000000011111111)).isEqualTo(8);
        assertThat(o.hammingWeight(0b00000000000000000111111111111111)).isEqualTo(15);
        assertThat(o.hammingWeight(0b00000000000000001111111111111111)).isEqualTo(16);
        assertThat(o.hammingWeight(0b01111111111111111111111111111111)).isEqualTo(31);
        assertThat(o.hammingWeight(0b11111111111111111111111111111111)).isEqualTo(32);

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.hammingWeight(0b11111111111111111111111111111101);
            o.hammingWeight(0b00000000000000000000000000001011);
            o.hammingWeight(0b00000000000000000000000010000000);
            o.hammingWeight(0b11111111111111111111111111111101);
            o.hammingWeight(0b00000000000000000000000000000000);
            o.hammingWeight(0b00000000000000000000000000000001);
            o.hammingWeight(0b00000000000000000000000000000011);
            o.hammingWeight(0b00000000000000000000000000101010);
            o.hammingWeight(0b00000000000000000000000001111111);
            o.hammingWeight(0b00000000000000000000000011111111);
            o.hammingWeight(0b00000000000000000111111111111111);
            o.hammingWeight(0b00000000000000001111111111111111);
            o.hammingWeight(0b01111111111111111111111111111111);
            o.hammingWeight(0b11111111111111111111111111111111);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
