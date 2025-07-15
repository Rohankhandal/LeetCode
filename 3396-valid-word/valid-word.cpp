class Solution {
public:
    bool isVowel(char ch) {
        ch = std::tolower(ch); // Convert to lowercase for case-insensitivity
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    bool isValid(string word) {
        // int charCnt=0;
        int vowel=0;
        int consnant=0;
        if(word.size()<3) return false; 
        for(auto &ch:word){
            if(isalnum(ch))
            {
                if(!isdigit(ch))
                {
                    // charCnt++;
                    if(isVowel(ch)) vowel++;
                    else consnant++;
                }
            }
            else return false;
        }

        return (vowel>=1 && consnant>=1) && true;
    }
};