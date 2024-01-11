class Solution {
public:
    int getSum(int a, int b) {
        int sum=a;
        int carry=b;
        while(carry)   //loop is true until carry is zero
        {
            sum=a^b;
            carry=(a&b)<<1;  //right shift for add carry 

            a=sum;
            b=carry;
        }
        return sum;
    }
};