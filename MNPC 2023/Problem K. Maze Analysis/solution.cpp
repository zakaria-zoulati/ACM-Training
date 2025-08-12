#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* left;   
    Trie* right;  
    int count;

    Trie() {
        left = nullptr;
        right = nullptr;
        count = 0;
    }

    void insert(const string& s) {
        Trie* root = this;
        for (char c : s) {
            if (c == 'L') {
                if (!root->left) {
                    root->left = new Trie();
                }
                root = root->left;
            } else {
                if (!root->right) {
                    root->right = new Trie();
                }
                root = root->right;
            }
            root->count++;
        }
    }

    int getCount(const string& s) {
        Trie* root = this;
        for (char c : s) {
            if (c == 'L') {
                if (!root->left) return 0;
                root = root->left;
            } else {
                if (!root->right) return 0;
                root = root->right;
            }
        }
        return root->count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie t;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s; 
        t.insert(s);
    }

    for (int i = 0; i < k; ++i) {
        string s; cin >> s ;
        cout << t.getCount(s) << "\n";
    }

    return 0;
}
