class Solution {
public:
    int robHelper(vector<int>& nums, int l, int r){
        int prev = 0;
        int curr = 0;
        for(int i = l; i <= r; i++)
        {
            int temp = max(prev + nums[i], curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return nums[0];
        return max(robHelper(nums, 0, size - 2), robHelper(nums, 1, size - 1));
    }
};