class Solution {
public:
    long long computeSum(int n){
        long long sum=0;
        while(n>0){
            int last=n%10;
            sum+=last*last;
            n/=10;
        }
    return sum;
    }

    bool isHappy(int n) {
        if(n<10){
            if(n==1 or n==7) return true;
        else return false;
        }
    long long sum=computeSum(n);
    return isHappy(sum);
    }
};