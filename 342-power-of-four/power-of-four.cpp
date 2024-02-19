class Solution {
public:
    bool isPowerOfFour(int n) {
          int low = 0;
        int high = 1e9;
        while(low<=high){
            int mid = (low+high)>>1;
            if(pow(4,mid)==n) return true;
            else if(pow(4,mid)>n) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if(n<=0) return false;
//         if(n==1) return true;

//         return (n%4==0) && isPowerOfFour(n/4);
//     }
// };