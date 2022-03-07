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
//		//������ �ø� ���ΰ�, �������� �ø� ���ΰ�.
//
//		//min�� �ϳ��� �����̸鼭 ����ȭ�� �ߴ�.
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
//			//local_l�� ���� �۾�.
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
//			//local_r�� ���� �۾�.
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
//		//0. base case�� ��������. <- ������� ����� �̿��ϱ� ���ؼ�.
//		//1. divide�� �߾��.
//		//2. divide �Ǿ��� �༮���� �������.
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