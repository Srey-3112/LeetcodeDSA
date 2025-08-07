class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None
        
class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}  # key -> Node

        # Dummy head and tail
        self.head, self.tail = Node(0, 0), Node(0, 0)
        self.head.next, self.tail.prev = self.tail, self.head

    def remove(self, node):
        """Unlink `node` from its current position."""
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev

    def insert(self, node):
        """
        Insert `node` right after head,
        marking it as the most-recently used.
        """
        nxt = self.head.next
        self.head.next = node
        node.prev = self.head
        node.next = nxt
        nxt.prev = node

    def get(self, key: int) -> int:
        node = self.cache.get(key, None)
        if not node:
            return -1
        # Move to front (most-recent)
        self.remove(node)
        self.insert(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        # If updating, remove old node
        if key in self.cache:
            self.remove(self.cache[key])

        # Insert new node at front
        new_node = Node(key, value)
        self.cache[key] = new_node
        self.insert(new_node)

        # Evict least-recent if over capacity
        if len(self.cache) > self.cap:
            lru = self.tail.prev  # node before tail is the least-recent
            self.remove(lru)
            del self.cache[lru.key]
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)