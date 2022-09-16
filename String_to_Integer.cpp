class Solution {
public:
    
    int CheckWhitespace(string s)
    {
        int result = 0;
        int i = 0;
        while(true)
        {
            if(s[i]==' ')
                result++;
            
            if(s[i] != ' ')
                return result;
            
            i++;
        }
    }
    
    void CheckingTwoStep(bool& negative, int& i, string inputString, string& str_){  
        
        if(inputString[i] == ' ')
        {
            i = CheckWhitespace(inputString);
        }
        
        if(inputString[i] == '-' || inputString[i] == '+')
        {
            if(inputString[i] == '-')
            {
                negative = true;
                str_.push_back('-');
            }
            else{
                str_.push_back('+');
            }
            i++;
                
        }
    }
    
    int myAtoi(string s) {

        int result = 0;
        int i = 0;
        int size = s.length();
        string str;
        bool negative = false;
        
        CheckingTwoStep(negative, i, s, str);
        
        while(i < size)
        {          
            if(s[i] >= '0' && s[i] <= '9') // check it is digit
            {
                str.push_back(s[i]);
            }
            else{
                i = size;
            }
            
            i++;
        }
        
        
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '-' || str[i] == '+')
                continue;
            
            if(str[i] == '0')
            {
                str.erase(str.begin() + i);
                i--;
            }
            else{
                i = str.length();
            }
                
        }
        
        int finalSize = str.length();
        for(int i = finalSize, j = 0; i > 0; i--, j++)
        {
            if(str[i - 1] == '-' || str[i-1] == '+')
            {
                continue;
            }
                
            if(negative)
            {               
 
                if(j > 9)
                    return INT_MIN;
                
                int pop = -((int)(str[i - 1]) - 48);
                
                if(j == 9 && pop < -2)
                    return INT_MIN;
                
                int addedAmount = pop * pow(10, j);
                
                if(result < (INT_MIN - addedAmount))
                {
                    return INT_MIN;   
                }
                
                result += addedAmount;
            }
            else{
                
                if(j > 9)
                    return INT_MAX;
                
                int addedAmount = 0;
                int pop = ((int)(str[i - 1]) - 48);
                
                if(j == 9 && pop > 2)
                    return INT_MAX;
                
                addedAmount += pop * pow(10 , j);
                
                if(result > INT_MAX - addedAmount)
                {
                    return INT_MAX;   
                }
                
                result += addedAmount;
 
            }
        }
        
        return result;
        
    }
};