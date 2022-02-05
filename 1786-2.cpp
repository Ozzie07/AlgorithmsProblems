#include <bits/stdc++.h>

using namespace std;


vector<int> getPi(string p) {
    int m = (int)p.size(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}


vector<int> kmp(string source, string target) {
    vector<int> res;
    auto pi = getPi(target);
    int n = (int)source.size(), m = (int)target.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && source[i] != target[j])
            j = pi[j - 1];
        if (source[i] == target[j]) {
            if (j == m - 1) {
                res.push_back(i - m + 1);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, p;
    getline(cin, s);
    getline(cin, p);
    auto matched = kmp(s, p);
    cout << matched.size() << '\n';
    for (auto i : matched)
        cout << i + 1 << ' ';
    return 0;
}