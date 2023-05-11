class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
        {
            swap(s[i], s[j]);
        }

        //recursion
         void recursion(vector<char>& s, int pos)
        {
            if(pos == s.size() / 2)
            {
                return;
            }
            
            swap(s[pos], s[s.size() - pos - 1]);
            recursion(s, pos + 1);
            
        }
    
        void reverseString(vector<char>& s) {
            recursion(s, 0);
        }

        //recursion - using start and end for the function parameter
        void recursion(vector<char>& s, int start, int end)
        {
            if(start >= end)
            {
                return;
            }
            
            swap(s[start], s[end]);
            recursion(s, start + 1, end - 1);
            
        }
    
        void reverseString(vector<char>& s) {
            recursion(s, 0, s.size() - 1);
        }
    }
};