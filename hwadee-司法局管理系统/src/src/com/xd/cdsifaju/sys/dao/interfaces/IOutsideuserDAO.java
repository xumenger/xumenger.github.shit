package com.xd.cdsifaju.sys.dao.interfaces;
import java.util.List;
import com.xd.cdsifaju.entities.Insideuser;
import com.xd.cdsifaju.entities.Outsideuser;

public interface IOutsideuserDAO {
	public void save(Outsideuser transientInstance) ;
	public void delete(Outsideuser persistentInstance);
	public Outsideuser findById(java.lang.Integer id) ;
	public Outsideuser findByOutsideUserName(String OutsideUserName) ;
	public List findByOutsideUserName(Object outsideUserName);
	public List findAll();
	Boolean login(Outsideuser user);
	void update(Outsideuser transientInstance);
	Boolean adduser(Outsideuser user);
}
