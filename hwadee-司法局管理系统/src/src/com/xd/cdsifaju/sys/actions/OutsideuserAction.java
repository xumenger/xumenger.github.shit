package com.xd.cdsifaju.sys.actions;

import java.util.List;
import java.util.Map;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;

import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;
import org.apache.struts2.interceptor.SessionAware;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;

import com.xd.cdsifaju.entities.Outsideuser;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import com.xd.cdsifaju.sys.services.interfaces.IOutsideuserservice;

@Controller
// ����
@Scope("prototype")
// ����
@ParentPackage(value = "struts-default")
@Results({
//@Result(name="success",value="districts",params={"contentType","text/json","root","districts","excludeNullProperties","true"},type=StringResult.class),
@Result(name="success",value="10000"),
@Result(name="login",value="/index/outlogin.jsp"),
@Result(name="loginerror",value="/index/login_error.jsp"),
@Result(name="register",value="/index/register.jsp"),
@Result(name="regist",value="/index/register.jsp"),
@Result(name="list",value="/admin/outsideuser_list.jsp"),
@Result(name="admin",value="/index.jsp"),
@Result(name="detail",value="/index/useredit.jsp"),
@Result(name="success1",value="/index/success.jsp"),

})

public class OutsideuserAction extends ActionSupport implements SessionAware{

	@Resource(name="outsideUserService")
	private IOutsideuserservice service;
	private Outsideuser outsideuser;
	private List<Outsideuser> listout;
	private Boolean result;
	private HttpServletRequest request;
    private Map<String, Object> session;
    private int aaa;
    
    
	
	public int getAaa() {
		return aaa;
	}

	public void setAaa(int aaa) {
		this.aaa = aaa;
	}

	public Boolean getResult() {
		return result;
	}

	public void setResult(Boolean result) {
		this.result = result;
	}

	public Map<String, Object> getSession() {
		return session;
	}

	public void setRequest(HttpServletRequest request) {
		this.request = request;
	}

	public IOutsideuserservice getService() {
		return service;
	}

	public void setService(IOutsideuserservice service) {
		this.service = service;
	}


	public Outsideuser getOutsideuser() {
		return outsideuser;
	}

	public void setOutsideuser(Outsideuser outsideuser) {
		this.outsideuser = outsideuser;
	}
	
	public List<Outsideuser> getListout() {
			return listout;
		}

	public void setListout(List<Outsideuser> listout) {
			this.listout = listout;
		}
		
	public String login() throws Exception{
			result = service.login(outsideuser);
			
			if(result){
				ActionContext.getContext().getSession().put("userData", outsideuser);
				return "admin";
				}
			else
				return "loginerror";
//		if(service.getUserByName(outsideUserName).getOutsideUserStatus().equals("off")){
//	            return OutsideuserAction.ERROR; 
//		}
//	        if( service.getUserByName(outsideUserName).getPassword().equals(Password)&&service.getUserByName(outsideUserName).getOutsideUserStatus()=="on"){
//	        	
//	            //��ȡActionContextʵ��ͨ����������Servlet API
//	            ActionContext context = ActionContext.getContext();
//	            //��session���Ƿ��Ѿ�������û���������ˣ�˵���Ѿ���¼�ˣ�
//	//����˵���ǵ�һ�ε�¼�ɹ�
//	            if(null != context.getSession().get("uName")){
//	                msg = this.outsideuser.getOutsideUserName() + "�����Ѿ���¼����!!!";
//	            }else{
//	                context.getSession().put("uName", this.outsideuser.getOutsideUserName());
//	            }
//	            return OutsideuserAction.SUCCESS;
//	        }else{
//	            msg = "��¼ʧ�ܣ��û���������";
//	            return "loginerror";
//	        }
	    }

	 
	    public String regist() throws Exception{
	    
	        if(service.adduser(outsideuser)){
	        service.addOutsideuser(outsideuser);
	        return "success1";
	        }
	        return "register";
	    }
	    
	    public String removeLock()throws Exception{
	    	Outsideuser user = service.getOutsideuserById(outsideuser.getUserNumber());
	    	user.setOutsideUserStatus("on");
	    	service.edit(user);
	    	return list();
	    }
	    public String setLockoutsideuser()throws Exception{
	    	Outsideuser user = service.getOutsideuserById(outsideuser.getUserNumber());
	    	user.setOutsideUserStatus("off");
	    	service.edit(user);
	    	return list();
	    }

		public String list() throws Exception
		{
			listout=service.list();
			return "list";
		}

		public HttpServletRequest getRequest() {
			return request;
		}

		public void setSession(Map<String, Object> session) {
			this.session = session;
		}

		public String detail() throws Exception {
			outsideuser =service.getOutsideuserById(outsideuser.getUserNumber());
			return "detail";
		}
		public String edit() throws Exception {
			service.edit(outsideuser);
			return list();
		}
	    public String gotoregist() throws Exception{
	    	return "regist";
	    }
	    public String gotologin() throws Exception{
	    	return "login";
	    }
}