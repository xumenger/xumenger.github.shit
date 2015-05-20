package com.xd.cdsifaju.sys.services.impl;
import com.xd.cdsifaju.entities.Insideuser;

import com.xd.cdsifaju.sys.dao.impl.InsideuserDAO;
import com.xd.cdsifaju.sys.services.interfaces.IInsideuserservice;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

@Service("insideUserService")
public class Insideuserservice implements IInsideuserservice{
	
	@Resource(name="insideuserdao")
	private InsideuserDAO insideuserDAO;

	public void add(Insideuser user) {
		// TODO Auto-generated method stub
		insideuserDAO.save(user);
	}
	public void edit(Insideuser user){
		insideuserDAO.update(user);
	}
	public InsideuserDAO getInsideuserDAO() {
		return insideuserDAO;
	}
	public Insideuser getUserByRole(String Role) {
		// TODO Auto-generated method stub
		List list = insideuserDAO.findByRole(Role);
		if(list.size() == 0){
			System.out.println("There is no one whose name is: " + Role +" !");
            return null;
		}
		return (Insideuser)list.get(0); //此处要注意
	}
	public void setInsideuserDAO(InsideuserDAO InsideuserDAO) {
		this.insideuserDAO = InsideuserDAO;
	}

	public Insideuser getInsideuserById(Integer UserID) {
		// TODO Auto-generated method stub
		Insideuser user = insideuserDAO.findById(UserID);
		return user;
	}
	public Insideuser getInsideuserById(Insideuser insideuser) {
		// TODO Auto-generated method stub
		Insideuser user = insideuserDAO.findById(insideuser);
		return user;
	}
	public Insideuser getInsideuserByName(String LoginName) {
		// TODO Auto-generated method stub
		Insideuser Insideuser = insideuserDAO.findByLoginName(LoginName);
		return Insideuser; //此处要注意
	
	}
	public List<Insideuser> list() {
		return insideuserDAO.findAll();
		
	}
	public List<Insideuser> list(String loginName) {
		return null;
	}
	public Boolean login(Insideuser user) {
		
		return insideuserDAO.login(user);
	}
	public Boolean adduser(Insideuser user) {
		return insideuserDAO.adduser(user);
	}



}
