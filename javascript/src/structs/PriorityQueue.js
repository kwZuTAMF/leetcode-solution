const siftUp = (k, x, es, cmp) => {
  while (k > 0) {
    let parent = (k - 1) >>> 1
    let e = es[parent]
    if (cmp(x, e) >= 0) break
    es[k] = e
    k = parent
  }
  es[k] = x
}

const siftDown = (k, x, es, n, cmp) => {
  let half = n >>> 1
  while (k < half) {
    let child = (k << 1) + 1
    let c = es[child]
    let right = child + 1
    if (right < n && cmp(c, es[right]) > 0) c = es[(child = right)]
    if (cmp(x, c) <= 0) break
    es[k] = c
    k = child
  }
  es[k] = x
}

const heapify = (es, cmp) => {
  let n = es.length
  let i = n >>> 1
  while (--i >= 0) siftDown(i, es[i], es, n, cmp)
}

class PriorityQueue {
  constructor(items, comparator) {
    this.queue = []
    this.comparator = typeof comparator === 'function' ? comparator : (a, b) => (a < b ? -1 : a > b ? 1 : 0)
    Array.isArray(items) && items.forEach(x => this.enqueue(x))
  }

  size() {
    return this.queue.length
  }

  isEmpty() {
    return this.queue.length === 0
  }

  peek() {
    return this.queue[0]
  }

  enqueue(e) {
    if (e == null) throw Error('PriorityQueue#enqueue: parameter is null or undefined')
    siftUp(this.queue.length, e, this.queue, this.comparator)
    return true
  }

  dequeue() {
    let es = this.queue
    let n = es.length - 1
    let result = es[0]
    if (result != null) {
      if (n > 0) siftDown(0, es[n], es, n, this.comparator)
      es.pop()
    }
    return result
  }

  toString() {
    return `[${this.queue.join(', ')}]`
  }
}

export { PriorityQueue }
