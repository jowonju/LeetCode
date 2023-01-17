class Solution {
public:
	//recursive
     int BinarySearch(vector<int>& nums, int left, int right, int target) {
    	if(left > right)
    	{
             return -1;
    	}
    	else {
	        int mid = (left + right) / 2;
		
	        if (nums[mid] == target)
	            return mid;

	        if (nums[mid] < target)
	        {
	            return BinarySearch(nums, mid + 1, right, target);
	        }
	        else {
	            return BinarySearch(nums, left, mid - 1, target);
	        }
	        
    	}
    }


    int search(vector<int>& nums, int target) {
        return BinarySearch(nums, 0, nums.size() - 1, target);

        //iterative
        int low = 0;
        int high = nums.size() - 1;
        
        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(nums[mid] == target)
                return mid;

            if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;
    }
};