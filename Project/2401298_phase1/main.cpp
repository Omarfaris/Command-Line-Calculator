#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool validInput(string input) {
    bool hasPoint = false, hasE = false;
    for (int i = 0; i < input.length(); i++) {
        if ((input[i] <= 57 && input[i] >= 48) || input[i] == '-') {
        } else if (input[i] == '.') {
            if (hasPoint) return false;
            hasPoint = true;
        } else if (input[i] == 'e') {
            if (hasE) return false;
            hasE = true;
        }
        else return false;
    }
    return true;
}

int main(int args, char *argv[]) {
    if (args != 4 || !validInput(argv[2]) || !validInput(argv[3])) {
        cout << "ERROR: Invalid arguments";
        return 0;
    }

    string operation = argv[1];
    double num1 = stod(argv[2]), num2 = stod(argv[3]);
    double result = 0;
    if (operation == "add") result = num1 + num2;
    else if (operation == "sub") result = num1 - num2;
    else if (operation == "mul") result = num1 * num2;
    else if (operation == "div") {
        if (num2 == 0) {
            cout << "ERROR: Division by zero";
            return 0;
        }
        result = num1 / num2;
    }
    else if (operation == "pow") {
        if (num1 == 0 && num2 == 0) {
            cout << "ERROR: Invalid result";
            return 0;
        }
        result = pow(num1, num2);
    }
    else {
        cout << "ERROR: Unknown operation";
        return 0;
    }

    if (isnan(result) || isinf(result)) {
        cout << "ERROR: Invalid result";
        return 0;
    }


    cout << std::fixed << setprecision(6) << result;
    return 0;
}