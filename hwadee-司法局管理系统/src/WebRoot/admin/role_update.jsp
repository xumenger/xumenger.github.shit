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
	<h1>修改权限</h1>
	<s:form action="role!edit.action" method="post">
    	<table style="width:100%">
    		<tr>
    			<input type="hidden" size="40" name="role.roleId" value="${role.roleId}"/>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right">角色名</td>
    			<td>
    				<input type="text" size="40" name="role.roleName" value="${role.roleName}"/>
    			</td>
    		</tr>
    			<tr>
    			<td style="width:30%;text-align: right">编辑权</td>
    			<td>
    				<select name="role.editRight"value="role.editRight">
    					<option value="0">无</option>
    					<option value="1">有</option>
					</select>
    			</td>
    		</tr>
    			<tr>
    			<td style="width:30%;text-align: right">申请管理权</td>
    			<td>
    				<select name="role.applyRight"value="role.applyRight">
    					<option value="0">无</option>
    					<option value="1">有</option>
					</select>
    			</td>
    		</tr>
    			<tr>
    			<td style="width:30%;text-align: right">公证管理权</td>
    			<td>
    				<select name="role.notarizationRight"value="role.notarizationRight">
    					<option value="0">无</option>
    					<option value="1">有</option>
					</select>
    			</td>
    		</tr>
    			<tr>
    			<td style="width:30%;text-align: right">用户管理权</td>
    			<td>
    				<select name="role.userRight"value="role.userRight">
    					<option value="0">无</option>
    					<option value="1">有</option>
					</select>
    			</td>
    		</tr>
    			<tr>
    			<td style="width:30%;text-align: right">权限管理权</td>
    			<td>
    				<select name="role.roleRight"value="role.roleRight">
    					<option value="0">无</option>
    					<option value="1">有</option>
					</select>
    			</td>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right"></td>
    			<td>
    				<input type="submit" value="保存" />
    				<input type="button" value="返回"/>
    			</td>
    		</tr>
    	</table>
    </s:form>
</div>	
</body>
</html>
