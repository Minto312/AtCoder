#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector
#define rep(i,s,e) for(int i = s;i < e;i++)
#define all(obj) obj.begin(),obj.end()


int main(){
    int N;
    string t1,t2;
    cin >> N >> t1 >> t2;

    if (t1 == t2){
        cout << "Yes" << endl;
        return 0;
    } 

    bool con1,con2,con3;
    rep(i,0,N){
        con1 = t1[i] == '1' || t1[i] == 'l';
        con1 = con1 && (t2[i] == '1' || t2[i] == 'l');
        // cout << "con1   " << con1 << endl; //debug
        con2 = t1[i] == '0' || t1[i] == 'o';
        con2 = con2 && (t2[i] == '0' || t2[i] == 'o');
        // cout << "con2   " << con2 << endl; //debug
        con3 = t1[i] == t2[i];

        if (!(con1 || con2 || con3)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}