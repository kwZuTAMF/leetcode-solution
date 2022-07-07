import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public String reverseWords(String s) {
        var slow = 0;
        var size = s.length();
        var temp = s.toCharArray();
        reverse(temp, 0, size - 1);
        for (var fast = 0; fast < size; fast++) {
            if (temp[fast] != ' ') {
                if (slow > 0) {
                    temp[slow++] = ' ';
                }
                int k = fast;
                for (; k < size && temp[k] != ' ';) {
                    temp[slow++] = temp[k++];
                }
                reverse(temp, slow - (k - fast), slow - 1);
                fast = k;
            }
        }
        return new String(temp, 0, slow);
    }

    private void reverse(char[] s, int i, int j) {
        while (i < j) swap(s, i++, j--);
    }

    private void swap(char[] s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.reverseWords("the sky is blue")).isEqualTo("blue is sky the");
        assertThat(o.reverseWords("hello world  ")).isEqualTo("world hello");
        assertThat(o.reverseWords("a good   example")).isEqualTo("example good a");

        var start = Instant.now();
        for (var i = 0; i < 10000; i++) {
            o.reverseWords("the sky is blue");
            o.reverseWords("hello world  ");
            o.reverseWords("a good   example");
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
