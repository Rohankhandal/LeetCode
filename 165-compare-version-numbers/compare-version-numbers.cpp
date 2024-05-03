class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        
        int n1=ver1.size();
        int n2=ver2.size();
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            long long num1=0,num2=0;
            while(i<n1 && ver1[i]!='.')
            {
                num1=num1*10+(ver1[i]-'0');
                i++;
            }
            while(j<n2&&ver2[j]!='.')
            {
                num2=num2*10+(ver2[j]-'0');
                j++;
            }
            if(num1>num2)
            {
                return 1;
            }
            else if(num1<num2)
            {
                return -1;
            }
            i++;
            j++;
        }
        while(i<n1)
        {
            long long num1=0;
           while(i<n1 && ver1[i]!='.')
            {
                num1=num1*10+(ver1[i]-'0');
                i++;
            }
            if(num1!=0) return 1;
            i++;
        }
        while(j<n2)
        {
            long long num2=0;
           while(j<n2&&ver2[j]!='.')
            {
                num2=num2*10+(ver2[j]-'0');
                j++;
            }
            if(num2!=0) return -1;
            j++;
        }
        return 0;
    }
};