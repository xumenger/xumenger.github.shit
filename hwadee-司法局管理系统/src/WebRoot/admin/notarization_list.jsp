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
	<h1>公证申请</h1>
	<s:form action="notarization!list.action" method="post">
	<table cellspacing="0" cellpadding="0">
		<tr>
			<td>公证编号</td>
			<td>个人编号</td>
			<td>公证状态</td>
			<td>申请时间</td>
			<td>公证员编号</td>
			<td>收费员编号</td>
			<td>审查员编号</td>
			<td>归档员编号</td>
			<td>申请人住址</td>
			<td>请求事项</td>
			<td>事实与理由</td>
		</tr>
		<s:iterator value="#request.listnota" var="u">
				    <tr>
				      <td><s:property value="notaId"/></td>
				      <td><s:property value="userId"/></td>
				       <td><s:property value="notaStatus"/></td>
				      <td><s:property value="appDate"/></td>
				      <td><s:property value="principalId"/></td>
				      <td><s:property value="feeCollectId"/> </td>
				      <td><s:property value="approvalId"/></td>
				      <td><s:property value="filerId"/></td>
				      <td><s:property value="notaAppAdd"/> </td>
				      <td><s:property value="notaClaims"/></td>
				      <td><s:property value="notaFact"/></td>
				    </tr>
	  </s:iterator>															
	</table>
	</s:form>
</div>	
</body>
</html>
