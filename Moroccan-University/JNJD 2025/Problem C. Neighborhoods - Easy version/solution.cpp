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
    int n , k ; 
    cin >> n >> k ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> arr[i] ; 
    sort( arr.begin() , arr.end() ) ; 
    int rs = 1 ; 
    for( int i=1 ; i<n ; ++i ){
        if( arr[i] - arr[i-1] > k ){
            rs++ ; 
        }
    }
    cout << rs << '\n' ; 
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