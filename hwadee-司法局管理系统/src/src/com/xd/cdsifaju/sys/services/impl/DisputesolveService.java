package com.xd.cdsifaju.sys.services.impl;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.xd.cdsifaju.entities.Disputesolve;
import com.xd.cdsifaju.sys.dao.interfaces.IDisputesolveDao;
import com.xd.cdsifaju.sys.services.interfaces.IDisputesolveService;
@Service("disputesolveservice")
public class DisputesolveService implements IDisputesolveService {
	@Resource(name = "disputesolvedao")
	private IDisputesolveDao dsdao;
	public List<Disputesolve> list() {
		// TODO Auto-generated method stub
		return dsdao.list();
	}
	public String add(Disputesolve ds) {
		// TODO Auto-generated method stub
		return dsdao.add(ds);
	}

}
