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