class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0; int right = 1;
        int maxprofit = 0;
        for(right; right < prices.size(); right++){
            if(prices[left] < prices[right]) {
                int profit = prices[right] - prices[left];
                maxprofit = max(maxprofit, profit);
            } else {
                left = right;
            }
        }
        return maxprofit;
    }
};
