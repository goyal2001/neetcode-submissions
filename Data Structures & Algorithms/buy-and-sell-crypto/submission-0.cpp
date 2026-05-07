class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProf = 0;
        for(int i=1;i<prices.size();i++){
           if(minPrice>prices[i]){
            minPrice = prices[i];
           }
           else{
            maxProf = max(maxProf,prices[i]-minPrice);
           }
        }
        return maxProf;
    }
};
