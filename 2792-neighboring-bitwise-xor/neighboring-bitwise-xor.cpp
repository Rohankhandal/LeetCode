class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

       int n=derived.size();
       int xorVal=0;
       for(auto &it:derived)
       {
        xorVal^=it;
       }
       return xorVal==0 ;
    }
};