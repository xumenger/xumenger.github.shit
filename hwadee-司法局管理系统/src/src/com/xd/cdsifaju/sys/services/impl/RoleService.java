package com.xd.cdsifaju.sys.services.impl;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.xd.cdsifaju.entities.Role;
import com.xd.cdsifaju.sys.dao.interfaces.IRoleDao;
import com.xd.cdsifaju.sys.services.interfaces.IRoleService;



@Service("roleService")
public class RoleService implements IRoleService{

	/**
	 * @param args
	 */
	@Resource(name="roleDao")
	private IRoleDao roleDao;
	
	public String add(Role role) {
		// TODO Auto-generated method stub
		//return null;
		return roleDao.add(role);
	}

	public List<Role> list() {
		// TODO Auto-generated method stub
		return roleDao.getRoles();
	}

	public String edit(Role role) {
		// TODO Auto-generated method stub
		//return null;
		return roleDao.edit(role);
	}

	public String delete(Role role) {
		// TODO Auto-generated method stub
		return roleDao.delete(role);
	}

	public Role detail(Role role) {
		// TODO Auto-generated method stub
		return roleDao.detail(role);
	}
	
	public int[] getright(String Name){
		return roleDao.getright(Name);
	}

}
