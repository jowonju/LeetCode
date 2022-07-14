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