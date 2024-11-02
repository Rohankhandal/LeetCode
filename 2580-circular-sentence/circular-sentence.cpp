class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream str(sentence);
        string tokenStr;
        char firstChar=sentence[0];
        char last='0';
        char start='0';
        while(getline(str,tokenStr,' '))
        {
            if(last=='0')  // it means this is first string
            {
                last=tokenStr[tokenStr.size()-1];
                continue;
            }
            start=tokenStr[0];

            if(start!=last) return false;

            last=tokenStr[tokenStr.size()-1];
        }

        if(last!=firstChar) return false;

        return true;

    }
};