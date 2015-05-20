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
	<h1>申请司法援助</h1>
	<s:form action="judicialsupportapply!list.action" method="post">
	<table cellspacing="0" cellpadding="0">
		<tr>
			<th>申请编号</th>
			<th>个人编号</th>
			<th>申请状态</th>
			<th>申请人性别</th>
			<th>申请人出生日期</th>
			<th>申请人住址</th>
			<th>请求事项</th>
			<th>事实与理由</th>
		</tr>
		<s:iterator value="#request.listjs" var="u">
				    <tr>
				      <td><s:property value="jsid"/></td>
				      <td><s:property value="userNumber"/></td>
				       <td><s:property value="jsstatus"/></td>
				      <td><s:property value="jsappSex"/></td>
				      <td><s:property value="jsappBirth"/></td>
				      <td><s:property value="jsappAdd"/> </td>
				      <td><s:property value="jsclaims"/></td>
				      <td><s:property value="jsfact"/></td>
				    </tr>
	  </s:iterator>															
	</table>
	</s:form>
</div>	
</body>
</html>
