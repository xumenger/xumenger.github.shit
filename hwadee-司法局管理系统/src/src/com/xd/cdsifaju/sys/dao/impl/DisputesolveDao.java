package com.xd.cdsifaju.sys.dao.impl;

import java.util.List;

import org.springframework.stereotype.Repository;

import com.xd.cdsifaju.common.dao.BasicSupportDao;
import com.xd.cdsifaju.entities.Disputesolve;
import com.xd.cdsifaju.sys.dao.interfaces.IDisputesolveDao;
@Repository("disputesolvedao")
public class DisputesolveDao  extends BasicSupportDao implements IDisputesolveDao {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@SuppressWarnings("unchecked")
	public List<Disputesolve> list() {
		// TODO Auto-generated method stub
		String hql = "from Disputesolve a";
		return (List<Disputesolve>)this.getHibernateTemplate().find(hql);
	}

	public String add(Disputesolve ds) {
		this.getHibernateTemplate().save(ds);
		return null;
	}

}
