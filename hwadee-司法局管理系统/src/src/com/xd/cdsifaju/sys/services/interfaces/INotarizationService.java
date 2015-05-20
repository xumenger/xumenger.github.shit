package com.xd.cdsifaju.sys.services.interfaces;


import java.util.List;

import com.xd.cdsifaju.entities.Notarization;

public interface INotarizationService {
	public String add (Notarization nota);
	public List<Notarization> findAll();
	public void delete(Notarization nota);
	public void edit(Notarization nota);
	public Notarization findById(int id);
	public List<Notarization> findByPrincipalId(Object principalId);
	public List<Notarization> findByFeeCollectId(Object feeCollectId);
	public List<Notarization> findByApprovalId(Object approvalId);
	public List<Notarization> findByFilerId(Object filerId);
}
