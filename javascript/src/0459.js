/**
 * @param {string} s
 * @return {boolean}
 */
function repeatedSubstringPattern(s) {
  return (s + s).slice(1, -1).includes(s)
}

// function repeatedSubstringPattern(s) {
//   let n = s.length
//   let next = new Int32Array(n)
//   for (let i = 1, j = 0; i < n; i++) {
//     while (j > 0 && s[i] !== s[j]) j = next[j - 1]
//     if (s[i] === s[j]) j++
//     next[i] = j
//   }
//   return next[n - 1] !== 0 && n % (n - next[n - 1]) === 0
// }

{
  const { strictEqual } = require('assert')

  const CASE = [
    ['abab', true],
    ['aba', false],
    ['abcabcabcabc', true],
  ]

  for (const [s, excepted] of CASE) {
    const actual = repeatedSubstringPattern(s)
    strictEqual(actual, excepted)
  }

  console.time()
  for (const [s, _] of CASE) {
    for (let i = 0; i < 100000; i++) {
      repeatedSubstringPattern(s)
    }
  }
  console.timeEnd()
}
