bool isElligible(int size, int newX, int newY, 
				vector < vector < int >> &arr, 
				vector<vector<bool>> &visited) {
	
	if((newX >= 0 && newX < size) && (newY >= 0 && newY < size) && 
	  visited[newX][newY] == 0 && arr[newX][newY] == 1) 
		return true;
	else
		return false;
	
}

void solve(int srcX, int srcY, vector < vector < int >> &arr, int size,
		  vector<vector<bool>> &visited, vector<string> &result, 
		  string path) {
	if(srcX == size - 1 && srcY == size - 1) {
		result.push_back(path);
		return;
	}
	
	visited[srcX][srcY] = 1;
	
	int newX = srcX + 1;
	int newY = srcY;
	if(isElligible(size, newX, newY, arr, visited)) {
		path += "D";
		solve(newX, newY, arr, size, visited, result, path);
		path.pop_back();
	}
	
	newX = srcX;
	newY = srcY - 1;
	if(isElligible(size, newX, newY, arr, visited)) {
		path += "L";
		solve(newX, newY, arr, size, visited, result, path);
		path.pop_back();
	}
	
	newX = srcX;
	newY = srcY + 1;
	if(isElligible(size, newX, newY, arr, visited)) {
		path += "R";
		solve(newX, newY, arr, size, visited, result, path);
		path.pop_back();
	}
	
	newX = srcX - 1;
	newY = srcY;
	if(isElligible(size, newX, newY, arr, visited)) {
		path += "U";
		solve(newX, newY, arr, size, visited, result, path);
		path.pop_back();
	}
	
	visited[srcX][srcY] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
	vector<vector<bool>> visited (n, vector<bool>(n, 0));
	vector<string> result;
	string path = "";
	
	if(arr[0][0] == 0)
		return result;
	
	solve(0, 0, arr, n, visited, result, path);
	
	return result;
}
