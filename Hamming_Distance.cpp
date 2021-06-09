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
    }
};

int main()
{
    Solution sol;
    cout << sol.hammingDistance(1, 4) << endl;
    cout << sol.hammingDistance(3, 1) << endl;
}