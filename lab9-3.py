class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def hasCycle(self, head):
        # Хэрэв холбоост жагсаалт хоосон буюу нэг элементтэй бол мөчлөг байхгүй гэж үзнэ.
        if not head or not head.next:
            return False
        
        # Зөрчигч болон яаралтай заагчийг эхэнд байрлуулна.
        slow = head
        fast = head
        
        # Яаралтай заагч нь хоёр алхмаар, зөрчигч заагч нь нэг алхмаар урагшилна.
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            # Хэрэв хоёр заагч уулзвал мөчлөг байгаа гэж үзээд true утга буцаана.
            if slow == fast:
                return True
        
        # Хэрэв мөчлөг олдоогүй бол false утга буцаана.
        return False