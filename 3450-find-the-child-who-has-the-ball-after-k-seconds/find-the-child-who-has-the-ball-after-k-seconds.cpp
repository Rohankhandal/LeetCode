class Solution {
public:
    int numberOfChild(int n, int k) {
       n--;
       int round=k/n;
       int goTo=k%n;
       if(round%2==0)  //we go from left side;
       {
        return goTo;
       }
       else
       {
        return n-goTo;
       }
    }
};