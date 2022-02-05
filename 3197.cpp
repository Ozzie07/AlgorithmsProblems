//#include <bits/stdc++.h>
//
//
//using namespace std;
//vector<pair<int, int>> SwanPosition;
//string str[1501];
//bool isQueued[1501][1501];
//int r, c;
//
//void QueuedReset(int _r, int _c)
//{
//	for (size_t i = 0; i < _r; i++)
//		for (size_t j = 0; j < _c; j++)
//			isQueued[i][j] = false;
//}
//
//class Visit
//{
//	int visit_r;
//	int visit_c;
//	bool** visit;
//private:
//	bool isSwan(const char &ch)
//	{
//		if (ch == 'L')
//			return true;
//		return false;
//	}
//public:
//	Visit(int _r, int _c) { 
//
//		visit_r = _r;
//		visit_c = _c;
//		visit = new bool* [_r];
//		for (size_t i = 0; i < _r; i++)
//		{
//			visit[i] = new bool[_c];
//		}
//	}
//
//	bool& ArrayInterface(int i, int j) { return visit[i][j]; }
//
//	bool& GraphInterface(int input) { 
//		int i = input / visit_r;
//		int j = input % visit_c;
//		return visit[i][j];
//	}
//
//	void visitInit()
//	{
//		for (size_t i = 0; i < visit_r; i++)
//		{
//			for (size_t j = 0; j < visit_c; j++)
//			{
//				if (str[i][j] == 'X')
//					visit[i][j] = true;
//				else
//					visit[i][j] = false;
//			}
//		}
//	}
//
//	void RegisterSwanPosition()
//	{
//		for (size_t i = 0; i < visit_r; i++)
//			for (size_t j = 0; j < visit_c; j++)
//				if (isSwan(str[i][j]))
//
//					SwanPosition.push_back({ i,j });
//	}
//
//	int GetRow()
//	{
//		return visit_r;
//	}
//
//	int GetColumn()
//	{
//		return visit_c;
//	}
//};
//
//bool isIce(string* str, int i, int j)
//{
//	if (str[i][j] == 'X')
//		return true;
//	return false;
//}
//
//queue<pair<int, int>> Queue1;
//queue<pair<int, int>> Queue2;
//
////true qing 1 false ging 2
//bool queuebool = true;
//
////녹이는 데에 성공했다면 주변을 검색해서 여전히 얼어있는 블록을 큐에 집어넣음.
//void Queuing(string* str, bool _isMelt, int i, int j)
//{
//	if (_isMelt)
//	{
//		if (!queuebool)
//		{
//			if (i - 1 > 0)
//				if (str[i - 1][j] == 'X')
//					if (!isQueued[i - 1][j])
//					{
//						Queue1.push({ i - 1,j });
//						isQueued[i - 1][j] = true;
//					}
//			//down
//			if (i + 1 < r)
//				if (str[i + 1][j] == 'X')
//					if (!isQueued[i + 1][j])
//					{
//						Queue1.push({ i + 1,j });
//						isQueued[i + 1][j] = true;
//					}
//			//left
//			if (j - 1 > 0)
//				if (str[i][j - 1] == 'X')
//					if (!isQueued[i][j - 1])
//					{
//						Queue1.push({ i ,j - 1 });
//						isQueued[i][j - 1] = true;
//					}
//			//right
//			if (j + 1 < c)
//				if (str[i][j + 1] == 'X')
//					if (!isQueued[i][j + 1])
//					{
//						Queue1.push({ i,j + 1 });
//						isQueued[i][j + 1] = true;
//					}
//		}
//		else
//		{
//			if (i - 1 > 0)
//				if (str[i - 1][j] == 'X')
//					if (!isQueued[i - 1][j])
//					{
//						Queue2.push({ i - 1,j });
//						isQueued[i - 1][j] = true;
//					}
//			//down
//			if (i + 1 < r)
//				if (str[i + 1][j] == 'X')
//					if (!isQueued[i + 1][j])
//					{
//						Queue2.push({ i + 1,j });
//						isQueued[i + 1][j] = true;
//					}
//			//left
//			if (j - 1 > 0)
//				if (str[i][j - 1] == 'X')
//					if (!isQueued[i][j - 1])
//					{
//						Queue2.push({ i ,j - 1 });
//						isQueued[i][j - 1] = true;
//					}
//			//right
//			if (j + 1 < c)
//				if (str[i][j + 1] == 'X')
//					if (!isQueued[i][j + 1])
//					{
//						Queue2.push({ i,j + 1 });
//						isQueued[i][j + 1] = true;
//					}
//		}
//	}
//}
////사방을 검색해서 해당 블록이 녹아야하면 녹이고, 녹임 여부를 반환.
//bool IsMelt(string* str, Visit& visit, int i, int j)
//{
//	bool isMelt = false;
//	if (str[i][j] == 'X')
//	{
//		if (i - 1 > 0)
//		{
//			if (str[i - 1][j] == '.')
//				isMelt = true;
//		}
//		//down
//		if (i + 1 < visit.GetRow())
//		{
//			if (str[i + 1][j] == '.')
//				isMelt = true;
//		}
//		//left
//		if (j - 1 > 0)
//		{
//			if (str[i][j - 1] == '.')
//				isMelt = true;
//		}
//		//right
//		if (j + 1 < visit.GetColumn())
//		{
//			if (str[i][j + 1] == '.')
//				isMelt = true;
//		}
//	}
//	if(isMelt)
//		str[i][j] = '0';
//
//	return isMelt;
//}
//
//void Melt(string* str, Visit& visit, int i, int j) // find X, find adjacent ., and store X's adjacent X
//{
//	// 사방을 검색시 .이 있다면 녹여야함.
//	// 그 때 주변의 X를 queue에 넣어야함. => 다음에도 녹을 것이기 때문.
//	bool isMelt = IsMelt(str, visit, i, j);
//	Queuing(str, isMelt, i, j);
//}
//
//void Applymelt(string* str)
//{
//	for (size_t i = 0; i < r; i++)
//		for (size_t j = 0; j < c; j++)
//			if (str[i][j] == '0')
//				str[i][j] = '.';
//}
//
//void OneDay(string* str, Visit& visit)
//{
//	visit.visitInit();
//	QueuedReset(r, c);
//	for (size_t i = 0; i < visit.GetRow(); i++)
//	{
//		for (size_t j = 0; j < visit.GetColumn(); j++)
//		{
//			Melt(str, visit, i, j);
//		}
//	}
//	Applymelt(str);
//}
//
//void TwoorMoreDay(string*str, Visit& visit)
//{
//	QueuedReset(r, c);
//	int i, j;
//	if (queuebool)
//	{
//		while (!Queue1.empty())
//		{
//			tie(i, j) = Queue1.front(); Queue1.pop();
//			bool isMelt = true;//큐에는 녹아야하는 녀석들만 있기 때문에 녹여줌.
//			str[i][j] = '0';
//			Queuing(str, isMelt, i, j);
//		}
//		queuebool = false;
//	}
//	else
//	{
//		while (!Queue2.empty())
//		{
//			tie(i, j) = Queue2.front(); Queue2.pop();
//			bool isMelt = true;//큐에는 녹아야하는 녀석들만 있기 때문에 녹여줌.
//			str[i][j] = '0';
//			Queuing(str, isMelt, i, j);
//		}
//		queuebool = true;
//	}
//	Applymelt(str);
//}
//
//bool isMeet = false;
//void SpawnSwan(string* str)
//{
//	str[SwanPosition[0].first][SwanPosition[0].second] = 'L';
//	str[SwanPosition[1].first][SwanPosition[1].second] = 'L';
//}
//
//void Go_Logic(string* str, Visit& visit, int Swan_i, int Swan_j)
//{
//	if (visit.ArrayInterface(Swan_i, Swan_j))
//		return;
//
//	visit.ArrayInterface(Swan_i, Swan_j) = true;
//	if (str[Swan_i][Swan_j] == 'L')
//	{
//		isMeet = true;
//	}
//	else
//	{
//		if (Swan_i - 1 > 0)
//		{
//			Go_Logic(str, visit, Swan_i - 1, Swan_j);
//		}
//		//down
//		if (Swan_i + 1 < visit.GetRow())
//		{
//			Go_Logic(str, visit, Swan_i + 1, Swan_j);
//		}
//		//left
//		if (Swan_j - 1 > 0)
//		{
//			Go_Logic(str, visit, Swan_i, Swan_j - 1);
//		}
//		//right
//		if (Swan_j + 1 < visit.GetColumn())
//		{
//			Go_Logic(str, visit, Swan_i, Swan_j + 1);
//		}
//	}
//}
//
//void Go(string* str, Visit& visit, int Swan_i, int Swan_j)
//{
//	visit.visitInit();
//	str[Swan_i][Swan_j] = '.';
//	Go_Logic(str, visit, Swan_i, Swan_j);
//	str[Swan_i][Swan_j] = 'L';
//}
//
//void ShowCurrentState(string* str)
//{
//	cout << "--------------------------------------------" << endl;
//	for (size_t i = 0; i < r; i++)
//		cout << str[i] << endl;
//}
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//	//\n faster than endl. endl makes buffer flush explicitly.
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> r >> c;
//
//
//	string IdonknowReason;
//	getline(cin, IdonknowReason);
//	for (size_t i = 0; i < r; i++)
//	{
//		getline(cin, str[i]);
//	}
//
//	Visit visit(r, c);
//	visit.RegisterSwanPosition();
//	int Day = 0;
//
//	//ShowCurrentState(str);
//	Go(str, visit, SwanPosition[0].first, SwanPosition[0].second);
//	if (isMeet)
//	{
//		cout << Day << endl; return 0;
//	}
//	OneDay(str, visit); Day++;
//	queuebool = false;
//	//one Day
//	while (!isMeet)
//	{
//		SpawnSwan(str);
////		ShowCurrentState(str);
//		Go(str, visit, SwanPosition[0].first, SwanPosition[0].second);
//		if (isMeet)
//			break;
//		TwoorMoreDay(str, visit); Day++;
//	}
//
//	cout << Day << endl;
//	return 0;
//};