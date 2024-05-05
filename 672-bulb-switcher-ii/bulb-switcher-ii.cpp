class Solution {
public:
    int flipLights(int n, int presses) {  //DRY RUN AND OBSERVE THE OUTPUT
        if(presses==0) return 1;  //Edge case
        if(n==1) return 2;
        if(n==2)
        {
            if(presses==1)
            {
                return 3;
            }
            else return 4;
        }
        if(n>=3)
        {
            if(presses==1)
                return 4;
            if(presses==2)
                return 7;
            return 8;
        }

        return -1;
    }
};