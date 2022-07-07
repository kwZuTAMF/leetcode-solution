/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
function fourSum(nums, target) {
  let n = nums.length
  if (n < 4) return []
  nums.sort((a, b) => a - b)
  let res = []
  for (let i = 0; i < n - 3; ++i) {
    if (i > 0 && nums[i] == nums[i - 1]) continue
    if (nums[i] + nums[n - 1] < target - nums[n - 2] - nums[n - 3]) continue
    if (nums[i] + nums[i + 1] > target - nums[i + 2] - nums[i + 3]) break
    for (let j = i + 1; j < n - 2; ++j) {
      if (j > i + 1 && nums[j] == nums[j - 1]) continue
      if (nums[i] + nums[j] < target - nums[n - 1] - nums[n - 2]) continue
      if (nums[i] + nums[j] > target - nums[j + 1] - nums[j + 2]) break
      let p = j + 1
      let q = n - 1
      while (p < q) {
        if (nums[i] + nums[j] < target - nums[p] - nums[q]) {
          do {
            ++p
          } while (p < q && nums[p] == nums[p - 1])
        } else if (nums[i] + nums[j] > target - nums[p] - nums[q]) {
          do {
            --q
          } while (p < q && nums[q] == nums[q + 1])
        } else {
          res.push([nums[i], nums[j], nums[p], nums[q]])
          do {
            ++p
          } while (p < q && nums[p] == nums[p - 1])
          do {
            --q
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
    [[1, 0, -1, 0, -2, 2], 0, [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]],
    [[2, 2, 2, 2, 2], 8, [[2, 2, 2, 2]]],
  ]

  for (const [nums, target, excepted] of CASES) {
    const actual = fourSum(nums, target)
    deepStrictEqual(actual, excepted)
  }

  console.time()
  for (const [nums, target, _] of CASES) {
    for (let i = 0; i < 100000; i++) {
      fourSum(nums, target)
    }
  }
  console.timeEnd()
}
