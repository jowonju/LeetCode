class Solution {
public:
    bool isPalindrome(string s) {
        
        string container;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= 65 && s[i] <= 90) // if a char is a upper alphabet, convert to lower alphabet
            {
                container.push_back(s[i] + 32);
            }    
            if(s[i] >= 48 && s[i] <= 57) // if a char is a number
            {
                container.push_back(s[i]);
            }  
            else if(s[i] >= 97 && s[i] <= 122){ // non-alphabet -> delete
                container.push_back(s[i]);
            }
        }
        
        string str(container);
        reverse(str.begin(), str.end());

        for(int i = 0; i < container.length(); i++)
        {
            if(str[i] != container[i])
                return false;
        }
            
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z') // if a char is a upper alphabet, convert to lower alphabet
            {
                s[i] += 32;
            }    
            else if(s[i] < 'a' || s[i] > 'z') { // non-alphabet -> delete
                
                if(s[i] >= '0' && s[i] <= '9')
                    continue;
                
                s.erase(s.begin() + i);
                i--;
            }
        }
        
        int size = s.length() / 2;
        for(int i = 0, j = s.length() - 1; i < size; i++, j--)
        {
            if(s[i] != s[j])
                return false;
        }
            
        return true;
    }
};