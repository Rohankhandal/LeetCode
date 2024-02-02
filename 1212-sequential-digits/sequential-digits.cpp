class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> a;

        for (int i = 1; i <= 9; ++i) {
            int num = i;
            int nextDigit = i + 1;

            while (num <= high && nextDigit <= 9) {
                num = num * 10 + nextDigit;
                if (low <= num && num <= high) a.push_back(num);
                ++nextDigit;
            }
        }

        sort(a.begin(), a.end());
        return a;
    }
};



//do at last when interviewer as to optimize
// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int>ans;
//         vector<int>allPossible={12,23,34,45,56,67,78,89,
//                             123,234,345,456,567,678,789,
//                             1234,2345,3456,4567,5678,6789,
//                             12345,23456,34567,45678,56789,
//                             123456,234567,345678,456789,
//                             1234567,2345678,3456789,
//                             12345678,23456789,
//                             123456789};
//         for(auto &it:allPossible)
//         {
//             if(it<low)
//             {
//                 continue;
//             }
//             if(it>high)
//             {
//                 break;
//             }
//             ans.push_back(it);
//         }
//         return ans;
//     }
// };