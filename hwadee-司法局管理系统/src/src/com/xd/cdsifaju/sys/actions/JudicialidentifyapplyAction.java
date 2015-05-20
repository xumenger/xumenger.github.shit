package com.xd.cdsifaju.sys.actions;

import java.util.List;

import javax.annotation.Resource;

import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;

import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;

import com.opensymphony.xwork2.ActionSupport;
import com.xd.cdsifaju.entities.Judicialidentifyapply;

import com.xd.cdsifaju.sys.services.interfaces.IJudicialidentifyapplyService;

@Controller
// ����
@Scope("prototype")
// ����
@ParentPackage(value = "struts-default")
@Results({
// @Result(name="success",value="fun",params={"contentType","text/plain","root","fun","excludeNullProperties","true"},type=JSONResult.class),
@Result(name = "list", value = "/admin/apply_identify_list.jsp"), 
@Result(name = "success", value = "/index/success.jsp")})
public class JudicialidentifyapplyAction extends ActionSupport {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	@Resource(name = "judicialidentifyapplyservice")
	private IJudicialidentifyapplyService jdservice;

	private Judicialidentifyapply jd;
	private List<Judicialidentifyapply> listjd;

	public Judicialidentifyapply getJd() {
		return jd;
	}

	public void setJd(Judicialidentifyapply jd) {
		this.jd = jd;
	}

	public List<Judicialidentifyapply> getListjd() {
		return listjd;
	}

	public void setListjd(List<Judicialidentifyapply> listjd) {
		this.listjd = listjd;
	}

	public String add() throws Exception {
		jdservice.add(jd);
		return "success";
	}

	public String list() throws Exception {
		listjd = jdservice.list();
		return "list";
	}
}
