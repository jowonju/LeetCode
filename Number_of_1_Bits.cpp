#include<iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {

        uint32_t checkNumber = 1;
        int result = 0;
        
        for (int i = 0; i < 32; i++)
        {
            if ((n & checkNumber) != 0) {
                result++;
            }
            checkNumber <<= 1;
        }
        return result;
    }
};

int main() {
    
    int result = 0;
    Solution sol;
    uint32_t number;

    std::cout << "Input: n = ";
    std::cin >> number;

    result = sol.hammingWeight(number);

    std::cout << "Output: " << result << std::endl;
    std::cout << "Explanation: The input binary string" << number << " has a total of "
        << result << " '1' bits." << std::endl;
}