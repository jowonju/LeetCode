class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int totalSize = 0;
        for(auto ptr = head; ptr!=nullptr; ptr = ptr->next)
        {
            totalSize++;
        }
        
        if(totalSize == 1)
        {
            return NULL;    
        }
        
        int indexFromBeginning = totalSize - n;
        
        ListNode* temp = NULL;
        
        if(indexFromBeginning == 0)
        {
            *head = *head->next;
            return head;
        }
        
        for(auto ptr = head; ptr != nullptr; ptr = ptr->next)
        {
            if(indexFromBeginning == 0)
            {
                temp->next = ptr->next;
                break;
            }
            temp = ptr;
            indexFromBeginning--;    
        }
        
       return head;
    }
};