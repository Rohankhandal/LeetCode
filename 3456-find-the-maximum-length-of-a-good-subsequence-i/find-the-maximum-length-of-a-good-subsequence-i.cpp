/* Approach 1 : Recursion (Pick / Not Pick) + Memo
Parameters :
index = current index
prev = index of previous element in subsequence
count = number of exceptions remaining i.e. seq[i] != seq[i+1]
Memoizate using 3d dp array.
Time : O(n * n * k)     // no of dp states
Space : O(n * n * k)
*/

class Solution {
public:
    int dp[501][502][26];
    int f(int index, int prev, int count, vector<int>& nums) {
        // Base case : out of bound
        if(index == nums.size())
            return 0;

        // already calculated
        if(dp[index][prev + 1][count] != -1)   //bcz prev==-1 so -1 is not valid that's why prev+1
            return dp[index][prev + 1][count];

        // Pick 
        int pick = 0;
        // seq not yet started or current element is same as previous
        if(prev == -1 || (nums[index] == nums[prev]))
            pick = 1 + f(index + 1, index, count, nums);
        else if (count > 0)   // current element is different and we have exception count remaining
            pick = 1 + f(index + 1, index, count - 1, nums);

        // Not Pick
        int notPick = f(index + 1, prev, count, nums);
        
        return dp[index][prev + 1][count] = max(pick, notPick);
    }
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        // current index, prev index, count, nums
        return f(0, -1, k, nums);
    }
};