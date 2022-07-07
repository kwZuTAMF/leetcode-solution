/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
function strStr(haystack, needle) {
  let n = haystack.length
  let m = needle.length
  if (m === 0) return 0
  let next = new Int32Array(m)
  for (let i = 1, j = 0; i < m; i++) {
    while (j > 0 && needle[i] !== needle[j]) j = needle[j - 1]
    if (needle[i] === needle[j]) j++
    next[i] = j
  }
  for (let i = 0, j = 0; i < n; i++) {
    while (j > 0 && haystack[i] != needle[j]) j = needle[j - 1]
    if (haystack[i] === needle[j]) j++
    if (j === m) return i - m + 1
  }
  return -1
}

{
  const { strictEqual } = require('assert')

  const CASES = [
    ['hello', 'll', 2],
    ['aaaaa', 'bba', -1],
  ]

  for (const [haystack, needle, excepted] of CASES) {
    const actual = strStr(haystack, needle)
    strictEqual(actual, excepted)
  }

  console.time()
  for (const [haystack, needle, _] of CASES) {
    for (let i = 0; i < 100000; i++) {
      strStr(haystack, needle)
    }
  }
  console.timeEnd()
}
