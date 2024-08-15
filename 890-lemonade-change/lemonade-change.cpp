class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int twenty=0;

        int n=bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            {
                five++;
                continue;
            }
            else if(bills[i]==10)
            {
                ten++;
                if(five==0)
                {
                    return false;
                } 
                five--;

            }
            else
            {
                twenty++;

                if(ten==0)
                {
                    if(five<3) return false;
                    else
                    {
                        five-=3;
                        continue;
                    }
                }
                else
                {
                    ten--;
                    if(five==0) return false;
                    five--;
                }
                
            }
        }
        return true;
    }
};