class Solution {
public:
    void deleteNum(vector<int>&num,int n,int i,int k,int count)
    {
        if(num.size()==1)
        {
            return ;
        }
        if(count==k-1)
        {
            count=0;
            num.erase(num.begin()+i);
        }

        deleteNum(num,n,(i+1)%num.size(),k,count+1);
    }

    int findTheWinner(int n, int k) {
        if(k==1) return n;
        vector<int>num;
        for(int i=1;i<=n;i++)
        {
            num.push_back(i);
        }
        int count=0;
         deleteNum(num,n,0,k,count);
         return num[0];
    }
};