#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector
#define rep(i,s,e) for(int i = s;i < e;i++)
#define all(obj) obj.begin(),obj.end()


int main(){
    vector<int> a = {1,2,3,4};
    cout << a.back() << endl;

    a.back()++;
    cout << a.back()++ << "    " << ++a.back();
    return 0;
}