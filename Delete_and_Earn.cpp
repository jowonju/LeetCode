class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int take = 0;
        int skip = 0;

        vector<int> vec(10001, 0);

        for(int num : nums)
        {
            vec[num] += num;
        }

        for(int i = 0; i < 10001; i++)
        {
            int takei = skip + vec[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
    
        return max(take, skip);
    }
};