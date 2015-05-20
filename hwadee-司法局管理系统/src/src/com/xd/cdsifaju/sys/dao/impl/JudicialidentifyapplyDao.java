package com.xd.cdsifaju.sys.dao.impl;

import java.util.List;

import org.springframework.stereotype.Repository;

import com.xd.cdsifaju.common.dao.BasicSupportDao;
import com.xd.cdsifaju.entities.Judicialidentifyapply;
import com.xd.cdsifaju.sys.dao.interfaces.IJudicialidentifyapplyDao;


@Repository("judicialidentifyapplydao")
public class JudicialidentifyapplyDao extends BasicSupportDao implements
		IJudicialidentifyapplyDao {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public String add(Judicialidentifyapply jd) {
		this.getHibernateTemplate().save(jd);
		return null;
	}

	@SuppressWarnings("unchecked")
	public List<Judicialidentifyapply> list() {
		String hql = "from Judicialidentifyapply a";
		return (List<Judicialidentifyapply>)this.getHibernateTemplate().find(hql);
	}

}
