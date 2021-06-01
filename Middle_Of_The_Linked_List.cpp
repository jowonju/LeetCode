using namespace std;
#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        int targetIndex = 0;
        ListNode* copyNode = head;

        for (ListNode* node = head; node != nullptr; node = node->next)
        {
            length++;
        }

        targetIndex = (length / 2) + 1;

        for (int i = 0; i < targetIndex - 1; i++)
        {
            if (copyNode->next != nullptr)
            {
                copyNode = copyNode->next;
            }
        }
        return copyNode;
    }
};

int main() {
    Solution sol;

    ListNode node5(5);
    ListNode node4(4, &node5);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);

    ListNode node(1, &node2);

    ListNode* result = sol.middleNode(&node);

    for (ListNode* node = result; node != nullptr; node = node->next) {
        cout << node->val;
    }
}