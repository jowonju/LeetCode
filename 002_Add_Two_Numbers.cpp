
#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while (l1 || l2 || carry != 0) {
            int no1 = l1 ? l1->val : 0;
            int no2 = l2 ? l2->val : 0;

            int sum = no1 + no2 + carry;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;

            carry = sum / 10;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return ans->next;
    }
};

int main()
{
    Solution sol;
    ListNode temp1(4);
    ListNode temp2(3);
    ListNode temp3(6);
    ListNode temp4(4);
    
    ListNode l1(2, &temp1);
    ListNode l2(5, &temp3);


    l1.next->next = &temp2;
    l2.next->next = &temp4;

    ListNode* ans = sol.addTwoNumbers(&l1, &l2);

    for(ListNode* temp = ans; temp != nullptr; temp  = temp->next)
    {
        std::cout << temp->val <<"\t";
    }
}