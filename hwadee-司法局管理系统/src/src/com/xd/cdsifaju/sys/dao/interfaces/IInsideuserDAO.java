package com.xd.cdsifaju.sys.dao.interfaces;
import java.util.List;


import com.xd.cdsifaju.entities.Insideuser;


public interface IInsideuserDAO {
	public void save(Insideuser transientInstance);
	public void update(Insideuser transientInstance);
	public void delete(Insideuser persistentInstance);
	public Insideuser findById(java.lang.Integer id);
	public List findByExample(Insideuser instance);
	public List findByRole(Object role);
	public List findByInsideUserStatus(Object insideUserStatus);
	public List findByUserPassword(Object userPassword);
	public List findByDepartment(Object department);
	public List<Insideuser> findAll();
	Boolean login(Insideuser user);
	Boolean adduser(Insideuser user);	
}
