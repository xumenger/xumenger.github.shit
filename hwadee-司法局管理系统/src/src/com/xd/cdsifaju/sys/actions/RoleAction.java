package com.xd.cdsifaju.sys.actions;


import java.util.Date;
import java.util.List;
import java.util.Map;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;

import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;
import org.apache.struts2.interceptor.ServletRequestAware;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;


import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionInvocation;
import com.opensymphony.xwork2.ActionSupport;
import com.xd.cdsifaju.entities.Insideuser;
import com.xd.cdsifaju.entities.Role;
import com.xd.cdsifaju.sys.services.interfaces.IRoleService;

@Controller
@Scope("prototype")
@ParentPackage(value="struts-default")
@Results({
   // @Result(name="success",value="fun",params={"contentType","text/plain","root","fun","excludeNullProperties","true"},type=JSONResult.class),
    @Result(name="add",value="/admin/role_add.jsp"),
    @Result(name="list",value="/admin/role_list.jsp"),
    @Result(name="detail",value="/admin/role_update.jsp"),
    @Result(name="adminleft",value="/admin/admin_lef.jsp")
})
public class RoleAction extends ActionSupport implements ServletRequestAware{
	
	private static final long serialVersionUID = 1L;

	/**
	 * @param args
	 */
	@Resource(name="roleService")
	private IRoleService roleService;
	
	private Role role;
	private List<Role> roles;
	
	private int[] right;
	
	

	public IRoleService getRoleService() {
		return roleService;
	}

	public void setRoleService(IRoleService roleService) {
		this.roleService = roleService;
	}

	public int[] getRight() {
		return right;
	}

	public void setRight(int[] right) {
		this.right = right;
	}

	public Role getRole() {
		return role;
	}

	public void setRole(Role role) {
		this.role = role;
	}

	public List<Role> getRoles() {
		return roles;
	}

	public void setRoles(List<Role> roles) {
		this.roles = roles;
	}
	
	
	public String detail() throws Exception
	{
			role=roleService.detail(role);
			return "detail";
	}
	
	public String delete() throws Exception
	{
		roleService.delete(role);
		return list();
	}
	
	public String add() throws Exception
	{
		roleService.add(role);
		return list();
	}
	
	public String list() throws Exception
	{
		roles=roleService.list();
		return "list";
	}
	
	public String edit() throws Exception
	{
		//this.Role.setUpdateTime(new Date());
		/*
		Date d=new Date();
		Simple
		*/
		roleService.edit(role);
		return list();
	}
	
	public String getright()throws Exception{
		/*ActionInvocation invocation = null;
		Map map=invocation.getInvocationContext().getSession();//获得session  
        Insideuser insideuser = (Insideuser) map.get("userInfo");//获取之前存入的那个键为"userInfo"的值，也就是存入的user信息
        */

		/*HttpServletRequest request =null;
		Insideuser insideuser=(Insideuser)request.getSession().getAttribute("userInfo");
        right=this.roleService.getright(insideuser.getLoginName());*/
		Insideuser insideuser=(Insideuser) ActionContext.getContext().getSession().get("userInfo");// 获取登陆成功时存入session里面的那个内部用户
		
		right=this.roleService.getright(insideuser.getLoginName());
		
/*		int[] i={1,0,1,0,1};
        right=i;*/
		
		return "adminleft";
	}
	
	public String gotoedit() throws Exception
	{
		//Role=RoleService.findbyid(Role);
		return "edit";
	}
	
	public String gotolist() throws Exception
	{
		roles=roleService.list();
		return "list";
	}

	public String gotoadd() throws Exception
	{
		return "add";
	}
	
	
	public void setServletRequest(HttpServletRequest arg0) {
		
		
	}
}
