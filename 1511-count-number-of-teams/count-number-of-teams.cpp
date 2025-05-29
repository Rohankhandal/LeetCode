class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int ans=0;
        for(int i=0;i<n;i++){
            //left small 
            int leftSmall=0,rightGreater=0;
            for(int j=i-1;j>=0;j--){
                if(rating[j]<rating[i]) leftSmall++;
            }

            //right greater
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i]) rightGreater++;
            }

            ans+=(leftSmall*rightGreater);

            int leftGreater=0,rightSmall=0;
            //left greater
            for(int j=i-1;j>=0;j--){
                if(rating[j]>rating[i]) leftGreater++;
            }

            //right small
            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i]) rightSmall++;
            }

            ans+=(leftGreater*rightSmall);
        }
        return ans;

    }
};