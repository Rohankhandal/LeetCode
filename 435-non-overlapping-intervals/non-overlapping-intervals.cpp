//https://leetcode.com/problems/non-overlapping-intervals/description/comments/1576818
//Three ways of collesion -> 
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int n=intervals.size();
      sort(intervals.begin(),intervals.end());
      int end=intervals[0][1];
      int overlap=0;
      for(int i=1;i<n;i++)
      {
        int s=intervals[i][0];
        int e=intervals[i][1];

        if(s<end){
            overlap++;
            end=min(e,end);
        }
        else 
        {
            end=e;
        }
      }  
      return overlap;
    }
};