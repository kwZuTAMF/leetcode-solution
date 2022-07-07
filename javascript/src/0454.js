/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number[]} nums3
 * @param {number[]} nums4
 * @return {number}
 */
function fourSumCount(nums1, nums2, nums3, nums4) {
  let n = 0
  let m = new Map
  nums1.forEach(x => nums2.forEach(y => m.set(x + y, (m.get(x + y) ?? 0) + 1)))
  nums3.forEach(x => nums4.forEach(y => (n += m.get(-x - y) ?? 0)))
  return n
}

{
  const { strictEqual } = require('assert')

  const CASES = [
    [[1, 2], [-2, -1], [-1, 2], [0, 2], 2],
    [[0], [0], [0], [0], 1],
  ]

  for (const [nums1, nums2, nums3, nums4, excepted] of CASES) {
    const actual = fourSumCount(nums1, nums2, nums3, nums4)
    strictEqual(actual, excepted)
  }

  console.time()
  for (const [nums1, nums2, nums3, nums4, _] of CASES) {
    for (let i = 0; i < 100000; i++) {
      fourSumCount(nums1, nums2, nums3, nums4)
    }
  }
  console.timeEnd()
}
