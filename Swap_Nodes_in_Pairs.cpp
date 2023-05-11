class Solution {
public:

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        if(head == nullptr || head->next == nullptr)
            return head;
        
        int val = head->val;
        head->val = head->next->val;
        head->next->val = val;
        swapPairs(head->next->next);
        
        return head;
    }
};