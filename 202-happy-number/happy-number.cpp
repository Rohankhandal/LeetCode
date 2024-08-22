class Solution {
public:
    bool isHappy(int n) {
        if(n==1) return true;
        while(n)
        {
            int num=n;
            int sum=0;
            while(num)
            {
                int rem=(num%10);
                sum+=rem*rem;
                num/=10;
            }
            n=sum;
            if(n<10)
            {
                if(n==1 || n==7) return true;
                break;
            } 
        }  

        return false;
    }
};