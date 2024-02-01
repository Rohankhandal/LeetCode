class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>res;
        vector<pair<int,int>>vec;
        int m=mat.size();
         
        for(int i=0;i<m;i++)
        {

            int left=0;
            int right=mat[i].size()-1;
            int ans=-1;
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(mat[i][mid]==1)
                {
                    ans=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
                
            }
            int soldier=0;
            if(ans==-1)
            {
                ans=0;
            }
            else
            {
                soldier=ans+1;
                
            }
            vec.push_back({soldier,i});
            
        }
        for(auto it:vec)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        cout<<endl;
        sort(vec.begin(),vec.end());
        for(auto it:vec)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        for(int i=0;i<k;i++)
        {
            res.push_back(vec[i].second);
        }
        return res;

    }
};