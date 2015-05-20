package com.xd.cdsifaju.sys.services.interfaces;

import java.util.List;


import com.xd.cdsifaju.entities.Outsideuser;

public interface IOutsideuserservice {

	public Outsideuser getOutsideuserById(Integer UserNumber);
	
	public void addOutsideuser(Outsideuser user);
	
	public void setpassword(Outsideuser user);
	
	List<Outsideuser> list();
	
	public Outsideuser getUserByName(String outsideUserName) ;
	Boolean login(Outsideuser user);
	void edit(Outsideuser user);
	Boolean adduser(Outsideuser user);

}
