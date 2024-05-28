#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()


struct item{
    int price;
    set<int> funcs;
};

int main(){
    int N,M;
    cin >> N >> M;
    vector<item> items(N);

    for (int i=0;i<N;i++){
        int func_num;
        cin >> items[i].price >> func_num;
        for (int j=0;j<func_num;j++){
            int func;
            cin >> func;
            items[i].funcs.insert(func);
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (i == j) continue;
            if (items[i].price < items[j].price) continue;

            set<int> same_func;
            set_intersection(all(items[i].funcs), all(items[j].funcs), inserter(same_func, same_func.begin()));

            if (same_func != items[i].funcs) continue;

            set<int> diff_func;
            set_difference(all(items[j].funcs), all(items[i].funcs), inserter(diff_func, diff_func.begin()));

            if (diff_func.size() > 0 || items[i].price > items[j].price){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}