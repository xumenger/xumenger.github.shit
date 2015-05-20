package com.xd.cdsifaju.entities;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * Notarization entity. @author MyEclipse Persistence Tools
 */

@SuppressWarnings("serial")
@Entity
@Table(name="notarization")
public class Notarization implements java.io.Serializable {

	// Fields

	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	@Column(name="NotaID")
	private Integer notaId;
	
	@Column(name="UserID")
	private Integer userId;
	
	@Column(name="UserNumber")
	private Integer userNumber;
	
	@Column(name="NotaStatus")
	private String notaStatus;
	
	@Column(name="AppDate")
	private Date appDate;
	
	@Column(name="PrincipalID")
	private Integer principalId;
	
	@Column(name="FeeCollectID")
	private Integer feeCollectId;
	
	@Column(name="ApprovalID")
	private Integer approvalId;
	
	@Column(name="FilerID")
	private Integer filerId;
	
	@Column(name="NotaClaims")
	private String notaClaims;
	
	@Column(name="NotaFact")
	private String notaFact;
	
	@Column(name="NotaAppAdd")
	private String notaAppAdd;

	// Constructors

	/** default constructor */
	public Notarization() {
	}

	/** full constructor */
	public Notarization(Integer userId, Integer userNumber, String notaStatus,
			Date appDate, Integer principalId, Integer feeCollectId,
			Integer approvalId, Integer filerId, String notaClaims,
			String notaFact, String notaAppAdd) {
		this.userId = userId;
		this.userNumber = userNumber;
		this.notaStatus = notaStatus;
		this.appDate = appDate;
		this.principalId = principalId;
		this.feeCollectId = feeCollectId;
		this.approvalId = approvalId;
		this.filerId = filerId;
		this.notaClaims = notaClaims;
		this.notaFact = notaFact;
		this.notaAppAdd = notaAppAdd;
	}

	// Property accessors

	public Integer getNotaId() {
		return this.notaId;
	}

	public void setNotaId(Integer notaId) {
		this.notaId = notaId;
	}

	public Integer getUserId() {
		return this.userId;
	}

	public void setUserId(Integer userId) {
		this.userId = userId;
	}

	public Integer getUserNumber() {
		return this.userNumber;
	}

	public void setUserNumber(Integer userNumber) {
		this.userNumber = userNumber;
	}

	public String getNotaStatus() {
		return this.notaStatus;
	}

	public void setNotaStatus(String notaStatus) {
		this.notaStatus = notaStatus;
	}

	public Date getAppDate() {
		return this.appDate;
	}

	public void setAppDate(Date appDate) {
		this.appDate = appDate;
	}

	public Integer getPrincipalId() {
		return this.principalId;
	}

	public void setPrincipalId(Integer principalId) {
		this.principalId = principalId;
	}

	public Integer getFeeCollectId() {
		return this.feeCollectId;
	}

	public void setFeeCollectId(Integer feeCollectId) {
		this.feeCollectId = feeCollectId;
	}

	public Integer getApprovalId() {
		return this.approvalId;
	}

	public void setApprovalId(Integer approvalId) {
		this.approvalId = approvalId;
	}

	public Integer getFilerId() {
		return this.filerId;
	}

	public void setFilerId(Integer filerId) {
		this.filerId = filerId;
	}

	public String getNotaClaims() {
		return this.notaClaims;
	}

	public void setNotaClaims(String notaClaims) {
		this.notaClaims = notaClaims;
	}

	public String getNotaFact() {
		return this.notaFact;
	}

	public void setNotaFact(String notaFact) {
		this.notaFact = notaFact;
	}

	public String getNotaAppAdd() {
		return this.notaAppAdd;
	}

	public void setNotaAppAdd(String notaAppAdd) {
		this.notaAppAdd = notaAppAdd;
	}

}