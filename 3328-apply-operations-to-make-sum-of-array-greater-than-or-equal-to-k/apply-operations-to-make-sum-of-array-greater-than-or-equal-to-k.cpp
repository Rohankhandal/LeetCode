class Solution {      //T.C:-O(K)
public:
    int minOperations(int k) {
        //first we have to increment as possible ,then doubled
        if(k==1) return 0;

        int minOp=INT_MAX;
        for(int i=0;i<k;i++)
        {
            //i means adding is 'i' times
            int curValue=1+i;

            int div=(k+curValue-1)/curValue -1;   //ceil value of(k/currValue)-1
             
             minOp=min(minOp,i+div);
        }
        return minOp;
    }
};


//MAth solution:-
// https://www.youtube.com/watch?v=_5fM6Q_qZ4U&ab_channel=AryanMittal
// T.C;-O(1)
// class Solution {      //T.C:-O(K)
// public:
//     int minOperations(int k) {
        
//     }
// };






// class Solution {
// public:
//     int minOperations(int k) {
//         int mini=INT_MAX;
//         if(k==1) return 0;
//         // for(int i=1;i<=k;i++)
//         // {
//         //      int minOp=0;
//         //      minOp+=(k/i)+(k%i!=0);
//         //      mini=min(minOp,mini);
//         // }
//         for(int i=2;i<=k;i++)
//         {
//              int minOp=0;
//              minOp+=(i-1);
//              minOp=minOp+(k/i)-(k%i==0);
//              mini=min(minOp,mini);
//         }
//         return mini;
//     }
// };