#include <iostream>
#include <stack>
#include <string>

bool checkParentheses(const std::string& input);

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (checkParentheses(input)) {
        std::cout << "The string contains a matching number of parentheses." << std::endl;
    }
    else {
        std::cout << "The string does not contain a matching number of parentheses." << std::endl;
    }

    return 0;
}

bool checkParentheses(const std::string& input)
{
    std::stack<char> parentheses;
    std::stack<int> numb;

    for (char c : input) {
        if (c == '(') {
            parentheses.push(c);
        }
        else if (c == ')') {
            if (parentheses.empty()) {
                return false;
            }
            else {
                parentheses.pop();
            }
        }
    }

    return parentheses.empty();


}