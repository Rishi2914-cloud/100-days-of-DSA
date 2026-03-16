class Solution {
  public:
    // Function to remove a loop in the linked list.
    bool removeLoop(struct Node* head) {

        struct Node *slow = head, *fast = head;

        // Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // If no loop
        if (slow != fast)
            return false;

        // Move slow to head
        slow = head;

        // If loop starts at head
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        }
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Remove loop
        fast->next = NULL;

        return true;
    }
};