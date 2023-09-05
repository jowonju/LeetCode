class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int size = nums.size();
        int result = 0;
        int current = 0;
        for(int i = 0; i < size; i++)
        {
            while(nums[i] > 0)
            {
                nums[i] /= 10;
                current++;
            }
            if(current % 2 == 0) result++;
            current = 0;
        }
        return result;
    }
};