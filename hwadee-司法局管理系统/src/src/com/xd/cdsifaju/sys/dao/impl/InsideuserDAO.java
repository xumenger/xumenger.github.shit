package com.xd.cdsifaju.sys.dao.impl;

import java.util.List;
import org.hibernate.LockMode;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Repository;

import com.xd.cdsifaju.common.dao.BasicSupportDao;
import com.xd.cdsifaju.entities.Insideuser;
import com.xd.cdsifaju.sys.dao.interfaces.IInsideuserDAO;

/**
 * A data access object (DAO) providing persistence and search support for
 * Insideuser entities. Transaction control of the save(), update() and delete()
 * operations can directly support Spring container-managed transactions or they
 * can be augmented to handle user-managed Spring transactions. Each of these
 * methods provides additional information for how to configure it for the
 * desired type of transaction control.
 * 
 * @see com.justice.entity.Insideuser
 * @author MyEclipse Persistence Tools
 */
@Repository("insideuserdao")

public class InsideuserDAO extends BasicSupportDao implements IInsideuserDAO{
	private static final long serialVersionUID = 1L;

	private static final Logger log = LoggerFactory
			.getLogger(InsideuserDAO.class);
	// property constants
	public static final String ROLE = "role";
	public static final String INSIDE_USER_STATUS = "insideUserStatus";
	public static final String LOGIN_NAME = "loginName";
	public static final String USER_PASSWORD = "userPassword";
	public static final String DEPARTMENT = "department";
	public static final Insideuser user = null;
	protected void initDao() {
		// do nothing
	}

	public void save(Insideuser transientInstance) {
		log.debug("saving Insideuser instance");
		try {
			getHibernateTemplate().save(transientInstance);
			log.debug("save successful");
		} catch (RuntimeException re) {
			log.error("save failed", re);
			throw re;
		}
	}
	@SuppressWarnings("unchecked")
	public void update(Insideuser transientInstance){
		log.debug("updating Insideuser instance");
		try{
			this.getHibernateTemplate().saveOrUpdate(transientInstance);
			log.debug("update successful");
		}catch(RuntimeException re){
			log.error("update failed",re);
			throw re;
		}
	}

	public void delete(Insideuser persistentInstance) {
		log.debug("deleting Insideuser instance");
		try {
			getHibernateTemplate().delete(persistentInstance);
			log.debug("delete successful");
		} catch (RuntimeException re) {
			log.error("delete failed", re);
			throw re;
		}
	}

	public Insideuser findById(java.lang.Integer id) {
		log.debug("getting Insideuser instance with id: " + id);
		try {
			Insideuser instance = (Insideuser) getHibernateTemplate().get(
					Insideuser.class, id);
			return instance;
		} catch (RuntimeException re) {
			log.error("get failed", re);
			throw re;
		}
	}
	public Insideuser findById(Insideuser insideuser) {
		log.debug("getting Insideuser instance with id: " + insideuser);
		try {
			Insideuser instance = (Insideuser) getHibernateTemplate().get(
					Insideuser.class, insideuser);
			return instance;
		} catch (RuntimeException re) {
			log.error("get failed", re);
			throw re;
		}
	}

	public List findByExample(Insideuser instance) {
		log.debug("finding Insideuser instance by example");
		try {
			List results = getHibernateTemplate().findByExample(instance);
			log.debug("find by example successful, result size: "
					+ results.size());
			return results;
		} catch (RuntimeException re) {
			log.error("find by example failed", re);
			throw re;
		}
	}

	public List findByProperty(String propertyName, Object value) {
		log.debug("finding Insideuser instance with property: " + propertyName
				+ ", value: " + value);
		try {
			String queryString = "from Insideuser as model where model."
					+ propertyName + "= ?";
			return getHibernateTemplate().find(queryString, value);
		} catch (RuntimeException re) {
			log.error("find by property name failed", re);
			throw re;
		}
	}
	public List findByRole(Object role) {
		return findByProperty(ROLE, role);
	}

	public List findByInsideUserStatus(Object insideUserStatus) {
		return findByProperty(INSIDE_USER_STATUS, insideUserStatus);
	}

	public Insideuser findByLoginName(String loginName) {
		Insideuser instance = (Insideuser) getHibernateTemplate().get(
				Insideuser.class, loginName);
		return instance;
	}
	public List findByUserPassword(Object userPassword) {
		return findByProperty(USER_PASSWORD, userPassword);
	}

	public List findByDepartment(Object department) {
		return findByProperty(DEPARTMENT, department);
	}


	@SuppressWarnings("unchecked")
	public List<Insideuser> findAll() {
		return this.getHibernateTemplate().find("from Insideuser");
	}

	public Insideuser merge(Insideuser detachedInstance) {
		log.debug("merging Insideuser instance");
		try {
			Insideuser result = (Insideuser) getHibernateTemplate().merge(
					detachedInstance);
			log.debug("merge successful");
			return result;
		} catch (RuntimeException re) {
			log.error("merge failed", re);
			throw re;
		}
	}

	public void attachDirty(Insideuser instance) {
		log.debug("attaching dirty Insideuser instance");
		try {
			getHibernateTemplate().saveOrUpdate(instance);
			log.debug("attach successful");
		} catch (RuntimeException re) {
			log.error("attach failed", re);
			throw re;
		}
	}

	public void attachClean(Insideuser instance) {
		log.debug("attaching clean Insideuser instance");
		try {
			getHibernateTemplate().lock(instance, LockMode.NONE);
			log.debug("attach successful");
		} catch (RuntimeException re) {
			log.error("attach failed", re);
			throw re;
		}
	}

	public Boolean login(Insideuser insideuser) {
		
		StringBuffer hql = new StringBuffer();
		hql.append("select a from Insideuser a where a.userPassword = ? and a.loginName = ? and a.insideUserStatus = 'on' ");
		
		if(this.getHibernateTemplate().find(hql.toString(),insideuser.getUserPassword(),insideuser.getLoginName()).isEmpty())
			return false;
		else
			return true;
	}

	public Boolean adduser(Insideuser insideuser) {
		
		StringBuffer hql = new StringBuffer();
		hql.append("select a from Insideuser a where a.loginName = ?");	
		if(this.getHibernateTemplate().find(hql.toString(),insideuser.getLoginName()).isEmpty())
			return true;
		else
			return false;
	}
}