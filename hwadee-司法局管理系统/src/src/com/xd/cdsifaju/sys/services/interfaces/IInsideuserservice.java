package com.xd.cdsifaju.sys.services.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Insideuser;

public interface IInsideuserservice {
	List<Insideuser> list();
	public Insideuser getInsideuserById(Integer UserID);
	public Insideuser getInsideuserByName(String LoginName);
	public void add(Insideuser user);
	public Insideuser getUserByRole(String Role);
	public void edit(Insideuser user);
	List<Insideuser> list(String loginName);
	public Insideuser getInsideuserById(Insideuser insideuser);
	Boolean login(Insideuser user);
	Boolean adduser(Insideuser user);
}
