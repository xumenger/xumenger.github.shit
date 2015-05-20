package com.xd.cdsifaju.sys.actions;

import java.util.List;

import javax.annotation.Resource;

import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;
import org.apache.struts2.interceptor.ServletRequestAware;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;

import com.opensymphony.xwork2.ActionSupport;
import com.xd.cdsifaju.entities.Judicialsupportapply;
import com.xd.cdsifaju.sys.services.interfaces.IJudicialsupportapplyService;

@Controller
// ����
@Scope("prototype")
// ����
@ParentPackage(value = "struts-default")
@Results({
// @Result(name="success",value="fun",params={"contentType","text/plain","root","fun","excludeNullProperties","true"},type=JSONResult.class),
@Result(name = "list", value = "/admin/apply_support_list.jsp"),
@Result(name = "success", value = "/index/success.jsp")
		 })
public class JudicialsupportapplyAction extends ActionSupport {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	@Resource(name = "judicialsupportapplyservice")
	private IJudicialsupportapplyService jsservice;

	private Judicialsupportapply js;
	private List<Judicialsupportapply> listjs;

	public Judicialsupportapply getJs() {
		return js;
	}

	public void setJs(Judicialsupportapply js) {
		this.js = js;
	}

	public List<Judicialsupportapply> getListjs() {
		return listjs;
	}

	public void setListjs(List<Judicialsupportapply> listjs) {
		this.listjs = listjs;
	}
	public String add() throws Exception{
		jsservice.add(js);
		return "success";
	}
	public String list() throws Exception{
		listjs=jsservice.list();
		return "list";	
	}
}
