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
<title>申请纠纷调解</title>
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
		<form action="disputesolve!add.action" method="post">

			<fieldset style="width:850px;">
				<legend style="font-size:30px">申请纠纷调解</legend>
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
								<label>申请人编号 ： <input type="text" name="ds.userNumber">
									<input type="hidden" />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp您的数字id
								</label>
							</p>
							<p>
								<label>申请人地址 ： <input type="text" name="ds.dsappBirth">
									<input type="hidden" />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp例：**省**市**镇**村
								</label>
							</p>
							<p>
								申请人生日 ： <input name="ds.dsappAdd" type="text" size="20"><input
									type="hidden" />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp例：1992-04-28
							</p>
							<p>
								申请人性别 ： <input name="ds.dsappSex" type="radio" value="man"
									checked> 男 <input type="radio" name="ds.dsappSex"
									value="woman"> 女
							</p>
							<p>
								申 请 事 项 ： <input name="ds.dsclaims" type="text" value=""
									size="88" maxlength="1024">
							</p>
							<p>
								<label>理由和事实 ： <textarea name="ds.dsfact" cols="100"
										rows="8"></textarea>
								</label>
							</p>
							<p>
								<input type="hidden" name="ds.dsstatus" value="apply"> <label
									for="Submit"></label> <input type="submit" name="Submit"
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
