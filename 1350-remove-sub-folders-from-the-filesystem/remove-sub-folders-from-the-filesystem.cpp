class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;

        for (string& f : folder) {
            bool isSub = false;
            for (string& r : res) {
                if (f.size() > r.size() && f.substr(0, r.size()) == r && f[r.size()] == '/') {
                    isSub = true;
                    break;
                }
            }
            if (!isSub) res.push_back(f);
        }
        return res;
    }
};



// class Solution {
// public:
//     vector<string> removeSubfolders(vector<string>& folder) {
//         vector<string>ans;
//         sort(folder.begin(),folder.end());
//         int n=folder.size();
//         string prev="";
//         for(auto &s:folder)
//         {
//             if(prev=="")
//             {
//                 ans.push_back(s);
//                  prev=s+"/";
//             }
//             else if(s.find(prev)==0)
//             {
//                 continue;
//             }
//             else
//             {
//                 prev=s+"/";
//                 ans.push_back(s);
//             }
//         }
//         return ans;
//     }
// };