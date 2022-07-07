class Node {
  constructor(val = null, left = null, right = null, next = null) {
    this.val = val
    this.left = left
    this.right = right
    this.next = next
  }

  toString() {
    return `val: ${this.val}, left: ${this.left}, right: ${this.right}, next: ${this.next}`
  }
}

const of = (...items) => {
  if (!items.length) return
  let root = new Node(items[0])
  let q = [root]
  for (let i = 1, n = items.length; i < n; i++) {
    let node = q.shift()
    if (items[i] != null) q.push((node.left = new Node(items[i])))
    if (++i === n) break
    if (items[i] != null) q.push((node.right = new Node(items[i])))
  }
  return root
}

const bfsByNext = root => {
  let res = []
  let q = [root]
  while (q.length) {
    let node = q.shift()
    if (node.left) {
      q.push(node.left)
    } else if (node.right) {
      q.push(node.right)
    }
    res.push([])
    while (node) {
      res[res.length - 1].push(node.val)
      node = node.next
    }
  }
  return res
}

module.exports = {
  Node,
  of,
  bfsByNext,
}
