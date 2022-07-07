import static org.assertj.core.api.Assertions.assertThat;

import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;

class Solution {
    public int openLock(String[] deadends, String target) {
        if ("0000".equals(target))
            return 0;
        var seen = new HashSet<String>();
        Collections.addAll(seen, deadends);
        if (seen.contains("0000"))
            return -1;
        seen.add("0000");
        var q = new LinkedList<String>();
        q.offer("0000");
        var step = 0;
        do {
            var size = q.size();
            for (var i = 0; i < size; i++) {
                var node = q.poll();
                if (node.equals(target))
                    return step;
                for (var child : children(node)) {
                    if (!seen.contains(child)) {
                        seen.add(child);
                        q.offer(child);
                    }
                }
            }
            step++;
        } while (!q.isEmpty());
        return -1;
    }

    private String[] children(String node) {
        var result = new String[8];
        var wheels = node.toCharArray();
        for (var i = 0; i < 4; i++) {
            var x = wheels[i];
            wheels[i] = x == '0' ? '9' : (char) (x - 1);
            result[i * 2] = new String(wheels);
            wheels[i] = x == '9' ? '0' : (char) (x + 1);
            result[i * 2 + 1] = new String(wheels);
            wheels[i] = x;
        }
        return result;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.openLock(new String[] { "0201", "0101", "0102", "1212", "2002" }, "0202")).isEqualTo(6);
        assertThat(o.openLock(new String[] { "8888" }, "0009")).isEqualTo(1);
        assertThat(o.openLock(new String[] { "8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888" }, "8888"))
                .isEqualTo(-1);
        assertThat(o.openLock(new String[] { "8888" }, "0000")).isEqualTo(0);
        assertThat(o.openLock(new String[] { "0000" }, "8888")).isEqualTo(-1);
        assertThat(o.openLock(new String[] { "9000" }, "8888")).isEqualTo(8);

        var start = Instant.now();
        for (var i = 0; i < 100; i++) {
            o.openLock(new String[] { "0201", "0101", "0102", "1212", "2002" }, "0202");
            o.openLock(new String[] { "8888" }, "0009");
            o.openLock(new String[] { "8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888" }, "8888");
            o.openLock(new String[] { "8888" }, "0000");
            o.openLock(new String[] { "0000" }, "8888");
            o.openLock(new String[] { "9000" }, "8888");
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
