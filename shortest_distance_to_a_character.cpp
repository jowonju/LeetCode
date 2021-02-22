#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int distance = 0;
        int compare = 0;
        int indicatorSize = 0;
        int indi = 0;
        vector<int> result;
        vector<int> indicator;
        int stringSize = s.size();

        for (int i = 0; i < stringSize; i++)
        {
            if (s[i] == c)
            {
                indicator.push_back(i);
            }
        }
        indicatorSize = indicator.size();

        for (int i = 0; i < stringSize; i++)
        {
            if (i > indicator[indi])
            {
                if (indicatorSize == 1)
                {
                    indi = 0;
                }
                else {
                    indi++;
                    if (indicatorSize == indi)
                        indi--;
                }
            }
            distance = abs(i - indicator[indi]);

            if (indi != 0)
            {
                compare = abs(i - indicator[--indi]);
                indi++;
                if (distance > compare)
                {
                    distance = compare;
                }
            }
            result.push_back(distance);
        }
        return result;
    }
};

int main() {
    Solution sol;

    string s_t = "loveleetcode";
    char c_t = 'e';
    

    string s_t1 = "abba";
    char c_t1 = 'b';

    //vector<int> test = sol.shortestToChar(s_t, c_t);
    vector<int> test = sol.shortestToChar(s_t1, c_t1);

    std::cout << "[ ";
    
    for (int i = 0; i < test.size(); i++)
        std::cout << test[i] << ", ";
    
    std::cout << ']' << std::endl;
    
}