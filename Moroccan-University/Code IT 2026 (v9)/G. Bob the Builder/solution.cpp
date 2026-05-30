#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

bool valid(  vector<int> &arr , ll w ){
    ll curr = 0 ; 
    for( int i : arr ){
        curr += i ; 
        if( curr == w ){
            curr = 0 ; 
        } else if( curr > w ) return false ; 
    }
    return curr == 0 ; 
}

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    ll sum = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        sum += arr[i] ; 
    }
    
    vector<pair<ll,ll>> ans ; 
    int count = 0 ; 
    
    for( ll i=2 ; i*i<=sum ; ++i ){
        if( sum % i == 0 ){
            if( valid( arr , i ) ){
                ans.push_back( { i , sum/i } ) ; 
                count++ ; 
            }
            if( i != sum / i && valid( arr , sum / i ) ){
                ans.push_back( {sum/i,i} ) ; 
                count++ ; 
            }
        }
    }

    cout << count << '\n' ; 
    sort( all(ans) ) ; 
    for( auto &[ a , b ] : ans ){
        cout << a << " " << b << '\n' ; 
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