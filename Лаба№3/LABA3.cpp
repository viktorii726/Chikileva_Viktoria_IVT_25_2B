#include<iostream>
#include<clocale>
#include<cmath>

using  namespace std;

long long int fa(int n) {
	if (n <= 1) 
		return 1;

	return n * fa(n - 1);
}


float func(float x, int n, float s) 
{
	if (n == 1)
		return x+s;
	
	if (n == 2) 
	{
		s += (pow(x, 3) / fa(3));
		return func(x, n - 1, s);
	}
	s += pow(x, 2 * n + 1) / fa(2 * n + 1);
	return func(x, n - 1, s);
}

int main() {
	setlocale(LC_ALL, "RUS");
	float x, n, s = 0;
	cout << "Элемент x= " ;
	cin >> x;
	cout << "Элемент n= " ;
	cin >> n;

	cout<<func(x, n, s);



}




