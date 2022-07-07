/**
 * @param {number} x
 * @return {number}
 */
function reverse(x) {
  let rev = 0
  while (x) {
    if (rev < -214748364 || rev > 214748364) return 0
    rev = rev * 10 + (x % 10)
    x = (x / 10) | 0
  }
  return rev
}

{
  const { strictEqual } = require('assert')

  const CASES = [
    [123, 321],
    [-123, -321],
    [120, 21],
  ]

  for (const [x, excepted] of CASES) {
    const actual = reverse(x)
    strictEqual(actual, excepted)
  }

  console.time()
  for (const [x, _] of CASES) {
    for (let i = 0; i < 100000; i++) {
      reverse(x)
    }
  }
  console.timeEnd()
}
