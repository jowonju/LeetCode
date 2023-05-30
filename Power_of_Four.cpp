class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<4){
            if(n==1) return true;
            else return false;
        }
        else{                    
            if(n%4==0)
            {
                return isPowerOfFour(n>>2);
            }
            else
            {
                return false;
            } 
        }
    }
};