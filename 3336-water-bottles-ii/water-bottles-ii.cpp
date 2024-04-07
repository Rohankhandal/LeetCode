class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total=0;
        int empty=0;
        while(numBottles)
        {
            total+=numBottles;
            empty+=numBottles;
            numBottles=0;
            while(empty>=numExchange)
            {
                empty-=numExchange;
                numExchange++;
                numBottles++;
            }
        }
        return total;
    }
};