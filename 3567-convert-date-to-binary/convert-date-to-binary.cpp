class Solution {
public:
    string integerToBinary(int num)
    {
        string s="";
        while(num)
        {
            s+=(num%2+'0');
            num/=2;
        }
        reverse(s.begin(),s.end());
        int i=0;
        while(s[i]==0)
        {
            i++;
        }
        return s.substr(i);
    }
    string convertDateToBinary(string date) {
        string ans="";
     
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8,2));
        cout<<year<<" "<<month<<" "<<day<<endl;

        string y=integerToBinary(year);
        string m=integerToBinary(month);
        string d=integerToBinary(day);
        ans=y+"-"+m+"-"+d;
        return ans;

    }
};