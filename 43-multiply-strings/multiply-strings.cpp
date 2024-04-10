class Solution {
public:
    string multiply(string num1, string num2) {
        string s="";
        if((num1[0]=='-' || num2[0]=='-') && (num1[0]!='-' || num2[0]!='-'))
    {
        s+='-';
    }
 
    if(num1[0] == '-')
        num1 = num1.substr(1);
   
    if(num2[0] == '-')
        num2 = num2.substr(1);
        
       int len1 = num1.size();
       int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);
 
    // Below two indexes are used to find positions
    // in result. 
    int shift = 0; 
    int index = 0; 
     
    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        index = 0; 
         
        // Go from right to left in num2             
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position. 
            int sum = n1*n2 + result[shift + index] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[shift + index] = sum % 10;
 
            index++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[shift + index] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        shift++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";
 
    // generate the result string
    
     
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
    }
};