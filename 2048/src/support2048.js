/*
*	底层支撑需要的js方法
*/

function getPosTop(i, j){
	return 20+i*120;
}

function getPosLeft(i, j){
	return 20+j*120;
}

function getNumberBackgroundColor(number){
	switch(number){
		/*bug经历：将例如case 2: return "#09c"; break;误写成case: 2 return "#09c"; break;将:的位置写错了，语法出现了错误，甚至导致了其他完全没有关系的函数也报错，很没头绪，必须警惕*/
		case 2: return "#eee4da"; break;
		case 4: return "#ede0c8"; break;
		case 8: return "#f2b179"; break;
		case 16: return "#f59563"; break;
		case 32: return "#f67e5f"; break;
		case 64: return "#f65e3b"; break;
		case 128: return "#edef72"; break;
		case 256: return "#edcc61"; break;
		case 512: return "#9c0"; break;
		case 1024: return "#33b5e5"; break;
		case 2048: return "#09c"; break;
		case 4096: return "#a6e"; break;
		case 8192: return "#93e"; break;
	}
	
	return "black";
}
function getNumberColor(number){
	if(number <= 4)
		return "#776e65";
		
	return "white";
}

function nospace(board){
	for(var i=0; i<4; i++)
		for(var j=0; j<4; j++){
			if(board[i][j] == 0)
				return false;
		}
		
	return true;
}

function nomove(board){
	if(canMoveLeft(board) || canMoveRight(board) || canMoveUp(board) || canMoveDown(board))
		return false;
		
	return true;
}

/*
	判断能否左移
*/
function canMoveLeft(board){
	/*当前的格子的左侧的格子为空或者和当前格子的数字是一样的时候，就可以左移*/
	/*判断能不能向左移动，只需要判断右侧的三列就可以了*/
	for(var i=0; i<4; i++)
		for(var j=1; j<4; j++)
			if(board[i][j] != 0)
				if(board[i][j-1]==0 || board[i][j-1]==board[i][j])
					return true;
	/*否则就不能左移*/
	return false;
}

/*
	判断能否右移
*/
function canMoveRight(board){
	/*当前的格子的右侧的格子为空或者和当前格子的数字是一样的时候，就可以右移*/
	/*判断能不能向右移动，只需要判断左侧的三列就可以了*/
	for(var i=0; i<4; i++)
		for(var j=2; j>=0; j--)
			if(board[i][j] != 0)
				if(board[i][j+1]==0 || board[i][j+1]==board[i][j])
					return true;
	/*否则就不能右移*/
	return false;
}

/*
	判断能否上移
*/
function canMoveUp(board){
	/*当前的格子的上侧的格子为空或者和当前格子的数字是一样的时候，就可以上移*/
	/*判断能不能向上移动，只需要判断下侧的三列就可以了*/
	for(var j=0; j<4; j++)
		for(var i=1; i<4; i++)
			if(board[i][j] != 0)
				if(board[i-1][j]==0 || board[i-1][j]==board[i][j])
					return true;
	/*否则就不能上移*/
	return false;
}

/*
	判断能否下移
*/
function canMoveDown(board){
	/*当前的格子的下侧的格子为空或者和当前格子的数字是一样的时候，就可以下移*/
	/*判断能不能向下移动，只需要判断上侧的三列就可以了*/
	for(var j=0; j<4; j++)
		for(var i=2; i>=0; i--)
			if(board[i][j] != 0)
				if(board[i+1][j]==0 || board[i+1][j]==board[i][j])
					return true;
	/*否则就不能下移*/
	return false;
}

/*
	第row行的第col1列和第col2列之间是不是有障碍物
*/
function noBlockHorizontal(row, col1, col2 ,board){
	for(var i=col1+1; i<col2; i++)
		if(board[row][i] != 0)
			return false;
	
	return true;
}

/*
	第col行的第row1列和第row2列之间是不是有障碍物
*/
function noBlockVertical(col, row1, row2 ,board){
	for(var i=row1+1; i<row2; i++)
		if(board[i][col] != 0)
			return false;
	
	return true;
}





































