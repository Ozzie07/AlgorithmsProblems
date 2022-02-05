//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int p; //테스트 케이스의 개수
//	int n, m; // 테스트 케이스의 번호, 나누는 수 m.
//	cin >> p;
//
//	while (p > 0)
//	{
//		cin >> n >> m;
//		//Code
//		
//		//
//		p--;
//	}
//
//	vector<long long> Fibonacci;
//	Fibonacci.push_back(0);
//	Fibonacci.push_back(1);
//	Fibonacci.push_back(1);
//	for (size_t i = 2; i < n; i++)
//	{
//		Fibonacci.push_back(Fibonacci[Fibonacci.size() - 1] + Fibonacci[Fibonacci.size() - 2]);
//	}
//	
//	for (size_t i = 0; i < n; i++)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	for (size_t i = 0; i < n; i++)
//	{
//		Fibonacci[i] << ' ';
//	}
//	cout << endl;
//	for (size_t i = 0; i < n; i++)
//	{
//		Fibonacci[i] % m << ' ';
//	}
//	cout << endl;
//
//	return 0;
//}
