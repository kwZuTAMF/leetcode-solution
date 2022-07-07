/**
 * @param {number} n
 * @return {number}
 */
function numSquares(n) {
  if (Number.isInteger(n ** 0.5)) return 1

  while (n % 4 == 0) n /= 4
  if (n % 8 == 7) return 4

  for (let i = 1; i * i <= n; i++)
    if (Number.isInteger((n - i * i) ** 0.5))
      return 2

  return 3
}

{
  const { strictEqual } = require('assert')

  const CASES = [
    [1, 1],
    [3, 3],
    [5, 2],
    [7, 4],
    [12, 3],
    [13, 2],
    [16, 1],
    [42, 3],
    [63, 4],
  ]

  for (const [n, excepted] of CASES) {
    const actual = numSquares(n)
    strictEqual(actual, excepted)
  }

  console.time()
  for (const [n, _] of CASES) {
    for (let i = 0; i < 100000; i++) {
      numSquares(n)
    }
  }
  console.timeEnd()
}
