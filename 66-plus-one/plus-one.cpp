class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i =n-1; i>=0; i--){
            digits[i]++;
            if(digits[i]<10){
                return digits;  //if function don't return value here,means array size must be increase bcz new one digit is come
                //e.g arr=[9];  or arr=[9,9,9,9]
                // 9+1=10 so, arr=[1,0];
            }

            digits[i]=0;  
            
        }

        // digits.insert(digits.begin(),1);  //insert  a new digit in begin
                    //  or
        digits.push_back(0);
        digits[0]=1;
        return digits;
    }
};