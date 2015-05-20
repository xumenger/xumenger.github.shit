<%@ page language="java" import="java.util.*" pageEncoding="utf-8"
	contentType="text/html; charset=UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://"
			+ request.getServerName() + ":" + request.getServerPort()
			+ path + "/";
%>

<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>成都市司法局</title>
<style type="text/css">
p {
	line-height: 60px;
	font-size: 15px;
	font-family: Arial;
}

td {
	text-align: left;
}
</style>
</head>

<body>
	<iframe src="outlink!gotoindextop.action" scrolling="no" height="220px"
		width="100%" frameborder="0"></iframe>
	<div id="body" align="center">
		<form action="notarization!add.action" method="post">

			<fieldset style="width:850px;">
				<legend style="font-size:30px">申请公证</legend>
				<table width="850px" height="900px" align="center"
					cellpadding="20px" cellspacing="0">
					<tr>
						<td>

							<p>&nbsp;</p>
							<p>
								<label for="username">申请人姓名 ：</label> <input type="text"
									id="username" name="username" value="" /> <input type="hidden" />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp例：张三<label
									for="pass"><br> </label>
							</p>
							<p>
								<label>申请人编号 ： <input type="text" name="nota.userNumber">
									<input type="hidden" />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp您的数字id
								</label>
							</p>
							<p>
								<label>申请人地址 ： <input type="text" name="nota.notaAppAdd">
									<input type="hidden" />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp例：**省**市**镇**村
								</label>
							</p>
							<p>
								申 请 日 期 ： <input name="nota.appDate" type="text" size="20"><input
									type="hidden" />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp例：1992-04-28
							</p>
							<p>
								申 请 事 项 ： <input name="nota.notaClaims" type="text" value=""
									size="88" maxlength="1024">
							</p>
							<p>
								<label>理由和事实 ： <textarea name="nota.notaFact" cols="100"
										rows="8"></textarea>
								</label>
							</p>
							<p>
								<input type="hidden" name="nota.notaStatus" value="apply">
								<label for="Submit"></label> <input type="submit" name="Submit"
									value="提交" id="Submit"> <input name="reset"
									type="reset" id="reset" value="重置" />
							</p>
						</td>
					</tr>
				</table>
			</fieldset>

		</form>
	</div>
</body>
</html>
