package com.xd.cdsifaju.sys.actions;

import javax.servlet.http.HttpServletRequest;

import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;
import org.apache.struts2.interceptor.ServletRequestAware;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import com.xd.cdsifaju.entities.Insideuser;
import com.xd.cdsifaju.entities.Outsideuser;


@Controller
@Scope("prototype")
@ParentPackage(value="struts-default")
@Results({
    @Result(name="login",value="/index/outlogin.jsp"),
    @Result(name="identify",value="/index/JudicialIdentifyApply.jsp"),
    @Result(name="support",value="/index/JudicialSupportApply.jsp"),
    @Result(name="dispute",value="/index/DisputeSolveApply.jsp"),
    @Result(name="notarization",value="/index/Notarization.jsp")
})
public class GotoAction extends ActionSupport implements ServletRequestAware{
//主要实现前台用户点击提交申请、公证预约的链接的时候，判断用户是否已经登录，若登陆则跳转到对应页面，否则跳转到登陆界面	
	public String gotoIdentify() throws Exception{
		if(ActionContext.getContext().getSession().get("userData")!=null)
			return "identify";
		else
			return "login";
	}
	
	public String gotoSupport() throws Exception{
		if(ActionContext.getContext().getSession().get("userData")!=null)
			return "support";
		else
			return "login";
	}
	
	public String gotoDispute() throws Exception{
		if(ActionContext.getContext().getSession().get("userData")!=null)
			return "dispute";
		else
			return "login";
	}
	
	public String gotoNotarization() throws Exception{
		if(ActionContext.getContext().getSession().get("userData")!=null)
			return "notarization";
		else
			return "login";
	}

	public void setServletRequest(HttpServletRequest arg0) {
		// TODO Auto-generated method stub
		
	}

}
