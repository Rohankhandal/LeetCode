// +,+=>+
// -,-=>+
// +,-=>-
// -,+=>-
// (means opposite sign , then neagtive)
// using bitwise operation
class Solution {
public:
    int divide(int dividend, int divisor) {
        if( dividend == INT_MIN && divisor == -1 )
            return INT_MAX;
        if(dividend == divisor) return 1;

        bool flag=(dividend>=0 == divisor>=0)?true:false;  //for sign in final answer
        long long dd=abs(dividend);
        long long dv=abs(divisor);

        unsigned int res=0;
        while(dd >= dv)
        {
            short count=0;
            while(dd > (dv << count+1)){    //MAIN POINT(DRY RUN)
                count++;
            }
            res+=(1<<count);  //MAIN POINT
            dd -= dv<<count;
        }
        return flag==true?res:-res;
        
    }
};


//using subtraction 

// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         if( dividend == INT_MIN && divisor == -1 )
//             return INT_MAX;
//        if( dividend == INT_MIN && divisor == 1 )
//             return INT_MIN;
//         bool flag=(dividend>=0 == divisor>=0)?true:false;
//         long long dd=abs(dividend);
//         long long dv=abs(divisor);
//         cout<<dd<<" "<<dv<<endl;
//         int cnt=0;
//         while(dd>=dv)
//         {
//             cnt++;
//             dd-=dv;
//         }
//         return flag==true?cnt:-cnt;
//     }
// };


// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         if( dividend == INT_MIN && divisor == -1 )
//             return INT_MAX;
//         long long int ans = dividend/divisor;
//         if(ans>INT_MAX)
//             return INT_MAX;
//         if(ans<INT_MIN)
//             return INT_MIN;
//         return ans;
//     }
// };