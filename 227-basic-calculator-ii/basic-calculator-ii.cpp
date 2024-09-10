class Solution {
public:
    int calculate(string s) {
        stack<int> operands; 
        int result = 0;    
        int num = 0;         
        char op = '+'; 
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            // If the character is a digit, form the current number
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // If the current character is an operator or we reach the end of the string
            if (!isdigit(c) && !isspace(c) || i == s.size() - 1) {
                if (op == '+') {
                    operands.push(num);  
                } else if (op == '-') {
                    operands.push(-num); 
                } else if (op == '*') {
                    int top = operands.top();
                    operands.pop();
                    operands.push(top * num); 
                } else if (op == '/') {
                    int top = operands.top();
                    operands.pop();
                    operands.push(top / num); 
                }
                
                // Update the operator and reset the number
                op = c;
                num = 0;
            }
        }

        while (!operands.empty()) {
            result += operands.top();
            operands.pop();
        }
        
        return result;
    }
};
