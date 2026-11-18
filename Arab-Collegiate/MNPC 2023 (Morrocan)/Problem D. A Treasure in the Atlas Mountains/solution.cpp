#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

void solve() {
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    int g = n % (k+1) ; 
    if( g == 0 ){
        cout << "Abdelghafour" << '\n' ; 
    }else {
        cout << "Khalil" << '\n' ; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1 ; 
    while (t--) {
        solve();
    }
    
    return 0;
}