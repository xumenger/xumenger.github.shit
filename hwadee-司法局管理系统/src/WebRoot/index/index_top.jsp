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
<title>成都市司法局</title>
<style type="text/css">	
a:link{
	color:#000;
	text-decoration:none;
}
a:visited{
	color:#000;
	text-decoration:none;
}
a.nav:hover{
	color:#F90;
	text-decoration:underline;
	font-size:18px;
}
a:hover{
	text-decoration:underline;
}
</style>
</head>

<body>

   <div id="img" align="center">
   <img src="images/top.PNG" ></div>
   <nav>
<%--     <div id="table">
     <table align="center" width="70%" border="0" id="tone">
      <tr><th  rowspan="2"><a href="#" class="nav">信息展示</a></th>
          <td w><a href="#" class="nav">综合资讯</a></td>
          <td ><a href="#" class="nav">法律服务</a></td>
          <th  rowspan="2"><a href="#" class="nav">网上办事</a></
          <th one="52" rowspan="2"><a href="#" class="nav">政民互动</a></th>
          <td one="49"><a href="#" class="nav">局长信箱</a></td>
          <td one="287"><a href="#" class="nav">便民服务</a></td>
                  	<s:iterator value="session.userData" var="u">
        		<s:if test="%{outsideUserName==""}">
					<tr href="outsideuser!gotologin.action/>"/><s:property value=登陆/></td></tr>
					<tr href="outsideuser!gotoregister.action/>"/><s:property value=注册/></td></tr>
				</s:if>
				<s:else>
				    <td href="outsideuser!detail.action?outsideuser.userNumber=<s:property value='userData.userNumber'/>">${userDate.loginName}：已登录</td>
				</s:else>
			</s:iterator>       
       </tr>
       <tr>
          <td><a href="#" class="nav">政务公开</a></td>
          <td>&nbsp;</td>
       </tr>
     </table>
    </div> --%>
   </nav>
</body>
</html>
