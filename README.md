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

*Leetcode 13*
My one
```c++
class Solution {
public:
    int romanToInt(string s) {
             
        int size = s.length();
        int result = 0;
        string copy = s;
        std::map<char, int> dictionary;
        
        dictionary.insert(std::pair<char,int>('I', 1));
        dictionary.insert(std::pair<char,int>('V', 5));
        dictionary.insert(std::pair<char,int>('X', 10));
        dictionary.insert(std::pair<char,int>('L', 50));
        dictionary.insert(std::pair<char,int>('C', 100));
        dictionary.insert(std::pair<char,int>('D', 500));
        dictionary.insert(std::pair<char,int>('M', 1000));
        
        for(int i = 0; i < size; i++)
        {
            if(i == size -1)
                continue;
            
            int compare1 = dictionary.find(copy[i])->second;
            int compare2 = dictionary.find(copy[i+1])->second;
            
            if (compare1 >= compare2)
            {
                result += compare1; 
            }
            else {
                int abs = std::abs(compare1 - compare2);
                result += abs;
                i++;
                if(i == size - 1)
                {
                    return result;
                }
            }
                    
        }
            
        result += dictionary.find(copy[size-1])->second;
        return result;       
    }
};
```
Runtime: 24 ms, faster than 30.97% of C++ online submissions for Roman to Integer.
Memory Usage: 8.2 MB, less than 29.33% of C++ online submissions for Roman to Integer.

First, I thought I need to distinguish those letters so I made a map to store them. 
After storing, I compared two chars in order, and if the compare1 value smaller than compar2, I subtract two numbers and plus the i.
Because the two chars combined to the one string and the other situation just add the compare1 value.

Another one
```c++
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int ans =0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]<mp[s[i+1]])
                ans-=mp[s[i]];
            else
                ans+=mp[s[i]];
        }
        return ans;
        
    }
};
```
It is similar to mine, but this one used an unordered map and did not use the insert function when initializing.
Also, this used the mp[s[i]], means the [] operator.
=> the [] operator returns the key's second value.
It is better to reduce the runtime because of not using the find function in every calculation.

*Leetcode - Remove Duplicates from Sorted Array*
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();

        for(int i = size - 1; i > 0; i--)
        {            
            if(i == 0)
                continue;
            
            if(nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i);
            }
        }
        
        return nums.size();
    }
};
```
I checked all elements using linear search. 
If the first value(nums[i]) is equal with the second value(nums[i - 1]) then delete the first value.
After checking all values, then just return the size of the changed vector.

*Leetcode - Best Time to Buy and Sell Stock II*
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int result = 0;
        int size = prices.size();

        for(int i = 0; i < size; i++)
        {
            if(i == size - 1)
                continue;
            
            if(prices[i] < prices[i + 1])
            {
                result += prices[i + 1] - prices[i];   
            }
            
        }

        return result;
    }
};
```
For check the profit, I compared the first value(prices[i]) and the second value(prices[i + 1]). 
If the first value is greater than the second value, then I can profit because I can sell the stock more expensive than I bought.
After storing the calculated profit, keep checking values. And if the condition is met again, add the profit value to the result value.

*Leetcode - Rotate Array*
```c++

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size();
        vector<int> modded(s);
        for(int i = 0; i < s; i++) modded[(i+k)%s] = nums[i];
        nums = modded;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int k_ = k % size;
            
        reverse(nums.begin(), nums.begin() + size - k_);
        reverse(nums.begin() +size - k_, nums.end());
        reverse(nums.begin(), nums.end());
    
    }

};
```
I didn't solve this problem but I can get to how to approach (rotating formula and reverse way) the rotating.

The first one is the formula way.
If using the formula((i + k) % s) then I can get the remaining indexes(like after the index of the k-> example is 3 so we can get the 3 index = the array starts at 0, not 1, so it's right to get the index 3).
For example, if the k is 3 and the given array is [1,2,3,4,5,6,7], the result be [5,6,7,1,2,3,4].

i | (i + k) % s |    result
0 |     3       | m[3] = num[0]; 
1 |     4       | m[4] = num[1];
2 |     5       | m[5] = num[2];
3 |     6       | m[6] = num[3];
4 |     0       | m[0] = num[4];
5 |     1       | m[1] = num[5];
6 |     2       | m[2] = num[6];

After applying that formula, can get the result array.

The second one used the reverse way.
I can separate the array-like 0 to n-k, and n-k to n. ->the first separate one is [1,2,3,4] and the second separate one is [5,6,7].
If I reverse the first one then the array is [4,3,2,1] and the second one is [7,6,5].
And reverse the whole array the array be [5, 6, 7, 1, 2, 3, 4].
Then I can easily get the reversed array.

*Leetcode - Contains Duplicate*

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool result = false;
        vector<int> storage = nums;
        std::sort(storage.begin(), storage.end());
        
        for(int i = 0; i < storage.size(); i++)
        {
            if(i == storage.size() - 1)
                continue;
            
            if(storage[i] == storage[i + 1])
            {
                result = true;
                break;
            }   
        }
        
        return result;
    }
};
```

First, I thought compare all values using two for loops. 
For example,
```c++
for(int i = 0; i < storage.size(); i++){
    int compare = storage[i];
    for(int j = 0; j < storage.size(); j++)
    {
        if(compare == storage[j])
        {
            result = true;
            break;
        }
    }
}
```
but this way's time complexity is O(n^2), so I used the std::sort function.
If the array is sorted then I can check the duplicated values by only using one for loop(linear search).
The sort function's time complexity is O(n log n) so it's better than the second way.

*Leetcode - Single number*

my one
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> storage = nums;
        sort(storage.begin(), storage.end());
        int size = nums.size();
        int result = 0;
        bool check = false;
        
        for(int i = 0; i < size - 1; i++)
        {
            if(storage[i] == storage[i + 1])
            {
                i++;
                continue;
            }
            else{
                check = true;
                result = storage[i];
                break;
            }
        }
        
        if(!check)
            result = storage[size - 1];
            
        return result;
    }
};
```
I thought if I used sorting then I can find the single number by searching the first(storage[i]) and the second value(storage[i+1]).
but I found better ways to solve this problem.
If I use the return, I don't need to use the bool variable.
Below is the improved version.
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> storage = nums;
        sort(storage.begin(), storage.end());
        int size = nums.size();
        int result = 0;
        bool check = false;
        
        for(int i = 0; i < size - 1; i += 2)
        {
            if(storage[i] != storage[i + 1])
            {
                return storage[i];
            }
            
        }   
        return storage[size - 1];
    }
};
```

And can solve this problem by using the map.
I also thought about using the map to solve this problem.
But I'm not familiar with using the map so I just used the first way.

another one using map
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       unordered_map<int,int> a;
       for(auto x: nums)
           a[x]++;
       for(auto z:a)
           if(z.second==1)
               return z.first;
       return -1;
    }
};
```
This is another person's answer for using a map.
After passing the for loop, the map stored values in ascending order.
For example, if the nums vector content [1,1,2,2,3], then the map's content be (1,2) | (2,2) | (3,1)
so I can get the single number through the map's second value.

*Leetcode - Intersection of Two Arrays II*

my one
```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> store1;
        map<int, int> store2;
        vector<int> result;
        
        for(auto num: nums1)
        {
            store1[num]++;
        }
        
        for(auto num: nums2)
        {
            store2[num]++;
        }
        
        for(std::map<int, int>::iterator it = store1.begin(); it != store1.end(); it++)
        {
            int compare = it->first;
            std::map<int, int>::iterator iter = store2.find(compare);
            int count = min(iter->second, it->second);
            for(int i = 0; i < count; i++)
            {
                result.push_back(iter->first);
            }
        }
        return result;
    }
};
```
I used map STL to compare the values.
First, store the values of each map.
After storing, then the result be (if the nums1 [4,9,5] and the nums2 [9, 4, 9, 8, 4])
store1: (4, 1) | (5, 1) | (9, 1)
store2: (4, 2) | (8, 1) | (9, 2)
=>The map sorts values in ascending order automatically. 

Second, find the iterator that has the same first value by using the for-loop.
If succeed at finding the value, then push_back the iterator's second value as the minimum value between two iterator's values.

the another one
```c++
class Solution {
public:
vector intersect(vector& nums1, vector& nums2) {

    vector<int> ans;
    
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    for(int i=0, j=0; i<nums1.size() && j<nums2.size(); )
    {
        if(nums1[i] < nums2[j])
            i++;
        else if(nums1[i] > nums2[j])
            j++;
        else
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return ans;
}
};
```
Above answer is the 100% fastest version.
This answer used sorting and for-loop that using two initial variable.
If the nums[i] < num2[j] then increase the i value, in the opposite situtaion, increase j value.
For example, the nums1 is [1, 2, 2, 1] and the nums2 is [2, 2].
After sorting two container, the nums1 be [1, 1, 2, 2] and the nums2 [2, 2].
In the for-loop, the i is increase when the i and j are 0.
When the condition that two values are same is met, then push_back the value because it means the value is same.