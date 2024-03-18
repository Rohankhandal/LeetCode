class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int sum=0;
        int i=0;
        while(i<n)
        {
           if(i+1<n && s[i]=='I' && s[i+1]=='V')
           {
              
              sum+=4; 
              i=i+2;
              continue;
           }  
           else if(i+1<n && s[i]=='I' && s[i+1]=='X')
           {
            sum+=9;
            i=i+2;
              continue;
           } 
            else if(i+1<n && s[i]=='X' && s[i+1]=='L')
            {
                sum+=40;
                i=i+2;
              continue;
            } 
            else if(i+1<n && s[i]=='X' && s[i+1]=='C')
            {
                sum+=90;
                i=i+2;
              continue;
            } 
            else if(i+1<n && s[i]=='C' && s[i+1]=='D')
            {
                sum+=400;
                i=i+2;
              continue;
            } 
            else if(i+1<n && s[i]=='C' && s[i+1]=='M')
            {
                sum+=900;
                i=i+2;
              continue;
            } 
            else if(s[i]=='I') sum+=1;
            else if(s[i]=='V') sum+=5;
            else if(s[i]=='X') sum+=10;
            else if(s[i]=='L') sum+=50;
            else if(s[i]=='C') sum+=100;
             else if(s[i]=='D') sum+=500;
             else if(s[i]=='M') sum+=1000;
            i++;
           
        }
        return sum;
       
    }
};