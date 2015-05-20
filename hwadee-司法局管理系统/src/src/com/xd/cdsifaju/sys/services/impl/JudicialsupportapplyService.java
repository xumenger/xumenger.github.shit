package com.xd.cdsifaju.sys.services.impl;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.xd.cdsifaju.entities.Judicialsupportapply;
import com.xd.cdsifaju.sys.dao.interfaces.IJudicialsupportapplyDao;
import com.xd.cdsifaju.sys.services.interfaces.IJudicialsupportapplyService;
@Service("judicialsupportapplyservice")
public class JudicialsupportapplyService implements
		IJudicialsupportapplyService {
   @Resource(name="judicialsupportapplydao")
   private IJudicialsupportapplyDao jsdao;
	public String add(Judicialsupportapply js) {
		return jsdao.add(js);
	}

	public List<Judicialsupportapply> list() {
		// TODO Auto-generated method stub
		return jsdao.list();
	}

}
