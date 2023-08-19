// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* current = head;
        
        // Calculate the length of the linked list
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        
        // Calculate the position of the node to remove from the beginning
        int removePos = length - n;
        
        // Handle the case where the head needs to be removed
        if (removePos == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        // Traverse the linked list again to remove the nth node from the end
        current = head;
        for (int i = 0; i < removePos - 1; i++) {
            current = current->next;
        }
        
        ListNode* toRemove = current->next;
        current->next = toRemove->next;
        delete toRemove;
        
        return head;
    }
};

