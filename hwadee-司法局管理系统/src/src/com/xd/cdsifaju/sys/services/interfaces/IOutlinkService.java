package com.xd.cdsifaju.sys.services.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Outlink;



public interface IOutlinkService {

	String add(Outlink outlink);
	List<Outlink> list();
	String edit(Outlink outlink);
	String delete(Outlink outlink);
	Outlink detail(Outlink outlink);
}
