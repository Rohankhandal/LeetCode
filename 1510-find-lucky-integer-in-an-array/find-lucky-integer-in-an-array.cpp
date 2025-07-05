


class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501]={0}, xMax=0;
        for(int x: arr){
            freq[x]++;
            xMax=max(x, xMax);
        }
        for(int x=xMax; x>=1; x--){
            if (freq[x]==x) return x;
        }
        return -1;
    }
};
// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         int ans=-1;
//         unordered_map<int,int>mp;
//         for(auto &it:arr)
//         {
//             mp[it]++;
//         }

//         for(auto &it:mp)
//         {
//             if(it.first==it.second)
//             {
//                 if(ans<it.first)
//                 {
//                     ans=it.first;
//                 }
//             }
//         }
//         return ans;
//     }
// };