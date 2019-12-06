# include <iostream>
# include <queue>
# include <vector>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int countOfNodes = graph.size();
    int* colors = new int[countOfNodes];
    queue<int> q;
    colors[0] = 1;
    for(int i=1;i<countOfNodes;i++){
        colors[i] = 0;
    }
    q.push(0);
    while(q.size()>0){
        int node = q.front();
        q.pop();
        int color = colors[node]==1?-1:1;
        for(size_t i=0; i<graph[node].size();i++){
            int adj = graph[node][i];
            if(colors[adj]==0){
                colors[adj] = color;
                q.push(adj);
            }
            else if(colors[adj]!=color){
                return false;
            }
        }
    }
    return true;
}

int main(){
	std::vector<std::vector<int>>  data {
			{1, 3},
			{0, 2},
			{1, 3},
			{0, 2}
	};
	bool isBipartiteGraph = isBipartite(data);
	std::cout << "isBipartiteGraph: " << isBipartiteGraph << std::endl;
}