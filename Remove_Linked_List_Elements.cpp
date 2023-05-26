class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;

        head->next = removeElements(head->next, val);

        if(head->val == val)
            return head->next;
        else
            return head;
    }
};