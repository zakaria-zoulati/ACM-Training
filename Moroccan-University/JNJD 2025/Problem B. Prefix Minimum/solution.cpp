#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <utility>
#include <fstream>
#include <cmath>
#include <iomanip>


using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    for( int i=1 ; i<n ; ++i ){
        if( arr[i] >= arr[i-1] ){
            cout << "NO" << '\n' ; 
            return ; 
        }
    }
    cout << "YES" << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}