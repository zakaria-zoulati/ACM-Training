#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


bool isGood( vector<int> &a , int n ,  int i ){
    if( i > 0 && a[i-1] > a[i] ) return  false ; 
    if( i + 1 < n && a[i+1] < a[i] ) return false ; 
    return true ; 
}

bool isBad( vector<int> &a , int n ,  int i ){
    if( i > 0 && a[i-1] < a[i] ) return  false ; 
    if( i + 1 < n && a[i+1] > a[i] ) return false ; 
    return true ; 
}

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }    

    int good = 0 ; 
    int bad = 0 ; 


    for( int i=0 ; i<n ; ++i ){
        if( isGood( arr , n , i ) ) good++ ; 
        if( isBad( arr , n , i ) ) bad++ ; 
    }

    int q ; cin >> q ; 
    while( q-- ){
        int t ; cin >> t ; 
        if( t == 1 ){
            int i ; cin >> i ; 
            int v ; cin >> v ; 
            i-- ; 


            if( isGood( arr , n , i ) ) good--; 
            if( isBad( arr , n , i ) ) bad--; 
            if( i > 0 ){
                if( isGood( arr , n , i-1 ) ) good--; 
                if( isBad( arr , n , i-1 ) ) bad--; 
            }
            if( i + 1 < n ){
                if( isGood( arr , n , i+1 ) ) good--; 
                if( isBad( arr , n , i+1 ) ) bad--; 
            }

            arr[i] = v ; 
            if( isGood( arr , n , i ) ) good++; 
            if( isBad( arr , n , i ) ) bad++; 
            if( i > 0 ){
                if( isGood( arr , n , i-1 ) ) good++; 
                if( isBad( arr , n , i-1 ) ) bad++; 
            }
            if( i + 1 < n ){
                if( isGood( arr , n , i+1 ) ) good++; 
                if( isBad( arr , n , i+1 ) ) bad++; 
            }
        }else if( t == 2 ){
            cout << ( good == n ? "YES\n" : "NO\n" ) ; 
        }else {
            cout << ( bad == n ? "YES\n" : "NO\n" ) ; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}