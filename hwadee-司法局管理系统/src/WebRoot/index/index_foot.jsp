<%@ page language="java" import="java.util.*" pageEncoding="utf-8" contentType="text/html; charset=UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags"  %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title></title>
</head>

<body>
  <hr>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  	友情链接：
	<div id="foot" align="center">
	  <table width="72%" bgcolor="#CCCCCC">
	    <s:iterator value="#request.outlinks" var="u">
          <a href='<s:property value="linkadd"/>' target="_blank"> <s:property value="linkName"/> </a>&nbsp;&nbsp;&nbsp;
        </s:iterator>
      </table>
    </div>
  <hr>
</body>
</html>
