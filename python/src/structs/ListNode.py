class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __eq__(self, __o: object) -> bool:
        return type(self) == type(__o) and repr(self) == repr(__o)

    def __repr__(self) -> str:
        return self.next and f'{self.val}->{self.next}' or f'{self.val}'


def create(*items):
    fake = ListNode()
    curr = fake
    for item in items:
        curr.next = ListNode(item)
        curr = curr.next
    return fake.next
