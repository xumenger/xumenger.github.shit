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
	<h1>纠纷调解</h1>
	<s:form action="disputesolve!list.action" method="post">
	<table cellspacing="0" cellpadding="0">
		<tr>
			<td>申请编号</td>
			<td>个人编号</td>
			<td>申请状态</td>
			<td>申请人性别</td>
			<td>申请人出生日期</td>
			<td>申请人住址</td>
			<td>请求事项</td>
			<td>事实与理由</td>
		</tr>
		<s:iterator value="#request.listds" var="u">
				    <tr>
				      <td><s:property value="dsid"/></td>
				      <td><s:property value="userNumber"/></td>
				       <td><s:property value="dsstate"/></td>
				      <td><s:property value="dsappSex"/></td>
				      <td><s:property value="dsappBirth"/></td>
				      <td><s:property value="dsappAdd"/> </td>
				      <td><s:property value="dsclaims"/></td>
				      <td><s:property value="dsfact"/></td>
				    </tr>
	  </s:iterator>															
	</table>
	</s:form>
</div>	
</body>
</html>
