class Solution {
public:
    //Dynamic Programming - Tabulation
    int rob(vector<int>& nums) {

        int size = nums.size();
        if(size == 1)
            return nums[0];
        
        vector<int> vec(nums);
        
        //For keeping the maximum value
        vec[1] = max(vec[0], vec[1]);
    
        for(int i = 2; i < size; i++)
        {
            vec[i] = max(nums[i] + vec[i - 2], vec[i - 1]);
        }
        
        return vec.back();
    }

    //Dynamic Programming - Memoization(Top-down)
    int rob(vector<int>& A) {
        vector<int> dp(size(A), -1);
        return rob(A, dp, 0);
    }

    int rob(vector<int>& A, vector<int>& dp, int i) {
        if (i >= size(A)) return 0;

        if (dp[i] != -1) return dp[i];

        return dp[i] = max(rob(A, dp, i + 1), A[i] + rob(A, dp, i + 2));
    }
};