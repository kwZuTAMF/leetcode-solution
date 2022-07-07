import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {

    public int romanToInt(String s) {
        var n = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            n += switch (s.charAt(i)) {
                case 'I' -> n < 5 ? 1 : -1;
                case 'V' -> 5;
                case 'X' -> n < 50 ? 10 : -10;
                case 'L' -> 50;
                case 'C' -> n < 500 ? 100 : -100;
                case 'D' -> 500;
                default -> 1000;
            };
        }
        return n;
    }

    public static void main(String[] args) {
        record Case(String s, int excepted) {
        }

        var CASES = new Case[] {
                new Case("III", 3),
                new Case("LVIII", 58),
                new Case("MCMXCIV", 1994),
        };

        var o = new Solution();

        for (var x : CASES) {
            assertThat(o.romanToInt(x.s)).isEqualTo(x.excepted);
        }

        var start = Instant.now();
        for (var x : CASES) {
            for (var i = 0; i < 1000000; i++) {
                o.romanToInt(x.s);
            }
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
