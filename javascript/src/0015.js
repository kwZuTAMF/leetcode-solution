/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function threeSum(nums) {
  let n = nums.length
  if (n < 3) return []
  nums.sort((a, b) => a - b)
  if (nums[0] > 0 || nums[n - 1] < 0) return []
  let res = []
  for (let i = 0; i < n - 2 && nums[i] <= 0; i++) {
    if (i == 0 || nums[i] != nums[i - 1]) {
      let p = i + 1
      let q = n - 1
      while (p < q) {
        let s = nums[i] + nums[p] + nums[q]
        if (s < 0) {
          do {
            p++
          } while (p < q && nums[p] == nums[p - 1])
        } else if (s > 0) {
          do {
            q--
          } while (p < q && nums[q] == nums[q + 1])
        } else {
          res.push([nums[i], nums[p], nums[q]])
          do {
            p++
          } while (p < q && nums[p] == nums[p - 1])
          do {
            q--
          } while (p < q && nums[q] == nums[q + 1])
        }
      }
    }
  }
  return res
}

{
  const { deepStrictEqual } = require('assert')

  const CASES = [
    [[-1, 0, 1, 2, -1, -4], [[-1, -1, 2],[-1, 0, 1]]],
    [[], []],
    [[0], []],
  ]

  for (const [nums, excepted] of CASES) {
    const actual = threeSum(nums)
    deepStrictEqual(actual, excepted)
  }

  console.time()
  for (const [nums, _] of CASES) {
    for (let i = 0; i < 100000; i++) {
      threeSum(nums)
    }
  }
  console.timeEnd()
}
