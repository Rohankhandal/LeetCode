class Solution {
public:
    int findComplement(int num) {
        int i=0;
        int ans=0;
       while(num)
       {
           if((num & 1)==0)
           {

               ans+=(1<<i);
           }
           i++;
           num>>=1;
       }
       return ans;
    }
};