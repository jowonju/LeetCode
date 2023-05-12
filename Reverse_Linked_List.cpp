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
    ListNode* reverseList(ListNode* head) {
        
        //1
        if(head == nullptr)
            return NULL;
        
        stack<int> st;
        
        for(auto ptr = head; ptr != nullptr; ptr = ptr->next)
        {
            st.push(ptr->val);
        }
        
        for(auto ptr = head; ptr != nullptr; ptr = ptr->next)
        {
            ptr->val = st.top();
            st.pop();
        }

        return head;

        //Iteratively
        ListNode *nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;

        //recursive
        return head ? reverseList(head->next, (head->next = prevNode, nextNode), head) : prevNode;

        //recursive 2
        ListNode* Recursive(ListNode* curr, ListNode* prev)
        {
            if(curr == nullptr)
                return curr;
            
            if (curr->next == nullptr)
            {
                curr->next = prev;
                return curr;
            }

            ListNode* result = Recursive(curr->next, curr);
            curr->next = prev;
            return result;
        }

        ListNode* reverseList(ListNode* head) {
            return Recursive(head, nullptr);
        }
    }
};