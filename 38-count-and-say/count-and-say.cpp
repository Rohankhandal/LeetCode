class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";

        }
        string say=countAndSay(n-1);
        string result="";
        //now process that say string
        for(int i=0;i<say.length();i++)
        {
            char ch=say[i];
            int count=1;
            while(i<say.size()-1 && say[i]==say[i+1])
            {
                count++;
                i++;
            }
            result+=to_string(count)+string(1,ch);   //IMP we convert ch into string through string(1,ch) gives length 1 string which is ch.
        }
        return result;
    }
};