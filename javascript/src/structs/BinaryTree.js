class TreeNode {
  constructor(val = 0, left = null, right = null) {
    this.val = val
    this.left = left
    this.right = right
  }

  toString() {
    return `<val: ${this.val}, left: ${this.left}, right: ${this.right}>`
  }
}

const of = (...items) => {
  if (!items.length) return
  let root = new TreeNode(items[0])
  let q = [root]
  for (let i = 1, n = items.length; i < n; i++) {
    let node = q.shift()
    if (items[i] != null) q.push((node.left = new TreeNode(items[i])))
    if (++i === n) break
    if (items[i] != null) q.push((node.right = new TreeNode(items[i])))
  }
  return root
}

const bfs = root => {
  let res = []
  let q = [root]
  while (q.length) {
    let { val, left, right } = q.shift()
    res.push(val)
    left && q.push(left)
    right && q.push(right)
  }
  return res
}

const preOrder = root => {
  let res = []
  let cur = root
  let stk = []
  while (cur || stk.length) {
    while (cur) {
      res.push(cur.val)
      stk.push(cur)
      cur = cur.left
    }
    cur = stk.pop().right
  }
  return res
}

const inOrder = root => {
  let res = []
  let cur = root
  let stk = []
  while (cur || stk.length) {
    while (cur) {
      stk.push(cur)
      cur = cur.left
    }
    cur = stk.pop()
    res.push(cur.val)
    cur = cur.right
  }
  return res
}

const postOrder = root => {
  let res = []
  let pre
  let cur = root
  let stk = []
  while (cur || stk.length) {
    while (cur) {
      stk.push(cur)
      cur = cur.left
    }
    cur = stk[stk.length - 1]
    if (cur.right && cur.right != pre) {
      cur = cur.right
    } else {
      stk.pop()
      res.push(cur.val)
      pre = cur
      cur = null
    }
  }
  return res
}

const morrisPreOrder = root => {
  let res = []
  let pre
  let cur = root
  while (cur) {
    if ((pre = cur.left)) {
      while (pre.right && pre.right != cur) {
        pre = pre.right
      }
      if (!pre.right) {
        res.push(cur.val)
        pre.right = cur
        cur = cur.left
      } else {
        pre.right = null
        cur = cur.right
      }
    } else {
      res.push(cur.val)
      cur = cur.right
    }
  }
  return res
}

const morrisInOrder = root => {
  let res = []
  let pre
  let cur = root
  while (cur) {
    if ((pre = cur.left)) {
      while (pre.right && pre.right != cur) {
        pre = pre.right
      }
      if (!pre.right) {
        pre.right = cur
        cur = cur.left
      } else {
        res.push(cur.val)
        pre.right = null
        cur = cur.right
      }
    } else {
      res.push(cur.val)
      cur = cur.right
    }
  }
  return res
}

const morrisPostOrder = root => {
  let res = []
  let pre
  let cur = root
  while (cur) {
    if ((pre = cur.right)) {
      while (pre.left && pre.left != cur) {
        pre = pre.left
      }
      if (!pre.left) {
        res.push(cur.val)
        pre.left = cur
        cur = cur.right
      } else {
        pre.right = null
        cur = cur.left
      }
    } else {
      res.push(cur.val)
      cur = cur.left
    }
  }
  return res.reverse()
}

module.exports = {
  TreeNode,
  of,
  bfs,
  preOrder,
  inOrder,
  postOrder,
  morrisPreOrder,
  morrisInOrder,
  morrisPostOrder,
}
