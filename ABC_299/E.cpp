#include <bits/stdc++.h>
using namespace std;

void print_array(vector<int>& array,int array_size){
    for (int row = 0;row < array_size;row++){
        for (int column = 0;column < array_size;column++){
                printf("%5d",array[row * array_size + column]);
        }
        cout << endl;
    }
}

bool term_check(vector<int>& choosing_nodes,vector<vector<int>>& possible_nodes,vector<vector<int>>& taboo_nodes,int term_idx,int term_count){
    if (static_cast<int>(choosing_nodes.size()) == term_count){
        return true;
    }
    for (int i = 0,size = taboo_nodes[term_idx].size();i < size;i++){
        int taboo = taboo_nodes[term_idx][i];
        if (any_of(choosing_nodes.begin(),choosing_nodes.end(),[taboo](int x){return x == taboo;})){
            return false;
        }
    }

    bool result = false;
    int size = possible_nodes.at(term_idx).size();
    for (int i = 0;i < size;i++){
        choosing_nodes.emplace_back(possible_nodes[term_idx][i]);
        result = term_check(choosing_nodes,possible_nodes,taboo_nodes,term_idx + 1,term_count);

        if (result){
            return true;
        }else{
            choosing_nodes.pop_back();
        }
    }

    return false;
}
int main(){
    const int MAX_NODE_COUNT = 2001;

    int node_count,side_count;

    cin >> node_count >> side_count;

    vector<int> distance(node_count * node_count,MAX_NODE_COUNT);
    for (int row = 0;row < node_count;row++){
        for (int column = 0;column < node_count;column++){
            if (row == column){
                distance[row * node_count + column] = 0;
            }
        }
    }

    int side_A,side_B;
    int neighbor[node_count][node_count] = {};
    for (int i = 0;i < side_count;i++){
        cin >> side_A >> side_B;

        side_A--;
        side_B--;

        distance[side_A * node_count + side_B] = 1;
        distance[side_B * node_count + side_A] = 1;

        neighbor[side_A][neighbor[side_A][0] + 1] = side_B;
        neighbor[side_A][0]++;

        neighbor[side_B][neighbor[side_B][0] + 1] = side_A;
        neighbor[side_B][0]++;
    }

    queue<int> searching_queue;
    for (int i = 0;i < node_count;i++) searching_queue.push(i);
    int current_node;
    vector<int> dist_cache;
    while (!searching_queue.empty()){
        current_node = searching_queue.front();
        searching_queue.pop();
        for (int target = 0;target < node_count;target++){
            if (distance[current_node * node_count + target] == MAX_NODE_COUNT){
                dist_cache.clear();
                for (int i = 1,neigh;i <= neighbor[current_node][0];i++){
                    neigh = neighbor[current_node][i];
                    dist_cache.emplace_back(1 + distance[neigh * node_count + target]);
                }
                int min = MAX_NODE_COUNT;
                for (int x : dist_cache){
                    if (x < min) min = x;
                }
                if (min < MAX_NODE_COUNT){
                    distance[current_node * node_count + target] = min;
                }else{
                    searching_queue.push(current_node);
                }
            }
        }
    }
    // print_array(distance,node_count);

    int term_count;
    cin >> term_count;

    int term_nodes[node_count];
    int term_dist[node_count];
    for (int i = 0;i < term_count;i++){
        cin >> term_nodes[i] >> term_dist[i];
        term_nodes[i]--;
    }
    vector<vector<int>> possible_nodes(term_count,vector<int>(0));
    vector<vector<int>> taboo_nodes(term_count,vector<int>(0));

    for (int term_idx = 0,current_node;term_idx < term_count;term_idx++){
        current_node = term_nodes[term_idx];
        // possible_nodes.emplace_back(current_node);
        // taboo_nodes.emplace_back(current_node);
        for (int check_node = 0;check_node < node_count;check_node++){
            if (distance[current_node * node_count + check_node] == term_dist[term_idx]){
                possible_nodes[term_idx].emplace_back(check_node);
            }else if (distance[current_node * node_count + check_node] < term_dist[term_idx]){
                taboo_nodes[term_idx].emplace_back(check_node);
            }
        }
    }

    vector<int> choosing_nodes(0);
    if (term_check(choosing_nodes,possible_nodes,taboo_nodes,0,term_count)){
        cout << "Yes" << endl;

        string text = "";
        int choosing_idx = 0;
        for (int i = 0;i < node_count;i++){
            try{
                if (i == choosing_nodes.at(choosing_idx)){
                    text += "1";
                    choosing_idx++;
                }else{
                    text += "0";
                }
            }catch(const out_of_range& e){
                text += "1";
            }
        }
        cout << text << endl;
    }else{
        cout << "No" << endl;
    }

    system("pause");
    return 0;
}
