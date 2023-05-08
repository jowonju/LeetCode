class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1)
            return false;
        
        map<char, int> dic = {{'(', 1},
                              {')', 2},
                              {'{', 3},
                              {'}', 4},
                              {'[', 5},
                              {']', 6}};
        
        int check = 0;
        stack<int> stk;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(stk.size() > 0 && stk.top() + 1 == dic[s[i]])
                stk.pop();
            
            if(dic[s[i]] % 2 == 1)
            {
                stk.push(dic[s[i]]);
                check++;
            }
            
        }
        
        if(stk.size() != 0 || check * 2 != s.length())
            return false;
        else
            return true;
      
    }
};