class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        
        while(n)
        {
            if(n % 2)
            {
                if(n > 0)
                {
                    result = x * result;
                }
                else
                {
                    result = result * 1/x;
                }
            }
            
            x = x * x;
            n /= 2;
        }
        return result;
    }
};