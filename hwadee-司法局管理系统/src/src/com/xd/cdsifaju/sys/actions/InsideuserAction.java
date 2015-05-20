package com.xd.cdsifaju.sys.actions;

import java.util.List;
import java.util.Map;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;

import com.xd.cdsifaju.sys.dao.impl.InsideuserDAO;
import com.xd.cdsifaju.entities.Insideuser;
import com.xd.cdsifaju.sys.services.impl.Insideuserservice;
import com.xd.cdsifaju.sys.services.interfaces.IInsideuserservice;

import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;
import org.apache.struts2.interceptor.SessionAware;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

@Controller
// ����
@Scope("prototype")
// ����
@ParentPackage(value = "struts-default")
@Results({
		// @Result(name="success",value="districts",params={"contentType","text/json","root","districts","excludeNullProperties","true"},type=StringResult.class),
		@Result(name = "success", value = "10000"),
		@Result(name = "login", value = "/admin/login.jsp"),
		@Result(name = "loginerror", value = "/admin/login_error.jsp"),
		@Result(name = "add", value = "/admin/insideuser_add.jsp"),
		@Result(name = "list", value = "/admin/insideuser_list.jsp"),
		@Result(name = "admin", value = "/admin/admin.jsp"),
		@Result(name = "detail", value = "/admin/insideuser_update.jsp"), })
public class InsideuserAction extends ActionSupport implements SessionAware {
	
	private String nameString = "asdasdas";
	private List<Insideuser> listin;
	private Boolean result;
	private HttpServletRequest request;
    private Map<String, Object> session;
	public Map<String, Object> getSession() {
		return session;
	}

	public void setSession(Map<String, Object> session) {
		this.session = session;
	}

	@Resource(name = "insideUserService")
	private IInsideuserservice service;

	
	public String getNameString() {
		return nameString;
	}

	public void setNameString(String nameString) {
		this.nameString = nameString;
	}

	public void setService(IInsideuserservice service) {
		this.service = service;
	}

	public Boolean getResult() {
		return result;
	}

	public void setResult(Boolean result) {
		this.result = result;
	}

	public IInsideuserservice getService() {
		return service;
	}

	public void setService(Insideuserservice service) {
		this.service = service;
	}

	public HttpServletRequest getRequest() {
		return request;
	}

	public void setRequest(HttpServletRequest request) {
		this.request = request;
	}

	private Insideuser insideuser;

	public Insideuser getInsideuser() {
		return insideuser;
	}

	public void setInsideuser(Insideuser insideuser) {
		this.insideuser = insideuser;
	}

	public String login() throws Exception {

		result = service.login(insideuser);

		if (result) {
			ActionContext.getContext().getSession().put("userInfo", insideuser);// 如果登陆成功，将该insideuser存入session，其key设为userInfo
//			nameString=insideuser.getLoginName();
	//		nameString="fuck";
	//		ActionContext.getContext().getSession().put("name", nameString);			
			return "admin";
		} else
			return "loginerror";
		// if(
		// user.getUserPassword().equals(service.getInsideuserByName(user.getLoginName()).getUserPassword())
		// &&
		// "on".equals(service.getInsideuserByName(user.getLoginName()).getInsideUserStatus())){
		// //��ȡActionContextʵ��ͨ����������Servlet API
		// ActionContext context = ActionContext.getContext();
		// //��session���Ƿ��Ѿ�������û���������ˣ�˵���Ѿ���¼�ˣ�
		// //����˵���ǵ�һ�ε�¼�ɹ�
		// if(null != context.getSession().get("uName")){
		// }else{
		// context.getSession().put("uName", this.insideuser.getLoginName());
		// }
		// return "admin";
		// }else{
		// return "loginerror";
		// }
	}

	public String AddInsideUser() throws Exception {
		if (service.adduser(insideuser)) {
		service.add(insideuser);
		return list();	
		}
		return "add";
	}

	public String list() throws Exception {
		listin = service.list();
		// Insideuser insideuser = new Insideuser();
		// insideuser.setUserId(123);
		// insideuser.setLoginName("����");
		// listin.add(insideuser);
		// System.out.println(">>>>>::"+listin.get(0).getLoginName());
		return "list";
	}

	public String add() throws Exception {
		service.add(insideuser);
		return "list";
	}

	public String gotoadd() throws Exception {
		return "add";
	}

	public String search() throws Exception {
		listin = service.list(insideuser.getRole());
		return "list";
	}

	public String gotolist() throws Exception {
		return list();
	}

	public String detail() throws Exception {
		insideuser =service.getInsideuserById(insideuser.getUserId());
		return "detail";
	}

	public List<Insideuser> getListin() {
		return listin;
	}

	public void setListin(List<Insideuser> listin) {
		this.listin = listin;
	}

	public String edit() throws Exception {
		service.edit(insideuser);
		return list();
	}

	public String gotologin() {
		return "login";
	}

	public String out() {
		ActionContext.getContext().getSession().clear();		
		return "login";
	}
}
