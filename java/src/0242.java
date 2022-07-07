import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] freq = new int[26];
        for (int i = 0, n = s.length(); i < n; i++) {
            freq[s.charAt(i) - 'a']++;
        }
        for (int i = 0, n = t.length(); i < n; i++) {
            if (--freq[t.charAt(i) - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.isAnagram("anagram", "nagaram")).isTrue();
        assertThat(o.isAnagram("rat", "car")).isFalse();

        var start = Instant.now();
        for (var i = 0; i < 1000; i++) {
            o.isAnagram("anagram", "nagaram");
            o.isAnagram("rat", "car");
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
