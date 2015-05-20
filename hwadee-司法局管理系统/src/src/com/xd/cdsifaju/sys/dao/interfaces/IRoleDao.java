package com.xd.cdsifaju.sys.dao.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Role;




public interface IRoleDao {

	String add(Role role);
	List<Role> getRoles();
	String edit(Role role);
	Role detail(Role role);
	String delete(Role role);
	int[] getright(String Name);
}
