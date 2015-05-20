package com.xd.cdsifaju.sys.services.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Role;



public interface IRoleService {

	String add(Role role);
	List<Role> list();
	String edit(Role role);
	String delete(Role role);
	Role detail(Role role);
	int[] getright(String Name);
}
