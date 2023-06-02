class Solution {
public:
    //bottom-up(tabulation)
    int tribonacci(int n) {
        vector<int> vec(n+3);
        
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 1;

        for(int i = 3; i <= n; i++)
        {
            vec[i] = vec[i-3] + vec[i-2] + vec[i-1];
        }

        return vec[n];
    }

    //top-down(memoization)
    int tribonacci(int n, vector<int>& vec)
    {
        if(vec[n] != -1) return vec[n];

        vec[n] = tribonacci(n-3, vec) + tribonacci(n-2, vec) + tribonacci(n-1, vec);
        return vec[n];
    }

    int tribonacci(int n) {
        vector<int> vec(n+3, -1);

        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 1;
        
        return tribonacci(n, vec);
    }
};