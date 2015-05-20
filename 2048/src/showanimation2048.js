/*
*	关于动画效果的所有js方法
*/

function showNumberWithAnimation(i, j, randNumber){
	var numberCell = $("#number-cell-"+i+"-"+j);
	
	numberCell.css('background-color', getNumberBackgroundColor(randNumber));
	numberCell.css('color', getNumberColor(randNumber));
	numberCell.text(randNumber);
	
	/*实现动画效果，要有jQuery的animate()函数实现，注意animate()函数的使用方式*/
	numberCell.animate({
		width:"100px",
		height:"100px",		//debug经历，之前错误的将height写成heigth，导致显示的时候$("#number-cell-"+i+"-"+j)没有高度，也就没法覆盖$("#grid-cell-"+i+"-"+j)，所以就没法正确显背景色
							//是在浏览器用审查元素工具发现$("#number-cell-"+i+"-"+j)的height属性没有正确设置而发现的问题
		top:getPosTop(i, j),
		left:getPosLeft(i, j),
	},50);//第二个参数是指在50ms时间内完成该动画，由原来的width、height、top、left值在50ms内渐变为现在的width、height、top、left值
}

/*
	从(fromx, fromy)移动到(tox,toy)，并伴有动画的过程
*/
function showMoveAnimation(fromx, fromy, tox, toy){
	var numberCell = $("#number-cell-"+fromx+"-"+fromy);
	
	numberCell.animate({
		top:getPosTop(tox, toy),
		left:getPosLeft(tox, toy),
		/*
		debug：错误的将		
			top:getPosTop(tox, toy),
			left:getPosLeft(tox, toy),
		写成：
			top:getPosTop(tox, toy);
			left:getPosLeft(tox, toy);
		错将,写成;造成语法错误
		*/
	},200);
}


/*
向前台更新分数
*/
function updateScore(score){
	$("#score").text(score);	//使用text()方法，将$("#score")元素的文字设置为score
}















