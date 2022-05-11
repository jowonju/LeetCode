*leetcode 376*
>This is my version code.
```c++
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
```
>Other people's
```c++
   public ListNode middleNode(ListNode head) {
    
    ListNode fastRunner = head;
    ListNode slowRunner = head;

    while(true){
        if(fastRunner == null || fastRunner.next == null) {
            break;
        }
        slowRunner = slowRunner.next;
        fastRunner = fastRunner.next.next;
    }

    return slowRunner;
  }
```
The fast pointer stops where behind the nullptr then the slow's position be the middle of the node because it is a single linked list and the pointer jump twice.
I thought the fast-slow method is good when I distinguish the thing is a cycle or not but I realize this method is also good for distinguishing the middle.

*leetcode 922*
>My version
```c++
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int size = nums.size();
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0 && nums[i] % 2 != 0) {
                while (true) {
                    if (j % 2 == 1 && nums[j] % 2 == 0)
                    {
                        break;
                    }
                    j++;
                }
                swap(nums[j], nums[i]);
            }
        }
        return nums;
    }
};
```
>Other person's version
```c++
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
         
        for(int i =0 , j =1 ; j < nums.size() && i <nums.size();)
        {
            if(nums[i] %2 ==0)
            i+=2;
            else if(nums[j] % 2 ==1)
            j+=2;
            else
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};
```
Since it checks even and odd indexes, it doesn't have to initialize only one variable or add one by one(like me, i++, and, i = 0). Just using +=2.
I didn't familiar with using the two variables at the for loop, but I realized the usage when I see this version.

*leetcode 104*
>My version
```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int rightLength = 0;
        int leftLength = 0;
        int result = 0;

        rightLength = maxDepth(root->right);
        leftLength = maxDepth(root->left);

        result = 1 + (rightLength > leftLength ? rightLength : leftLength);

        return result;
    }
};
```
>Other person's version
```c++
class Solution{
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return max(maxDepth(root->right),maxDepth(root->left))+1;
    }

};
```
When using algorithm max function, the runtime is 0 ms. If I use the max function, then I don't need to declare variables(like my version -> rightLength, leftLength, result).
And I think this part 
```c++ 
return max(maxDepth(root->right),maxDepth(root->left))+1;
``` 
is RVO, so the runtime reduced. Also, using the algorithm function reduces the runtime, but I don't know the reason(6/4).

*leetcode 614*
>code
```c++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
        
    }
};
```
I struggle with this problem. After spending 1 day, I determined that seeing the solution and after seeing the solution, I felt this problem is good to practice the recursion.
When I solving this problem, I knew the method that gets each value of the leaves but I didn't know how to store the values(each tree's leaf values). 
The first time, I used the map and vector to store the values but there was a problem that stores the nullptr.
```c++
if (root1 == nullptr)
    return root2;
if (root2 == nullptr)
    return root1;
```
However, as you can see, I don't need to store any values if I use the root. Just plus root2's value to root1.
If root1 is null, return root2 and accept the value as a result, then I also change the nullptr location's value to root2's value.

*Leetcode 461*
>my version
```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        bitset<32> x_bitset(x);
        bitset<32> y_bitset(y);
        
        for(int i = 0; i<x_bitset.size(); i++)
        {
            if (x_bitset[i] != y_bitset[i])
                result++;
        }
        
        return result;
    }
};
```
I used the bitset header to get the bits of the x and y. After getting the bits, I compared the bits one by one.
For solving this question, I did study the bitset header usage.

>other person's version
```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int res = 0; 
        while(n){ 
            res += n & 1; 
            n >>= 1; 
        }
        return res;         
    }
};
```
This version using the XOR to get the result. I knew the XOR but I didn't think that using the XOR to solve this problem.
For example, if x is 5 and y is 1.
x 0101      0100    0100    0100
y 0001  ->  0001 -> 0010 -> 0100  
^ ----     &----   &----   &----
  0100      0000    0000    0100  = then the result += 1;
I think the XOR version is useful to pratice the XOR or bit operation.

*Leetcode 2*
I couldn't solve this problem so just understand write for the study.

```c++
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
```
Store the remainder to the temp->next. Since the temp is the ans's pointer, so the ans value is changed even if the temp value is changed.
Get the l1 and l2's sum value also the carry. The carry is increased when the sum exceeds 10. (sum/10)
After getting the sum between current nodes then change the node to the next node's value.
And repeat this until l1 or l2 be the nullptr.
When the l1 or l2 is nullptr or the carry is 0 then I can get the answer(stored the ans).