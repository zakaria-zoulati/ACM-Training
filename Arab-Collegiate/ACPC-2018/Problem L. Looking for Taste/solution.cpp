#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll rs = 0;  
    for( int i=0 ; i<n ; ++i ){
        rs |= arr[i] ; 
    }
    cout << rs << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("looking.in", "r", stdin);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}