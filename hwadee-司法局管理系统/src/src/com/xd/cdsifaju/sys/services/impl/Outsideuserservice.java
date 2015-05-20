package com.xd.cdsifaju.sys.services.impl;


import com.xd.cdsifaju.entities.Outsideuser;
import com.xd.cdsifaju.sys.dao.impl.OutsideuserDAO;
import com.xd.cdsifaju.sys.services.interfaces.IOutsideuserservice;

import java.util.List;

import javax.annotation.Resource;
import org.springframework.stereotype.Service;
@Service("outsideUserService")
public class Outsideuserservice implements IOutsideuserservice {
@Resource(name="outsideuserdao")
private OutsideuserDAO OutsideuserDAO;
private String password;
private Outsideuser user;
	
		public Outsideuser getUserById(Integer userId) {
			// TODO Auto-generated method stub
			Outsideuser user = OutsideuserDAO.findById(userId);
			return user;
		}

		public Outsideuser getUserByName(String outsideUserName) {
			// TODO Auto-generated method stub
			return OutsideuserDAO.findByOutsideUserName(outsideUserName);
		}





		public Outsideuser getOutsideuserById(Integer UserNumber) {
			// TODO �Զ���ɵķ������
			Outsideuser user = OutsideuserDAO.findById(UserNumber);
			return user;
		}

	
		public void addOutsideuser(Outsideuser user) {
			// TODO �Զ���ɵķ������
			OutsideuserDAO.save(user);
		}


		public void setpassword(Outsideuser user) {
			// TODO �Զ���ɵķ������
			user.setPassword(password);
		}

		public List<Outsideuser> list() {
			return OutsideuserDAO.findAll();
		}
		public Outsideuser list(String outsideUserName) {
			return OutsideuserDAO.findByOutsideUserName(outsideUserName);
		}
		
	    public void add() throws Exception
		{
			OutsideuserDAO.save(user);
		}

		public Boolean login(Outsideuser user) {
			return OutsideuserDAO.login(user);
		}

		public void edit(Outsideuser user) {
			OutsideuserDAO.update(user);
			
		}

		public Boolean adduser(Outsideuser user) {
			return OutsideuserDAO.adduser(user);
		}


	}