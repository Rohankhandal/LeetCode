class Solution {
public:
bool check(string str,string pattern)
{
    int i=0;
    int cap=0;
    for(int j=0;j<str.size();j++)
    {
        if(i<pattern.size() && str[j]==pattern[i]) i++;
        else if(str[j]>='A' && str[j]<='Z') cap++;  //we count capital letter bcz if any another capital lettern found between patter
        //then answer is false;
        //e.g pattern="FB" and string="ForceFeedBack" answer is "false";
    }
    return (i==pattern.size() && cap==0);
}
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n=queries.size();
        vector<bool>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=check(queries[i],pattern);
        }
        return ans;
    }
};