// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            
            if(isBadVersion(mid)){
                high = mid; 
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }

    int searching(int n)
    {
        if(isBadVersion(n) == false)
        {
            return n + 1;
        }
        
        return searching(n - 1);
    }
    
    int firstBadVersion(int n) {
        return searching(n);
    }
};