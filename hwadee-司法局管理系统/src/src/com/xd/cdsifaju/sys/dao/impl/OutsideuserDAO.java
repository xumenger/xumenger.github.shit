package com.xd.cdsifaju.sys.dao.impl;

import java.util.Date;
import java.util.List;
import org.hibernate.LockMode;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.context.ApplicationContext;
import org.springframework.stereotype.Repository;

import com.xd.cdsifaju.common.dao.BasicSupportDao;
import com.xd.cdsifaju.entities.Insideuser;
import com.xd.cdsifaju.entities.Outsideuser;
import com.xd.cdsifaju.sys.dao.interfaces.IOutsideuserDAO;

/**
 * A data access object (DAO) providing persistence and search support for
 * Outsideuser entities. Transaction control of the save(), update() and
 * delete() operations can directly support Spring container-managed
 * transactions or they can be augmented to handle user-managed Spring
 * transactions. Each of these methods provides additional information for how
 * to configure it for the desired type of transaction control.
 * 
 * @see com.justice.entity.Outsideuser
 * @author MyEclipse Persistence Tools
 */
@Repository("outsideuserdao")
public class OutsideuserDAO extends BasicSupportDao implements IOutsideuserDAO{
	private static final long serialVersionUID = 1L;
	
	private static final Logger log = LoggerFactory
			.getLogger(OutsideuserDAO.class);
	// property constants
	public static final String ROLE = "role";
	public static final String OUTSIDE_USER_NAME = "outsideUserName";
	public static final String OUTSIDE_USER_STATUS = "outsideUserStatus";
	public static final String USER_SEX = "userSex";
	public static final String CURRENT_ADDR = "currentAddr";
	public static final String MOBILE = "mobile";
	public static final String QQ = "qq";
	public static final String MSN = "msn";
	public static final String PHONE = "phone";
	public static final String ZIP_CODE = "zipCode";
	public static final String ADDRESS = "address";
	public static final String PASSWORD = "password";
	public static final Outsideuser user = null;
	protected void initDao() {
		// do nothing
	}

	public void save(Outsideuser transientInstance) {
		log.debug("saving Outsideuser instance");
		try {
			getHibernateTemplate().save(transientInstance);
			log.debug("save successful");
		} catch (RuntimeException re) {
			log.error("save failed", re);
			throw re;
		}
	}
	@SuppressWarnings("unchecked")
	public void delete(Outsideuser persistentInstance) {
		log.debug("deleting Outsideuser instance");
		try {
			getHibernateTemplate().delete(persistentInstance);
			log.debug("delete successful");
		} catch (RuntimeException re) {
			log.error("delete failed", re);
			throw re;
		}
	}

	public Outsideuser findById(java.lang.Integer id) {
		log.debug("getting Outsideuser instance with id: " + id);
		try {
			Outsideuser instance = (Outsideuser) getHibernateTemplate().get(
					Outsideuser.class, id);
			return instance;
		} catch (RuntimeException re) {
			log.error("get failed", re);
			throw re;
		}
	}
	public Outsideuser findByOutsideUserName(String OutsideUserName) {
		log.debug("finding Outsideuser instance by OutsideUserName");
		try {
			Outsideuser instance = (Outsideuser) getHibernateTemplate().get(
					Outsideuser.class, OutsideUserName);
			return instance;
		} catch (RuntimeException re) {
			log.error("get failed", re);
			throw re;
		}
	}
	public List findByExample(Outsideuser instance) {
		log.debug("finding Outsideuser instance by example");
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
		log.debug("finding Outsideuser instance with property: " + propertyName
				+ ", value: " + value);
		try {
			String queryString = "from Outsideuser as model where model."
					+ propertyName + "= ?";
			return getHibernateTemplate().find(queryString, value);
		} catch (RuntimeException re) {
			log.error("find by property name failed", re);
			throw re;
		}
	}
	public List findByProperty(String propertyName, Object value,List user) {
		log.debug("finding Outsideuser instance with property: " + propertyName
				+ ", value: " + value);
		try {
		String queryString = "from "+ user +"  where"
				+ propertyName + "=?";
		return getHibernateTemplate().find("queryString, value");
		} catch (RuntimeException re) {
			log.error("find by property name failed", re);
			throw re;
		}
	}
	
	public List findByRole(Object role) {
		return findByProperty(ROLE, role);
	}
	public List findByRole(Object role,List user) {
		return findByProperty(ROLE, role,user);
	}
	public List findByOutsideUserName(Object outsideUserName) {
		return findByProperty(OUTSIDE_USER_NAME, outsideUserName);
	}

	public List findByOutsideUserName(Object outsideUserName,List user) {
		return findByProperty(OUTSIDE_USER_NAME, outsideUserName,user);
	}
	
	public List findByOutsideUserStatus(Object outsideUserStatus) {
		return findByProperty(OUTSIDE_USER_STATUS, outsideUserStatus);
	}
	public List findByOutsideUserStatus(Object outsideUserStatus,List user) {
		return findByProperty(OUTSIDE_USER_STATUS, outsideUserStatus,user);
	}
	public List findByUserSex(Object userSex) {
		return findByProperty(USER_SEX, userSex);
	}
	public List findByUserSex(Object userSex,List user) {
		return findByProperty(USER_SEX, userSex,user);
	}

	public List findByCurrentAddr(Object currentAddr) {
		return findByProperty(CURRENT_ADDR, currentAddr);
	}
	public List findByCurrentAddr(Object currentAddr,List user) {
		return findByProperty(CURRENT_ADDR, currentAddr,user);
	}
	public List findByMobile(Object mobile) {
		return findByProperty(MOBILE, mobile);
	}
	public List findByMobile(Object mobile,List user) {
		return findByProperty(MOBILE, mobile,user);
	}
	public List findByQq(Object qq) {
		return findByProperty(QQ, qq);
	}
	public List findByQq(Object qq,List user) {
		return findByProperty(QQ, qq,user);
	}
	public List findByMsn(Object msn) {
		return findByProperty(MSN, msn);
	}
	public List findByMsn(Object msn,List user) {
		return findByProperty(MSN, msn,user);
	}

	public List findByPhone(Object phone) {
		return findByProperty(PHONE, phone);
	}
	public List findByPhone(Object phone,List user) {
		return findByProperty(PHONE, phone, user);
	}
	public List findByZipCode(Object zipCode) {
		return findByProperty(ZIP_CODE, zipCode);
	}
	public List findByZipCode(Object zipCode,List user) {
		return findByProperty(ZIP_CODE, zipCode,user);
	}
	public List findByAddress(Object address) {
		return findByProperty(ADDRESS, address);
	}
	public List findByAddress(Object address,List user) {
		return findByProperty(ADDRESS, address, user);
	}
	public List findByPassword(Object password) {
		return findByProperty(PASSWORD, password);
	}
	public List findByPassword(Object password,List user) {
		return findByProperty(PASSWORD, password, user);
	}


	@SuppressWarnings("unchecked")
	public List <Outsideuser>findAll() {
		return this.getHibernateTemplate().find("from Outsideuser");
	}

	public Outsideuser merge(Outsideuser detachedInstance) {
		log.debug("merging Outsideuser instance");
		try {
			Outsideuser result = (Outsideuser) getHibernateTemplate().merge(
					detachedInstance);
			log.debug("merge successful");
			return result;
		} catch (RuntimeException re) {
			log.error("merge failed", re);
			throw re;
		}
	}

	public void attachDirty(Outsideuser instance) {
		log.debug("attaching dirty Outsideuser instance");
		try {
			getHibernateTemplate().saveOrUpdate(instance);
			log.debug("attach successful");
		} catch (RuntimeException re) {
			log.error("attach failed", re);
			throw re;
		}
	}

	public void attachClean(Outsideuser instance) {
		log.debug("attaching clean Outsideuser instance");
		try {
			getHibernateTemplate().lock(instance, LockMode.NONE);
			log.debug("attach successful");
		} catch (RuntimeException re) {
			log.error("attach failed", re);
			throw re;
		}
	}

	public Boolean login(Outsideuser outsideuser) {
		
		StringBuffer hql = new StringBuffer();
		hql.append("select a from Outsideuser a where a.password = ? and a.outsideUserName = ? and a.outsideUserStatus = 'on'");
		
		if(this.getHibernateTemplate().find(hql.toString(),outsideuser.getPassword(),outsideuser.getOutsideUserName()).isEmpty())
			return false;
		else
			return true;
	}

	public void update(Outsideuser transientInstance) {
		log.debug("updating Insideuser instance");
		try{
			this.getHibernateTemplate().saveOrUpdate(transientInstance);
			log.debug("update successful");
		}catch(RuntimeException re){
			log.error("update failed",re);
			throw re;
		}
		
	}

	public Boolean adduser(Outsideuser outsideuser) {
		StringBuffer hql = new StringBuffer();
		hql.append("select a from Outsideuser a where  a.outsideUserName = ? ");
		
		if(this.getHibernateTemplate().find(hql.toString(),outsideuser.getOutsideUserName()).isEmpty())
			return true;
		else
			return false;
	}
}