package com.xd.cdsifaju.sys.dao.impl;

import java.util.List;

import org.springframework.stereotype.Repository;

import com.xd.cdsifaju.common.dao.BasicSupportDao;
import com.xd.cdsifaju.entities.Judicialsupportapply;
import com.xd.cdsifaju.sys.dao.interfaces.IJudicialsupportapplyDao;

@Repository("judicialsupportapplydao")
public class JudicialsupportapplyDao extends BasicSupportDao implements IJudicialsupportapplyDao {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public String add(Judicialsupportapply js) {
		this.getHibernateTemplate().save(js);
		return null;
	}

	@SuppressWarnings("unchecked")
	public List<Judicialsupportapply> list() {
		String hql="select a from Judicialsupportapply a ";
		return (List<Judicialsupportapply>)this.getHibernateTemplate().find(hql);
	}

}
