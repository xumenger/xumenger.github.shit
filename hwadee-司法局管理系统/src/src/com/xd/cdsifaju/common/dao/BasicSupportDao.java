package com.xd.cdsifaju.common.dao;
import java.io.Serializable;

import javassist.SerialVersionUID;

import javax.annotation.Resource;



import org.hibernate.SessionFactory;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

public class BasicSupportDao extends HibernateDaoSupport implements
		Serializable{
	private static final long SerialVersionUID = 1L;
	
	/*@Resource(name = "hibernateTemplate")
	public void setHibernatetemplate(HibernateTemplate hibernateTemplate) {
		super.setHibernateTemplate(hibernateTemplate);
	}*/
	
	//∏∏¿‡HibernateDaoSupport◊¢»ÎsessionFactory
	@Resource(name="sessionFactory")
	public void setSuperSessionFactory(SessionFactory sessionFactory){
	super.setSessionFactory(sessionFactory);	
	}
}
