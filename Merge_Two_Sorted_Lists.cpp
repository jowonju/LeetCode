/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    //iterative
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode result;
        ListNode* tail = &result;
        
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                tail->next = list1;        
                list1 = list1->next;
            }
            else if(list1->val > list2->val) 
            {
                tail->next = list2;        
                list2 = list2->next;
                
            }
            tail = tail->next;
        }
        
        if(list1 !=nullptr)
            tail->next = list1;
        else
            tail->next = list2;
        
        return result.next;

        //recursively
                
        if(list1 == nullptr)
        {
            return list2;
        }
        if(list2 == nullptr)
        {
            return list1;
        }
            
        
        if(list1->val <= list2->val)
        {   
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        
    }
};