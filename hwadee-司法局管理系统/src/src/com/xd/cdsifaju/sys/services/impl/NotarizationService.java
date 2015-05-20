package com.xd.cdsifaju.sys.services.impl;


import java.util.List;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.xd.cdsifaju.entities.Notarization;
import com.xd.cdsifaju.sys.dao.interfaces.INotarizationDao;
import com.xd.cdsifaju.sys.services.interfaces.INotarizationService;
@Service("notarizationservice")
public class NotarizationService implements INotarizationService {
	@Resource(name="notarizationdao")
	private INotarizationDao notadao;
	public String add(Notarization nota) {
		return notadao.add(nota);
	}
	public List<Notarization> findAll() {
		// TODO Auto-generated method stub
		List<Notarization> list = notadao.findAll();
		if(list.size()==0)
		   return null;
		else
			return list;
	}
	public void delete(Notarization nota) {
		// TODO Auto-generated method stub
		notadao.delete(nota);
	}
	public void edit(Notarization nota) {
		// TODO Auto-generated method stub
		notadao.edit(nota);
	}
	public Notarization findById(int id) {
		// TODO Auto-generated method stub
		return notadao.findById(id);
	}
	public List<Notarization> findByPrincipalId(Object principalId) {
		// TODO Auto-generated method stub
		return notadao.findByPrincipalId(principalId);
	}
	public List<Notarization> findByFeeCollectId(Object feeCollectId) {
		// TODO Auto-generated method stub
		return notadao.findByFeeCollectId(feeCollectId);

	}
	public List<Notarization> findByApprovalId(Object approvalId) {
		// TODO Auto-generated method stub
		return notadao.findByApprovalId(approvalId);
	}
	public List<Notarization> findByFilerId(Object filerId) {
		// TODO Auto-generated method stub
		return notadao.findByFilerId(filerId);
	}

}
