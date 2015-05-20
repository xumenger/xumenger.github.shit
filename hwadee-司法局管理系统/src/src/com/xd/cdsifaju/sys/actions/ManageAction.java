package com.xd.cdsifaju.sys.actions;

import java.util.*;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;

import org.apache.struts2.config.Namespace;
import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;
import org.apache.struts2.interceptor.ServletRequestAware;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;

import com.opensymphony.xwork2.ActionSupport;
import com.xd.cdsifaju.entities.Notarization;
import com.xd.cdsifaju.sys.services.interfaces.INotarizationService;

@Scope("prototype")
@ParentPackage("struts-default")
@Results({
	@Result(name="list", value="/admin/work_info_list.jsp")
})

@Controller("manageAction")
public class ManageAction extends ActionSupport implements ServletRequestAware{

	private static final long serialVersionUID = 1L;
	@Resource(name="notarizationservice")
	private INotarizationService notaservice;
	private List<Notarization> nolist = new ArrayList<Notarization>();
	private int userid;
	
	public String check() throws Exception{
		List<Notarization> prinList = notaservice.findByPrincipalId(userid);
		List<Notarization> feeList = notaservice.findByFeeCollectId(userid);
		List<Notarization> appList = notaservice.findByApprovalId(userid);
		List<Notarization> filList = notaservice.findByFilerId(userid);
		
		if(prinList.size()!=0){
		
			nolist = prinList;
			return "list";
		}
		else if(feeList.size()!=0){
			
			nolist = feeList;
			return "list";
		 }
		else if(appList.size()!=0){
			
			nolist = appList;
			return "list";
		}
		else if(filList.size()!=0){
			
			nolist = filList;
			return "list";
		}
		else
			return "list";	
	}
	
	public int getUserid() {
		return userid;
	}

	public void setUserid(int userid) {
		this.userid = userid;
	}

	public List<Notarization> getNolist() {
		return nolist;
	}
	
	public void setNolist(List<Notarization> nolist) {
		this.nolist = nolist;
	}

	public void setServletRequest(HttpServletRequest arg0) {
		// TODO Auto-generated method stub
		
	}

}
