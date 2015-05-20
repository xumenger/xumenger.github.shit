<%@ page language="java" import="java.util.*" pageEncoding="utf-8" contentType="text/html; charset=UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags"  %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>司法局后台管理</title>

<!-- paste this code into your webpage -->
<link href="tablecloth/tablecloth.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="tablecloth/tablecloth.js"></script>
<!-- end -->

<style>

body{
	margin:0;
	padding:0;
	background:#f1f1f1;
	font:70% Arial, Helvetica, sans-serif; 
	color:#555;
	line-height:150%;
	text-align:left;
}
a{
	text-decoration:none;
	color:#057fac;
}
a:hover{
	text-decoration:none;
	color:#999;
}
h1{
	font-size:140%;
	margin:0 20px;
	line-height:80px;	
}
</style>

</head>

<body>

<div>
	<h1>文章列表</h1>
	<s:form action="article!search.action" method="post">
    	<table style="width:100%">
    		<tr>
    			<td>
    				文章名称：
    				<input type="text" name="article.articleName"  size="40"></input>
    				
    				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
					<input type="submit" value="查询"/>
					<!-- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
					<input type="button" value="增加" onclick="javascript:location.href='article!gotoadd.action';"/>
    			</td>
    		</tr>
    		<tr>
    			<td>
    				<table style="width:100%">
						<tr>
							<td>文章序号</td>
							<td>文章名称</td>
							<td>作者</td>
							<td>文章类型</td>
							<td>更新时间</td>
							<td>审核状态</td>
							<td>编辑</td>
						</tr>
					<s:iterator value="#request.listartc" var="u">
				    <tr>
				      <td><s:property value="articleID"/></td>
				      <td><s:property value="articleName"/></td>
				      <td><s:property value="author"/></td>
				      <td><s:property value="articleType"/></td>
				      <td><s:property value="updateTime"/></td>
				      <td><s:property value="articleStatus"/> </td>
				      
				      <td>
				      	<a href="article!detail.action?article.articleID=<s:property value='articleID'/>">编辑</a>
				      	<a href="article!delete.action?article.articleID=<s:property value='articleID'/>">删除</a>
				      </td> 
				    </tr>
				    </s:iterator>
					</table>
    			</td>
    		</tr>
    	</table>
    </s:form>
</div>	
</body>
</html>
