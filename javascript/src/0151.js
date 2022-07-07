/**
 * @param {string} s
 * @return {string}
 */
function reverseWords(s) {
  return s.trim().split(/\s+/g).reverse().join(' ')
}

/* function reverseWords(s) {
  s = [...s]
  let slow = 0
  let fast = 0
  let size = s.length
  reverse(s, 0, size - 1)
  for (; fast < size; fast++) {
    if (s[fast] != ' ') {
      if (slow > 0) s[slow++] = ' '
      let k = fast
      while (k < size && s[k] != ' ') s[slow++] = s[k++]
      reverse(s, slow - (k - fast), slow - 1)
      fast = k
    }
  }
  let res = ''
  for (let i = 0; i < slow; i++) res += s[i]
  return res
}

function reverse(xs, i, j) {
  while (i < j) swap(xs, i++, j--)
}

function swap(xs, i, j) {
  let t = xs[i]
  xs[i] = xs[j]
  xs[j] = t
} */

{
  const { strictEqual } = require('assert')

  const CASES = [
    ['the sky is blue', 'blue is sky the'],
    ['  hello world  ', 'world hello'],
    ['a good   example', 'example good a'],
  ]

  for (const [s, excepted] of CASES) {
    const actual = reverseWords(s)
    strictEqual(actual, excepted)
  }

  console.time()
  for (const [s, _] of CASES) {
    for (let i = 0; i < 100000; i++) {
      reverseWords(s)
    }
  }
  console.timeEnd()
}
