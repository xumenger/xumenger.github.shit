/**
 * @author younth.wang
 * 功能：运动框架及一些常用函数  
 * 最后更新：2014-07-29
 * 
 */


/**
 * id选择器
 */
function $$ (id) {
	return document.getElementById(id);
}

/**
 * class选择器，选出的是数组，要用下标选出
 * sClass必选，oParent是父元素，可以为空，为空的时候默认从document开始选择
 * oParent不为空的时候，是父级的id
 * */

function getByClass(sClass,oParent){
	//获得父元素
	
	var oParent=parent?document.getElementById(oParent):document;
	var aEle=oParent.getElementsByTagName('*');//当前节点下面所有元素
	var i=0;
	var aResult=[];//空数组
	
	for(i=0;i<aEle.length;i++)
	{
		if(aEle[i].className==sClass)
		{
			aResult.push(aEle[i]);//增加到数组
		}
	}
	return aResult;
}

/**
 * 获取、设置样式
 * 两个参数，获取，三个参数，设置
 * 注意opacity取值是1-100
 * 支持链式操作：使用JSON同时设置多个样式如何处理？
 * */
function css(obj, attr, value){
	if(arguments.length==2){
		//获取
		if(attr!='opacity'){
			//ie obj.currentStyle 与 标准 getComputedStyle
			return parseInt(obj.currentStyle?obj.currentStyle[attr]:document.defaultView.getComputedStyle(obj, false)[attr]);
		}
		else{
			//opacity特殊处理
			return Math.round(100*parseFloat(obj.currentStyle?obj.currentStyle[attr]:document.defaultView.getComputedStyle(obj, false)[attr]));
		}
	}
	else if(arguments.length==3){
		//设置样式
		switch(attr){
			case 'width':
			case 'height':
			case 'paddingLeft':
			case 'paddingTop':
			case 'paddingRight':
			case 'paddingBottom':
				value=Math.max(value,0);//以上不能为0
			case 'left':
			case 'top':
			case 'marginLeft':
			case 'marginTop':
			case 'marginRight':
			case 'marginBottom':
			case 'lineHeight':
			case 'fontSize':
				obj.style[attr]=value+'px';
				break;
			case 'opacity':
				obj.style.filter="alpha(opacity:"+value+")";
				obj.style.opacity=value/100;
				break;
			default:
				obj.style[attr]=value;
		}
		//返回值
		return function (attr_in, value_in){
			return css(obj, attr_in, value_in);//这里是一个链式调用
		};		
	}
	//设置样式,同事设置多个样式
}


//添加事件处理，用此函数添加事件防止事件覆盖 
function addListener(target,type,handler){
	if(target.addEventListener){
		target.addEventListener(type,handler,false);
	}else if(target.attachEvent){
		target.attachEvent('on'+type,handler);
	}else{
		target['on'+type]=handler;
	}
}

//获取元素相对于屏幕左边的距离 利用offsetLeft,运用offsetLeft注意层级
function getPosition(node){
	var left = node.offsetLeft;
	var top = node.offsetTop;
	var parent = node.offsetParent;
	while(parent != null){
		left += parent.offsetLeft;
		top += parent.offsetTop;
		parent=parent.offsetParent;	
	}
	return {"left":left,"top":top};
}

//获取页面的高度和宽度
function  getPageHeight() {
	return Math.max(document.documentElement.scrollHeight, document.body.scrollHeight);
}
function  getPageWidth() {
	return Math.max(document.documentElement.scrollWidth, document.body.scrollWidth);
}

//获取页面可视区域高度和宽度
function getViewHeight () {
	return document.documentElement.clientHeight || document.body.clientHeight;
}
function getViewWidth () {
	return document.documentElement.clientWidth || document.body.clientWidth;
}

//获取scrollTop
function getScrollTop () {
	return document.documentElement.scrollTop||document.body.scrollTop; 
}
//对象复制，boj2覆盖boj1
function extend(obj1,obj2){
	for(var attr in obj2){
		obj1[attr] = obj2[attr];
	}
}

//封装的ajax操作函数
function ajax(url, fnSucc, fnFaild){
	//1.创建ajax对象
	var oAjax=null;
	
	if(window.XMLHttpRequest){
		oAjax=new XMLHttpRequest();
	}
	else{
		oAjax=new ActiveXObject("Microsoft.XMLHTTP");
	}
	
	//2.连接服务器
	//open(方法, url, 是否异步)
	oAjax.open('GET', url, true);
	
	//3.发送请求
	oAjax.send();
	
	//4.接收返回
	//OnReadyStateChange
	oAjax.onreadystatechange=function (){
		if(oAjax.readyState==4){
			if(oAjax.status==200){
				//alert('成功：'+oAjax.responseText);
				fnSucc(oAjax.responseText);
			}
			else{
				if(fnFaild){
					fnFaild();
				}
			}
		}
	};
}

/**
 * jsonp : json + padding(内填充)  创建
 * 用法：createJs('http://www.yunstudio.net/jsonp.js?callback=yunstudio')
 * jsonp.js文件里面各式应该是 yunstudio({name:'yunstudio',sex:'男'},{});
 * function yunstudio(){
 * 	//回调
 * }
 * */
function createJs(sUrl){
	
	var oScript = document.createElement('script');
	oScript.type = 'text/javascript';
	oScript.src = sUrl;
	document.getElementsByTagName('head')[0].appendChild(oScript);

}

//定义自定义事件
function bindEvent(obj,events,fn){
	//obj : 楼层
	//events : 书架
	//fn : 一本书
	
	obj.listeners = obj.listeners || {};
	obj.listeners[events] = obj.listeners[events] || [];
	
	obj.listeners[events].push( fn );
	
	if(obj.nodeType){
		if(obj.addEventListener){
			obj.addEventListener(events,fn,false);
		}
		else{
			obj.attachEvent('on'+events,fn);
		}
	}
}
//主动触发自定义事件
function fireEvent(obj,events){
	
	if(obj.listeners && obj.listeners[events]){
		for(var i=0;i<obj.listeners[events].length;i++){
			 obj.listeners[events][i]();
		}
	}
	
}

//获取数组中最小值及其索引
function getArrmin (arr) {
	var index=0;
	var value=arr[index];
	for(var i=1;i<arr.length;i++){
		if(arr[i]<value){
			value=arr[i];
			index=i;
		}
	}
	return {
		index:index,
		value:value
	}
}
//获取数组中最大值及其索引
function getArrmax (arr) {
	var index=0;
	var value=arr[index];
	for(var i=1;i<arr.length;i++){
		if(arr[i]>value){
			value=arr[i];
			index=i;
		}
	}
	return {
		index:index,
		value:value
	}
}

//函数节流：滚动条触发，次数太多
function throttle(method,delay){
        var timer=null;
        return function(){
            var context=this, args=arguments;
            clearTimeout(timer);
            timer=setTimeout(function(){
                method.apply(context,args);
            },delay);
        }
}

//检测input框的连续触发
function onput (obj,fn) {
	var ie = !-[1,];
	//兼容标准与ie
	ie?obj.onpropertychange = fn:obj.oninput=fn;
}

//获取字符串的长度，一个汉字是两个字符
function getLength(str){
	return String(str).replace(/[^\x00-\xff]/g,'aa').length;
}

//删除指定节点
function removeNode (node) {
	node.parentNode.removeChild(node);
}

//关闭定时器，停止运动
function stopMove(obj){
	clearInterval(obj.timer);
}

//设置cookie
function setCookie(name, value, iDay){
	var oDate=new Date();
	oDate.setDate(oDate.getDate()+iDay);//N天以后日期
	document.cookie=name+'='+value+';expires='+oDate;
}

//获取cookie
function getCookie(name){
	//'username=abc; password=123456; aaa=123; bbb=4r4er'
	var arr=document.cookie.split('; ');
	var i=0;
	
	//arr->['username=abc', 'password=123456', ...]
	
	for(i=0;i<arr.length;i++){
		//arr2->['username', 'abc']
		var arr2=arr[i].split('=');
		
		if(arr2[0]==name){
			return arr2[1];
		}
	}
	
	return '';
}

/**
 * 
 * obj:目标点
 * json:运动的参数
 * fnCallBack回调函数
 * 缓冲运动
 * */
function startMoveBuffer(obj, json, fnCallBack){
	var iCur=0;//iCur获取当前的值
	var iSpeed=0;//速度
	clearInterval(obj.timer);
	//obj.timer是多物体运动，每个物体一个定时器
	obj.timer=setInterval(function (){
	var bStop=true;	//多物体运动标识符，标志着运动全部结束（所有值到达目标点）
	for(var attr in json){
		//1.取当前的值(已经包括对opacity的特殊处理)
		iCur=css(obj, attr);
		//2.计算速度，目标点为：json[attr]
		iSpeed=(json[attr]-iCur)/3;
		iSpeed=iSpeed>0?Math.ceil(iSpeed):Math.floor(iSpeed);
		//3.检测停止，某个值没到达，bStop设为false
		if(iCur!=json[attr]){
			//至少一个没到，所有到达才停止
			bStop=false;
			//设置值
			css(obj, attr, iCur+iSpeed);
		}
	}
	//循环结束，检测bStop
		if(bStop){
			clearInterval(obj.timer);
			obj.timer=null;
			//回调函数,call改变this指向，让fnCallBack可以用this
			if(fnCallBack){
				fnCallBack.call(obj);
			}
		}
	}, 30)
}


//增加弹性运动效果,要与经典运动合并，速度计算 方式及停止条件不同，其他相同！
function startMoveFlex(obj,json,fnCallBack){
	var iCur=0;
	var iSpeed = 0;
	clearInterval(obj.timer);
	obj.timer = setInterval(function(){
		var bStop=true;
		for(var attr in json){
			//1.取当前的值(已经包括对opacity的特殊处理)
			iCur=css(obj, attr);
			//2.计算速度，目标点为：json[attr]
			iSpeed += (json[attr] - iCur)/6;
			iSpeed *= 0.75;//摩擦系数
			//3.检测停止，某个值没到达，bStop设为false
			if( Math.abs(iSpeed)<=1 && Math.abs(json[attr] - iCur)<=1 ){
				clearInterval(obj.timer);
				//到达终点，修正位置速度
				css(obj,attr,json[attr]);
				iSpeed = 0;
			}
			else{
				bStop=false;
				css(obj, attr, iCur+iSpeed);
			}
		}
		if(bStop){
			clearInterval(obj.timer);
			obj.timer=null;
			if(fnCallBack){
				fnCallBack.call(obj);
			}
		}
	},30);
}

/***
 *buffer 与 flex 运动的合并，如果iType为空且要调用回调需要注意
 * 默认是：buffer缓冲运动
 * 可惜还有浏览器切换的问题，需要时间版运动
 */

function startMove(obj, json, iType, fnCallBack){
	//对iType进行判断，可能省略了iType直接写了回调
	if( typeof iType == 'function' ){
		fnCallBack=iType;
		iType='buffer';
	}
	
	var iCur=0;//iCur获取当前的值
	var iSpeed=0;//速度
	clearInterval(obj.timer);
	//obj.timer是多物体运动，每个物体一个定时器
	obj.timer=setInterval(function (){
		var bStop=true;	//多物体运动标识符，标志着运动全部结束（所有值到达目标点）
		for(var attr in json){
			//1.取当前的值(已经包括对opacity的特殊处理)
			iCur=css(obj, attr);
			//2.计算速度，目标点为：json[attr]
			if(iType=='flex'){
				//弹性运动
				iSpeed += (json[attr] - iCur)/6;
				iSpeed *= 0.75;//摩擦系数
				//3.检测停止，某个值没到达，bStop设为false
				if( Math.abs(iSpeed)<=1 && Math.abs(json[attr] - iCur)<=1 ){
					clearInterval(obj.timer);
					//到达终点，修正位置速度
					css(obj,attr,json[attr]);
					iSpeed = 0;
				}
				else{
					bStop=false;
					css(obj, attr, iCur+iSpeed);
				}
			}else{
				//默认是缓冲运动
				iSpeed=(json[attr]-iCur)/8;
				iSpeed=iSpeed>0?Math.ceil(iSpeed):Math.floor(iSpeed);
				//3.检测停止，某个值没到达，bStop设为false
				if(iCur!=json[attr]){
					//至少一个没到，所有到达才停止
					bStop=false;
					//设置值
					css(obj, attr, iCur+iSpeed);
				}
			}
		}
		
		//循环结束，检测bStop
		if(bStop){
			clearInterval(obj.timer);
			obj.timer=null;
			//回调函数,call改变this指向，让fnCallBack可以用this
			if(fnCallBack){
				fnCallBack.call(obj);
			}
		}
	}, 30)
}


