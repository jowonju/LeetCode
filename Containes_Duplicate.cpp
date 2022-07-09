class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool result = false;
        vector<int> storage = nums;
        std::sort(storage.begin(), storage.end());
        
        for(int i = 0; i < storage.size() - 1; i++)
        {
            if(storage[i] == storage[i + 1])
            {
                result = true;
                break;
            }   
        }
        
        return result;
    }
};