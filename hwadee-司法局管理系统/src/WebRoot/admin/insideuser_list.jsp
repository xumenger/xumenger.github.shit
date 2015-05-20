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
<form action="insideuser!list.action" method="post">
	<h1>内部用户列表</h1>
	<s:form action="insideuser!search.action" method="post">
    	<table style="width:100%">
    		<tr>
    			<td>
					<!-- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
					<input type="button" value="增加" onclick="javascript:location.href='insideuser!gotoadd.action';"/>
					
					<select name="user.role">
    					<option value="editor">编辑人员</option>
    					<option value="greffier">公证员</option>
    					<option value="charge">收费员</option>
    					<option value="checker">审查员</option>
    					<option value="filing">归档员</option>
    					<option value="admin">管理员</option>
					</select>
					<input type="submit" value="查询"/>
				
    			</td>
    		</tr>
    		<tr>
    			<td>
    				<table style="width:100%">
						<tr>
							<td>用户ID</td>
							<td>角色</td>
							<td>用户名</td>
							<td>状态</td>
							<td>操作</td>
						</tr>
					<s:iterator value="listin" id="u">
				    <tr>
				      <td><s:property value="#u.userId"/></td>
				      <td><s:property value="#u.role"/></td>
				       <td><s:property value="#u.loginName"/></td>
					   <td><s:property value="#u.InsideUserStatus"/></td>
				      <td>
				    <a href="insideuser!detail.action?insideuser.userId=<s:property value='userId'/>">编辑</a>
			      	<a href="manage!check.action?userid=<s:property value='userId' />">查看</a>
				      </td> 
				    </tr>
				    </s:iterator>
					</table>
    			</td>
    		</tr>
    	</table>
    </s:form>
    </form>
</div>	
</body>
</html>
