class Solution {
public:
    string greatestLetter(string str) {

    unordered_set<char> s;
    string Ans = "";
    char temp = ' ';
    
    for (int i = 0; i < str.size(); i++)  //first store lowercase letter in set
        if (str[i] >= 'a' && str[i] <= 'z')
            s.insert(str[i]);

    for (int i = 0; i < str.size(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')  //traverse on upper case letter ,and check there
            if (s.find(str[i] + 32) != s.end())
                temp = max(temp, str[i]);
            
    if(temp!=' ')
        Ans+=temp;
    
    return Ans;

    }
};