class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);

        int sz=s.size();
        bool flag=false;
        int idx=0;
        for(int i=sz-2;i>=0;i--)
        {
            if(s[i]<s[i+1])
            {
                flag=true;
                idx=i;
                break;
            }
        }
        if(!flag) return -1;
      
        //find next greater element from right
        int j=0;
        for(j=sz-1;j>idx;j--)
        {
            if(s[j]>s[idx])
            {
                break;
            }
        }
        swap(s[idx],s[j]);
        reverse(s.begin()+idx+1,s.end());

        long long temp=stoll(s);

        if(temp>INT_MAX) return -1;
        else return temp;
    }
};