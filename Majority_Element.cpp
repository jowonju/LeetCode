class Solution {
public:
    int majorityElement(vector<int>& nums) {

        //Hash map
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            if(m[nums[i]] > nums.size() /2)
            {
                result = nums[i];
                break;
            }                
        }

        return result;

        //MOORE'S VOTING ALGORITHM
        int count = 0;
        int result = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                result = nums[i];
                count++;
            }
            else if(nums[i] == result){
                count++;
            }
            else{
                count--;
            }
        }

        return result;

        //Divide and Conquer
        int countFrequency(vector<int>&nums, int l, int r, int target)
        {
            int count = 0;
            for(int i = l; i <= r; i++)
            {
                if(nums[i] == target)
                    count++;
            }
            return count;
        }
        
        int majorityElement(vector<int>& nums, int l, int r)
        {
            if(l == r) return nums[l];

            int mid = l + (r - l) / 2;
            int left = majorityElement(nums, l, mid);
            int right = majorityElement(nums, mid + 1, r);

            int leftCount = countFrequency(nums, l, r, left);
            int rightCount = countFrequency(nums, l, r, right);

            if(leftCount > rightCount)
                return left;
            else
                return right;
        }

        int majorityElement(vector<int>& nums) {
            return majorityElement(nums, 0, nums.size() - 1);
        }
    }
};