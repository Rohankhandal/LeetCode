class Solution {
public:
void phoneNumber(vector<string>&ans,vector<string>&matching,string output,int i,string digits)
{
    if(i>=digits.size())
    {
        ans.push_back(output);
        return ;
    }
    int intDigit=digits[i]-'0';
    string temp=matching[intDigit];
    for(int j=0;j<temp.size();j++)
    {
        char ch=temp[j];
        phoneNumber(ans,matching,output+ch,i+1,digits);

    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0)
        {
            return ans;
        }
        vector<string>matching(10);
        matching[2]="abc";
        matching[3]="def";
        matching[4]="ghi";
        matching[5]="jkl";
        matching[6]="mno";
        matching[7]="pqrs";
        matching[8]="tuv";
        matching[9]="wxyz";

        int i=0;
        string output="";
        phoneNumber(ans,matching,output,i,digits);
        return ans;
        
        }
    
};
