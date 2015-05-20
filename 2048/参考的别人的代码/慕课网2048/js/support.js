/*
 支持main.js的函数，供main。js调用
 * */
//webapp处理,注意取整，不然不同屏幕可能出现小数跳动
var documentWidth=window.screen.availWidth;//移动设备
var gridContainerWidth=parseInt(documentWidth*0.92);// 内容宽度
var cellSideLength = parseInt(0.18 * documentWidth);//小方块边长
var cellSpace = parseInt(0.04*documentWidth);//间距

//支持移动版
function getPosTop( i , j ){
    return cellSpace + i*(cellSpace+cellSideLength);
}

function getPosLeft( i , j ){
    return cellSpace + j*(cellSpace+cellSideLength);
}

function getNumberBackgroundColor( number ){
    switch( number ){
        case 2:return "#eee4da";break;
        case 4:return "#ede0c8";break;
        case 8:return "#f2b179";break;
        case 16:return "#f59563";break;
        case 32:return "#f67c5f";break;
        case 64:return "#f65e3b";break;
        case 128:return "#edcf72";break;
        case 256:return "#edcc61";break;
        case 512:return "#9c0";break;
        case 1024:return "#33b5e5";break;
        case 2048:return "#09c";break;
        case 4096:return "#a6c";break;
        case 8192:return "#93c";break;
    }

    return "black";
}

function getNumberColor( number ){
    if( number <= 4 )
        return "#776e65";

    return "white";
}

//判断有没有空格了
function nospace( board ){

    for( var i = 0 ; i < 4 ; i ++ )
        for( var j = 0 ; j < 4 ; j ++ )
            if( board[i][j] == 0 )
            //还有空间
                return false;

    return true;
}

//能否向左移动，判断12个格子（第0列不需要判断），条件是：左边数字为0或者有相同的数字
function canMoveLeft( board ){

    for( var i = 0 ; i < 4 ; i ++ )
        for( var j = 1; j < 4 ; j ++ )
            if( board[i][j] != 0 )
                if( board[i][j-1] == 0 || board[i][j-1] == board[i][j] )
                    return true;

    return false;
}

function canMoveRight( board ){

    for( var i = 0 ; i < 4 ; i ++ )
        for( var j = 2; j >= 0 ; j -- )
            if( board[i][j] != 0 )
                if( board[i][j+1] == 0 || board[i][j+1] == board[i][j] )
                    return true;

    return false;
}

function canMoveUp( board ){

    for( var j = 0 ; j < 4 ; j ++ )
        for( var i = 1 ; i < 4 ; i ++ )
            if( board[i][j] != 0 )
                if( board[i-1][j] == 0 || board[i-1][j] == board[i][j] )
                    return true;

    return false;
}

function canMoveDown( board ){

    for( var j = 0 ; j < 4 ; j ++ )
        for( var i = 2 ; i >= 0 ; i -- )
            if( board[i][j] != 0 )
                if( board[i+1][j] == 0 || board[i+1][j] == board[i][j] )
                    return true;

    return false;
}

//判断水平位置i行是否有障碍物
function noBlockHorizontal( row , col1 , col2 , board ){
    for( var i = col1 + 1 ; i < col2 ; i ++ )
        if( board[row][i] != 0 )
        //存在障碍物
            return false;
    return true;
}

//判断垂直j是否有障碍物
function noBlockVertical( col , row1 , row2 , board ){
    for( var i = row1 + 1 ; i < row2 ; i ++ )
        if( board[i][col] != 0 )
            return false;
    return true;
}

//判断能否运动
function nomove( board ){
    if( canMoveLeft( board ) ||
        canMoveRight( board ) ||
        canMoveUp( board ) ||
        canMoveDown( board ) )
        return false;

    return true;
}


/*
 *下面是各种动画的效果
 * */

//显示随机数字运动效果
function showNumberWithAnimation( i , j , randNumber ){

	var numberCell=$$('number-cell-'+i+'-'+j);

    css(numberCell,'backgroundColor',getNumberBackgroundColor( randNumber ) );
    css(numberCell,'color',getNumberColor( randNumber ) );
    numberCell.innerHTML=randNumber;
	startMoveBuffer(numberCell,{top:getPosTop( i , j ),left:getPosLeft( i , j ),width:cellSideLength,height:cellSideLength});
}

function showMoveAnimation( fromx , fromy , tox, toy ){
	var numberCell = $$('number-cell-'+ fromx + '-' + fromy );
	startMoveBuffer(numberCell,{left:getPosLeft( tox , toy ),top:getPosTop( tox , toy )})
}

function updateScore( score ){
	//var score=document.getElementById('score');
	//分数变化的动画
	var myscore=$$('score');
	myscore.innerHTML=score;
}


