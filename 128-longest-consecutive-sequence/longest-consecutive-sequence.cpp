// T.C:-O(N+N)
// S.C:-O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        set<int>mp;
        for(auto &it:nums)
        {
            mp.insert(it);
        }   
        int temp=*mp.begin();
        int num=temp;
        int count=1;
        int ans=INT_MIN;
        for(auto &val:mp)
        {
            if(val==temp) continue;
            if(val==num+1)
            {
                count++;
            }
            else{
                 ans=max(ans,count);
                count=1;
            }
            num=val;
        }
       ans=max(ans,count);  //if else condition is not excuted
        return  ans;
    }
};


//Optimal SOlution-1
// int longestSuccessiveElements(vector<int>&a) {
//     int n = a.size();
//     if (n == 0) return 0;

//     //sort the array:
//     sort(a.begin(), a.end());
//     int lastSmaller = INT_MIN;
//     int cnt = 0;
//     int longest = 1;

//     //find longest sequence:
//     for (int i = 0; i < n; i++) {
//         if (a[i] - 1 == lastSmaller) {
//             //a[i] is the next element of the
//             //current sequence.
//             cnt += 1;
//             lastSmaller = a[i];
//         }
//         else if (a[i] != lastSmaller) {
//             cnt = 1;
//             lastSmaller = a[i];
//         }
//         longest = max(longest, cnt);
//     }
//     return longest;

// }











// Brute Approach
// bool linearSearch(vector<int>&a, int num) {
//     int n = a.size(); //size of array
//     for (int i = 0; i < n; i++) {
//         if (a[i] == num)
//             return true;
//     }
//     return false;
// }
// int longestSuccessiveElements(vector<int>&a) {
//     int n = a.size(); //size of array
//     int longest = 1;
//     //pick a element and search for its
//     //consecutive numbers:
//     for (int i = 0; i < n; i++) {
//         int x = a[i];
//         int cnt = 1;
//         //search for consecutive numbers
//         //using linear search:
//         while (linearSearch(a, x + 1) == true) {
//             x += 1;
//             cnt += 1;
//         }

//         longest = max(longest, cnt);
//     }
//     return longest;
// }