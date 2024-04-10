class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int i=0; //deck
        int j=0; //ans
        int n=deck.size();
        vector<int>ans(n,0);
        sort(deck.begin(),deck.end());
        bool skip=true;
        while(i<n)
        {
            if(ans[j]==0)  //if answer is not inserted in vector ans
            {
                if(skip)
                {
                    ans[j]=deck[i];
                    i++;
                }
                skip=!skip;
            }


            j=(j+1)%n;
        }
        return ans;
    }
};