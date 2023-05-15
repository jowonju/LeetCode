class Solution {
public:
    //top-bottom
    int CS(int n, std::vector<int>& vec)
    {
        if(vec[n] != 0)
            return vec[n];
        else if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        
        return vec[n] = CS(n-1, vec) + CS(n-2,vec);
        
    }
    
    int climbStairs(int n) {
        vector<int> vec(n+1);
        return CS(n, vec);
    }


    //top-bottom memoization
    int find(int* arr, int n)
    {
        if(arr[n] != -1)
            return arr[n];
        
        arr[n] = find(arr, n - 1) + find(arr, n - 2);
        
        return arr[n];    
    }
    
    int climbStairs(int n) {
        
        int* iarr = new int [n + 1];
    
        memset(iarr, -1, sizeof(*iarr) * (n+1));
    
        iarr[0] = 1;
        iarr[1] = 1;
        
        return find(iarr, n);     
    }

    int climbStairs(int n) {

        //bottom-top tabulation
        vector<int> vec(n + 1);
        vec[0] = 1;
        vec[1] = 1;
        
        for(int i = 2; i < n + 1; i++)
        {
            vec[i] = vec[i - 1] + vec[i - 2];
        }
        
        return vec[n];
    }
};