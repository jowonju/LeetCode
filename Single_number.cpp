class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> storage = nums;
        sort(storage.begin(), storage.end());
        int size = nums.size();
        int result = 0;
        bool check = false;
        
        for(int i = 0; i < size - 1; i++)
        {
            if(storage[i] == storage[i + 1])
            {
                i++;
                continue;
            }
            else{
                check = true;
                result = storage[i];
                break;
            }
        }
        
        if(!check)
            result = storage[size - 1];
            
        return result;
    }
};