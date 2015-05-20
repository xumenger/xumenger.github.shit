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
<s:form action="outsideuser!list.action" method="post">
	<h1>外部用户列表</h1>
    	<table style="width:100%">
    		<tr>
    			<td>
					<!-- <input type="button" value="增加" onclick="javascript:location.href='outsideuser!gotoadd.action';"/> -->
    			</td>
    		</tr>
    		<tr>
    			<td>
    				<table style="width:100%">
						<tr>
							<td>用户编号</td>
							<td>角色</td>
							<td>姓名</td>
							<td>性别</td>
							<td>手机</td>
							<td>通讯地址</td>
							<td>操作</td>
						</tr>
					<s:iterator value="listout" id="u">
				    <tr>
				      <td><s:property value="#u.userNumber"/></td>
				      <td><s:property value="#u.role"/></td>
				      <td><s:property value="#u.outsideUserName"/></td>
				      <td><s:property value="#u.userSex"/></td>
				      <td><s:property value="#u.mobile"/></td>
				      <td><s:property value="#u.Address"/></td>
				   	  <td>
				      	<a href="outsideuser!setLock.action?outsideuser.userNumber=<s:property value='userNumber'/>">冻结</a> 
				      	<a href="outsideuser!removeLock.action?outsideuser.userNumber=<s:property value='userNumber'/>">解冻</a>
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
