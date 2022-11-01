#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
	int n;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "------------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(10) << "log ((1+x)/(1*(1-x)))" << " |"
		<< setw(7) << "S" << " |"
		<< setw(8) << "n" << " |"
		<< endl;
	cout << "------------------------------------------------------" << endl;

	x = xp;

	while (x <= xk)
	{
		n = 0;
		a = x;
		S = a;
		do {
			n++;
			R = ((x * x) * (2 * n - 1)) / (2 * n + 1);
			a *= R;
			S += a;
		} while (abs(a) >= eps);
		cout << "|" << setw(4) << setprecision(2) << x << " |"
			<< setw(20) << setprecision(5) << log((1 + x) / (1 * (1 - x))) << " |"
			<< setw(10) << setprecision(5) << 2 * S << " |"
			<< setw(8) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-------------------------------------------------" << endl;

	return 0;
}