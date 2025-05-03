class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        unordered_map<int,int>mp;
        int maxFreq=0;
        int maxEle=0;
        for(auto &it:tops)
        {
            mp[it]++;
            if(mp[it]>maxFreq)
            {
                maxFreq=mp[it];
                maxEle=it;
            }
        }
        int ans=-1;
        cout<<maxEle<<" "<<maxFreq<<endl;

        bool flag=true;
        int cnt1=0;
        for(int i=0;i<n;i++)
        {
            if(tops[i]!=maxEle)
            {
                if(bottoms[i]!=maxEle)
                {
                    flag=false;
                    break;
                }
                else{
                    // swap(tops[i],bottoms[i]);
                    cnt1++;
                }
            }
        }
        if(flag==false)
        {
            cout<<"H"<<endl;
            cnt1=INT_MAX;
        }

        mp.clear();
        maxFreq=0;
        maxEle=0;
        flag=true;
        for(auto &it:bottoms)
        {
            mp[it]++;
            if(mp[it]>maxFreq)
            {
                maxFreq=mp[it];
                maxEle=it;
            }
        }

       cout<<maxEle<<" "<<maxFreq<<endl;
        int cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(bottoms[i]!=maxEle)
            {
                if(tops[i]!=maxEle)
                {
                    flag=false;
                    break;
                }
                else{
                    cout<<"F"<<endl;
                    swap(tops[i],bottoms[i]);
                    cnt2++;
                }
            }
        }
        if(flag==false) cnt2=INT_MAX;
        ans=min(cnt1,cnt2);

        if(ans==INT_MAX) return -1;

        return ans;
    }
};