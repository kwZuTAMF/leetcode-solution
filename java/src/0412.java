import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fizzBuzz(int n) {
        var ans = new ArrayList<String>(n);
        for (var i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                ans.add(i % 5 == 0 ? "FizzBuzz" : "Fizz");
            } else {
                ans.add(i % 5 == 0 ? "Buzz" : Integer.toString(i));
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.fizzBuzz(3)).isEqualTo(List.of("1", "2", "Fizz"));
        assertThat(o.fizzBuzz(5)).isEqualTo(List.of("1", "2", "Fizz", "4", "Buzz"));
        assertThat(o.fizzBuzz(15)).isEqualTo(List.of("1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"));

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.fizzBuzz(3);
            o.fizzBuzz(5);
            o.fizzBuzz(15);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
