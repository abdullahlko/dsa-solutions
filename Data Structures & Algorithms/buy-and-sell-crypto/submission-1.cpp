class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            int currentPrice = prices[i];
            int profit = currentPrice - minPrice;
            maxProfit = max(maxProfit, profit);
            minPrice = min(minPrice, currentPrice);
        }
        return maxProfit;
    }
};