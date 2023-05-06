class Solution {
public:
    bool isPowerOfThree(int n) {
        
        //With loops
        if(n == 1)
            return true;
        
        if(n <= 0)
            return false;
        
        while(n > 0)
        {
            if((n / 3) == 1 && (n % 3) == 0)
                return true;
            
            if(n % 3 != 0)
                return false;
            
            n /= 3;
        
        }
        
        return false;

        //Better version with loop iteration
        if(n <= 1)
            return false;
        
        while(n % 3 == 0)
        {
            n /= 3;
        }
        
        return n == 1;

        //Using log function
        return n > 0 && 1162261467 % n == 0;
    }
};