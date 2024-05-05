class Solution {
public:
bool isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
          c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
bool isWord(string s)
{
    for(auto  &it:s)
    {
        if(!isdigit(it) && !isalpha(it)) return false;
    }
    return true;
}
    bool isValid(string word) {
        int n=word.size();
        bool flag=isWord(word);
        if(flag==false) return false; 
        if(n>=3)
        {
            bool Vowel=false;
            bool Consonant=false;
            for(auto &it:word)
            {
               
                if(isdigit(it)|| isalpha(it))
                {
                    if(!isdigit(it) && isVowel(it))
                    {
                        Vowel=true;
                    }
                    else if(!isdigit(it))
                    {
                        Consonant=true;
                    }
                    if(Vowel && Consonant) return true;
                }
                else return false;
            }
        }
        else return false;

        return false;
    }
};