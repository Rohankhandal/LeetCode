
//Normal Method
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int fMin=INT_MAX;
        int sMin=INT_MAX;
        for(auto x:prices){
            if(x<fMin)
            {
                sMin=fMin;
                fMin=x;
            }
            else
            {
                sMin=min(sMin,x);
            }
        }
        int leftOver=money-fMin-sMin;
        return leftOver>=0?leftOver:money;
    }
};