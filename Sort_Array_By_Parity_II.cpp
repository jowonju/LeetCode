using namespace std;
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int size = nums.size();
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0 && nums[i] % 2 != 0) {
                while (true) {
                    if (j % 2 == 1 && nums[j] % 2 == 0)
                    {
                        break;
                    }
                    j++;
                }
                swap(nums[j], nums[i]);
            }
        }
        return nums;
    }
};

int main() {
    vector<int> test1{ 4,2,5,7 };
    vector<int> test2{ 3,1,4,2 };
    vector<int> test3{ 4,1,1,0,1,0 };
    Solution sol;
    
    vector<int> result1 = sol.sortArrayByParityII(test1);
    vector<int> result = sol.sortArrayByParityII(test3);

    for (int i = 0; i < test1.size(); i++)
    {
        cout << result1[i] << "\t";
    }
}