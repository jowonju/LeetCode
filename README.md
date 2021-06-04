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