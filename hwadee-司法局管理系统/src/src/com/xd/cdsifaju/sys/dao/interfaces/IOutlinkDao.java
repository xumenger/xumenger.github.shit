package com.xd.cdsifaju.sys.dao.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Outlink;




public interface IOutlinkDao {

	String add(Outlink outlink);
	List<Outlink> getOutlinks();
	String edit(Outlink outlink);
	Outlink detail(Outlink outlink);
	String delete(Outlink outlink);
}
