class Solution {
public:
  string fractionAddition(string expression) {
    // Regular expression to match fractions
    regex pattern("([+-]?\\d+/\\d+)");
    smatch matches;
    auto it = sregex_iterator(expression.begin(), expression.end(), pattern);
    auto end = sregex_iterator();
    
    // Initial result is 0/1
    pair<int, int> result = {0, 1};

    while (it != end) {
        string fracStr = it->str();
        size_t slashPos = fracStr.find('/');
        int numerator = stoi(fracStr.substr(0, slashPos));
        int denominator = stoi(fracStr.substr(slashPos + 1));
        
        // Add or subtract the fraction from the result
        int resultNumerator = result.first * denominator + numerator * result.second;
        int resultDenominator = result.second * denominator;
        
        result = {resultNumerator, resultDenominator};

        ++it;
    }

    // Simplify the final result
    int num = result.first;
    int den = result.second;
    int commonDiv = gcd(num, den);
    
    result.first = num / commonDiv;
    result.second = den / commonDiv;
    
    // Ensure denominator is positive
    if (result.second < 0) {
        result.first = -result.first;
        result.second = -result.second;
    }
    
    // Return the result as a string
    return to_string(result.first) + "/" + to_string(result.second);
  }
    
};
