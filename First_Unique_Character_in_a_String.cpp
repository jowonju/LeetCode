class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> um;
        for(auto str : s)
        {
            um[str]++;
        }
        
        bool flag = false;
        for(auto iter : um)
        {
            if(iter.second % 2 == 1) //if met the conditon even once, it means need to return the index
            {
                flag = true;
            }
        }
        
        if(!flag)
            return -1;
        else{
            int minimumIndex = s.size() - 1;
            bool check = false;
            for(auto iter : um)
            {
                if(iter.second ==  1)
                {
                    check = true;
                    int index = s.find(iter.first);
                    if(minimumIndex > index)
                        minimumIndex = index;
                }
            }
            
            if(!check)
                return -1;
            
            return minimumIndex;
        }
        
    }
};