
//Give TLE
// class Solution {
// public:
//     long long solveMem(vector<pair<int, int>>& v, int i, int k, int mini, vector<vector<vector<long long>>>& dp) {
//         if (i >= v.size()) {
//             return (k == 0) ? 0 : INT_MIN;
//         }
//         if (k == 0) return 0;

//         if (dp[i][k][mini + 1] != -1) return dp[i][k][mini + 1];

//         long long take = 0;
//         if (mini == -1) {
//             take = (long long)v[i].first * v[i].second + solveMem(v, i + 1, k - 1, v[i].second, dp);
//         } else {
//             take = (long long)v[i].first * mini + solveMem(v, i + 1, k - 1, mini, dp);
//         }

//         long long noTake = solveMem(v, i + 1, k, mini, dp);

//         return dp[i][k][mini + 1] = max(take, noTake);
//     }

//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         vector<pair<int, int>> v;
//         for (int i = 0; i < nums1.size(); i++) {
//             v.push_back({nums1[i], nums2[i]});
//         }
//         auto comp = [&](pair<int, int>& p1, pair<int, int>& p2) {
//             return p1.second < p2.second;
//         };
//         sort(v.begin(), v.end(), comp);

//         int n = nums1.size();
        
//         int maxiEle=INT_MIN;
//         for(auto &it:nums2)
//         {
//             maxiEle=max(it,maxiEle);
//         }
//         vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(k + 1, vector<long long>(maxiEle + 2, -1)));

//         return solveMem(v, 0, k, -1, dp);
//     }
// };


//1) make vector pair 
//2) sort on the based on second number in descending order
//3) now take every element of nums2 as a minElement and get maximum sum and mutiply it .
class Solution {
public:

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < nums1.size(); i++) {
            v.push_back({nums1[i], nums2[i]});
        }
        auto comp = [&](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        sort(v.begin(), v.end(), comp);


        priority_queue<int,vector<int>,greater<int>>pq;

        long long  kSum=0;
        
        for(int i=0;i<=k-1;i++)  
        {
            pq.push(v[i].first);
            kSum+=v[i].first;
        }
        //we can't check for score before k-1 th element in nums2 bcz
        //before it we can't make a subsequence of size k as taking minimum element of nums2[i] ;i<k

        //bcz we can't take element from right side of nums1 [if we take then minimum element is change bcz we sorted nums2 in descending order]
        

        long long ans=kSum*v[k-1].second;

        for(int i=k;i<n;i++)  //take every element as minimum element and count score
        {
            //taking minimum as vec[i].second;
            kSum+=v[i].first-pq.top();

            pq.pop();
            pq.push(v[i].first);

            ans=max(ans,kSum*v[i].second);
        }

        return ans;
    }

};
