#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector
#define all(obj) obj.begin(),obj.end()

int main(){
    int N;
    cin >> N;

    vector<string> words(N);
    for (int i=0;i<N;i++){
        cin >> words[i];
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (i == j) continue;

            string str = words[i] + words[j];
            string rstr = str;
            reverse(all(rstr));
            if (str == rstr){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}