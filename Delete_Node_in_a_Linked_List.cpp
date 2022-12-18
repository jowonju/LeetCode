/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        //1
        for(ListNode* nodePtr = node; nodePtr != nullptr; nodePtr  = nodePtr->next)
        {
            nodePtr->val = nodePtr->next->val;
            
            if(nodePtr->next->next == nullptr)
            {
                nodePtr->next = nullptr;
                break;
            }
        }
        
        //2
        *node = *node->next;        
        
    }
    
};