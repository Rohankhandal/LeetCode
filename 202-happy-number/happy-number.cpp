/*

    Time Complexity : O(logN) where N is the number.

    Space Complexity : O(logN), Hash Table(unordered_set(set)) space.

    Solved using Math + Hash Table.

*/
class Solution {
public:

    bool isHappy(int n) {
        set<int>st;
        while(true)
        {
            int sum=0;
            while(n)
            {
                int rem=n%10;
                sum+=pow(rem,2);
                n/=10;
            }
            // if sum is 1, return true;
            if(sum==1)
            {
                return true;
            }
            //else , the new number is the current sum
            n=sum;
            
    //check if we have already encountered that number
            if(st.count(n))
                return false;

            st.insert(n);
        }
        return false;
    }
};

//Simple solution:-
// class Solution {
// public:
//     long long computeSum(int n){
//         long long sum=0;
//         while(n>0){
//             int last=n%10;
//             sum+=last*last;
//             n/=10;
//         }
//     return sum;
//     }

//     bool isHappy(int n) {
//         if(n<10){
//             if(n==1 or n==7) return true;
//         else return false;
//         }
//     long long sum=computeSum(n);
//     return isHappy(sum);
//     }
// };