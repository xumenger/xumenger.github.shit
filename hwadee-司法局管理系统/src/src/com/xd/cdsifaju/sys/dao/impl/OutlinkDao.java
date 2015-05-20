package com.xd.cdsifaju.sys.dao.impl;

import java.util.List;

import org.springframework.stereotype.Repository;

import com.xd.cdsifaju.common.dao.BasicSupportDao;
import com.xd.cdsifaju.entities.Article;
import com.xd.cdsifaju.entities.Outlink;
import com.xd.cdsifaju.sys.dao.interfaces.IOutlinkDao;



@Repository("outlinkDao")
class OutlinkDao extends BasicSupportDao implements IOutlinkDao{

	private static final long serialVersionUID = 1L;

	public String add(Outlink outlink) {
		
		this.getHibernateTemplate().save(outlink);
		return "add";
	}
		
	@SuppressWarnings("unchecked")
	public List<Outlink> getOutlinks() {
		return this.getHibernateTemplate().find("from Outlink order by linkId");
	}


	public String edit(Outlink outlink) {
		
		this.getHibernateTemplate().saveOrUpdate(outlink);
		return "update";
	}

	public Outlink detail(Outlink outlink) {
		
		return this.getHibernateTemplate().get(Outlink.class, outlink.getLinkId());
	}
	
	public String delete(Outlink outlink) {

		this.getHibernateTemplate().delete(outlink);
		return "delete";
		
	}

}
