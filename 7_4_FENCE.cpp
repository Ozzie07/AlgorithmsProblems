//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//#define NUM_OF_BARS 20001
//	int n;
//	int bars[NUM_OF_BARS];
//	int answer = 0;
//	void GetInput()
//	{
//		cin >> n;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> bars[i];
//		}
//	}
//
//	int LocalAns(int l, int r, int height)
//	{
//		int local;
//		local = (r - l + 1) * height;
//		return local;
//	}
//
//	void Merge(int start, int end, int mid)
//	{
//		int local = 0;
//		int local_l = mid;
//		int local_r = mid + 1;
//		int h = min(bars[local_l], bars[local_r]);
//
//		//왼쪽을 늘릴 것인가, 오른쪽을 늘릴 것인가.
//
//		//min을 하나씩 움직이면서 최적화를 했다.
//		while (!(local_l == start || local_r == end))
//		{
//			local = LocalAns(local_l, local_r, h);
//			//cout << "L : " << local_l << "  R : " << local_r << " Local : " << local << " h : " << h << endl;
//			if (local > answer)
//				answer = local;
//
//			if (bars[local_l - 1] < bars[local_r + 1])
//			{
//				local_r++;
//				h = min(h, bars[local_r]);
//			}
//			else
//			{
//				local_l--;
//				h = min(h, bars[local_l]);
//			}
//		}
//
//		if (local_r == end)
//		{
//			//local_l에 대한 작업.
//
//			for (local_l; local_l >= start; local_l--)
//			{
//				h = min(h, bars[local_l]);
//				local = LocalAns(local_l, local_r, h);
//				if (local > answer)
//					answer = local;
//				//cout << "L : " << local_l << "  R : " << local_r << " Local : " << local << " h : " << h << endl;
//			}
//			return;
//		}
//
//		if (local_l == start)
//		{
//			//local_r에 대한 작업.
//			for (local_r; local_r <= end; local_r++)
//			{
//				h = min(h, bars[local_r]);
//				local = LocalAns(local_l, local_r, h);
//				if (local > answer)
//					answer = local;
//				//cout << "L : " << local_l << "  R : " << local_r << " Local : " << local << " h : " << h << endl;
//			}
//			return;
//		}
//
//	}
//
//	void Divide(int start, int end)
//	{
//		//
//		//
//		//0. base case를 선정했음. <- 재귀적인 방식을 이용하기 위해서.
//		//1. divide를 했어요.
//		//2. divide 되었던 녀석들을 합쳐줬다.
//
//		if (end == start)
//		{
//			if(answer < bars[end])
//				answer = bars[end];
//			return;
//		}
//
//		int mid = start + ((end - start) >> 1);
//		Divide(start, mid);
//		Divide(mid + 1, end);
//
//		Merge(start, end, mid);
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		Divide(0, n - 1);
//		cout << answer << '\n';
//	}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//	return 0;
//}