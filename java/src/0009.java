import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public boolean isPalindrome(int x) {
        if (x <= 9)
            return x >= 0;
        if (x % 10 == 0)
            return false;
        var p = 0;
        var q = x;
        while (q > p) {
            p = p * 10 + q % 10;
            q /= 10;
        }
        return p == q || p / 10 == q;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.isPalindrome(-1)).isFalse();
        assertThat(o.isPalindrome(-10)).isFalse();
        assertThat(o.isPalindrome(-11)).isFalse();
        assertThat(o.isPalindrome(-111)).isFalse();
        assertThat(o.isPalindrome(0)).isTrue();
        assertThat(o.isPalindrome(1)).isTrue();
        assertThat(o.isPalindrome(2)).isTrue();
        assertThat(o.isPalindrome(3)).isTrue();
        assertThat(o.isPalindrome(4)).isTrue();
        assertThat(o.isPalindrome(5)).isTrue();
        assertThat(o.isPalindrome(6)).isTrue();
        assertThat(o.isPalindrome(7)).isTrue();
        assertThat(o.isPalindrome(8)).isTrue();
        assertThat(o.isPalindrome(9)).isTrue();
        assertThat(o.isPalindrome(10)).isFalse();
        assertThat(o.isPalindrome(121)).isTrue();
        assertThat(o.isPalindrome(1001)).isTrue();
        assertThat(o.isPalindrome(10201)).isTrue();

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.isPalindrome(-1);
            o.isPalindrome(-10);
            o.isPalindrome(-11);
            o.isPalindrome(-111);
            o.isPalindrome(0);
            o.isPalindrome(1);
            o.isPalindrome(2);
            o.isPalindrome(3);
            o.isPalindrome(4);
            o.isPalindrome(5);
            o.isPalindrome(6);
            o.isPalindrome(7);
            o.isPalindrome(8);
            o.isPalindrome(9);
            o.isPalindrome(10);
            o.isPalindrome(121);
            o.isPalindrome(1001);
            o.isPalindrome(10201);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
