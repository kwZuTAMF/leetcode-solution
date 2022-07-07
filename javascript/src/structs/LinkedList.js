class ListNode {
  constructor(val) {
    this.val = val
    this.next = null
  }

  toString() {
    return this.next ? `${this.val}->${this.next}` : `${this.val}`
  }
}

const of = (...items) => {
  if (!items.length) return
  let fake = { next: null }
  let curr = fake
  items.forEach(item => (curr = curr.next = new ListNode(item)))
  return fake.next
}

const eq = (p, q) => {
  if (!p && !q) return true
  if (!p || !q || p.val != q.val) return false
  return eq(p.next, q.next)
}

const cycle = (pos, ...items) => {
  if (!items.length) return
  let fake = { next: null }
  let curr = fake
  items.forEach(item => (curr = curr.next = new ListNode(item)))
  if (~pos) {
    let last = fake.next
    while (pos--) last = last.next
    let node = last
    while (last.next) last = last.next
    last.next = node
  }
  return fake.next
}

module.exports = {
  ListNode,
  of,
  eq,
  cycle,
}
