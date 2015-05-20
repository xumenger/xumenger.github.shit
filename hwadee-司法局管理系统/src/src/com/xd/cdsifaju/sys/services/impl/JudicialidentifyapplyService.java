package com.xd.cdsifaju.sys.services.impl;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.xd.cdsifaju.entities.Judicialidentifyapply;

import com.xd.cdsifaju.sys.dao.interfaces.IJudicialidentifyapplyDao;

import com.xd.cdsifaju.sys.services.interfaces.IJudicialidentifyapplyService;

@Service("judicialidentifyapplyservice")
public class JudicialidentifyapplyService implements
		IJudicialidentifyapplyService {
	@Resource(name = "judicialidentifyapplydao")
	private IJudicialidentifyapplyDao jddao;

	public String add(Judicialidentifyapply jd) {
		return jddao.add(jd);
	}

	public List<Judicialidentifyapply> list() {
		// TODO Auto-generated method stub
		return jddao.list();
	}

}
