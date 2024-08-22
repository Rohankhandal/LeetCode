//T.c:-O(log(num))
// class Solution {
// public:
//     int findComplement(int num) {
//         int i=0;
//         int ans=0;
//        while(num)
//        {
//            if((num & 1)==0)
//            {
//                ans+=(1<<i);
//            }
//            i++;
//            num>>=1;
//        }
//        return ans;
//     }
// };

class Solution {
public:
    int findComplement(int num) {
        int count=(int)(log2(num))+1;
        long long mask=(1L<<count)-1;

        long long ans=num^mask;
        return ans;
    }
};