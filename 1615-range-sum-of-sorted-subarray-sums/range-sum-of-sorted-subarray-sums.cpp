//Approach-2 (How to find sorted subarray sums using Heap)
//T.C : O(n^2 *n logn)
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P;
    int M = 1e9+7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P>, greater<P>> pq;
        
        //pair<sum, i> -> (subarray sum, till index i)
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int result = 0;

        for (int count = 1; count <= right; count++) {
            auto p = pq.top();
            pq.pop();
          
          	int sum=p.first;
            int idx=p.second;

            // If the current index is greater than or equal to left, add the
            // value to the answer.
            if (count >= left) {
                result = (result + sum) % M;
            }

            // If index is less than the last index, increment it and add its
            // value
            int new_idx=idx+1;
          	P new_pair;
          
            if (new_idx < n ) {
                new_pair.first=sum+nums[new_idx];
                new_pair.second=new_idx;
              
                pq.push(new_pair);
            }
        }
        return result;
    }
};