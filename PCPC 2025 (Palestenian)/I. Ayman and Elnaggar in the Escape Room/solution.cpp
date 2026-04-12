#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }    

    int best = 0 ; 
    int ans = 0 ; 

    int curr = 0 ; 
    int prev = 0 ; 
    vector<bool> f(n+1,false) ; 

    for( int i=0 ; i<n ; ++i ){
        if( f[ arr[i] ]  ){
            while( arr[prev] != arr[i] ){
                if( arr[prev] < curr ){
                    curr = arr[prev] ; 
                }
                f[ arr[prev] ] = false ; 
                prev++ ; 
            }
            prev++ ; 
        }else if( arr[i] == curr ){
            curr++ ; 
            while( curr+1<=n && f[curr+1] ){
                curr++ ; 
            }
        }
        f[ arr[i] ] = true ; 
        if( curr > best ){
            best = curr ; 
            ans = i - prev + 1 ; 
        }else if( curr == best ){
            ans = max( ans , i - prev + 1 ) ; 
        }
    }
    cout << ans << '\n' ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}