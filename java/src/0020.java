import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.LinkedList;

class Solution {
    public boolean isValid(String s) {
        var n = s.length();
        if (n % 2 != 0)
            return false;
        var stack = new LinkedList<Character>();
        for (var i = 0; i < n; i++) {
            var c = s.charAt(i);
            switch (c) {
                case '(' -> stack.push(')');
                case '[' -> stack.push(']');
                case '{' -> stack.push('}');
                default -> {
                    if (!stack.isEmpty() && stack.pop() != c)
                        return false;
                }
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.isValid("()")).isTrue();
        assertThat(o.isValid("()[]{}")).isTrue();
        assertThat(o.isValid("(]")).isFalse();
        assertThat(o.isValid("([)]")).isFalse();
        assertThat(o.isValid("{[]}")).isTrue();

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.isValid("()");
            o.isValid("()[]{}");
            o.isValid("(]");
            o.isValid("([)]");
            o.isValid("{[]}");
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
