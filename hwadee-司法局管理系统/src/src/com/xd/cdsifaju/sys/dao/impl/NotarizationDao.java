package com.xd.cdsifaju.sys.dao.impl;


import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Repository;

import com.xd.cdsifaju.common.dao.BasicSupportDao;
import com.xd.cdsifaju.entities.Notarization;
import com.xd.cdsifaju.sys.dao.interfaces.INotarizationDao;

@Repository("notarizationdao")
public class NotarizationDao extends BasicSupportDao implements
		INotarizationDao {

	private static final long serialVersionUID = 1L;
	private static final Logger log = LoggerFactory
			.getLogger(NotarizationDao.class);
	public static final String PRINCIPAL_ID = "principalId";
	public static final String FEE_COLLECT_ID = "feeCollectId";
	public static final String APPROVAL_ID = "approvalId";
	public static final String FILER_ID = "filerId";

	public String add(Notarization nota) {

		this.getHibernateTemplate().save(nota);
		return null;
	}
	protected void initDao() {
		// do nothing
	}

	public void delete(Notarization persistentInstance) {
		log.debug("deleting Notarization instance");
		try {
			getHibernateTemplate().delete(persistentInstance);
			log.debug("delete successful");
		} catch (RuntimeException re) {
			log.error("delete failed", re);
			throw re;
		}
	}
	
	public void edit(Notarization persistentInstance){
		log.debug("updating Notarization instance");
		try {
			getHibernateTemplate().update(persistentInstance);
			log.debug("update successful");
		} catch (RuntimeException re) {
			log.error("update failed", re);
			throw re;
		}
	}

	public Notarization findById(java.lang.Integer id) {
		log.debug("getting Notarization instance with id: " + id);
		try {
			Notarization instance = (Notarization) getHibernateTemplate().get(
					"com.justice.entity.Notarization", id);
			return instance;
		} catch (RuntimeException re) {
			log.error("get failed", re);
			throw re;
		}
	}

	public List findByExample(Notarization instance) {
		log.debug("finding Notarization instance by example");
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
		log.debug("finding Notarization instance with property: "
				+ propertyName + ", value: " + value);
		try {
			String queryString = "from Notarization as model where model."
					+ propertyName + "= ?";
			return getHibernateTemplate().find(queryString, value);
		} catch (RuntimeException re) {
			log.error("find by property name failed", re);
			throw re;
		}
	}

	public List findAll() {
		log.debug("finding all Notarization instances");
		try {
			String queryString = "from Notarization";
			return getHibernateTemplate().find(queryString);
		} catch (RuntimeException re) {
			log.error("find all failed", re);
			throw re;
		}
	}
	
	public List findByPrincipalId(Object principalId) {
		return findByProperty(PRINCIPAL_ID , principalId);
	}

	public List findByFeeCollectId(Object feeCollectId) {
		return findByProperty(FEE_COLLECT_ID, feeCollectId);
	}

	public List findByApprovalId(Object approvalId) {
		return findByProperty(APPROVAL_ID, approvalId);
	}

	public List findByFilerId(Object filerId) {
		return findByProperty(FILER_ID, filerId);
	}
	
}
