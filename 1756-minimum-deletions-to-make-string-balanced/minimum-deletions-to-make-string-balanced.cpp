class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>A(n,0);
        vector<int>B(n,0);
        int countA=0,countB=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a') countA++;
            A[i]=countA;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='b') countB++;
            B[i]=countB;
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int sum=A[i]+B[i];
            maxi=max(maxi,sum);
        }
        return n-maxi;
    }
};