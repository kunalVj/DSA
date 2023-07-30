class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0, profit=0, buy, sell;
        while(i < prices.size()-1){
            while(i < prices.size()-1 && prices[i+1] <= prices[i]){
                i++;
            }
            buy = prices[i];
            while(i < prices.size()-1 && prices[i+1] > prices[i]){
                i++;
            }
            sell = prices[i];
            profit += sell - buy;
        }
        return profit;
    }
};






/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        int ans = 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minprice){
                minprice = prices[i];
            }
            else if(prices[i] - minprice > maxprofit){
                maxprofit += prices[i] - minprice;
                //ans += maxprofit;
            }

            ans = maxprofit;
            
        }
        return ans;
    }
}; */