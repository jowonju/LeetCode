#include<iostream>
#include<vector>
#include<algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next !=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                return true;
        }
        return false;
        
    }
};

int main() {
    Solution sol;

    ListNode firstNode(3);
    ListNode secondNode(2);

    firstNode.next = &secondNode;
    firstNode.next->next = &ListNode(0);
    firstNode.next->next->next = &ListNode(-4);
    firstNode.next->next->next->next = &secondNode;

    ListNode node(1);
    bool result = sol.hasCycle(&firstNode);
    bool result2 = sol.hasCycle(&node);
    std::cout << result;
    std::cout << result2;
}