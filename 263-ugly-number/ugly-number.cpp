class Solution {
public:
    bool isUgly(int n) {
        //simply check whether n is divisble by 2,3,5 , if not return false
        //if divisible then at last if we have 1 then return true;
        //bcz 1 is also ugly number 1=2^0*3^0*5^0;

        while(n>1)
        {
            if(n%2==0)
            {
                n/=2;
            }
            else if(n%3==0)
            {
                n/=3;
            }
            else if(n%5==0)
            {
                n/=5;
            }
            else
            {
                return false;
            }
        }
        return (n==1);
    }
};