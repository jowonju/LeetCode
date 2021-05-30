using namespace std;
#include<iostream>
#include<vector>

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int size = strs.size();
        int stringSize = 0;
        int numberOfDelete = 0;
        //brute force
        for (int stringIndex = 0; stringIndex < strs[0].size(); stringIndex++)
        {
            for (int i = 0; i < size; i++)
            {
                if (i == size - 1)
                    break;

                if (strs[i][stringIndex] > strs[i + 1][stringIndex])
                {
                    numberOfDelete++;
                    break;
                }
                
            }
        }
        return numberOfDelete;
    }
};

int main()
{
    vector<string> test = { "cba", "daf", "ghi" };
    vector<string> test1 = { "zyx", "wvu", "tsr" };

    Solution sol;
    std::cout<<sol.minDeletionSize(test)<<std::endl;
    std::cout<<sol.minDeletionSize(test1)<<std::endl;
}