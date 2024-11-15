class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v(n,1);
        for(int i=0;i<n;i++)
        {
            v[i]=i+1;
            cout<<v[i]<<endl;
        }
        int i=0;
        while(v.size()>1)
        {
            int lossIdx=(i+k-1)%v.size();
            i=lossIdx;
            // cout<<lossIdx<<" "<<v[lossIdx]<<endl;;
            v.erase(v.begin()+lossIdx);
           
        }
        return  v[0];
    }
};