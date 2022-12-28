class Solution {
public:
    bool isPalindrome(ListNode* head) {

        //using another data container. time complexity: O(n), space complexity: 
        stack<int> stk;
        
        for(auto ptr = head; ptr != nullptr; ptr = ptr->next)
        {
            stk.push(ptr->val);
        }
        
        int size = stk.size();
        
        for(int i = 0; i < size / 2; i++)
        {
            if(head->val != stk.top())
                return false;
            
            stk.pop();
            head = head->next;
        }
        return true;
        
        //Floyd's Cycle Detection Algorithm. space complexity:O(1) time complexity: O(N)
        ListNode* fast = head, *slow = head, *prev, *temp;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev = slow; slow=slow->next; prev->next = NULL;
        while(slow)
        {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        slow = prev; fast = head;
        while(slow)
        {
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};