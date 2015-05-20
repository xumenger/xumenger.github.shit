/*
 *desinged by younth.wang
 * 主程序js
 * 在线地址：www.yunstudio.net/2048
 * */
var board = [];//4*4数组存放数字
var score = 0;
var hasConflicted = [];//纪录某元素是否冲突 

var maxSocre=0;
//webapp处理,纪录开始结束的坐标，用于计算方向
var startx=0;
var starty=0;
var endx=0;
var endy=0;

window.onload=function(){
	prepareForMobile();
	newgame();
	var newGame=$$('newgamebutton');
	newGame.onclick=function(){
		newgame();
	}
	
	//键盘事件
	document.onkeyup=function(ev){
		var ev=ev||event;//获取事件
		//ev.preventDefault();//防止出现滚动条的拖动问题
	    switch( ev.keyCode ){
	        case 37: //left
	            if( moveLeft() ){
	                setTimeout("generateOneNumber()",210);
	                setTimeout("isgameover()",300);
	            }
	            break;
	        case 38: //up
	            if( moveUp() ){
	                setTimeout("generateOneNumber()",210);
	                setTimeout("isgameover()",300);
	            }
	            break;
	        case 39: //right
	            if( moveRight() ){
	                setTimeout("generateOneNumber()",210);
	                setTimeout("isgameover()",300);
	            }
	            break;
	        case 40: //down
	            if( moveDown() ){
	                setTimeout("generateOneNumber()",210);
	                setTimeout("isgameover()",300);
	            }
	            break;
	        default: //default
	            break;
	    }
		
	}
	
}

//事件监听器，触屏版事件,防止屏幕点击的bug
document.addEventListener('touchstart',function(event){
	startx=event.touches[0].pageX;//touches.event
	starty=event.touches[0].pageY;
});

//阻止触摸时浏览器的缩放、滚动条滚动，但是貌似有bug，还在寻找中
document.addEventListener('touchmove',function(event){
	event.preventDefault();
});

document.addEventListener('touchend',function(event){
	//changedTouches
	endx=event.changedTouches[0].pageX;//x
	endy=event.changedTouches[0].pageY;//y
	//手指离开的时候，判断移动的方向
	//先判断是x,y在判断正负方向
	
	var deltax=endx-startx;
	var deltay=endy-starty; 
	//判断是否是点击,小于某个值，不是移动操作
	if(Math.abs(deltax)<0.3*documentWidth&&Math.abs(deltay)<0.3*documentWidth){
		return;
	}
	
	if(Math.abs(deltax)>=Math.abs(deltay)){
		//x
		if(deltax>0){
		//right
            if( moveRight() ){
                setTimeout("generateOneNumber()",210);
                setTimeout("isgameover()",300);
            }
			
		}else{
		//left
            if( moveLeft() ){
                setTimeout("generateOneNumber()",210);
                setTimeout("isgameover()",300);
            }

		}
	}
	else{
		if(deltay>0){
		//down
            if( moveDown() ){
                setTimeout("generateOneNumber()",210);
                setTimeout("isgameover()",300);
            }

		}else{
		//up
            if( moveUp() ){
                setTimeout("generateOneNumber()",210);
                setTimeout("isgameover()",300);
            }

		}
		
	}
	
});


function prepareForMobile(){
	if(documentWidth>500){
		//电脑端，大于500px就设置成为500
		gridContainerWidth=500;
		cellSpace=20;
		cellSideLength=100;
	}
	
	//移动端设置container区域
	var container=$$('grid-container');
	css(container,'width',gridContainerWidth-2*cellSpace);
	css(container,'height',gridContainerWidth-2*cellSpace);
	css(container,'padding',cellSpace);
	css(container,'borderRadius',0.02*gridContainerWidth);
	
	//设置所有小格子
	var gridCell=getByClass('grid-cell','grid-container');//选择所有的 数字单元格
	for(var i=0;i<gridCell.length;i++){
		css(gridCell[i],'width',cellSideLength);
		css(gridCell[i],'height',cellSideLength);
		css(gridCell[i],'borderRadius',0.02*cellSideLength);
	}
	
}

function newgame(){
    //初始化棋盘格
    init();
    //在随机两个格子生成数字
    generateOneNumber();
    generateOneNumber();
}

//初始化
function init(){
    for( var i = 0 ; i < 4 ; i ++ )
        for( var j = 0 ; j < 4 ; j ++ ){
			var gridCell=$$('grid-cell-'+i+"-"+j);//选择单元格 
			var posTop=getPosTop(i,j);
			var posLeft=getPosLeft(i,j);
			css(gridCell,'top',posTop);
			css(gridCell,'left',posLeft);
			
        }

    for( var i = 0 ; i < 4 ; i ++ ){
        board[i] =[];//创建二维数组
        hasConflicted[i] = new Array();
        for( var j = 0 ; j < 4 ; j ++ ){
            board[i][j] = 0;
            hasConflicted[i][j] = false;//初始都没碰撞
        }
    }

    updateBoardView();

    var maxScore=$$('maxscore');
	//读取cookie中的score
	var cookie_score=getCookie('score');
	if(cookie_score){
		maxScore.innerHTML=cookie_score;
	}else{
		maxScore.innerHTML=0;
	}

}


//整体数据刷新
function updateBoardView(){
	var containter=$$('grid-container');
	//删除之前所有的numbercell
	var ncell=getByClass('number-cell','grid-container');//选择所有的 数字单元格
	console.log(ncell.length);
	for(var i=0;i<ncell.length;i++){
		removeNode(ncell[i]);
	}
    for( var i = 0 ; i < 4 ; i ++ ){
        for( var j = 0 ; j < 4 ; j ++ ){
        	var numberCell=document.createElement('div');
        	numberCell.className='number-cell';
        	numberCell.id='number-cell-'+i+'-'+j;
        	containter.appendChild(numberCell);
            var theNumberCell=$$('number-cell-'+i+'-'+j);

            if( board[i][j] == 0 ){
            	//初始化宽高为0
            	css(theNumberCell,'width',0);
                css(theNumberCell,'height',0);
                //支持移动版本
                var posTop=getPosTop(i,j)+cellSideLength/2;
                var posLeft=getPosLeft(i,j)+cellSideLength/2;
                
                css(theNumberCell,'top',posTop);
                css(theNumberCell,'left',posLeft);
            }
            else{
            	//支持移动版
                css(theNumberCell,'width',cellSideLength);
                css(theNumberCell,'height',cellSideLength);
                
                var posTop=getPosTop(i,j);
                var posLeft=getPosLeft(i,j);
                css(theNumberCell,'top',posTop);
                css(theNumberCell,'left',posLeft);
                var bgColor=getNumberBackgroundColor( board[i][j] );
                css(theNumberCell,'backgroundColor',bgColor );
                css(theNumberCell,'color',getNumberColor( board[i][j] ) );
                theNumberCell.innerHTML=board[i][j];
            }

            hasConflicted[i][j] = false;
        }
    	
    }
    
    //注意ncell之前被删除了，应该重新获取，重新设置字体行高
    var numberCell=getByClass('number-cell','grid-container');//选择所有的 数字单元格
    for(var i=0;i<numberCell.length;i++){
    	css(numberCell[i],'lineHeight',cellSideLength);
    	css(numberCell[i],'fontSize',0.6*cellSideLength);
    }
}

function generateOneNumber(){

	//先判断能否生成数字
    if( nospace( board ) )
        return false;

    //随机一个位置
    //注意：floor后还是浮点数，需要转化为整型
    var randx = parseInt( Math.floor( Math.random()  * 4 ) );
    var randy = parseInt( Math.floor( Math.random()  * 4 ) );

	//死循环判断,此处代码可以优化，限定次数
    while( true ){
        if( board[randx][randy] == 0 )
            break;//可用的位置，跳出循环
		//继续尝试生成随机数
        randx = parseInt( Math.floor( Math.random()  * 4 ) );
        randy = parseInt( Math.floor( Math.random()  * 4 ) );
    }

    //随机一个数字
    var randNumber = Math.random() < 0.5 ? 2 : 4;

    //在随机位置显示随机数字
    board[randx][randy] = randNumber;//更新board数组
    showNumberWithAnimation( randx , randy , randNumber );

    return true;
}

function isgameover(){
    if( nospace( board ) && nomove( board ) ){
        gameover();
    }
}

function gameover(){
	//游戏 结束 ，将得分与 cookie中得分比较
	var cookie_score=getCookie('score');
	if(cookie_score){
		if(score>cookie_score){
			//更新cookie
			setCookie('score',score,5);
		}
	}else{
		//将分数存入cookie
		setCookie('score',score,5);
	}

    alert('gameover!');
}


function moveLeft(){
	//判断是否能够向左移动
    if( !canMoveLeft( board ) )
        return false;

    //moveLeft
    for( var i = 0 ; i < 4 ; i ++ )
        for( var j = 1 ; j < 4 ; j ++ ){
            if( board[i][j] != 0 ){
				//判断是否能向左移动，循环判断
                for( var k = 0 ; k < j ; k ++ ){
                	//判断i,k位置为0，且没有障碍物（第i行从k到j没有障碍物）
                    if( board[i][k] == 0 && noBlockHorizontal( i , k , j , board ) ){
                        //move
                        showMoveAnimation( i , j , i , k );//进行移动i,j--->i,k
                        board[i][k] = board[i][j];
                        board[i][j] = 0;
                        continue;
                    }
                   	//相等且没有障碍物，进行合并
                    else if( board[i][k] == board[i][j] && noBlockHorizontal( i , k , j , board ) && !hasConflicted[i][k] ){
                        //move
                        showMoveAnimation( i , j , i , k );
                        //add,叠加操作
                        board[i][k] += board[i][j];
                        board[i][j] = 0;
                        //add score
                        score += board[i][k];
                        updateScore( score );

                        hasConflicted[i][k] = true;//i,k位置碰撞了
                        continue;
                    }
                }
            }
        }
	//以上是对数组board的操作，最后在进行更新
    setTimeout("updateBoardView()",100);
    return true;
}

function moveRight(){
    if( !canMoveRight( board ) )
        return false;

    //moveRight
    for( var i = 0 ; i < 4 ; i ++ )
        for( var j = 2 ; j >= 0 ; j -- ){
            if( board[i][j] != 0 ){
                for( var k = 3 ; k > j ; k -- ){

                    if( board[i][k] == 0 && noBlockHorizontal( i , j , k , board ) ){
                        //move
                        showMoveAnimation( i , j , i , k );
                        board[i][k] = board[i][j];
                        board[i][j] = 0;
                        continue;
                    }
                    else if( board[i][k] == board[i][j] && noBlockHorizontal( i , j , k , board ) && !hasConflicted[i][k] ){
                        //move
                        showMoveAnimation( i , j , i , k);
                        //add
                        board[i][k] += board[i][j];
                        board[i][j] = 0;
                        //add score
                        score += board[i][k];
                        updateScore( score );

                        hasConflicted[i][k] = true;
                        continue;
                    }
                }
            }
        }

    setTimeout("updateBoardView()",100);
    return true;
}

function moveUp(){

    if( !canMoveUp( board ) )
        return false;

    //moveUp
    for( var j = 0 ; j < 4 ; j ++ )
        for( var i = 1 ; i < 4 ; i ++ ){
            if( board[i][j] != 0 ){
                for( var k = 0 ; k < i ; k ++ ){

                    if( board[k][j] == 0 && noBlockVertical( j , k , i , board ) ){
                        //move
                        showMoveAnimation( i , j , k , j );
                        board[k][j] = board[i][j];
                        board[i][j] = 0;
                        continue;
                    }
                    else if( board[k][j] == board[i][j] && noBlockVertical( j , k , i , board ) && !hasConflicted[k][j] ){
                        //move
                        showMoveAnimation( i , j , k , j );
                        //add
                        board[k][j] += board[i][j];
                        board[i][j] = 0;
                        //add score
                        score += board[k][j];
                        updateScore( score );

                        hasConflicted[k][j] = true;//该位置碰撞了
                        continue;
                    }
                }
            }
        }

    setTimeout("updateBoardView()",100);
    return true;
}

function moveDown(){
    if( !canMoveDown( board ) )
        return false;

    //moveDown
    for( var j = 0 ; j < 4 ; j ++ )
        for( var i = 2 ; i >= 0 ; i -- ){
            if( board[i][j] != 0 ){
                for( var k = 3 ; k > i ; k -- ){

                    if( board[k][j] == 0 && noBlockVertical( j , i , k , board ) ){
                        //move
                        showMoveAnimation( i , j , k , j );
                        board[k][j] = board[i][j];
                        board[i][j] = 0;
                        continue;
                    }
                    else if( board[k][j] == board[i][j] && noBlockVertical( j , i , k , board ) && !hasConflicted[k][j] ){
                        //move
                        showMoveAnimation( i , j , k , j );
                        //add
                        board[k][j] += board[i][j];
                        board[i][j] = 0;
                        //add score
                        score += board[k][j];
                        updateScore( score );

                        hasConflicted[k][j] = true;
                        continue;
                    }
                }
            }
        }

    setTimeout("updateBoardView()",100);
    return true;
}