class Solution {
public:
    int kthFactor(int n, int k) {
        // Answer must be in [1,n] ,so e.g 12 =>factors 1,2,3,4,6,12
        // sqrt(n)=> 3 , so we can loop on 1 to 3 then go back reverse from 3 to 1 to get 4,6,12 as[n/*ii]
        int i=0;
        for(i=1;i*i<=n;i++)
        {
            if(n%i==0 && --k==0)
            {
                cout<<"INsdie";
                return i;
            }
        }
        int m=--i;
        for(;m>=1;m--)
        {
            if(m*m==n) continue;   //special case bcz m*m case solved in above code e.g:-36
            if(n%m==0 && --k==0)
            {
                return (n/m);
            }
        }
        return -1;
    }
};

//O(N)
// class Solution {
// public:
//     int kthFactor(int n, int k) {
//         int cnt=0;
//         // int ans=0;
//         for(int i=1;i<=n;i++)
//         {
//             if(n%i==0)
//             {
//                 cnt++;
//                 if(cnt==k)
//                 {
//                     return i;
//                 }
//             }
//         }
//         return -1;
//     }
// };