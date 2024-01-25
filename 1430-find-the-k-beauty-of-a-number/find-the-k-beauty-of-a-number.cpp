class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str=to_string(num);
        int count=str.size();
        int ans=0;
        for(int i=0;i<=str.size()-k;i++)
        {
            string temp=str.substr(i,k);
            int check=stoi(temp);
            cout<<check<<endl;
            if(check!=0 && num%check==0 )
            {
                ans++;
            }
        }
        return ans;
    }
};