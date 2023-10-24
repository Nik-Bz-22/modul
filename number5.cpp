#include <iostream>
#include <cmath>
#include <string>

using namespace std;


double factorial(double n) {
    if (n < 0) {
        cout << "factorial doesn't exist" << endl;
        return 0;
    }
    double fac = 1;
    for (int i = 1; i <= n; ++i) {
        fac *= i;
    }
    return fac;
}

void calculate(double x, double e) {
    double sum = 0;
    bool status = 1;
    cout << "sin() value in radians: "  << x << endl;
    cout  << "eps precision: " << e << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    for (int n = 1; status; ++n) {

        double elem = pow(-1, n - 1) * (pow(x, 2 * n - 1) / factorial(2 * n - 1));
        cout << "element number " << n << ":\t" << elem << endl;

        if (abs(elem) >= e) sum += elem;
        else status = 0;

        
    }
    cout << "______________________________________________________________________________________________" << endl;
    cout << "sin(" << x << ") = " << sum << "\n\n\n\n";
}

string deleteSymbol(const string& input, char symbolToRemove) {
    string result;

    bool symbolDeleted = false;

    for (char ch : input) {
        if (symbolDeleted) {
            result += ch;
        }
        else {
            if (ispunct(ch)) {
                symbolDeleted = true;
                result += ch;
            }
            else if (ch != symbolToRemove) {

                result += ch;
            }
        }
    }

    return result;
}





void strEdit() {

    string text = "ajhfjksfhjskdhfjschchchchchc!chchch dffdsfd, ajdhdjka ch dfnsdjhj ";

    string substring = "ch";


    size_t punctuationPos = text.find_first_of(".!?,;:");

    if (punctuationPos != string::npos) {

        size_t substringPos = text.find(substring);

        if (substringPos != string::npos && substringPos < punctuationPos) {

            text.erase(substringPos, punctuationPos - substringPos);
        }
    }

    cout << "editing text: " << text << endl;

}


int main() {
    strEdit();


    return 0;
}






