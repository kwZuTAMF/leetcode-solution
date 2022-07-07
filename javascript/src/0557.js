/**
 * @param {string} s
 * @return {string}
 */
function reverseWords (s) {
  return s.split(' ').map(x => [...x].reverse().join('')).join(' ')
}

{
  const { strictEqual } = require('assert')

  const CASE = [
    ["Let's take LeetCode contest", "s'teL ekat edoCteeL tsetnoc"],
    ['God Ding', 'doG gniD'],
  ]

  for (const [s, excepted] of CASE) {
    const actual = reverseWords(s)
    strictEqual(actual, excepted)
  }

  console.time()
  for (const [s, _] of CASE) {
    for (let i = 0; i < 100000; i++) {
      reverseWords(s)
    }
  }
  console.timeEnd()
}
