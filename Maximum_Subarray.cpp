class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //Sliding Window
        int size = nums.size();
        int curr = 0;
        int max = pow(10, 5) * (-1);
        
        for(int i = 0; i < size; i++)
        {
            if(curr < 0)
            {
                curr = nums[i];
            }
            else{
                curr += nums[i];
            }
            
            if(max < curr)
            {
                max = curr;
            }            
           
        }
        
        return max;

        //Divide and Conquer
         int maxSubArray(vector<int>& nums, int l, int r)
        {
            if(l >= r)
                return nums[l];
            
            int mid = (l + r) / 2;
            int leftSum = 0;
            int rightSum = 0;
            int sum = 0;
            
            for(int i = mid; i >= l; i--)
            {
                sum += nums[i];
                if(sum > leftSum)
                {
                    leftSum = sum;
                }
            }
            
            sum = 0;
            for(int i = mid + 1; i <= r; i++)
            {
                sum += nums[i];
                if(sum > rightSum)
                {
                    rightSum = sum;
                }
            }
            
            int maxLeftRight = max(maxSubArray(nums, l, mid), maxSubArray(nums, mid + 1, r));
            
            return max(maxLeftRight, leftSum + rightSum);
        }
    
    int maxSubArray(vector<int>& nums) {    
        return maxSubArray(nums, 0, nums.size() - 1);    
    }
    
};