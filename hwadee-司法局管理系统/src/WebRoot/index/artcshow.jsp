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
img{
	height:70%;
	width:80%;
}
.note{
	text-align:left;
	text-indent:2em;
	font-size:20px;
}
</style>
</head>
<div id="body">
<iframe src="outlink!gotoindextop.action" width="100%" height="220px" scrolling="no" frameborder="0"></iframe>
   <div id="center">
      <div id="current" align="center">
         <table width="65%" bgcolor="#CCCCCC">
            <tr><td align="left"><font size="-2">&nbsp;当前位置：综合资讯</font></td></tr>
         </table> 
      </div>
      &nbsp;<br>
      <div align="center">
      <fieldset style="width:70%; border:hidden;">
         <legend align="center"><font size="+2" color="#FF9900"><b>${article.articleName}</b></font></legend>
            <p>&nbsp;</p>
          
            <p></p>
           <tr>
    		<td>${article.articleContent}</td>
    		</tr>
           
     </fieldset>
     </div>
   </div>
</div>   
<body>
</body>
</html>
