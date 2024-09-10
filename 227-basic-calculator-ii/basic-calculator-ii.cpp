

class Solution {
public:
    int calculate(string s) {
        stack<int> operands;  // Stack to store intermediate results
        int result = 0;       // Final result
        int num = 0;          // Current number being processed
        char op = '+';        // Current operator, initialized to '+'
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            // If the character is a digit, form the current number
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // If the current character is an operator or we reach the end of the string
            if (!isdigit(c) && !isspace(c) || i == s.size() - 1) {
                if (op == '+') {
                    operands.push(num);  // Push the current number to the stack
                } else if (op == '-') {
                    operands.push(-num); // Push the negative number to the stack
                } else if (op == '*') {
                    int top = operands.top();
                    operands.pop();
                    operands.push(top * num);  // Multiply the top number with the current number
                } else if (op == '/') {
                    int top = operands.top();
                    operands.pop();
                    operands.push(top / num);  // Divide the top number by the current number
                }
                
                // Update the operator and reset the number
                op = c;
                num = 0;
            }
        }

        // Sum up all values in the stack to get the final result
        while (!operands.empty()) {
            result += operands.top();
            operands.pop();
        }
        
        return result;
    }
};
