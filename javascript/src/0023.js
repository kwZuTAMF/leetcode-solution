const { ListNode, of, eq } = require('./structs/LinkedList')

/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
function mergeKLists(lists) {
  if (!lists) return
  let k = lists.length
  for (let step = 1; step < k; step <<= 1) {
    for (let i = 0; i + step < k; i += step << 1) {
      lists[i] = merge(lists[i], lists[i + step])
    }
  }
  return lists[0]
}

function merge(p, q) {
  let fake = { next: null }
  let curr = fake
  while (p && q) {
    if (p.val <= q.val) {
      curr.next = p
      p = p.next
    } else {
      curr.next = q
      q = q.next
    }
    curr = curr.next
  }
  curr.next = p ?? q
  return fake.next
}

{
  const { strictEqual } = require('assert')

  const CASES = [
    [[of(1, 4, 5), of(1, 3, 4), of(2, 6)], of(1, 1, 2, 3, 4, 4, 5, 6)],
    [null, null],
    [[null], null],
  ]

  for (const [lists, excepted] of CASES) {
    const actual = mergeKLists(lists)
    strictEqual(eq(actual, excepted), true)
  }

  console.time()
  for (let i = 0; i < 10000; i++) {
    mergeKLists([of(1, 4, 5), of(1, 3, 4), of(2, 6)])
    mergeKLists([])
    mergeKLists([null])
  }
  console.timeEnd()
}
