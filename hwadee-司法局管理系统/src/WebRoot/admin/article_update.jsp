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

<script type="text/javascript" charset="utf-8" src="../ueditor1_4_3-utf8-jsp/ueditor.config.js"></script>
<script type="text/javascript" charset="utf-8" src="../ueditor1_4_3-utf8-jsp/ueditor.all.min.js"> </script>
<script type="text/javascript" charset="utf-8" src="../ueditor1_4_3-utf8-jsp/lang/zh-cn/zh-cn.js"></script>

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
	<h1>更改文章</h1>
	<s:form action="article!edit.action" method="post">
    	<table style="width:100%">
    		<tr>
    			<input type="hidden" size="40" name="article.articleID" value="${article.articleID}"/>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right">文章名称</td>
    			<td>
    				<input type="text" size="40" name="article.articleName" value="${article.articleName}"/>
    			</td>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right">审核员ID</td>
    			<td>
    				<input type="text" size="40" name="article.userID" value="${article.userID}"/>
    			</td>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right">文章类型</td>
    			<td>
    				<select name="article.articleType"value="article.articleType">
    					<option value="1">政务信息公开</option>
    					<option value="2">综合资讯</option>
    					<option value="3">公共法律服务</option>
    					<option value="4">队伍建设</option>
    					<option value="5">通知公告</option>
					</select>
    			</td>
    		</tr>
    	
    		<tr>
    			<td style="width:30%;text-align: right">上传时间</td>
    			<td>
    				<input type="date" name="article.updateTime" value="${article.updateTime}"/>
    			</td>
    		</tr>
    		<!--  -->
    		<tr>
    			<td style="width:30%;text-align: right">作者</td>
    			<td>
    				<input type="text" name="article.author"value="${article.author}"/>
    			</td>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right">审核状态</td>
    			<td>
    				<select name="article.articleStatus"value="article.articleStatus">
    					<option value="1">未审核</option>
    					<option value="2">通过</option>
    					<option value="3">未通过</option>
    				</select>
    			</td>
    		</tr>
    		<tr>
    			<td style="width:30%;text-align: right">文章正文</td>
    			<td>
    				<script id="editor" type="text/plain" style="width:1024px;height:500px;" name="article.articleContent"">
					${article.articleContent}
					</script>
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

<script type="text/javascript">
var ue = UE.getEditor('editor');
</script>

</body>
</html>
