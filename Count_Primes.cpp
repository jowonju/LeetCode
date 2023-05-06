class Solution {
public:
    int countPrimes(int n) {
        std::vector<bool> vec(n, false);
        
        for(long i = 2; i < n; i++)
        {
            for(long j = i * i; j < n; j += i)
            {
                vec[j] = true;
            }
        }
        
        int result = 0;
        for(int i = 2; i < n; i++)
        {
            if(!vec[i])
                result++;
        }
        
        return result;
    }
};