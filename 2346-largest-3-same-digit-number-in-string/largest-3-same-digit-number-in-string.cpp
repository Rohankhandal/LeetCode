class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="0";
        int n=num.size();
        for(int i=0;i<n-2;i++){
            char ch=num[i];
            if(num[i+1]==ch && num[i+2]==ch){
                int v=stoi(ans);
                int c=stoi(num.substr(i,3));
                // cout<<c<<endl;

                if(c>=v){
                    ans=num.substr(i,3);
                }
            }
        }
        return ans=="0"?"":ans;
    }
};