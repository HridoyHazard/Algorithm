#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

void permutation(int taken, int n, vector<int> &vec, vector<bool> &vis, vector<int> &res) {
//    cout << idx << endl;
    if(taken == n) {
        for(int i=0; i<n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i=0; i<n; i++) {
        if( !vis[i] ) {
            res.push_back(vec[i]);
            vis[i] = true;
            permutation(taken+1, n, vec, vis, res);
            vis[i]=false;
            res.pop_back();
        }
    }

    return;
}

int main() {

    int n;
    while(cin >> n) {
        vector<int> varr(n);
        for(int i=0; i<n; i++) {
            cin >> varr[i];
        }
        vector<bool> mark(n, false);
        vector<int> res;

        permutation(0, n, varr, mark, res);
    }

    return 0;
}
