#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define loop(n) for(int i = 0; i < n; ++i)
#define i_am_speed std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

int modpow(const int& x, const int& power, const int& mod) {
    if (power == 0) return 1;
    if (power == 1) return x;
    int sqrt = modpow(x, power / 2, mod);
    sqrt *= sqrt;
    sqrt %= mod;
    if (power % 2) sqrt *= x;
    sqrt %= mod;
    return sqrt;
}

template<typename T = int>
vector<T> read(int n) {
    vector<T> v (n);
    for (T& x : v) cin >> x;
    return v;
}

template<typename T = int>
vector<vector<T>> read(int n, int m) {
    vector<vector<T>> v (n, vector<T> (m));
    for (auto& x : v) x = read<T>(n);
    return v;
}

template<typename T = int>
void print(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

template<typename T = int>
void print(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}

void solve_test_case() {
    int n;
    cin >> n;
    auto a = read(n);
    auto b = read(n);
    int cnta = 0, cntb = 0;
    bool are_same_a = true, are_same_b = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i] && a[i] == 1) are_same_a = false;
        if (a[i] != b[i] && b[i] == 1) are_same_b = false;
        cnta += a[i];
        cntb += b[i];
    }
    std::cout << abs(cnta - cntb) + (!are_same_a && !are_same_b) << '\n';
}

signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}