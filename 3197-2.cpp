//#include <bits/stdc++.h>
//using namespace std;
//
//int c, r;
//bool VISITIED[1501][1501] = { false, };
//int dx[4] = { -1,1,0,0 };
//int dy[4] = { 0,0,-1,1 };
//vector <pair<int, int>> SwanPosition;
//string str[1501];
//string DynamicMap[1501][1501];
//queue<pair<int, int>> queue1;
//queue<pair<int, int>> queue2;
//bool switchQueue = true;
//bool isQueued[1501][1501] = { false, };
//bool SwanVisited[1501][1501] = { false, };
//
//
//queue<pair<int, int>>* CustomQueue()
//{
//	if (switchQueue) //ensure this your first queue.
//		return &queue1;
//	else
//		return &queue2;
//}
//
//void ChangeCurrentQueue()
//{
//	switchQueue = !switchQueue;
//}
//
//int day = 0;
//
//void VisitInit()
//{
//	for (size_t i = 0; i < r; i++)
//		for (size_t j = 0; j < c; j++)
//			VISITIED[i][j] = false;
//}
//
//void IsQueuedInit()
//{
//	for (size_t i = 0; i < r; i++)
//		for (size_t j = 0; j < c; j++)
//			isQueued[i][j] = false;
//}
//
//bool isSwan(const char& ch)
//{
//	if (ch == 'L')
//		return true;
//	return false;
//}
//
//void RegisterSwanPosition()
//{
//	for (size_t i = 0; i < r; i++)
//		for (size_t j = 0; j < c; j++)
//			if (isSwan(str[i][j]))
//				SwanPosition.push_back({ i,j });
//}
//
//void SpawnSwan(string* str)
//{
//	str[SwanPosition[0].first][SwanPosition[0].second] = '.';
//	str[SwanPosition[1].first][SwanPosition[1].second] = 'L';
//}
//
//bool isFound = false;
//bool Meetarr[1501] = { false, };
//
//void DFS_findHusband_logic(string* _map, pair<int, int> startPosition, int _day)
//{
//	if (SwanVisited[startPosition.first][startPosition.second])
//		return;
//	int x_r = startPosition.first;
//	int x_c = startPosition.second;
//	SwanVisited[startPosition.first][startPosition.second] = true;
//	//DoSomething
//	if (_map[x_r][x_c] == 'L')
//	{
//		Meetarr[_day] = true;
//	}
//	//
//	for (int i = 0; i < 4; i++) {
//		int nx_r = x_r + dx[i];
//		int nx_c = x_c + dy[i];
//		if (0 <= nx_r && nx_r < r && 0 <= nx_c && nx_c < c) {
//			if(!(_map[nx_r][nx_c]== 'X'))
//				DFS_findHusband_logic(_map, { nx_r, nx_c }, _day);
//		}
//	}
//}
//
////날짜를 입력 받아서 해당 날에 대해 Meetarr를 수정함.
//void DFS_findHusband(string* _map, int _day)
//{
//	pair<int, int> Swan = SwanPosition[0];
//	SpawnSwan(_map);
//	DFS_findHusband_logic(_map, Swan, _day);
//}
//
//
//void QueueAtFirstDay(pair<int, int> startPosition)
//{
//	if (VISITIED[startPosition.first][startPosition.second])
//		return;
//	int x_r = startPosition.first;
//	int x_c = startPosition.second;
//	VISITIED[x_r][x_c] = true;
//	//DoSomething
//	//
//	for (int i = 0; i < 4; i++) {
//		int nx_r = x_r + dx[i];
//		int nx_c = x_c + dy[i];
//		if (((0 <= nx_r) && (nx_r < r)) && ((0 <= nx_c) && (nx_c < c))) {
//			if (str[x_r][x_c] == 'X')
//				if(str[nx_r][nx_c] == '.')
//					if (!isQueued[x_r][x_c])
//					{
//						queue1.push({ x_r,x_c });
//						isQueued[x_r][x_c] = true;
//					}
//		QueueAtFirstDay({ nx_r, nx_c });
//		}
//	}
//}
//
//void QueueAtFirstDayWrapper()
//{
//	VisitInit();
//	QueueAtFirstDay({ 0,0 });
//}
//
////하루가 지나고 얼음의 상태 반영.
//void OneNight()
//{
//	IsQueuedInit();
//	queue<pair<int, int>> *internalQueue1 = CustomQueue();
//	ChangeCurrentQueue();
//	queue<pair<int, int>> *internalQueue2 = CustomQueue();
//
//	while (!internalQueue1->empty())
//	{
//		pair<int, int> current = internalQueue1->front(); internalQueue1->pop();
//
//		int x = current.first;
//		int y = current.second;
//		str[x][y] = '.';
//
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (((0 <= nx) && (nx < r)) && ((0 <= ny) && (ny < c)))
//				if(str[nx][ny] == 'X')
//					if (!isQueued[nx][ny])
//					{
//						internalQueue2->push({ nx,ny });
//						isQueued[nx][ny] = true;
//					}	
//		}
//	}
//}
//
//int maxday;
//void PrintCurrentState()
//{
//	cout << "Today : ";
//	for (size_t day = 0; day < maxday; day++)
//	{
//		cout << day << endl;
//
//		for (size_t i = 0; i < r; i++)
//		{
//			cout << DynamicMap[day][i] << endl;
//		}
//		system("pause");
//	}
//}
//
//void MakeMap(int _day)
//{
//	for (size_t i = 0; i < r; i++)
//	{
//		DynamicMap[_day][i] = str[i];
//	}
//}
//
//void PreMap()
//{
//	for (size_t i = 1; i < maxday; i++)
//	{
//		OneNight();
//		MakeMap(i);
//	}
//}
//
//int BinarySearch(int _start, int _end)
//{
//	int first = _start;
//	int last = _end;
//	int mid;
//
//	while (first <= last)
//	{
//		mid = (first + last) / 2;
//
//		DFS_findHusband(DynamicMap[mid], mid);
//		if (Meetarr[mid])
//		{
//			DFS_findHusband(DynamicMap[mid - 1], (mid - 1));
//			if (!Meetarr[mid - 1])
//				return mid;
//			else
//			{
//				//왼쪽으로.
//				last = mid - 1;
//			}
//			//searchDone
//		}
//		else
//		{
//			first = mid + 1;
//		}
//	}
//	return -1;
//}
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	//\n faster than endl. endl makes buffer flush explicitly.
//
//	//getInput
//	cin >> r >> c;
//	maxday = max(r, c) >> 1;
//
//	string eraseNewlineCharacter;
//	getline(cin, eraseNewlineCharacter);
//	for (size_t i = 0; i < r; i++)
//		getline(cin, str[i]);
//
//	RegisterSwanPosition();
//	MakeMap(0);
//	QueueAtFirstDayWrapper();
//	PreMap();
//
//	//PrintCurrentState();
//
//	//Find Specific Day
//	cout << BinarySearch(0, maxday) << endl;
//
//
//	return 0;
//};