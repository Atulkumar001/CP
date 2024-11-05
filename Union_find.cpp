#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int n, set_size;
    vector<int> parent, rank;

    UnionFind(int a){
        n = set_size = a;
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y){
        int rootX = find(x), rootY = find(y);
        if(rootX != rootY){
            if(rank[rootX] >= rank[rootY]) {
                parent[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }
            else{
                parent[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
            set_size -= 1;
        }
    }
    
    void reset(){
        set_size = n;
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int size(){
        return set_size;
    }
    
    void print(){
        for(int i = 1; i <= n; i++){
            cout << i << " --> " << parent[i] << "\n";
        }
    }
        
        
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0){
            uf.merge(x, y);
        } 
        else if(com == 1){
            cout << uf.same(x, y) << '\n';
        }
    }
    
    return 0;
}
