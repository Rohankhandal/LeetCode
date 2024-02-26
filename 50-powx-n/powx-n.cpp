class Solution {
public:
double power(double x,int n)
{
    double ans=1;
    while(n)
    {
        if(n&1)
        {
            ans*=x;
        }
        x=(x*x);
        n=n/2;
    }
    cout<<ans<<endl;
    return ans;
}
    double myPow(double x, int n) {
        int sign=1;
        if(n<0)
        {
            sign=-1;
            // n=-n;
        }
        double p=power(x,n);
        return sign==1?p:(1.0/p);
    }
};