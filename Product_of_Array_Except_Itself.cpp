class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //using division operator
        int prod = 1;
        int count = 0;
        int size = nums.size();
        vector<int> res(0, size);
        
        for(int i = 0; i < size; i++)
        {
            if(nums[i] == 0)
            {
                count++;
            }
            else{
                prod *= nums[i];
            }
        }
        
        if(count > 1)
        {
            res.assign(size, 0);
            return res;
        }
            

        for(int i = 0; i < size; i++)
        {   
            if(count == 1)
            {
                if(nums[i] == 0)
                    res.push_back(prod);
                else{
                    res.push_back(0);
                }
            
            }
            else{
                res.push_back(prod/nums[i]);
            }
            
        }
        return res;

       //usig suffix and prefix container
       int size = nums.size();
       vector<int> pre(size);
       vector<int> suf(size);
       pre[0] = nums[0];
       suf[size - 1] = nums[size - 1];
    
       for(int i = 1; i < size - 1; i++)
       {
           pre[i] = pre[i-1] * nums[i];
       }

       for(int i = size - 2; i > 0; i--)
       {
           suf[i] = nums[i] * suf[i + 1];
       }

       for(int i = 0; i < size; i++)
       {
           if(i==0) nums[i] = suf[i+1];
           else if(i==size-1) nums[i] = pre[i-1];
           else nums[i] = pre[i-1] * suf[i+1];
       }

       return nums;
    }
};