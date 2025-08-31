#include<bits/stdc++.h>
using namespace std;

void dfsRec(vector<vector<int>> &adj,vector<bool> &visited, int s, vector<int> &res){
visited[s]=true;
res.push_back(s);

for(auto x:adj[s]){
    if(visited[x]==false) dfsRec(adj,visited,x,res);
}


}

vector<int> dfs(vector<vector<int>> &adj){

vector<bool> visited(adj.size(),false);
int s=0;
vector<int> res;
dfsRec(adj,visited,s,res);
return res;
}

vector<int> bfs(vector<vector<int>> &adj){
int V=adj.size();
int s=0;

vector<bool> visited(V,false);
vector<int> res;
queue<int> q;

visited[s]= true;
q.push(s);

while(!q.empty()){
    int curr=q.front();
    q.pop();
    res.push_back(curr);

    for(int x:adj[curr]){
        if(!visited[x]){
            visited[x]=true;
            q.push(x);
        }
    }
}
return res;
}

int main(){

vector<vector<int>> adj={{1,2,3},{0,2,4},{0,1,3,4,5},{0,2,5},{1,2},{2,3}};

vector<int> ans=bfs(adj);

for(auto i:ans){
    cout<<i<<" ";
}
cout<<endl;

vector<int> res=dfs(adj);
for(auto j:res){
    cout<<j<<" ";
}

return 0;
}
