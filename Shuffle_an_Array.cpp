class Solution {
public:
    Solution(vector<int>& nums) {
        currentVec = nums;
        firstVec = nums;
    }
    
    vector<int> reset() {
        return firstVec;
    }
    
    vector<int> shuffle() {
        int randNum = rand() % currentVec.size();
        swap(currentVec[0], currentVec[randNum]);
        return currentVec;
    }

private:
    vector<int> currentVec;
    vector<int> firstVec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */