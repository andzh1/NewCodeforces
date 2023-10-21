#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define vi vector<int>
#define get(a) int a; cin >> a;
#define repeat(n) for(int i = 0; i < n; ++i)
#define loop(j, n) for(int j = 0; j < n; ++j)
#define iloop(n) loop(i, n)
#define jloop(n) loop(j, n)
#define kloop(n) loop(j, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define foreach(val, container) for (const auto& val : container)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

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


template<typename T>
void print(const T& v) {
    cout << v << ' ';
}

template<typename T = int>
void print(const vector<T>& v) {
    for (const auto& x : v) print(x);
    cout << '\n';
}

template<typename T = int>
void print(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}


template <typename TContainer>
void sort(TContainer& v) {
  sort(all(v));
}

template <typename TContainer>
void rsort_v(TContainer& v) {
  sort(rall(v));
}

// template <typename AxisType = int>
// struct Point {
//   AxisType x = 0;
//   AxisType y = 0;
//   int index = 0;
//   bool first_compare_by_x_ = true;

//   explicit Point(AxisType x, AxisType y) : x(x), y(y) {}
//   explicit Point(AxisType x, AxisType y, bool cmp)
//       : x(x), y(y), first_compare_by_x_(cmp) {}
//   explicit Point(AxisType x, AxisType y, int index)
//       : x(x), y(y), index(index) {}
//   explicit Point(AxisType x, AxisType y, int index, bool cmp)
//       : x(x), y(y), index(index), first_compare_by_x_(cmp) {}

//   bool operator<(const Point& other) const {
//     if (first_compare_by_x_) {
//       return (x < other.x) || (x == other.x && y < other.y) ||
//              (x == other.x && y == other.y && index < other.index);
//     } else {
//       return (y < other.y) || (y == other.y && x < other.x) ||
//              (x == other.x && y == other.y && index < other.index);
//     }
//   }
// };

template<typename first_t = int64_t, typename second_t = int64_t>
struct CustomComparablePair {
    first_t first;
    second_t second;
    int index = 0;

    explicit CustomComparablePair(first_t x, second_t y) : first(x), second(y) {}
    explicit CustomComparablePair(first_t x, second_t y, int index)
        : first(x), second(y), index(index) {}

    CustomComparablePair() = default;

    virtual bool operator<(const CustomComparablePair& other) const = 0;
};

template<typename first_t = int, typename second_t = int>
struct MyPoint: public CustomComparablePair<first_t, second_t> {
    using CustomComparablePair<first_t, second_t>::CustomComparablePair;


    bool operator<(const CustomComparablePair<first_t, second_t>& other) const override {
        const MyPoint& otherPoint = static_cast<const MyPoint&>(other);
        return (this->first < otherPoint.first) || 
               (this->first == otherPoint.first && this->second < otherPoint.second) ||
               (this->second == otherPoint.second && this->first == otherPoint.first && this->index < otherPoint.index);
    }
};

using two_int_t = MyPoint<int, int>;

struct Point {
    double x;
    double y;
};

double dist(const Point& first, const Point& second) {
    auto d1 = (first.x - second.x);
    auto d2 = (first.y - second.y);
    return sqrt(d1 * d1 + d2 * d2);
}

void solve_test_case() {
    Point P, A, B;
    std::cin >> P.x >> P.y >> A.x >> A.y >> B.x >> B.y;
    Point start{0, 0};
    double distToA = dist(start, A);
    double distToB = dist(start, B);

    vector<double> ans;

    // A, A
    auto w1 = max(dist(A, start), dist(A, P));
    // B, B
    auto w2 = max(dist(B, start), dist(B, P));
    // A, B
    auto w3 = max(max(dist(A, start), dist(B, P)), dist(A, B) / 2);
    auto w4 = max(max(dist(B, start), dist(A, P)), dist(A, B) / 2);

    cout << setprecision(11) << min(w1, min(w2, min(w3, w4))) << '\n';
}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}

