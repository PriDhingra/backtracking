bool isSafe(int row, int col, vector<vector<int>>& sudoku, int val) {
	for(int i = 0;i < 9;i++) {
		if(sudoku[row][i] == val)
			return false;
		
		if(sudoku[i][col] == val)
			return false;
		
		if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val) 
			return false;
		
	}
	
	return true;
}

bool solve(vector<vector<int>>& sudoku) {
	for(int row = 0; row < 9;row++) {
		for(int col = 0;col < 9;col++) {
			if(sudoku[row][col] == 0) {
				for(int i = 1;i <= 9;i++) {
					if(isSafe(row, col, sudoku, i)) {
						sudoku[row][col] = i;
						bool isSolution = solve(sudoku);
						if(isSolution)
							return true;
						else
							sudoku[row][col] = 0;
					}
				}
				
				return false;
			}
		}
	}
	
	return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
	
	solve(sudoku);
}
