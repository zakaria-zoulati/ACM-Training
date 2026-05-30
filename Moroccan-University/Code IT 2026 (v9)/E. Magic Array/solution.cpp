#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n , q ; 
    cin >> n >> q ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }    
    int mi = 0 , ma = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] < arr[mi] ){
            mi = i ; 
        }
        if( arr[i] > arr[ma] ){
            ma = i ; 
        }
    }
    while( q-- ){
        int t ; cin >> t ; 
        if( t == 4 ){
            cout << ma + 1 << '\n' ; 
        }else {
            int x ; cin >> x ; 
            if( t != 1 ){
                if( x == 0 ){
                    mi = 0 ; 
                    ma = 0 ; 
                }else if( x < 0 ){
                    int temp = mi ; 
                    mi = ma ; 
                    ma = temp ; 
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}