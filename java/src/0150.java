import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public int evalRPN(String[] tokens) {
        var stk = new int[(tokens.length + 1) >> 1];
        var top = -1;
        for (var token : tokens) {
            switch (token) {
                case "+" -> stk[--top] += stk[top + 1];
                case "-" -> stk[--top] -= stk[top + 1];
                case "*" -> stk[--top] *= stk[top + 1];
                case "/" -> stk[--top] /= stk[top + 1];
                default  -> stk[++top] = Integer.parseInt(token);
            }
        }
        return stk[top];
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.evalRPN(new String[] { "2", "1", "+", "3", "*" })).isEqualTo(9);
        assertThat(o.evalRPN(new String[] { "4", "13", "5", "/", "+" })).isEqualTo(6);
        assertThat(o.evalRPN(new String[] { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" }))
                .isEqualTo(22);

        var start = Instant.now();
        for (var i = 0; i < 100000; i++) {
            o.evalRPN(new String[] { "2", "1", "+", "3", "*" });
            o.evalRPN(new String[] { "4", "13", "5", "/", "+" });
            o.evalRPN(new String[] { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" });
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
