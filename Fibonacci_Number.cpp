class Solution {
public:
    //recursion
    int fib(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        
        return fib(n - 1) + fib(n - 2);
    }

    //recursion with memoization
    int fibonacci(int n, vector<int>& vec)
    {
        if(vec[n] != 0)
            return vec[n];
        
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        
        vec[n] = fibonacci(n-1, vec) + fibonacci(n-2, vec);
        
        return vec[n];
    }
    
    int fib(int n) {
        vector<int> vec(n + 1);
        
        return fibonacci(n, vec);
    }
};