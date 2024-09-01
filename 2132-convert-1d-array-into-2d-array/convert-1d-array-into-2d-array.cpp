class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        int size=original.size();

        int count=0;
        while(count<size)
        {
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                if(count<size)
                {
                    temp.push_back(original[count]);
                    count++;
                }
                else break;
                
            }
            ans.push_back(temp);
        }
        vector<vector<int>>emptyArr;
        return (ans.size()==m&ans[0].size()==n)?ans:emptyArr;
    }
};