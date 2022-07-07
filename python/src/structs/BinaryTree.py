from collections import deque


class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self) -> str:
        return f'val: {self.val}, left: {self.left}, right: {self.right}'

    def __str__(self) -> str:
        return str(self.val)

    def bfs(self):
        res = []
        q = deque([self])
        while q:
            cur = q.popleft()
            res.append(cur.val)
            cur.left and q.append(cur.left)
            cur.right and q.append(cur.right)
        return res

    def pre_order(self):
        res = []
        cur = self
        stk = deque()
        while cur or stk:
            while cur:
                res.append(cur.val)
                stk.append(cur)
                cur = cur.left
            cur = stk.pop().right
        return res

    def in_order(self):
        res = []
        cur = self
        stk = deque()
        while cur or stk:
            while cur:
                stk.append(cur)
                cur = cur.left
            cur = stk.pop()
            res.append(cur.val)
            cur = cur.right
        return res

    def post_order(self):
        res = []
        pre = None
        cur = self
        stk = deque()
        while cur or stk:
            while cur:
                stk.append(cur)
                cur = cur.left
            cur = stk[-1]
            if cur.right and cur.right != pre:
                cur = cur.right
            else:
                stk.pop()
                res.append(cur.val)
                pre = cur
                cur = None
        return res

    def morris_pre_order(self):
        res = []
        cur = self
        while cur:
            if pre := cur.left:
                while pre.right and pre.right != cur:
                    pre = pre.right
                if not pre.right:
                    res.append(cur.val)
                    pre.right = cur
                    cur = cur.left
                else:
                    pre.right = None
                    cur = cur.right
            else:
                res.append(cur.val)
                cur = cur.right
        return res

    def morris_in_order(self):
        res = []
        cur = self
        while cur:
            if pre := cur.left:
                while pre.right and pre.right != cur:
                    pre = pre.right
                if not pre.right:
                    pre.right = cur
                    cur = cur.left
                else:
                    res.append(cur.val)
                    pre.right = None
                    cur = cur.right
            else:
                res.append(cur.val)
                cur = cur.right
        return res

    def morris_post_order(self):
        res = []
        cur = self
        while cur:
            if pre := cur.right:
                while pre.left and pre.left != cur:
                    pre = pre.left
                if not pre.left:
                    res.append(cur.val)
                    pre.left = cur
                    cur = cur.right
                else:
                    pre.left = None
                    cur = cur.left
            else:
                res.append(cur.val)
                cur = cur.left
        return res[::-1]


class Node:

    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

    def __repr__(self) -> str:
        return f'val: {self.val}, left: {self.left}, right: {self.right}, next: {self.next}'

    def __str__(self) -> str:
        return str(self.val)

    def bfs(self):
        res = []
        q = deque([self])
        while q:
            cur = q.popleft()
            res.append(cur.val)
            cur.left and q.append(cur.left)
            cur.right and q.append(cur.right)
        return res

    def get_values_by_next(self):
        res = []
        q = deque([self])
        while q:
            cur = q.popleft()
            if cur.left:
                q.append(cur.left)
            elif cur.right:
                q.append(cur.right)
            res.append([])
            while cur:
                res[-1].append(cur.val)
                cur = cur.next
        return res


def create(cls, *items) -> TreeNode | Node:
    match items:
        case []:
            return
        case [item]:
            return cls(item)
        case [head, *tail]:
            root = cls(head)
            q = deque([root])
            it = iter(tail)
            while True:
                node = q.popleft()
                try:
                    if (item := next(it)) is not None:
                        node.left = cls(item)
                        q.append(node.left)
                    if (item := next(it)) is not None:
                        node.right = cls(item)
                        q.append(node.right)
                except StopIteration:
                    break
            return root
