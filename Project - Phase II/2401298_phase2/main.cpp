#include <iostream>
#include "Complex.h"
#include <string>
#include <iomanip>

using namespace std;

bool validInput(string input);
Complex parseComplex(string input);

int main(int args, char *argv[]) {
    if (args < 3 || args > 4) {
        cout << "ERROR: Invalid arguments";
        return 0;
    }
    if (args == 3 && !validInput(argv[2])) {
        cout << "ERROR: Invalid complex number";
        return 0;
    }
    if (args == 4 && (!validInput(argv[2]) || !validInput(argv[3]))) {
        cout << "ERROR: Invalid complex number";
        return 0;
    }

    Complex num1, num2, result;
    string operation = argv[1];

    num1 = parseComplex(argv[2]);
    if (operation == "mag") {
        cout << std::fixed << setprecision(6) << num1.magnitude();
        return 0;
    }
    if (args == 3) {
        cout << "ERROR: Invalid arguments";
        return 0;
    }
    num2 = parseComplex(argv[3]);
    if (operation == "add") {
        result = num1.add(num2);
    } else if (operation == "sub") {
        result = num1.sub(num2);
    } else if (operation == "mul") {
        result = num1.mul(num2);
    } else if (operation == "div") {
        if (num2.getReal() == 0 && num2.getImag() == 0) {
            cout << "ERROR: Division by zero";
            return 0;
        }
        result = num1.div(num2);
    } else {
        cout << "ERROR: Unknown operation";
        return 0;
    }

    string imagPlus = "";
    if (result.getImag() >= 0) imagPlus = "+";
    cout << std::fixed << setprecision(6) << result.getReal() << imagPlus << result.getImag() << "i";
}

bool validInput(string input) {
    int hasPoint = 0;
    bool hasI = false;
    for (int i = 0; i < input.length(); i++) {
        if ((input[i] <= 57 && input[i] >= 48) || input[i] == '-' || input[i] == '+') {
        } else if (input[i] == '.') {
            hasPoint++;
            if (hasPoint > 2) return false;
        } else if (input[i] == 'i' && i == input.length() - 1) {
            if (hasI) return false;
            hasI = true;
        }
        else return false;
    }
    if (!hasI) return false;
    return true;
}

Complex parseComplex(string input) {
    double real, imag;
    int i = 0, count = 0;
    if (!(input[0] == '-' || input[0] == '+')) count = 1;
    while (count < 2) {
        if (input[i] == '+' || input[i] == '-') count++;
        i++;
    }
    try {
        real = stod(input.substr(0, i - 1));
        imag = stod(input.substr(i - 1, input.length() - 2));
    } catch (const std::invalid_argument&) {
        cout << "ERROR: Invalid complex number";
    }
    return Complex(real, imag);
}