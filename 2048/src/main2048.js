/*
*	游戏的主逻辑需要的js方法
*		bug经历：将main2048.js误写成mian2048.js，但是在index.html里面还是加载的main2048.js，所以当然就导致页面上没有效果
*		经验总结：在index.html里面加载了main2048.js和support2048.js，那么在main2048.js里面调用support2048.js里面的函数，就不需要再在，main2048.js里面再写加载support2048.js的语句了，其他也都类似
*/

/*
	游戏所需的所有数据
*/
var board = new Array();		//这是2048游戏的格子中需要的数据，存在一个数组里面
var score = 0;					//存储分数
var hasConflicted = new Array();	//记录每一个小格子是否已经发生过了一次碰撞

/*
	当整个程序加载完毕之后，运行的主函数
*/
$(document).ready(function(){
	newgame();	//开始一个新的游戏
});

/*
	开始新的游戏
*/
function newgame(){
	init();//初始化棋盘
	
	/*在随机两个格子生成数字（2或者4）*/
	generateOneNumber();//因为随机生成一个数字是这个游戏中常会用到的函数，所以讲随机生成两个数字拆分用两个随机生成一个数字的方法实现，更利于方法的重用
	generateOneNumber();
}

/*
	初始化棋盘
*/
function init(){
	for(var i=0; i<4; i++)
		for(var j=0; j<4; j++){
			var gridCell = $("#grid-cell-"+i+"-"+j);	//通过id来获取相应的格子对象
			gridCell.css('top',getPosTop(i, j) );		//调用support2048.js里面的函数getPosTop(i, j) ，注意使用css()函数设置$("#grid-cell-"+i+"-"+j)元素的top值
			gridCell.css('left',getPosLeft(i, j) );		//调用support2048.js里面的函数getPosLeft(i, j) 
		}
	
	for(var i=0; i<4 ;i++){
		board[i]=new Array();		//将board由原来定义的一位数组初始化为现在所需要的二维数组
		hasConflicted[i]=new Array();
		for(var j=0; j<4; j++){
			board[i][j]= 0;
			hasConflicted[i][j]=false;
		}
	}
	
	updateBoardView();		//该函数用于通知前端，对数据进行重新的设定
	
	score = 0;
	
}

/*
	根据board变量的值，对前端的number-cell元素进行操作（因为没有在index.html里面定义number-cell元素，所以首先要动态的添加numbercell元素）
*/
function updateBoardView(){
	$(".number-cell").remove();		//如果当前游戏里面已经有了number-cell元素，首先要删除掉这些元素（注意使用$(".number-cell")格式获取class为number-cell的元素）
	for(var i=0; i<4; i++)			//再根据当前的board值来添加新的number-cell元素
		for(var j=0; j<4; j++){
			$("#grid-container").append('<div class="number-cell" id="number-cell-'+i+'-'+j+'"></div>');		//在#grid-container元素里面追加16个.number-cell元素
			var theNumberCell = $('#number-cell-'+i+'-'+j);
			
			if(board[i][j] == 0){//board[i][j]没有数值的情况
				theNumberCell.css('width', '0px');
				theNumberCell.css('height', '0px');
				
				/*将number-cell放在grid-cell的中间，因为number-cell和grid-cell都是参照grid-container的绝对定位*/
				theNumberCell.css("top",getPosTop(i, j)+50);
				theNumberCell.css("left",getPosLeft(i, j)+50);
			}
			else{//board[i][j]有值时，用number-cell覆盖grid-cell（即number-cell显示的宽、高、位置和grid-cell是一样的），也是因为number-cell和grid-cell都是参照grid-container的绝对定位
				theNumberCell.css('width', '100px');
				theNumberCell.css('height', '100px');
				theNumberCell.css('top',getPosTop(i, j) );
				theNumberCell.css('left',getPosLeft(i, j) );
				
				/*根据数字的不同显示不同的颜色*/
				theNumberCell.css('background-color', getNumberBackgroundColor(board[i][j]));		//背景色，getNumberBackgroundColor(board[i][j])在support2048.js里面
				theNumberCell.css('color', getNumberColor(board[i][j]));					//前景色，getNumberColor(board[i][j])在support2048.js里面
				
				/*number-cell显示数值*/
				theNumberCell.text(board[i][j]);
			}
			
			hasConflicted[i][j]=false;
		}
}

/*
*	在随机一个格子里面生成数字
*/
function generateOneNumber(){
	if(nospace(board)){//先去判断现在的情况还能不能生成一个数字
		return false;	//只要当前的4*4的棋盘格子里面没有空间，就不能生成新的数字
	}
	
	/*随机选择一个位置*/
	var randx = parseInt(Math.floor(Math.random()*4));
	var randy = parseInt(Math.floor(Math.random()*4));
	
	/*判断该随机位置是否可用，也就是判断该位置是否已经被占用了*/
	while(true){
		if(board[randx][randy] == 0)
			break;
		else{
			var randx = parseInt(Math.floor(Math.random()*4));
			var randy = parseInt(Math.floor(Math.random()*4));
		}
	}
	
	/*随机选择一个要显示的数字（2或者4）*/
	randNumber = Math.random()<0.5 ? 2 : 4;
	
	/*在随机选择的位置，显示随机选择的那个数字*/
	board[randx][randy]=randNumber;
	showNumberWithAnimation(randx, randy, randNumber);		//使用动画的效果，在随机选择的位置，显示随机选择的那个数字
	
	return true;		//其他情况，return true，也就是还能随机生成数字
}

/*
	实现玩家按下一个按键时候的操作
*/
$(document).keydown(function(event){
	switch(event.keyCode){
		case 37://左方向键的编号
			if(moveLeft()){
				setTimeout("generateOneNumber()",210);//格子移动后，游戏就会再随机生成一个数字
				setTimeout("isgameover()",300);//判断游戏是否结束
			}
			break;
		case 38://上方向键的编号
			if(moveUp()){
				setTimeout("generateOneNumber()",210);//格子移动后，游戏就会再随机生成一个数字
				setTimeout("isgameover()",300);//判断游戏是否结束
			}
			break;
		case 39://右方向键的编号
			if(moveRight()){
				setTimeout("generateOneNumber()",210);//格子移动后，游戏就会再随机生成一个数字
				setTimeout("isgameover()",300);//判断游戏是否结束
			}
			break;
		case 40://下方向键的编号
			if(moveDown()){
				setTimeout("generateOneNumber()",210);//格子移动后，游戏就会再随机生成一个数字
				setTimeout("isgameover()",300);//判断游戏是否结束
			}
			break;
		default://其他情况，不作处理
			break;
	}
});

/*
	判断游戏是否结束，当所有格子都满了，并且没有任何两个相邻的格子是一样的数字
*/
function isgameover(){
	if(nospace(board) && nomove(board))
		gameover();
}

function gameover(){
	alert("game over!");
}

/*
	按左方向键执行的函数
*/
function moveLeft(){
	/*首先判断当前的局势，能不能向左移动*/
	if(!canMoveLeft(board))
		return false;
		
	/*只需处理右侧的三列就可以了*/
	/*对每个数字的左侧位置进行判断，看是否可成为落脚点？
		1.落脚点位置是否为空？
		2.落脚点位置数字和待判断元素数字相等？
		3.移动的路径中是否有障碍物？
	*/
	for(var i=0; i<4; i++)
		for(var j=1; j<4; j++){
			if(board[i][j]!=0){
				for(var k=0; k<j; k++){//遍历board[i][j]左侧的所有元素
					if(board[i][k]==0 && noBlockHorizontal(i, k, j ,board)){
						/*移动*/
						showMoveAnimation(i, j, i, k);		//移动，并有动画效果
						board[i][k]=board[i][j];
						board[i][j]=0;
						continue;
					}else if(board[i][j]==board[i][k] && noBlockHorizontal(i, k, j ,board) && !hasConflicted[i][k]){
						/*移动*/
						showMoveAnimation(i, j, i, k);
						/*
						board[i][k]=board[i][j];
						board[i][j]=0;
						debug过程：错误的没加思考就直接将上面的代码拷打下面来了，根本没考虑这次要叠加而不是单纯的移动
						*/
						
						/*叠加*/
						board[i][k]+=board[i][j];
						board[i][j]=0;
						
						/*加分*/
						score += board[i][k];
						
						/*向前台更新分数*/
						updateScore(score);
						
						/*更改hasConflicted[i][k]为true*/
						hasConflicted[i][k]=true;
						continue;
					}
				}
			}
		}
	setTimeout("updateBoardView()",200);	//将board里面的数据更新到页面显示上，为了显示动画效果，调用setTimeout()函数让updateBoardView()延迟100ms执行
	return true;
}


/*
	按右方向键执行的函数
*/
function moveRight(){
	if(!canMoveRight(board))
		return false;
		
	for(var i=0; i<4; i++)
		for(var j=2; j>=0; j--){
			if(board[i][j]!=0){
				for(var k=3; k>j; k--){
					if(board[i][k]==0 && noBlockHorizontal(i, k, j ,board)){
						/*移动*/
						showMoveAnimation(i, j, i, k);	
						board[i][k]=board[i][j];
						board[i][j]=0;
						continue;
					}else if(board[i][j]==board[i][k] && noBlockHorizontal(i, k, j ,board) && !hasConflicted[i][k]){
						/*移动*/
						showMoveAnimation(i, j, i, k);
						/*叠加*/
						board[i][k]+=board[i][j];
						board[i][j]=0;
						/*加分*/
						score += board[i][k];
						/*向前台更新分数*/
						updateScore(score);
						
						hasConflicted[i][k]=true;
						continue;
					}
				}
			}
		}
	setTimeout("updateBoardView()",200);
	return true;
}


/*
	按上方向键执行的函数
*/
function moveUp(){
	if(!canMoveUp(board))
		return false;
		
	for(var j=0; j<4; j++)
		for(var i=1; i<4; i++){
			if(board[i][j]!=0){
				for(var k=0; k<i; k++){
					if(board[k][j]==0 && noBlockVertical(j, i, k ,board)){
					/*debug:错误地将noBlockVertical(j, i, k ,board)写成noBlockVertical(j, k, i ,board)导致运行时逻辑出错*/
						/*移动*/
						showMoveAnimation(i, j, k, j);
						board[k][j]=board[i][j];
						board[i][j]=0;
						continue;
					}else if(board[i][j]==board[k][j] && noBlockVertical(j, i, k ,board) && !hasConflicted[k][j]){
						/*移动*/
						showMoveAnimation(i, j, k, j);
						/*叠加*/
						board[k][j]+=board[i][j];
						board[i][j]=0;
						/*加分*/
						score += board[k][j];
						/*向前台更新分数*/
						updateScore(score);
						
						hasConflicted[k][j]=true;
						continue;
					}
				}
			}
		}
	setTimeout("updateBoardView()",200);
	return true;
}


/*
	按下方向键执行的函数
*/
function moveDown(){
	if(!canMoveDown(board))
		return false;
		
	for(var j=0; j<4; j++)
		for(var i=2; i>=0; i--){
			if(board[i][j]!=0){
				for(var k=3; k>i; k--){
					if(board[k][j]==0 && noBlockVertical(j, i, k ,board)){
						/*移动*/
						showMoveAnimation(i, j, k, j);		
						board[k][j]=board[i][j];
						board[i][j]=0;
						continue;
					}else if(board[i][j]==board[k][j] && noBlockVertical(j, i, k ,board) && !hasConflicted[k][j]){
						/*移动*/
						showMoveAnimation(i, j, k, j);
						/*叠加*/
						board[k][j]+=board[i][j];
						board[i][j]=0;
						/*加分*/
						score += board[k][j];
						/*向前台更新分数*/
						updateScore(score);
						
						hasConflicted[k][j]=true;
						continue;
					}
				}
			}
		}
	setTimeout("updateBoardView()",200);	
	return true;
}






















