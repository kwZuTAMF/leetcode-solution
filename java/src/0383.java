import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        int[] freq = new int[26];
        for (int i = 0, n = magazine.length(); i < n; i++) {
            freq[magazine.charAt(i) - 'a']++;
        }
        for (int i = 0, n = ransomNote.length(); i < n; i++) {
            if (--freq[ransomNote.charAt(i) - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.canConstruct("a", "b")).isFalse();
        assertThat(o.canConstruct("aa", "ab")).isFalse();
        assertThat(o.canConstruct("aa", "aab")).isTrue();

        var start = Instant.now();
        for (var i = 0; i < 1000; i++) {
            o.canConstruct("a", "b");
            o.canConstruct("aa", "ab");
            o.canConstruct("aa", "aab");
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
