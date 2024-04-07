class Solution {
public:
    string getSmallestString(string str, int k) {
        int size = str.size();
        string result = "";
        for(int i = 0; i < size; i++) {
            //left side distance str[i]-'a' and right side distance(26-(str[i]-'a'))
            int action = min(str[i] - 'a', 26 - (str[i] - 'a'));
            
            if(k >= action) {
                result += 'a';
                k -= action;
            }
            else {
                result += char((int)str[i] - k);
                k = 0;
            }
        }
        return result;
    }
};