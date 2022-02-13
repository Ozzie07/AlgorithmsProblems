//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//    int N;
//    int A[500001];
//    int problem_MAX = 500'001;
//    void GetInput()
//    {
//        cin >> N;
//        for (size_t i = 1; i <= N; i++)
//        {
//            cin >> A[i];
//        }
//    }
//public:
//    void Invoke()
//    {
//        GetInput();
//       // cout << "------------------RES-----------------" << endl;
//        cout << check() << endl;
//       // cout << "--------------------------------------" << endl;
//
//        //bool changed = false;
//        //for (int i = 1; i <= N + 1; i++) {
//        //    changed = false;
//        //    for (int j = 1; j <= N - i; j++) {
//        //        if (A[j] > A[j + 1]) {
//        //            changed = true;
//        //            swap(A[j], A[j + 1]);
//        //        }
//        //    }
//
//        //    //한 번 돌았지만 더 바꿀 것이 없었다.
//        //    if (changed == false) {
//        //        cout << i << '\n';
//        //        break;
//        //    }
//        //}
//    }
//
//    int check()
//    {
//        int min = problem_MAX;
//        int num = 1;
//        for (int i = N; i >= 1; i--)
//        {
//            if (A[i] > min)
//            {
//                num++;
//            }
//            //minUpdate
//            if (A[i] < min)
//            {
//                min = A[i];
//            }
//
//        }
//        return num;
//    }
//};
//
//
//int main() {
//    //	freopen("input.txt", "r", stdin);
//    //	freopen("output.txt", "w", stdout);
//
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    //\n faster than endl. endl makes buffer flush explicitly.
//    Solution solution;
//    solution.Invoke();
//
//    return 0;
//}