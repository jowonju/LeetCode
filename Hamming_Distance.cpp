using namespace std;
#include<iostream>
#include<vector>
#include<bitset>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        bitset<32> x_bitset(x);
        bitset<32> y_bitset(y);
        
    	for(int i = 0; i < x_bitset.size(); i++)
    	{
            if (x_bitset[i] != y_bitset[i])
                result++;
    	}
    	
        return result;

        //version 2
        int result = 0;
        int compare = 1;

        while (compare <= (x ^ y))
        {
            int calculation = (x ^ y) & compare;

            if (calculation != 0)
                result++;
            
            if (compare == INT_MAX / 2 + 1)
            {
                break;
            }

            compare = compare << 1;
        }

        return result;

    }
};

int main()
{
    Solution sol;
    cout << sol.hammingDistance(1, 4) << endl;
    cout << sol.hammingDistance(3, 1) << endl;
}