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
	<h1>角色权限管理</h1>
	<s:form action="article!search.action" method="post">
    	<table style="width:100%">
    		<tr>
    			<td>
					<!-- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
					<input type="button" value="增加" onclick="javascript:location.href='role!gotoadd.action';"/>
    			</td>
    		</tr>
    		<tr>
    			<td>
    				<table style="width:100%">
						<tr>
							<td>角色编号</td>
							<td>角色名称</td>
							<td>编辑权</td>
							<td>申请管理权</td>
							<td>公证管理权</td>
							<td>用户管理权</td>
							<td>权限管理权</td>
							<td>编辑</td>
						</tr>
					<s:iterator value="#request.roles" var="u">
				    <tr>
				      <td><s:property value="roleId"/></td>
				      <td><s:property value="roleName"/></td>
				      <td><s:property value="editRight"/></td>
				       <td><s:property value="applyRight"/></td>
				      <td><s:property value="notarizationRight"/></td>
				      <td><s:property value="userRight"/></td>
				      <td><s:property value="roleRight"/> </td>
					
				      <td>
				      	<a href="role!detail.action?role.roleId=<s:property value='roleId'/>">编辑</a>
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
