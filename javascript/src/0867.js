/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
function transpose(matrix) {
  return matrix[0].map((_, i) => matrix.map(m => m[i]))
}

{
  const { deepStrictEqual } = require('assert')

  const CASES = [
    [[[1, 2, 3], [4, 5, 6], [7, 8, 9]], [[1, 4, 7], [2, 5, 8], [3, 6, 9]]],
    [[[1, 2, 3], [4, 5, 6]], [[1, 4], [2, 5], [3, 6]]],
  ]

  for (let [matrix, excepted] of CASES) {
    const actual = transpose(matrix)
    deepStrictEqual(actual, excepted)
  }

  console.time()
  for (const [matrix, _] of CASES) {
    for (let i = 0; i < 100; i++) {
      transpose(matrix)
    }
  }
  console.timeEnd()
}
