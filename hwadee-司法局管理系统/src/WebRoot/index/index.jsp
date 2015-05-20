<%@ page language="java" import="java.util.*" pageEncoding="utf-8" contentType="text/html; charset=UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags"  %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>成都市司法局</title>
<style type="text/css">	
a:link{
	color:#000;
	text-decoration:none;
}
a:visited{
	color:#000;
	text-decoration:none;
}
a.nav:hover{
	color:#F90;
	text-decoration:underline;
	font-size:18px;
}
a:hover{
	text-decoration:underline;
}
</style>
</head>

<body >
<div id="main">
 <div id=""top>
 <iframe src="outlink!gotoindextop.action" scrolling="no" height="180px" width="100%" frameborder="0"></iframe>
 </div>
 <div id="center">
      <div id="tableFir">
      <div  style="text-align:right; width:85%">
     	 <s:if test="#session.userData!=null">
			<td > <a href="outsideuser!detail.action?outsideuser.userNumber=<s:property value='#session.userData.userNumber'/>">${userData.outsideUserName}</a>：已登录</td>
      		
		</s:if>
		<s:else>
			<td> <a href="outsideuser!gotologin.action">登陆</a></td>
			<td> <a href="outsideuser!gotoregist.action">注册</a></td>
		</s:else>
		</div>  
     <table border="0" width="25%" height="300px" style="position:absolute; left:15%; border:thin #CCC solid;">
          <tr><th align="left" height="25px" style="background:url(images/byh.jpg) repeat;"><a href="#"><font color="#00CCFF">政务信息公开</font></a></th></tr> 
        	<s:iterator value="#request.listartc" var="u">
        		<s:if test="%{articleType==1}">
        		<s:if test="%{articleStatus==2}">
					<tr hright="20px"><td><a href="article!gotoartc.action?article.articleID=<s:property value='articleID'/>"/><s:property value="articleName"/></a></td></tr>
				</s:if>
				</s:if>
				<s:else>
				</s:else>
			</s:iterator>
			
        </table>
         <table border="0" width="30%" height="300px" style="position:absolute; left:41%; border:thin #FC3 solid;">
            <tr><th colspan="2" align="left" background="images/byh.jpg" height="25px"><a href="#"><font color="#00CCFF">综合资讯</font></a></th></tr> 
            
        	<s:iterator value="#request.listartc" var="u">
        		<s:if test="%{articleType==2}">
        		<s:if test="%{articleStatus==2}">
					<tr><td><a href="article!gotoartc.action?article.articleID=<s:property value='articleID'/>"/><s:property value="articleName"/></td></tr>
				</s:if>
				</s:if>
				<s:else>
				</s:else>
			</s:iterator>
         </table>
          <table border="0" width="15%" height="300px" style="position:absolute; left:72%; background:#F7F7F7;"> 
           <tr><th align="left" height="25px"><a href="#">网上办事</a></th></tr> 
			<%-- <s:iterator value="#request.listartc" var="u">
        		<s:if test="%{articleType==5}">
        		<s:if test="%{articleStatus==2}">
				<tr><td><a href="article!gotoartc.action?article.articleID=<s:property value='articleID'/>"/><s:property value="articleName"/></td></tr>
				</s:if>
				</s:if>
				<s:else>
				</s:else>
			</s:iterator> --%>
		    <tr><td><a href="goto!gotoSupport.action" class="nav">法律援助</a></td></tr>
            <tr><td><a href="goto!gotoDispute.action" class="nav">纠纷调解</a></td></tr>
            <tr><td><a href="goto!gotoIdentify.action" class="nav">司法鉴定</a></td></tr>
            <tr><td><a href="goto!gotoNotarization.action" class="nav">公证预约</a></td></tr>
      </div>
      <div id="img1" >
         <a href="#"><img src="images/adf.png" style="position:absolute; top:537px; left:14%;"></a>
      </div>
      <div>
         <table border="0" width="25%" height="300px" style="position:absolute; left:15%; top:625px; border:thin #CCC solid;">
          <tr><th align="left" height="25px" style="background:url(images/byh.jpg) repeat"><a href="#"><font color="#00CCFF">公共法律服务</font></a></th></tr> 
            <s:iterator value="#request.listartc" var="u">
        	<s:if test="%{articleType==3}">
        	<s:if test="%{articleStatus==2}">
			<tr><td><a href="article!gotoartc.action?article.articleID=<s:property value='articleID'/>"/><s:property value="articleName"/></td></tr>
			</s:if>
			</s:if>
			<s:else>
			</s:else>
			</s:iterator>
         </table>
         <table border="0" width="30%" height="300px" style="position:absolute; left:41%; top:625px; border:thin #FC3 solid;">
            <tr><th align="left" background="images/byh.jpg" height="25px"><a href="#"><font color="#00CCFF">队伍建设</font></a></th></tr> 
            <s:iterator value="#request.listartc" var="u">
        	<s:if test="%{articleType==4}">
        	<s:if test="%{articleStatus==2}">
			<tr><td><a href="article!gotoartc.action?article.articleID=<s:property value='articleID'/>"/><s:property value="articleName"/></td></tr>
			</s:if>
			</s:if>
			<s:else>
			</s:else>
			</s:iterator>
         </table>
         </table>
        <table border="0" width="15%" height="300px" style="position:absolute; left:72%; top:625px; background:#F7F7F7;">
            <tr><th align="left" height="25px"><a href="#">便民服务</a></th></tr> 
			<tr><td><a href="http://www.duba.com/static/wannianli/wannianli.html" target="_new">万年历</a></td></tr>
			<tr><td><a href="#" target="_new">公交查询</a></td></tr>
			<tr><td><a href="admin-templates" target="_new">常用电话</a></td></tr>
			<tr><td><a href="http://www.weather.com.cn/" target="_new">天气预报</a></td></tr>
			<tr><td><a href="admin-templates" target="_new">友情链接</a></td></tr>
			<tr><td><a href="admin-templates" target="_new">网站地图</a></td></tr> 
         </table>
         </table>
   </div>
</div>
<div style="clear:both"></div>
  <div id="bottom">
	<iframe src="outlink!gotoindexfoot.action" scrolling="no" height="10%" width="100%" frameborder="0" style="position:absolute; top:925px"></iframe></div>
</div>
</body>
</html>
