class Solution {
public:
    int smallestNumber(int n) {
        
        for(int i=n;i<=2000;i++)
        {
            int zero=0,one=0;
            int num=i;
            while(num)
            {
                if(num&1) one++;
                else zero++;

                num>>=1;
            }
            if(zero==0) return i;
        }
        return 0;
    }
};