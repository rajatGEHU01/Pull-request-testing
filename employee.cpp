#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

// ISSUE 1: Hardcoded credentials
// SEC010 - Hardcoded secret detection
string api_key = "demo-secret-key-123456789";

// ISSUE 2: Unsafe function
// CPP002 - Potential buffer overflow
void saveEmployee(string name) {
    char buffer[20];
    strcpy(buffer, name.c_str());
    cout << buffer << endl;
}

// ISSUE 3: Unsafe temporary filename
// CPP008 - Medium severity
void createTemporaryFile() {
    char filename[L_tmpnam];
    tmpnam(filename);
}

// ISSUE 4: Duplicate code - Original function
int calculateSalary(vector<int>& values) {
    int total = 0;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] > 0) {
            total = total + values[i];
        }
    }
    return total;
}

// ISSUE 4: DUP001 - Duplicate code
// Same logic with different variable names
int calculateBonus(vector<int>& amounts) {
    int result = 0;
    for (int j = 0; j < amounts.size(); j++) {
        if (amounts[j] > 0) {
            result = result + amounts[j];
        }
    }
    return result;
}

// ISSUE 5: CYC001 - High cyclomatic complexity
// 11 decision points + base complexity = 12
int evaluateEmployee(int score) {
    int rating = 0;

    if (score > 10) rating++;
    if (score > 20) rating++;
    if (score > 30) rating++;
    if (score > 40) rating++;
    if (score > 50) rating++;
    if (score > 60) rating++;
    if (score > 70) rating++;
    if (score > 80) rating++;
    if (score > 85) rating++;
    if (score > 90) rating++;
    if (score > 95) rating++;

    return rating;
}

int main() {
    vector<int> salaries = {10000, 20000, 30000};

    cout << calculateSalary(salaries) << endl;
    cout << calculateBonus(salaries) << endl;
    cout << evaluateEmployee(95) << endl;

    return 0;
}
