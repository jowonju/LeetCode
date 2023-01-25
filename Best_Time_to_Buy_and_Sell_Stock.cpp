class Solution {
public:
    //time complexity:O(N), space complexity:O(1)
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int mp = 0;
        
        for(int i = 1; i < prices.size(); i++){
            if(buy > prices[i])
                buy = prices[i];
            else if(mp < prices[i] - buy)
            {
                mp = prices[i] - buy;
            }
        }
        
        return mp;
    }
};