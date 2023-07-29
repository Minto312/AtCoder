#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(obj) obj.begin(), obj.end()
#define vv vector<vector<


bool solve(){
    vector <int> a(8);
    for (int i = 0; i < 8; i++){
        cin >> a[i];
    }

    if (a[0] < 100 || a[7] > 675) return false;
    if (a[0] % 25 != 0) return false;
    for (int i = 1; i < 8; i++){
        if (a[i] < a[i-1]) return false;
        if (a[i] % 25 != 0) return false;
    }
    return true;
}

int main(){
    if (solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}