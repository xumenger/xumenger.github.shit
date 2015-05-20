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
	<h1>新增内部用户</h1>
		<s:form action="insideuser!AddInsideUser.action" method="post">
    	<table style="width:100%">
    		<tr>
    			<td style="width:30%;text-align: right">用户名</td>
    			<td>
    				<input type="text" size="40" name="insideuser.loginName"/>
    			</td>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right">用户密码</td>
    			<td>
    				<input type="password" size="40" name="insideuser.UserPassword"/>
    			</td>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right">用户部门</td>
    			<td>
    				<input type="text" size="40" name="insideuser.department"/>
    			</td>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right">角色</td>
    			<td>
    				<select name="insideuser.role">
    					<option value="editor">编辑人员</option>
    					<option value="greffier">公证员</option>
    					<option value="charge">收费员</option>
    					<option value="checker">审查员</option>
    					<option value="filing">归档员</option>
    					<option value="admin">管理员</option>
					</select>
    			</td>
    			</tr>
    			<td style="width:30%;text-align: right">用户状态</td>
    			<td>
    				<select name="insideuser.insideUserStatus">
    					<option value="on">未冻结</option>
    					<option value="off">冻结</option>
					</select>
    			</td>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right"></td>
    			<td>
    				<input type="submit" value="保存" />
    				<input type="button" value="返回"onclick="javascript:location.href='insideuser!gotolist.action';"/>
    			</td>
    		</tr>
    		
    	</table>
    </s:form>
</div>	
</body>
</html>
