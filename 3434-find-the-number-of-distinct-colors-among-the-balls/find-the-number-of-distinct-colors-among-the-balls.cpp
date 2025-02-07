 // limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]
// limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]
// 1
// [[0,1],[1,4],[1,1],[1,4],[1,1]]
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>colMap;  //val=>col
        unordered_map<int,int>revMap;  //col=>valCnt  this will count colour
        int n=queries.size();
        vector<int>ans(n,0);
        int i=0;
        for(auto &it:queries)
        {
            int x=it[0];
            int y=it[1];
            int exY=colMap[x];
            if(revMap.find(exY)!=revMap.end())
            {
               revMap[exY]--;
                if(revMap[exY]==0) revMap.erase(exY);
              
            }
            revMap[y]++;
            colMap[x]=y;
            ans[i++]=revMap.size();
            
            
        }
        return ans;
    }
};