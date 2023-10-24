#include <iostream>
#include <cmath>
using namespace std;


class Assignment1 {

private:
    double getRecurSin(int n, double item = 1) {
        if (n == 0) {
            return item;
        }
        else {
            double oper = sin(item);
            return getRecurSin(n - 1, oper);
        }

    }


public:
    void ToDo(int n, double x) {
        double mainRow = 0;
        for (int i = 1; i <= n; ++i) {
            mainRow += getRecurSin(i, x);
        }
        cout << mainRow << endl;
    }
};


class Assignment2 {
private:
    unsigned long long factorial(int n) {
        if (n == 0) return 1;
        else return n * factorial(n - 1);   
    }
    double firstFunc(double x) {
        return (sin(2 * x) + 1) / (sin(x) + pow(cos(x), 2));
    }
    double secondFunc(double x) {
        double sum = 0;
        for (int i = 0; i <= 7; ++i) {
            sum += (pow(x, 4 * i + 2)) / (factorial(2 * i + 1));
        }
        return sum;
    }

public:
    void ToDo() {
        double a, b;
        double n;
        cout << "Enter a, b and n" << endl;
        cin >> a;
        cin >> b;
        cin >> n;
        cout << "Processing..." << endl;
        cout << "-------------------------" << endl;
        cout << "|   X   |     f(x)      |" << endl;
        cout << "-------------------------" << endl;
        double distance = b - a;
        for (; a < b; a += n) {
            if (abs(a) >= 1) {
                cout << "|  " << a << "\t|  " << firstFunc(a) << "\t|" << '\n';
            }
            else
            {
                cout << "|  " << a << "\t|  " << secondFunc(a) << "\t|" << '\n';

            }
            cout << "-------------------------" << endl;

        }
            if (abs(b) >= 1) cout << "|  " << b << "\t|  " << firstFunc(b) << "\t|" << '\n'; else cout << "|  " << b << "\t|  " << secondFunc(b) << "\t|" << '\n';
            cout << "-------------------------" << endl;  

    }
};


class Assignment3 {
public:
    int a_n_1 = 1;
    void ToDo(double eps) {
        bool status = 1;
        for (int n = 2; status; ++n) {
            double a_n = 3 + a_n_1 / pow(2, n);
            cout << abs(a_n - a_n_1) << endl;
            if (abs(a_n - a_n_1) < eps) { cout << n << endl; status = 0; }
            a_n_1 = a_n;
        }
    }

};

double nestedSqrt(int n, int limit) {
    if (limit == 1) {
        return sqrt(n);
    }
    else {
        return sqrt(n + nestedSqrt(n + 3, limit - 1));
    }
}

int main() {
    //Assignment1().ToDo(4, 1);
    //Assignment2().ToDo();
    //Assignment3().ToDo(0.01);
    cout << nestedSqrt(3, 9);



    return 0;
}


