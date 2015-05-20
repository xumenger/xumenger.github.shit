package com.xd.cdsifaju.sys.dao.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Judicialidentifyapply;

public interface IJudicialidentifyapplyDao {
	String add(Judicialidentifyapply jd);

	List<Judicialidentifyapply> list();
}
