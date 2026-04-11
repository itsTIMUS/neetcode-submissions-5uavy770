class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int lastSmall=0;
        int profitMax=0;
        for(int i=0; i<n; i++){
            int profit= prices[i]-prices[lastSmall];
            if(prices[i]<prices[lastSmall]){
                lastSmall=i;
            }
            profitMax=max(profit,profitMax);
        }
        return profitMax;
    }
};
