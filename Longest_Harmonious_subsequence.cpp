class Solution {
public:
    int findLHS(vector<int>& nums) {
        int result = 0;
        int compare = 0;

        map<int, int> res;
        map<int, int>::iterator iter;
        
        for (auto num : nums)
        {
            res[num]++;
        }
        
        for (iter = res.begin(); iter != res.end(); iter++)
        {
            if (iter == res.end())
                break;

            int first = iter->first;
            int second = iter->second;

            if (res.find(first + 1) != res.end()) {
                compare = second + res[first + 1];
            }

            if (result < compare)
            {
                result = compare;
                compare = 0;
            }

        }
        
        return result;
    }
};