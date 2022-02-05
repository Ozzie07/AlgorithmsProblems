#include <iostream>

typedef long long Data;
using namespace std;
int main()
{
	Data n;
	cin >> n;
	while (true)
	{
		cout << n << " ";
		if (n == 1) break;

		if (n % 2 == 0) 
			n = n >> 1;
		else 
			n = (n * 3 + 1);
	}
	cout << "\n";
	return 0;
}