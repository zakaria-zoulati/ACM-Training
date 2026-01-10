#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 998244353 ;

int get( vector<vector<ll>> &sparse , int l , int r ){
    int k = (int) log2( r - l + 1 )  ; 
    int ans = sparse[l][k] | sparse[r-(1<<k)+1][k] ; 
    return ans ; 
}

ll getLeft( int i , map<int,int> &m , int val , vector<vector<ll>> &sparse , int n ){
    if( i == 0 || sparse[i-1][0] >= val || ( sparse[i-1][0] & val ) != sparse[i-1][0] ){
        return i ; 
    }
    int l = ( m.find( val ) == m.end() ? 0 : m[val] + 1 ) ; 
    int r = i-1 ; 
    while( l < r ){
        int mid = l + ( r - l )/2 ; 
        int curr = get( sparse , mid , i-1 ) ; 
        if( ( val & curr ) == curr ){
            r = mid ; 
        }else {
            l = mid + 1 ; 
        }
    }
    return l ; 
} 
ll getRight( int i , int val , vector<vector<ll>> &sparse , int n ){
    int l = i ; 
    int r = n-1 ; 
    while( l < r ){
        int mid = l + ( r - l + 1 )/2 ; 
        if( get( sparse , i , mid ) == val ){
            l = mid ; 
        }else {
            r = mid - 1 ;
        }
    }
    return l ; 
}

void solve(){
  int n ; cin >> n ; 
  vector<ll> arr(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> arr[i] ; 
  }
  int k = log2( n ) ; 
  vector<vector<ll>> sparse_or( n , vector<ll>( k+1 , 0 )) ; 
  for( int i=0 ; i<n ; ++i ){ 
      sparse_or[i][0] = arr[i] ; 
  }
  for( int i=1 ; i<=k ; ++i ){
      for( int j=0 ; j<n ; ++j ){
          if( j + ( 1 << i ) <= n ){
              sparse_or[j][i] = (sparse_or[j][i-1] | sparse_or[j+(1<<(i-1))][i-1]) ; 
          }
      }
  }
 
  ll ans = 0; 
  map<int,int> m ; 
  for( int i=0 ; i<n ; ++i ){
      ll l = getLeft( i , m , arr[i] , sparse_or , n  ) ; 
      ll r = getRight( i , arr[i] , sparse_or , n ) ; 
      m[arr[i]] = i ; 
      ans += (i-l+1)*(r-i+1) ; 
  }
  
  cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
