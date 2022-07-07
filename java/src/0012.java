import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

class Solution {
    public String intToRoman(int num) {
        return (switch (num / 1000) {
            case 1 -> "M";
            case 2 -> "MM";
            case 3 -> "MMM";
            default -> "";
        } + switch (num % 1000 / 100) {
            case 1 -> "C";
            case 2 -> "CC";
            case 3 -> "CCC";
            case 4 -> "CD";
            case 5 -> "D";
            case 6 -> "DC";
            case 7 -> "DCC";
            case 8 -> "DCCC";
            case 9 -> "CM";
            default -> "";
        } + switch (num % 100 / 10) {
            case 1 -> "X";
            case 2 -> "XX";
            case 3 -> "XXX";
            case 4 -> "XL";
            case 5 -> "L";
            case 6 -> "LX";
            case 7 -> "LXX";
            case 8 -> "LXXX";
            case 9 -> "XC";
            default -> "";
        } + switch (num % 10) {
            case 1 -> "I";
            case 2 -> "II";
            case 3 -> "III";
            case 4 -> "IV";
            case 5 -> "V";
            case 6 -> "VI";
            case 7 -> "VII";
            case 8 -> "VIII";
            case 9 -> "IX";
            default -> "";
        });
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.intToRoman(3)).isEqualTo("III");
        assertThat(o.intToRoman(58)).isEqualTo(("LVIII"));
        assertThat(o.intToRoman(1994)).isEqualTo(("MCMXCIV"));

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.intToRoman(3);
            o.intToRoman(58);
            o.intToRoman(1994);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
