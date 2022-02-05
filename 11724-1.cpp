#include <bits/stdc++.h>
//Union-Find

using namespace std;

int link[1001];
int size_arr[1001];
int num[1001];
int n, m, s, d;
//int Find(int x) { while (x != link[x]) x = link[x]; }
int Find(int x) { 
	if (x == link[x]) return x; 
	return link[x] = Find(link[x]); 
}
bool same(int a, int b) { return Find(a) == Find(b); }
void Unite(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (size_arr[a] < size_arr[b]) swap(a, b);
	size_arr[a] += size_arr[b];
	link[b] = a;
}
int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	cin >> n >> m;

	for (size_t i = 0; i < n; i++)
	{
		link[i] = i;
		size_arr[i] = 1;
		num[i] = 0;
	}

	for (size_t i = 0; i < m; i++)
	{
		cin >> s >> d;
		Unite(s, d);
	}

	int res = 0;
	for (size_t i = 0; i < n; i++)
	{
		num[Find(i)]++;
	}
	for (size_t i = 0; i < n; i++)
	{
		if (num[i])
			res++;
	}

	cout << res;
	return 0;
}