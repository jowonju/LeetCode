class Solution {
public:
    int reverse(int x) {
        int max = std::numeric_limits<int>::max();
        int min = std::numeric_limits<int>::min();
        
        int result = 0;
        bool flag = false;
        
        string str = to_string(x);
        
        if(x < 0)
        {
            flag = true;
            str.erase(str.begin());
        }
        
        std::reverse(str.begin(), str.end());
        
        int stringSize = str.size();
        int checkingValue = 0;
        
        for(int i = 0, multiplier = stringSize - 1; i < stringSize; i++, multiplier--)
        { 
            int integer = str[i] - 48;
                        
            if(multiplier > 8 && integer > 2)
                return 0;
            
            if(i == stringSize - 1 && integer == 0)
            {
                break;
            }
            
            int multipliedValue = pow(10, multiplier);
            checkingValue = max - result;
            
            if(multipliedValue * integer > checkingValue)
                return 0;
            
            result += integer * multipliedValue;
        }
        
        if(flag)
            result *= -1;
        
        return result;
    }
};