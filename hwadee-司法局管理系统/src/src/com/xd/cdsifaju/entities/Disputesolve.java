package com.xd.cdsifaju.entities;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * Disputesolve entity. @author MyEclipse Persistence Tools
 */

@SuppressWarnings("serial")
@Entity
@Table(name="disputesolve")
public class Disputesolve implements java.io.Serializable {

	// Fields

	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	@Column(name="DSId")
	private Integer dsid;
	
	@Column(name="UserNumber")
	private Integer userNumber;
	
	@Column(name="DSState")
	private String dsstate;
	
	@Column(name="DSAppSex")
	private String dsappSex;
	
	@Column(name="DSAppAdd")
	private Date dsappAdd;
	
	@Column(name="DSAppBirth")
	private String dsappBirth;
	
	@Column(name="DSClamis")
	private String dsclaims;
	
	@Column(name="DSFact")
	private String dsfact;

	// Constructors

	/** default constructor */
	public Disputesolve() {
	}

	/** full constructor */
	public Disputesolve(Integer userNumber, String dsstate, String dsappSex,
			Date dsappAdd, String dsappBirth, String dsclaims, String dsfact) {
		this.userNumber = userNumber;
		this.dsstate = dsstate;
		this.dsappSex = dsappSex;
		this.dsappAdd = dsappAdd;
		this.dsappBirth = dsappBirth;
		this.dsclaims = dsclaims;
		this.dsfact = dsfact;
	}

	// Property accessors

	public Integer getDsid() {
		return this.dsid;
	}

	public void setDsid(Integer dsid) {
		this.dsid = dsid;
	}

	public Integer getUserNumber() {
		return this.userNumber;
	}

	public void setUserNumber(Integer userNumber) {
		this.userNumber = userNumber;
	}

	public String getDsstate() {
		return this.dsstate;
	}

	public void setDsstate(String dsstate) {
		this.dsstate = dsstate;
	}

	public String getDsappSex() {
		return this.dsappSex;
	}

	public void setDsappSex(String dsappSex) {
		this.dsappSex = dsappSex;
	}

	public Date getDsappAdd() {
		return this.dsappAdd;
	}

	public void setDsappAdd(Date dsappAdd) {
		this.dsappAdd = dsappAdd;
	}

	public String getDsappBirth() {
		return this.dsappBirth;
	}

	public void setDsappBirth(String dsappBirth) {
		this.dsappBirth = dsappBirth;
	}

	public String getDsclaims() {
		return this.dsclaims;
	}

	public void setDsclaims(String dsclaims) {
		this.dsclaims = dsclaims;
	}

	public String getDsfact() {
		return this.dsfact;
	}

	public void setDsfact(String dsfact) {
		this.dsfact = dsfact;
	}

}