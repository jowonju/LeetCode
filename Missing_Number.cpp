class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int largestNumber = INT_MIN;
        int total = 0;
        bool check = false;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
                check = true;
            
            if(nums[i] > largestNumber)
            {
                largestNumber = nums[i];
            }
            total += nums[i];
        }
        
        
        if(!check)
            return 0;
        else if((largestNumber*(largestNumber+1))/2 - total == 0)
            return largestNumber + 1;
        else
            return (largestNumber*(largestNumber+1))/2 - total;
    
        //Improved version
        int size = nums.size();
        int sum = 0;
        
        for(int i = 0; i < size; i++)
        {
            sum += nums[i];
        }
        
        return (size*(size+1)/2) - sum;
          

   
    }
};