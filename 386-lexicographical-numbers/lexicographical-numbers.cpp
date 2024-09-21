class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(i);
        }
        auto comp=[&](int &a,int&b)
        {
            string x=to_string(a);
            string y=to_string(b);

            return x<y;
        };

        sort(ans.begin(),ans.end(),comp);

        return ans;
    }
};