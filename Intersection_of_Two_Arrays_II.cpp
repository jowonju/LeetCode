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