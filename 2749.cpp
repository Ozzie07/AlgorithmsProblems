#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

class Solution
{
	LL n;
	LL X[2][2] = { 0,1,1,1 };
	LL F[2] = { 0,1 }; //It means f(0), f(1).
	LL divisor = 1'000'000'007;
public:
	void ShowArray()
	{
		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < 2; j++)
			{
				cout << X[i][j] << ' ';
			}
			cout << endl;
		}
	}

	void Multiply(LL* arr)
	{
		LL res[2];
		res[0] = X[0][0] * arr[0] + X[0][1] * arr[1];
		res[1] = X[1][0] * arr[0] + X[1][1] * arr[1];
		arr[0] = res[0];
		arr[1] = res[1];
	}

	//res = param1 * param2.
	void MultiplyArray(LL param1[][2], LL param2[][2], LL res[][2])
	{
		//int res[2][2];
		res[0][0] = ((param1[0][0] * param2[0][0]) % divisor + (param1[0][1] * param2[1][0]) % divisor) % divisor;
		res[0][1] = ((param1[0][0] * param2[0][1]) % divisor + (param1[0][1] * param2[1][1]) % divisor) % divisor;
		res[1][0] = ((param1[1][0] * param2[0][0]) % divisor + (param1[1][1] * param2[1][0]) % divisor) % divisor;
		res[1][1] = ((param1[1][0] * param2[0][1]) % divisor + (param1[1][1] * param2[1][1]) % divisor) % divisor;
	}

	void Substitude(LL input[][2], LL res[][2])
	{
		res[0][0] = input[0][0];
		res[0][1] = input[0][1];
		res[1][0] = input[1][0];
		res[1][1] = input[1][1];
	}

	void PowerX(LL n, LL input[][2], LL res[][2])
	{
		if (n == 0)
		{
			;
			return;
		}
		if (n == 1)
		{
			LL temp[2][2];
			Substitude(res, temp);
			MultiplyArray(temp, input, res);
			return;
		}
		if (n % 2 == 1)
		{
			PowerX(n - 1, input, res);
			LL temp[2][2];
			Substitude(res, temp);
			MultiplyArray(temp, input, res);
			return;
		}

		//description if(n%2 == 0)
		LL temp[2][2] = { 1,0,0,1 };
		LL temp2[2][2] = { 1,0,0,1 };
		PowerX(n / 2, input, temp);
		MultiplyArray(temp, temp, res);
		return;
	}

	void Fibonacci(LL _n)
	{
		if (_n == 0)
			cout << F[0];
		else if (_n == 1)
			cout << F[1];
		else if (_n > 1)
		{
			//for (size_t i = 0; i < _n - 2; i++)
			//{
			//	Multiply(F);
			//}
			LL res[2][2] = { 1,0,0,1 };
			PowerX(n - 2, X, res);
			Substitude(res, X);
			Multiply(F);
			cout << (F[0] + F[1]) % divisor << endl;
		}
	}

	void Invoke()
	{
		cin >> n;
		Fibonacci(n);
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Solution solution;
	solution.Invoke();

	return 0;
}