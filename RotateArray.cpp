class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size();
        vector<int> modded(s);
        for(int i = 0; i < s; i++) modded[(i+k)%s] = nums[i];
        nums = modded;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int k_ = k % size;
            
        reverse(nums.begin(), nums.begin() + size - k_);
        reverse(nums.begin() +size - k_, nums.end());
        reverse(nums.begin(), nums.end());
    
    }

};