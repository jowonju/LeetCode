class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int duplicated = 0;

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