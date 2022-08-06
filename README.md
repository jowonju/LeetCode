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

*Leetcode - Plus One*

```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int size = digits.size();
    
        for(int i = size, index = size - 1; i > 0; i--, index--)
        {
            int count = digits[index] + 1;
            if(count == 10)
            {
                if(index - 1 < 0)
                {
                    digits[index] = 1;
                    digits.push_back(0);
                }
                else {
                    digits[index] = 0; 
                }
            }
            else {
                digits[index]++;
                return digits;
            }
        }
        return digits;
    }
};
```
First, start at the end of the vector and just plus one to the element.
If the element value is under 9, don't need to think about the digit number, but if the value is over 9, then it means the digit number is increased. 
For example, if the element value is 9 and after plus one, the digit number is increased from 1 to 2. (1 -> 10)
And if that situation(digit number increased), the index value be 0, but if the former index is not assigend than the index value be 1 and push back 0 to the end.
For example, if the value is 9 then the value(index - 1) is -1, it means the index is out of range.
So changed the index value 1 and push back 0 to the end, the result be [1, 0].

*Leetcode - Move Zeros*


```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
          
        if(size == 1) 
            return;
        
        int zeroCount = 0;
        bool flag = false;
        
        for(int i = 0; i < size; i++)
        {
            if(nums.size() == 0 || i > nums.size() - 1)
                break;
            
            if(flag)
            {
                i = 0;
                flag = false;
            }
            if(nums[i] == 0)
            {
                nums.erase(nums.begin() + i);
                zeroCount++;
                flag = true;
            }
        }
        
        for(int i = 0; i < zeroCount; i++)
        {
            nums.push_back(0);
        }
    }
};
```
First, I thought to get the frequency of zeros and erase the zero value when encountering the nums[i] is 0.
Second, after deleting all zeros, push_back the zero.
The flag and size == 0 are conditions to avoid the out-of-range error.

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
          
        if(size == 1) 
            return;
        
        int zeroCount = 0;
        bool flag = false;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]==0)
            {
                nums.erase(nums.begin() + i);
                i--;
                zeroCount++;    
            }
            
        }
        
        for(int i = 0; i < zeroCount; i++)
        {
            nums.push_back(0);
        }
    }
};
```
The second version is an improved version.
The first time, I tried this version that deleting the zero number by using nums.begin() + i;
But when I tried that, I didn't think about the i-- and I used the stored size(line 741).
If I changed to nums.size() then I don't need to think about the out-of-range error.

*Leetcode - Two sum*

my one
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for(int i = 0 ; i < size; i ++)
        { 
            int findValue = target - nums[i];
            for(int j = 0; j < size; j++)
            {
                if(i == j)
                    continue;
                
                if(nums[j] == findValue)
                {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
```
I used brute force way. 
Find the findvalue(target = num1 + num2 => num1 = target - num2) from the second for loop and return the vector right away.

another one - using hash map(unordered_map using hash table)
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int size = nums.size();
        for(int i = 0; i < size; ++i)
        {
            int diff = target - nums[i];
            if(mp.find(diff)!=mp.end())
            {
                return {mp[diff],i};
            }
            mp.insert({nums[i],i});
        }
        return {};
    }
};
```
I am not familiar with using a hash map(unorderded_map).
So after solving the problem using brute force, I tried to solve this problem using the hash map.
But I failed to find other person's answers and understand the way.

First, if cannot find the diff value(=find value), insert the value({nums[i],i}).
For example, the nums are [2, 7, 11, 15] and the target value is 9.
In the first loop(i = 0), there is no value cause it's an empty one so insert the value.
In this case, the (2,0) will be stored in a map container.
And when the i = 1, the diff value is 2.
In the map, there is a value that has a 2(key value) so can enter the if statement.
And if succeed to find the value, it means it finds the two sums' vector.
So return the {mp[diff],i}.
In this case, the returned vector is {mp[2], 1} => { 0, 1 }.

i | num[i] | diff | insert | return      | mp[]
0 |   2    |  7   |  (2,0) |   X         | (2,0)
1 |   7    |  2   |    X   | O => {0, 1} | (2,0)

*Leetcode - Valid Sudoku*

my one
```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //x check
        for(int y = 0; y < 9; y++)
        {
            unordered_map<char, int> m;
            for(int x = 0; x < 9; x++)
            {   
                if(board[y][x] == '.')
                    continue;

                m[board[y][x]]++;
                
                if(m[board[y][x]] > 1)
                    return false;
            }
            m.clear();
        }
        
        //y check
        for(int x = 0; x < 9; x++)
        {
            unordered_map<char, int> m;
            for(int y = 0; y < 9; y++)
            {
                if(board[y][x] == '.')
                    continue;
                
       
                m[board[y][x]]++;
                
                if(m[board[y][x]] > 1)
                     return false;
                     
            }
            m.clear();
        }
        
        //grid check
        int xAdd = 0;
        int yAdd = 0;
        int count = 0;
     
        while(count != 9)
        {
            if(xAdd == 9)
                xAdd = 0;
                
            unordered_map<char, int> m;
            for(int y = yAdd; y < yAdd + 3; y++)
            {
                for(int x = xAdd; x < xAdd + 3; x++)
                {    
                    if(board[y][x] == '.')
                        continue;

                    m[board[y][x]]++;
                    
                    if(m[board[y][x]] > 1)
                        return false;
                }
            }
            count++;
            m.clear();
            xAdd += 3;
            
            if(count % 3 == 0)
                yAdd +=3;
        }
        
        return true;
        
    }
};
```
I used an unordered_map to know the repetition.
And separate three conditions into row check, column check, and sub 3x3 check.
The way that checking repetition is storing values to the m.
For example, if there is a char '5' in the board[1][1], then the char be the key value and increase the second value if the value exists.
And, suppose to there is a duplicate char '5' in the board[2][1], this means it is not valid sudoku cause there is a repetition in the same column.
So the m['5'] = 2. => exceed 1, succed to find duplicate value!


another one
```c++
bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<int>> rows(9, unordered_set<int>());
    vector<unordered_set<int>> columns(9, unordered_set<int>());
    vector<unordered_set<int>> boxes(9, unordered_set<int>());

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.')
          continue;

        int num = board[i][j] - '0';

        if (rows[i].count(num))
          return false;

        if (columns[j].count(num))
          return false;

        // This is a straight-forward math formula to locate a box
        // Out of the 9 boxes
        int box_index = (i / 3) * 3 + j / 3;

        if (boxes[box_index].count(num))
          return false;

        rows[i].insert(num);
        columns[j].insert(num);
        boxes[box_index].insert(num);
      }
    }

    return true;
}
```
This version used three variables to store columns, rows, and boxes.
To get the number, check the duplicate values by using the unordered_set's count function.
The count function returns the number of elements found.
The unordered_set containers do not allow for duplicate values, this means that the function actually returns 1 if an element with that value exits in the container, and zero otherwise.
If the return value is 1, then return false cause it's not valid sudoku that has a repetition number in the row or column or box.

And for checking the sub-boxes, using the math formula from this formula, can get the sub-boxes index for the 3x3 box.
For example,
if there is a number 5 in the (1,1) cell, the box index is 0.
After inserting the number, the 5 is stored in the boxes[0]. =>first sub-box's element.
And if there is a number in the (3,0) cell, the box index is 1. => second sub-box's element.

After getting a box index, insert the value into the vector array.
For the row, insert to the y index, and for the column, insert to the x index.
For the box, just use box_index.

*Leetcode - reverse string*

my one
```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};
```
Get the two variables to point first and end and just swap two values.
For example, if the s is [1, 2, 3, 4, 5], i is 0 and j is 4.
First iteration result is [5, 2, 3, 4, 1].
Second iteration result is [5, 4, 3, 2, 1].
The for loop works until s.size() / 2 so the second iteration will be an answer.


*Leetcode - Rotate Image*

my one
```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = i + 1, index = i + 1; j < matrix.size(); j++, index++)
            {
                swap(matrix[i][j], matrix[index][i]);
            }
            
        }
        
        for(int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```
I didn't solve this problem on my own so I searched for this problem and how to solve it.
First, the first column matrix transposes the row matrix.
For example, if the matrix is 
[1 2 3 4]
[5 6 7 8]
[9 10 11 12]
[13 14 15 16], the first column is [1,5,9,13] and make this column to row then the result be

[1 5 9 13]
[2 6 7 8]
[3 10 11 12]
[4 14 15 16].

This operation applies to all columns then the final result be
[1 5 9 13]
[2 6 10 14]
[3 7 11 15]
[4 8 12 16].

After gaining this result, reverse this matrix.
[13 9 5 1]
[14 10 6 2]
[15 11 7 3]
[16 12 8 4].
I can get the result.

I think I'm not good at solving the in-placea problem.
Need to practice more problems.

*Leetcode - Reverse integer*

```c++
class Solution {
public:
    int reverse(int x) {
        int max = std::numeric_limits<int>::max();
        int min = std::numeric_limits<int>::min();
        
        int result = 0;
        bool flag = false;
        
        string str = to_string(x);
        
        if(x < 0)
        {
            flag = true;
            str.erase(str.begin());
        }
        
        int stringSize = str.size();
        int checkingValue = 0;
        
        for(int i = stringSize - 1; i >= 0; --i)
        { 
            int integer = str[i] - 48;
                        
            if(i > 8 && integer > 2)
                return 0;
            
            if(i == 0 && integer == 0)
            {
                break;
            }
            
            int multipliedValue = pow(10, i);
            checkingValue = max - result;
            
            if(multipliedValue * integer > checkingValue)
                return 0;
            
            result += integer * multipliedValue;
        }
        
        if(flag)
            result *= -1;
        
        return result;
    }
};
```
I thought it needs to convert the integer value to a string value.
So I used the to_string() function => it converts an integer value to a string value like 123 -> "123". 
And for getting the integer value from the string, subtract 48(the decimal value of the char '0') to each string element cause I just need numbers 0 to 9.
For a negative value, I checked the value at the beginning, so if the condition is met(x < 0) then multiply -1 to the resulting number.
Also, I need to check the integer range.
If the reversed integer value exceeds the int range([-2^31, 2^31 -1]), it causes an error. 
For checking the range, I used the checking variable.  
```c++
            checkingValue = max - result;
            
            if(multipliedValue * integer > checkingValue)
                return 0;
```
The max - result value is stored in the checking value.
If the multipliedValue * integer value exceeds the checking value, it means the addedValue causes the range error.
For example, suppose an example value is 2147483651. This value exceeds the maximum value of 51.
So in that example, the checking value is 47 and the added value is 50. Added value is greater than the checking value, returned 0.

another one
```c++

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            if(res > INT_MAX/10 || res < INT_MIN/10)
                return 0;
            res = res*10 + x%10;
            x /= 10; 
        }
        return res;
    }
};
```
I found a clever solution to this problem.
The (number % 10) gives the last digit number.
For example, if the value is 123 then the value % 10 is 3 -> the last digit.
So if using that calculation, I can get the reversed number.
Suppose an example number is 123.

iteration | x % 10 |   x    | res |
    0     |   -    |   -    | 0   |
    1     |   3    |   123  | 3   |
    2     |   2    |   12   | 32  |
    3     |   1    |   1    | 321 |

For the range check, using res > INT_MAX/10 and res < INT_MIN / 10.
