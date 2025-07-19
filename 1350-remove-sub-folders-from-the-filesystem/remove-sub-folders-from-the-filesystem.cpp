class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        sort(folder.begin(),folder.end());
        int n=folder.size();
        string prev="";
        for(auto &s:folder)
        {
            if(prev=="")
            {
                ans.push_back(s);
                 prev=s+"/";
            }
            else if(s.find(prev)==0)
            {
                continue;
            }
            else
            {
                prev=s+"/";
                ans.push_back(s);
            }
        }
        return ans;
    }
};