class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange)
        {
            int drink=numBottles/numExchange;
            int rem=numBottles%numExchange;
            ans+=drink;
            
            numBottles=drink;
            numBottles+=rem;
        }
        return ans;
    }
};