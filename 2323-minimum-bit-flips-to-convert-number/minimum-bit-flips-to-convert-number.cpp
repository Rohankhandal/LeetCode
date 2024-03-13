class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n=start^goal;
        int count=0;
        while(n){
           count+=n&1;
            n=n>>1;
        }
        return count;
    }
};

// First MEthod
// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         int cnt=0;
//         int s,g;
//         while(goal || start)
//         {
//              s=start&1;
//              g=goal&1;
//              //cout<<s<<" "<<g<<endl;
//              if(s!=g) cnt++;
//              start=start>>1;
//              goal=goal>>1;
//         }
//         return cnt;
//     }
// };