class Solution {
public:
    int jump(vector<int>& nums) {
        //greedy solution
        int size = nums.size();
        if(size < 2) return 0;

        int ladder = nums[0];
        int stairs = nums[0];
        int jump = 1;

        for(int i = 1; i < size; i++)
        {
            if(i == size - 1) return jump;

            if(i + nums[i] > ladder) ladder = i + nums[i];

            stairs--;

            if(stairs == 0)
            {
                stairs = ladder - i;
                jump++;
            }
        }
        
        return jump;
    }
};