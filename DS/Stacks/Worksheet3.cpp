//Write the program to evaluate the expression using the stacks

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOperator(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluateExpression(const string& expr) {
    stack<int> values;
    stack<char> operators;

    int i = 0;
    while (i < expr.length()) {
        char c = expr[i];
        if (isspace(c)) {
            i++;
            continue;
        } 
        else if (isdigit(c)) {
            int num = c - '0';
            while (i + 1 < expr.length() && isdigit(expr[i + 1])) {
                num = num * 10 + (expr[i + 1] - '0');
                i++;
            }
            values.push(num);
        } 
        else if (c == '(') {
            operators.push(c);
        } 
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                values.push(applyOperator(a, b, op));
            }
            operators.pop();
        } 
        else {
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                char op = operators.top();
                operators.pop();
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                values.push(applyOperator(a, b, op));
            }
            operators.push(c);
        }
        i++;
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        int b = values.top();
        values.pop();
        int a = values.top();
        values.pop();
        values.push(applyOperator(a, b, op));
    }

    return values.top();
}

int main() {

    string expression = "(10+10)*(4-2)";
    int result = evaluateExpression(expression);
    cout << "Result: " << result << endl;
    return 0;

}
