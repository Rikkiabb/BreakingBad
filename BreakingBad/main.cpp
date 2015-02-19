#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<int>side(100001, -1);

bool is_bipartite = true;

struct edge {
    string u;
    int weight;
    edge(string _u, int _w) {
        u = _u;
        weight = _w;
    }
};

vector<int>adj[100001];

void check_bipartite(int u){
    
    for(int i = 0; i < adj[u].size(); i++){
    
        int v = adj[u][i];
        if(side[v] == -1){
        
            side[v] = 1 - side[u];
            check_bipartite(v);
        
        } else if(side[u] == side[v]){
        
            is_bipartite = false;
        
        }
    
    }

}


int main() {

    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int n = 0;
    cin >> n;
    
    vector<edge>graph; // Graph which keeps the index and the string
    map<string,int>indexes; // To find the index of a string
    map<string,int>::iterator it;
    
    for(int i = 0; i < n; i++){
        
        string name;
        cin >> name;
        graph.push_back(edge(name, i));
        indexes.insert(pair<string, int>(name, i));
        
    }
    
    int m = 0;
    cin >> m;

    for(int i = 0; i < m; i++){
        
        string n1 = "", n2 = "";
        cin >> n1 >> n2;
        int number1 = 0, number2 = 0;
        
        it = indexes.find(n1);
        number1 = it->second;

        
        it = indexes.find(n2);
        number2 = it->second;

        
        adj[number1].push_back(number2); // Add edges to both
        adj[number2].push_back(number1);
    
    }
    

    
    for(int u = 0; u < n; u++){
    
        if(side[u] == -1){
        
            side[u] = 0;
            check_bipartite(u);
        
        }
    
    }
    
    if(!is_bipartite){ // Can't split them
    
        cout << "impossible" << endl;
    
    }
    
    if(is_bipartite){
    
        for(int i = 0; i < n; i++){
            
            if(side[i] == 0){
            
                cout << graph[i].u << " ";
            
            }
        
        }
        
        cout << endl;
        
        for(int i = 0; i < n; i++){
            
            if(side[i] != 0){
                
                cout << graph[i].u << " ";
                
            }
            
        }
        
    
    }

    return 0;
}
