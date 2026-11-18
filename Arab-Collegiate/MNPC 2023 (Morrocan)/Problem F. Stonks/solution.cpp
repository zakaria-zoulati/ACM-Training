#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;
using ll = long long;

void solve() {
    map<int,string> m_is  ; 
    map<string,int> m_si  ; 
    m_is[0] = "" ; 
    m_si[""] = 0 ; 
    vector<int> f(1,0) ; 
    vector<ll> count(1,0) ; 
    int q ; cin >> q ;
    int best = 0 ;
    ll bcount = 0 ; 
    int els = 0 ;  
    int curr =1 ; 
    while( q-- ){
        int t ; cin >> t ; 
        if( t == 1 ){
            string s ; cin >> s ; 
            int price ; cin >> price ; 
            if( m_si[s] == 0 ){
                m_si[s] = curr ; 
                m_is[curr] = s ; 
                curr++ ; 
                count.push_back(0) ;
                f.push_back(0) ;
            }

            if( f[ m_si[s] ] == els ){
                f[ m_si[s] ]++ ;
                els++ ; 
                best = m_si[s] ; 
                count[ m_si[s] ] += price ; 
                bcount = count[ m_si[s] ] ; 
            }else if( ++f[ m_si[s]] == els ){
                count[ m_si[s] ] += price ; 
                if( count[ m_si[s] ] > bcount ){
                    bcount = count[ m_si[s] ] ; 
                    best = m_si[s] ; 
                }else if( count[ m_si[s] ] == bcount && s < m_is[best] ){
                    best = m_si[s] ;
                }
            }else{
                count[ m_si[s] ] += price ; 
            }
        }else {
            cout << m_is[best] << '\n' ; 
        }
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