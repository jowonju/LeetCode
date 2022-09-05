class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> u_map1;
        unordered_map<char, int> u_map2;
        
        for(char str : s)
        {
            u_map1[str]++;
        }
        
        for(char str : t)
        {
            u_map2[str]++;
        }
        
        if(u_map1.size() != u_map2.size())
            return false;
            
        for(auto iter = u_map1.begin(); iter != u_map1.end(); iter++)
        {
            if(iter->second != u_map2[iter->first])
                return false;
        }
        
        return true;
    }
};