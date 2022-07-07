/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
function largestSumAfterKNegations(nums, k) {
  nums.sort((a, b) => Math.abs(a) - Math.abs(b))
  for (let i = nums.length - 1; i >= 0 && k; i--) {
    if (nums[i] < 0) {
      nums[i] *= -1
      k--
    }
  }
  if (k & 1) {
    nums[0] *= -1
  }
  return nums.reduce((a, b) => a + b)
}

{
  const { strictEqual } = require('assert')

  const CASES = [
    [[4, 2, 3], 1, 5],
    [[3, -1, 0, 2], 3, 6],
    [[2, -3, -1, 5, -4], 2, 13],
  ]

  for (const [nums, k, excepted] of CASES) {
    const actual = largestSumAfterKNegations(nums, k)
    strictEqual(actual, excepted)
  }

  console.time()
  for (const [nums, k, _] of CASES) {
    for (let i = 0; i < 100000; i++) {
      largestSumAfterKNegations(nums, k)
    }
  }
  console.timeEnd()
}
