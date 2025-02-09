class Solution {
public:
    int romanToInt(string s) {
             
        int size = s.length();
        int result = 0;
        string copy = s;
        std::map<char, int> dictionary;
        
        dictionary.insert(std::pair<char,int>('I', 1));
        dictionary.insert(std::pair<char,int>('V', 5));
        dictionary.insert(std::pair<char,int>('X', 10));
        dictionary.insert(std::pair<char,int>('L', 50));
        dictionary.insert(std::pair<char,int>('C', 100));
        dictionary.insert(std::pair<char,int>('D', 500));
        dictionary.insert(std::pair<char,int>('M', 1000));
        

        for(int i = 0; i < size; i++)
        {
            if(i == size -1)
                continue;
            
            int compare1 = dictionary.find(copy[i])->second;
            int compare2 = dictionary.find(copy[i+1])->second;
            
            if (compare1 >= compare2)
            {
                result += compare1; 
            }
            else {
                int abs = std::abs(compare1 - compare2);
                result += abs;
                i++;
                if(i == size - 1)
                {
                    return result;
                }
            }
                    
        }
            
        result += dictionary.find(copy[size-1])->second;
        return result;

        int result = 0;
        map<char, int> dictionary = { { 'I' , 1 },
                                      { 'V' , 5 },
                                      { 'X' , 10 },
                                      { 'L' , 50 },
                                      { 'C' , 100 },
                                      { 'D' , 500 },
                                      { 'M' , 1000 } 
                                    };
        
        
        for(int i = 0 ; i < s.length(); i++)
        {
            if((dictionary[s[i + 1]] - dictionary[s[i]]) / 4 == dictionary[s[i]] || 
               (dictionary[s[i + 1]] - dictionary[s[i]]) / 9 == dictionary[s[i]])
            {
                result += dictionary[s[i + 1]] - dictionary[s[i]];
                i++;
            }
            else{
                result += dictionary[s[i]];
            }
        }
        
        return result;

        //Just subtract the current number if the next element is greater than the current element.
        for(int i = 0 ; i < s.length(); i++)
        {
            if(dictionary[s[i]] < dictionary[s[i+1]])
            {
                result -= dictionary[s[i]];
            }
            else{
                result += dictionary[s[i]];
            }
        }
        
        return result;
        

        
    }
};