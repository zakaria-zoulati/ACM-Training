#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int ans = 0;
        if (n > 1) {
            for (int i = 1; i < n; ++i) {
                ans = max(ans, abs(arr[i] - arr[i - 1]));
            }
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}
