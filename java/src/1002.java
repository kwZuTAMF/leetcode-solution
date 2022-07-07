import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> commonChars(String[] words) {
        int[] freq = new int[26];
        for (int i = 0, n = words[0].length(); i < n; i++) {
            freq[words[0].charAt(i) - 'a']++;
        }
        for (int i = 1, n = words.length; i < n; i++) {
            int[] temp = new int[26];
            for (int j = 0, m = words[i].length(); j < m; j++) {
                temp[words[i].charAt(j) - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                freq[k] = Math.min(freq[k], temp[k]);
            }
        }
        var chars = new ArrayList<String>();
        for (int i = 0; i < 26; i++) {
            while (freq[i]-- > 0) {
                chars.add(String.valueOf((char) (i + 'a')));
            }
        }
        return chars;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.commonChars(new String[] { "bella", "label", "roller" })).isEqualTo(List.of("e", "l", "l"));
        assertThat(o.commonChars(new String[] { "cool", "lock", "cook" })).isEqualTo(List.of("c", "o"));

        var start = Instant.now();
        for (var i = 0; i < 1000; i++) {
            o.commonChars(new String[] { "bella", "label", "roller" });
            o.commonChars(new String[] { "cool", "lock", "cook" });
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
