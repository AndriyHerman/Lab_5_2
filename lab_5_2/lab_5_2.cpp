// Лабораторна робота № 5.2 (Варіант 4) — спосіб 2 (функції типу void)
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототипи void-функцій (результати повертаються через параметри-посилання &s та &a)
void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(12) << "ln(x+1)" << " |"
        << setw(12) << "S" << " |"
        << setw(7) << "n" << " |" << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s); // виклик процедури без присвоєння
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(12) << setprecision(5) << log(x + 1) << " |"
            << setw(12) << setprecision(5) << s << " |"
            << setw(7) << n << " |" << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}

// Функція обчислення суми ряду Тейлора (змінює n та s за посиланням)
void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = x; // перший доданок ряду при n = 0
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

// Функція обчислення чергового доданку (змінює a за посиланням)
void A(const double x, const int n, double& a)
{
    double R = -x * n / (n + 1); // коефіцієнт рекурентності
    a *= R;
}