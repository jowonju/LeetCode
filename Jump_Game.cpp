class Solution {
public:
    bool canJump(vector<int>& nums) {
        //Linear Approach
        int maxReach = nums[0];
    
        for(int i = 0; i < nums.size(); i++)
        {
            if(maxReach < i) return false;

            if(maxReach < nums[i] + i) maxReach = nums[i] + i;
        }

        return true;
    }
};