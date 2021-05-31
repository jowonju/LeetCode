using namespace std;
#include<iostream>
#include<vector>

class Solution {
public:
    vector<int> countBits(int n) {
        int mask = 0b1;
        vector<int> result(n + 1, 0);
        int numberOfBits = 0;
        int container = 0;

        for (int i = 0; i < n + 1; i++)
        {
            container = i;
            while (container != 0)
            {
                if (container & mask == 1)
                    numberOfBits++;
                container >>= 1;
            }
            result[i] = numberOfBits;
            numberOfBits = 0;
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> test = sol.countBits(5);
    int size = test.size();
    
    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << test[i] << "]";
    }
    
}