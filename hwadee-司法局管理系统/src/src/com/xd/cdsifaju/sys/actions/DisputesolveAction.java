package com.xd.cdsifaju.sys.actions;

import java.util.List;

import javax.annotation.Resource;

import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;

import com.opensymphony.xwork2.ActionSupport;
import com.xd.cdsifaju.entities.Disputesolve;
import com.xd.cdsifaju.sys.services.interfaces.IDisputesolveService;

@Controller
//����
@Scope("prototype")
//����
@ParentPackage(value = "struts-default")
@Results({
//@Result(name="success",value="fun",params={"contentType","text/plain","root","fun","excludeNullProperties","true"},type=JSONResult.class),
@Result(name = "list", value = "/admin/apply_dispute_list.jsp"),
@Result(name = "success", value = "/index/success.jsp") })
public class DisputesolveAction extends ActionSupport{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	@Resource(name = "disputesolveservice")
	private IDisputesolveService dsservice;
	private Disputesolve ds;
	private List<Disputesolve> listds;
	public Disputesolve getDs() {
		return ds;
	}
	public void setDs(Disputesolve ds) {
		this.ds = ds;
	}
	public List<Disputesolve> getListds() {
		return listds;
	}
	public void setListds(List<Disputesolve> listds) {
		this.listds = listds;
	}
	public String list() throws Exception{
		listds=dsservice.list();
		return "list";
		}
	public String add() throws Exception{
		dsservice.add(ds);
		return "success";
	}

}
