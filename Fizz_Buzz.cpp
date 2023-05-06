class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vec(n);
        for(int i = 0, j = 1; i < n; i++, j++)
        {
            if(j % 15 == 0)
            {
                vec[i] = "FizzBuzz";
            }
            else if(j % 3  == 0)
            {
                vec[i] = "Fizz";
            }
            else if(j % 5 == 0)
            {
                vec[i] = "Buzz";
            }
            else {
                vec[i] = to_string(j);
            }
        }
        return vec;
    }
};