



struct point {
	int x ; int y;
}
// row == n && col==m
int isValid(int row , int col){
	return row<n && col<m && row>=0 && col>=0;
}

struct queueNode
{
    point pt;  // The cordinates of a cell
    int dist;  // cell's distance of from the source
};
 
int r = {-1 , 1 , 0 , 0};
int c = { 0 , 0 , 1 , -1};

int BFS(int mat[][col] , point scr , point des) {

	if(!mat[scr.x][scr.y] && !mat[des.x][des.y]){
		return -1;
	}

	vector<vector<int>> v;
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0 ; j < m ; j ++){
			v[i][j]=0;
		}
	}
	v[scr.x][scr.y] = 1;

	queueNode s = {scr , 0}
	q.push(s);

	while(!q.empty()){
		queueNode curr = q.front();
		point pt = curr.point;

		if(pt.x == des.x && pt.y == des.y){

			return curr.dist;

		}

		for (int i = 0; i < 4; ++i)
		{
			int row = pt.x + r[i];
			int col = pt.y + c[i];

			if (isValid(row, col) && mat[row][col] &&
               !visited[row][col])
            {
                // mark cell as visited and enqueue it
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
            }
        }
		
	}
	return -1;

}