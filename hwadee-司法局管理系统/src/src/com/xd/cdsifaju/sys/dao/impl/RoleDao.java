package com.xd.cdsifaju.sys.dao.impl;

import java.util.List;

import org.springframework.stereotype.Repository;

import com.xd.cdsifaju.common.dao.BasicSupportDao;
import com.xd.cdsifaju.entities.Insideuser;
import com.xd.cdsifaju.entities.Role;
import com.xd.cdsifaju.sys.dao.interfaces.IRoleDao;



@Repository("roleDao")
class RoleDao extends BasicSupportDao implements IRoleDao{

	private static final long serialVersionUID = 1L;

	public String add(Role role) {
		
		this.getHibernateTemplate().save(role);
		return "add";
	}
		
	@SuppressWarnings("unchecked")
	public List<Role> getRoles() {
		return this.getHibernateTemplate().find("from Role order by roleId");
	}


	public String edit(Role role) {
		this.getHibernateTemplate().update(role); 
		return "update";
	}

	public Role detail(Role role) {
		
		return this.getHibernateTemplate().get(Role.class, role.getRoleId());
	}
	
	public String delete(Role role) {

		this.getHibernateTemplate().delete(role);
		return "delete";	
	}
	
	public int[] getright(String Name){
		
		Insideuser insideuser = (Insideuser) this.getHibernateTemplate().find("select iu from Insideuser iu where iu.loginName= ?",Name).get(0);
		String RoleName = insideuser.getRole();
		Role role = (Role)this.getHibernateTemplate().find("select r from Role r where r.roleName= ?",RoleName).get(0);
		
		int[] right={role.getEditRight(),role.getApplyRight(),role.getNotarizationRight(),role.getUserRight(),role.getRoleRight()};
		return right;
	}

}
