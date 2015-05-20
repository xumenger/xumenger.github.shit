package com.xd.cdsifaju.sys.services.impl;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.xd.cdsifaju.entities.Outlink;
import com.xd.cdsifaju.sys.dao.interfaces.IOutlinkDao;
import com.xd.cdsifaju.sys.services.interfaces.IOutlinkService;



@Service("outlinkService")
public class OutlinkService implements IOutlinkService{

	/**
	 * @param args
	 */
	@Resource(name="outlinkDao")
	private IOutlinkDao outlinkDao;
	
	public String add(Outlink outlink) {
		// TODO Auto-generated method stub
		//return null;
		return outlinkDao.add(outlink);
	}

	public List<Outlink> list() {
		// TODO Auto-generated method stub
		return outlinkDao.getOutlinks();
	}

	public String edit(Outlink outlink) {
		// TODO Auto-generated method stub
		//return null;
		return outlinkDao.edit(outlink);
	}

	public String delete(Outlink outlink) {
		// TODO Auto-generated method stub
		return outlinkDao.delete(outlink);
	}

	public Outlink detail(Outlink outlink) {
		// TODO Auto-generated method stub
		return outlinkDao.detail(outlink);
	}

}
