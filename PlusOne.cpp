class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int size = digits.size();
    
        for(int i = size, index = size - 1; i > 0; i--, index--)
        {
            int count = digits[index] + 1;
            if(count == 10)
            {
                if(index - 1 < 0)
                {
                    digits[index] = 1;
                    digits.push_back(0);
                }
                else {
                    digits[index] = 0; 
                }
            }
            else {
                digits[index]++;
                return digits;
            }
        }
        return digits;
    }
};