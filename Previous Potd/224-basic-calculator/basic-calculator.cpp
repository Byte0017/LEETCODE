class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        int result = 0;
        int sign = 1; 
        int n = s.size(); 
      
        for (int i = 0; i < n; ++i) {
            // If the character is a digit, it could be part of a multi-digit number.
            if (isdigit(s[i])) {
                int num = 0;
                // Construct the number from the subsequent digits
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                result += sign * num;
                --i;
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                // When encountering '(', push the current result and sign onto the stack
                operands.push(result);
                operands.push(sign);
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                // Ending a sub-expression, pop sign from stack and multiply it with the current result
                result *= operands.top();
                operands.pop();
                result += operands.top();
                operands.pop();
            }
            
        }
        return result;
    }
};