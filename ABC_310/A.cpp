#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N, drink_price, discounted_drink_price;
    cin >> N >> drink_price >> discounted_drink_price;

    vector<int> dish_prices(N);
    int min_dish_price = INT32_MAX;
    int dish_price;
    for(int i = 0; i < N; i++){
        cin >> dish_price;
        if (dish_price < min_dish_price){
            min_dish_price = dish_price;
        }
    }

    if (drink_price < discounted_drink_price + min_dish_price){
        cout << drink_price << endl;
        cerr << "drink_price" << endl;
    } else {
        cout << discounted_drink_price + min_dish_price << endl;
        cerr << "discounted_drink_price + min_dish_price" << endl;
    }
    return 0;
}