#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(obj) obj.begin(), obj.end()
#define vv vector<vector<




int main(){
    int N,price_color_n;
    cin >> N >> price_color_n;

    vector<string> ate_color(N);
    for (int i = 0; i < N; i++){
        cin >> ate_color[i];
    }

    vector<string> price_color(price_color_n+2,"end");
    for (int i = 1; i <= price_color_n; i++){
        cin >> price_color[i];
    }

    vector<int> price(price_color_n+1);
    for (int i = 0; i < price_color_n+1; i++){
        cin >> price[i];
        // cout << i << "   " << price[i] << endl; //debug
    }

    int sum = 0;
    for (string x : ate_color){
        // cout << x << endl; //debug
        for (int i = 1; i < price_color.size(); i++){
            if (x == price_color[i]){
                // cout << x << " = " << price_color[i] << endl; //debug
                sum += price[i];
                // cout << price[i] << endl; //debug
                // cout << sum << endl; //debug
                break;
            }else if (price_color[i] == "end"){
                // cout << i << " = " << price_color[i] << endl; //debug
                sum += price[0];
                // cout << sum << endl; //debug
            }
        }
    }
    cout << sum << endl;

    return 0;
}