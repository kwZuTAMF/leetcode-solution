/**
 * @param {number} n
 * @return {number}
 */
function countPrimes(n) {
  if (n < 3) return 0
  let count = n >> 1
  let sieve = new Uint8Array(n)
  for (let i = 3; i * i < n; i += 2) {
    if (!sieve[i]) {
      for (let j = i * i; j < n; j += i << 1) {
        if (!sieve[j]) {
          sieve[j] = 1
          count--
        }
      }
    }
  }
  return count
}

{
  const { strictEqual } = require('assert')

  const CASES = [
    [0, 0],
    [1, 0],
    [2, 0],
    [3, 1],
    [4, 2],
    [5, 2],
    [6, 3],
    [7, 3],
    [8, 4],
    [9, 4],
    [10, 4],
    [11, 4],
    [12, 5],
    [13, 5],
    [14, 6],
    [15, 6],
    [10000, 1229],
    [499979, 41537],
    [999983, 78497],
    [1500000, 114155],
  ]

  for (let [n, excepted] of CASES) {
    const actual = countPrimes(n)
    strictEqual(actual, excepted)
  }

  console.time()
  for (const [n, _] of CASES) {
    for (let i = 0; i < 100; i++) {
      countPrimes(n)
    }
  }
  console.timeEnd()
}
