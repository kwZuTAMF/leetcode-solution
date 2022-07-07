const { ListNode, of, eq } = require('./structs/LinkedList')

/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
function mergeTwoLists(list1, list2) {
  let fake = { next: null }
  let curr = fake
  while (list1 && list2) {
    if (list1.val <= list2.val) {
      curr.next = list1
      list1 = list1.next
    } else {
      curr.next = list2
      list2 = list2.next
    }
    curr = curr.next
  }
  curr.next = list1 ?? list2
  return fake.next
}

{
  const { strictEqual } = require('assert')

  const CASES = [
    [of(1, 2, 4), of(1, 3, 4), of(1, 1, 2, 3, 4, 4)],
    [null, null, null],
    [null, of(0), of(0)],
  ]

  for (const [list1, list2, excepted] of CASES) {
    const actual = mergeTwoLists(list1, list2)
    strictEqual(eq(actual, excepted), true)
  }

  console.time()
  for (let i = 0; i < 10000; i++) {
    mergeTwoLists(of(1, 2, 4), of(1, 3, 4))
    mergeTwoLists(null, null)
    mergeTwoLists(null, of(0))
  }
  console.timeEnd()
}
