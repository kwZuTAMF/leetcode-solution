import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    // you need treat n as an unsigned value
    // public int reverseBits(int n) {
    //     var rev = 0;
    //     for (var i = 0; i < 32 && n != 0; i++) {
    //         rev |= (n & 1) << (31 - i);
    //         n >>>= 1;
    //     }
    //     return rev;
    // }

    public int reverseBits(int n) {
        n = (n & 0x55555555) << 1 | (n >>> 1) & 0x55555555;
        n = (n & 0x33333333) << 2 | (n >>> 2) & 0x33333333;
        n = (n & 0x0f0f0f0f) << 4 | (n >>> 4) & 0x0f0f0f0f;
        return (n << 24) | ((n & 0xff00) << 8) | ((n >>> 8) & 0xff00) | (n >>> 24);
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.reverseBits(0b00000010100101000001111010011100)).isEqualTo(0b00111001011110000010100101000000);
        assertThat(o.reverseBits(0b11111111111111111111111111111101)).isEqualTo(0b10111111111111111111111111111111);

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.reverseBits(0b00000010100101000001111010011100);
            o.reverseBits(0b11111111111111111111111111111101);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
