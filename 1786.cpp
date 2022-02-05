//#include <iostream>
//
//#include <vector>
//
//#include <string>
//
//using namespace std;
//
//
//
//string T, P;
//
//
//
////N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿��� pi[] ���
//
////pi[i] = N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
//
//vector<int> getPartialMatch(const string& N)
//
//{
//    int M = N.size();
//    vector<int> pi(M, 0);
//    //KMP�� �ڱ� �ڽ��� ã�´�
//    //N�� N���� ã�´�.
//    //begin=0�̸� �ڱ� �ڽ��� ã�ƹ����ϱ� �ȵ�!
//    int begin = 1, matched = 0;
//    //���� ���ڰ� N�� ���� ������ ������ ã���鼭 �κ� ��ġ�� ��� ����Ѵ�
//    while (begin + matched < M)
//    {
//        if (N[begin + matched] == N[matched])
//        {
//            matched++;
//            pi[begin + matched - 1] = matched;
//        }
//        else
//        {
//            if (matched == 0)
//                begin++;
//            else
//            {
//                begin += matched - pi[matched - 1];
//                matched = pi[matched - 1];
//            }
//        }
//    }
//    return pi;
//}
//
//
//
//vector<int> kmpSearch2(const string& H, const string& N)
//{
//    int n = H.size(), m = N.size();
//    vector<int> result;
//    vector<int> pi = getPartialMatch(N);
//    //���� ������ ������ ��
//    int matched = 0;
//    //¤������ �� ���ڸ� ��ȸ
//
//    for (int i = 0; i < n; i++)
//    {
//        //matched�� ���ڿ� ¤������ �ش� ���ڰ� ����ġ�� ���,
//        //���� ������ ������ ���� pi[matched-1]�� ���δ�
//        while (matched > 0 && H[i] != N[matched])
//            matched = pi[matched - 1];
//        //���ڰ� ������ ���
//        if (H[i] == N[matched])
//        {
//            matched++;
//            if (matched == m)
//            {
//                //�������� �ε����� 0�� �ƴ� 1���� ����
//                result.push_back(i - m + 2);
//                matched = pi[matched - 1];
//            }
//        }
//    }
//    return result;
//}
//
//
//
//int main(void)
//{
//
//    ios_base::sync_with_stdio(0);
//    getline(cin, T); //���� �����ؼ� �Է¹ޱ� ����
//    getline(cin, P);
//    vector<int> result = kmpSearch2(T, P);
//
//    //endl ���� �ð� �ʰ�
//
//    cout << result.size() << "\n";
//
//    for (int i = 0; i < result.size(); i++)
//
//        cout << result[i] << "\n";
//
//    return 0;
//
////��ó: https://jaimemin.tistory.com/627 [������]
//}
//
//
//
