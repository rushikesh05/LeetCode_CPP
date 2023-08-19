// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

 

// Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
// Example 2:


// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
// Example 3:


// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.
 

// Constraints:

// The number of the nodes in the list is in the range [0, 104].
// -105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.


#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false; // No cycle if there are 0 or 1 nodes.
        }
        
        ListNode* tortoise = head;
        ListNode* hare = head;
        
        while (hare != nullptr && hare->next != nullptr) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            
            if (tortoise == hare) {
                return true; // Cycle detected.
            }
        }
        
        return false; // No cycle found.
    }
};

// Explanation:

// The hasCycle function takes a pointer to the head of a linked list and returns true if there is a cycle in the linked list, and false otherwise.
// We start by checking if the linked list is empty or has only one node. If either condition is true, there can be no cycle.
// We initialize two pointers, tortoise and hare, both pointing to the head of the linked list.
// We use a while loop to move the tortoise pointer one step at a time and the hare pointer two steps at a time.
// If there is a cycle, the hare pointer will eventually catch up to the tortoise pointer. At this point, we return true.
// If the hare pointer reaches the end of the linked list (i.e., becomes nullptr), there is no cycle, and we return false.