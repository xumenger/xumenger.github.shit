package com.xd.cdsifaju.sys.actions;


import java.util.Date;
import java.util.List;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;

import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;
import org.apache.struts2.interceptor.ServletRequestAware;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;


import com.opensymphony.xwork2.ActionSupport;
import com.xd.cdsifaju.entities.Outlink;
import com.xd.cdsifaju.sys.services.interfaces.IOutlinkService;

@Controller
@Scope("prototype")
@ParentPackage(value="struts-default")
@Results({
   // @Result(name="success",value="fun",params={"contentType","text/plain","root","fun","excludeNullProperties","true"},type=JSONResult.class),
    @Result(name="add",value="/admin/outlink_add.jsp"),
    @Result(name="list",value="/admin/outlink_list.jsp"),
    @Result(name="detail",value="/admin/outlink_update.jsp"),
    @Result(name="indexfoot",value="/index/index_foot.jsp"),
    @Result(name="indextop",value="/index/index_top.jsp"),
})
public class OutlinkAction extends ActionSupport implements ServletRequestAware{
	
	private static final long serialVersionUID = 1L;

	/**
	 * @param args
	 */
	@Resource(name="outlinkService")
	private IOutlinkService outlinkService;
	
	private Outlink outlink;
	private List<Outlink> outlinks;

	public Outlink getOutlink() {
		return outlink;
	}

	public void setOutlink(Outlink outlink) {
		this.outlink = outlink;
	}

	public List<Outlink> getOutlinks() {
		return outlinks;
	}

	public void setOutlinks(List<Outlink> outlinks) {
		this.outlinks = outlinks;
	}
	
	
	public String detail() throws Exception
	{
			outlink=outlinkService.detail(outlink);
			return "detail";
	}
	
	public String delete() throws Exception
	{
		outlinkService.delete(outlink);
		return list();
	}
	
	public String add() throws Exception
	{
		outlinkService.add(outlink);
		return list();
	}
	
	public String list() throws Exception
	{
		outlinks=outlinkService.list();
		return "list";
	}
	
	public String edit() throws Exception
	{
		//this.Outlink.setUpdateTime(new Date());
		/*
		Date d=new Date();
		Simple
		*/
		outlinkService.edit(outlink);
		return list();
	}
	public String gotoedit() throws Exception
	{
		//Outlink=outlinkService.findbyid(outlink);
		return "edit";
	}
	
	public String gotolist() throws Exception
	{
		outlinks=outlinkService.list();
		return "list";
	}

	public String gotoindexfoot() throws Exception
	{
		outlinks=outlinkService.list();
		return "indexfoot";
	}
	
	public String gotoindextop() throws Exception
	{
		return "indextop";
	}
	
	public String gotoadd() throws Exception
	{
		return "add";
	}
	public String gotologin() {
		return "login";
	}
	
	public void setServletRequest(HttpServletRequest arg0) {
		
		
	}
}
