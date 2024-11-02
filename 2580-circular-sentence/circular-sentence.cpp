//T.C:-O(N)
// class Solution {
// public:
//     bool isCircularSentence(string sentence) {
//         stringstream str(sentence);
//         string tokenStr;
//         char firstChar=sentence[0];
//         char last='0';
//         char start='0';
//         while(getline(str,tokenStr,' '))
//         {
//             if(last=='0')  // it means this is first string
//             {
//                 last=tokenStr[tokenStr.size()-1];
//                 continue;
//             }
//             start=tokenStr[0];

//             if(start!=last) return false;

//             last=tokenStr[tokenStr.size()-1];
//         }

//         if(last!=firstChar) return false;

//         return true;

//     }
// };




class Solution {
public:
    bool isCircularSentence(string sentence) {
        char firstChar=sentence[0];
        int n=sentence.size();
        char last='0';
        char start='0';
        char prev='0';
        for(int i=0;i<n;i++)
        {
            char ch=sentence[i];
            if(ch==' ')  //it means next char is first char of next string
            {
                start=sentence[i+1];
                last=sentence[i-1];
                if(start!=last) return false;

            }
            prev=ch;
        }

        if(firstChar!=prev) return false;

        return true;
    }
};