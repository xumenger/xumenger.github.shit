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
   <div id="img" align="center">
   <img src="images/top.PNG" /></div>
<div>
  <h1>用户注册</h1>
  <s:form action="outsideuser!regist.action" method="post">
	<table cellspacing="0" cellpadding="0">
		<tr>
			<th colspan="4"></th>
		</tr>
		<tr>
			<td style="width:30%;text-align: right">用户名：</td><td>
			<input name="outsideuser。outsideUserName"  type="text" size="20"/> 
			</td>
		</tr>			
		<tr>
			<td style="width:30%;text-align: right">密码：</td><td>
			<input name="outsideuser。password"  type="password" size="20" /> 
			</td>
		</tr>			
		<tr>
		<td style="width:30%;text-align: right">用户状态：</td><td>
		未冻结<input name="outsideuser。outsideUserStatus" type="hidden" size="20" value="on"/> 
		</td>
		</tr>			
		<tr>
    		<td style="width:30%;text-align: right">性别</td>
    			<td>
    				<select name="outsideuser.userSex">
    					<option value="1">男</option>
    					<option value="0">女</option>
					</select>                        
    			</td>
    			</tr>
		<tr>
			<td style="width:30%;text-align: right">生日</td><td>
			<input name="outsideuser。birthDate"  type="text" size="20"/> 
		</td>
		</tr>
		<tr>
			<td style="width:30%;text-align: right">现居住地</td><td>
			<input name="outsideuser。currentAddr"  type="text" size="20"/> 
		</td>
		</tr>
		<tr>
			<td style="width:30%;text-align: right">手机</td><td>
			<input name="outsideuser。mobile"  type="text" size="20"/> 
		</td>
		</tr>	
		<tr>
			<td style="width:30%;text-align: right">QQ</td><td>
			<input name="outsideuser。qq" type="text" size="20"/> 
		</td>
		</tr>
		<tr>
			<td style="width:30%;text-align: right">个人MSN</td><td>
			<input name="outsideuser。msn" type="text" size="20"/> 
		</td>
		</tr>
		<tr>
			<td style="width:30%;text-align: right">固定电话</td><td>
			<input name="outsideuser。phone" type="text" size="20"/> 
		</td>
		</tr>	
		<tr>
			<td style="width:30%;text-align: right">邮政编码</td><td>
			<input name="outsideuser。zipCode"  type="text" size="20"/> 
		</td>
		</tr>
		<tr>
			<td style="width:30%;text-align: right">通讯地址</td><td>
			<input name="outsideuser。address"  type="text" size="20"/> 
		</td>
		</tr>		
         <td height="35" >&nbsp;</td>
         <td width="10%" height="17" ><input  type="submit" value="注册"/></td>
         <td width="9%" ><input name="cs" type="button" class="button" id="cs" value="取消"  />
        </td>
         <td width="68%" >&nbsp;</td>
         <td width="2%" class="top_hui_text">&nbsp;</td>
               </table>
         </s:form>
         </div>
</body>
</html>
