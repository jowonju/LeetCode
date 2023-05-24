class Solution {
public:

    string longestNiceSubstring(string s) {
        if(s.length() < 2) return "";

        unordered_set<char> us(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++)
        {
            if (us.find((char)toupper(s[i])) == end(us) || us.find((char)tolower(s[i])) == end(us)) {
                    string s1 = longestNiceSubstring(s.substr(0, i));
                    string s2 = longestNiceSubstring(s.substr(i + 1));
                    return s1.size() >= s2.size() ? s1 : s2;
            }
        }
        return s;
    }
};