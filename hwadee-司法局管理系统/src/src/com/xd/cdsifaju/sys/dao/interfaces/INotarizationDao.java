package com.xd.cdsifaju.sys.dao.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Notarization;

public interface INotarizationDao {
	public String add(Notarization nota);
	public void delete(Notarization persistentInstance);
	public void edit(Notarization persistentInstance);
	public Notarization findById(java.lang.Integer id);
	public List findByExample(Notarization instance);
	public List findByProperty(String propertyName, Object value);
	public List findAll();
	public List findByPrincipalId(Object principalId);
	public List findByFeeCollectId(Object feeCollectId);
	public List findByApprovalId(Object approvalId);
	public List findByFilerId(Object filerId);

}
