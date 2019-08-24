# include <iostream>
# include <queue>
# include <vector>
# include <tuple>

void fillVisited(const std::vector<std::vector<int>>&  data, std::tuple<size_t, size_t>& node, std::vector<std::vector<bool>>& isVisited){
	std::queue<std::tuple<size_t, size_t>> nodesToProcess;
	nodesToProcess.push(node);
	size_t x,y;
	while(!nodesToProcess.empty()){
		std::tuple<size_t, size_t> node = nodesToProcess.front();
		std::tie(x,y) = node;
		if(((x+1) < data.size()) && (data[x+1][y] == 1) && !isVisited[x+1][y])
		{
			nodesToProcess.push(std::make_tuple(x+1,y));
		}
		if(((x+1) < data.size()) && (y > 0) && (data[x+1][y-1] == 1) && !isVisited[x+1][y-1])
		{
			nodesToProcess.push(std::make_tuple(x+1,y-1));
		}
		if(((x+1) < data.size()) && ((y+1) < data[0].size()) && (data[x+1][y+1] == 1) && !isVisited[x+1][y+1])
		{
			nodesToProcess.push(std::make_tuple(x+1,y+1));
		}
		/*if((x >0 ) && (data[x-1][y] == 1) && !isVisited[x-1][y])
		{
			nodesToProcess.push(std::make_tuple(x-1,y));
		}
		if((x > 0) && (y > 0) && (data[x-1][y-1] == 1) && !isVisited[x-1][y-1])
		{
			nodesToProcess.push(std::make_tuple(x-1,y-1));
		}
		if((x > 0) && ((y+1) < data[0].size()) && (data[x-1][y+1] == 1) && !isVisited[x-1][y+1])
		{
			nodesToProcess.push(std::make_tuple(x-1,y+1));
		}
		if((y > 0) && (data[x][y-1] == 1) && !isVisited[x][y-1])
		{
			nodesToProcess.push(std::make_tuple(x,y-1));
		}*/
		if(((y+1) < data[0].size()) && (data[x][y+1] == 1) && !isVisited[x][y+1])
		{
			nodesToProcess.push(std::make_tuple(x,y+1));
		}
		isVisited[x][y] = true;
		nodesToProcess.pop();
	}
}

int findNumIslands(const std::vector<std::vector<int>>&  data){
	std::vector<std::vector<bool>> isVisited;
	int numIslands = 0;
	//initialize
	for(size_t i=0;i<data.size();i++){
		std::vector<bool> row;
		for(size_t j=0;j<data[i].size();j++){
			row.push_back(false);
		}
		isVisited.push_back(row);
	}
	//find by visiting the nodes
	for(size_t i=0;i<data.size();i++){
		for(size_t j=0;j<data[i].size();j++){
			if(data[i][j]==0 || isVisited[i][j]){
				continue;
			}
			else{
				auto node = std::make_tuple(i,j);
				fillVisited(data,node,isVisited);
				numIslands++;
			}
		}
	}
	return numIslands;
}



int main(){
	std::vector<std::vector<int>>  data {
			{1, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 0, 0, 0},
			{1, 1, 0, 0, 1},
			{1, 1, 0, 0, 1}
	};
	int numIslands = findNumIslands(data);
	std::cout << "Found " << numIslands << " islands." << std::endl;
}
