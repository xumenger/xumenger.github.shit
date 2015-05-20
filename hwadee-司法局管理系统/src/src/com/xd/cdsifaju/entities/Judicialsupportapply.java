package com.xd.cdsifaju.entities;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * Judicialsupportapply entity. @author MyEclipse Persistence Tools
 */

@SuppressWarnings("serial")
@Entity
@Table(name="judicialsupportapply")
public class Judicialsupportapply implements java.io.Serializable {

	// Fields

	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	@Column(name="JSID")
	private Integer jsid;
	
	@Column(name="UserNumber")
	private Integer userNumber;
	
	@Column(name="JSStatus")
	private String jsstatus;
	
	@Column(name="JSAppID")
	private Integer jsappId;
	
	@Column(name="JSAppSex")
	private String jsappSex;
	
	@Column(name="JSAppBirth")
	private Date jsappBirth;
	
	@Column(name="JSAppAdd")
	private String jsappAdd;
	
	@Column(name="JSClaims")
	private String jsclaims;
	
	@Column(name="JSFact")
	private String jsfact;

	// Constructors

	/** default constructor */
	public Judicialsupportapply() {
	}

	/** full constructor */
	public Judicialsupportapply(Integer userNumber, String jsstatus,
			Integer jsappId, String jsappSex, Date jsappBirth, String jsappAdd,
			String jsclaims, String jsfact) {
		this.userNumber = userNumber;
		this.jsstatus = jsstatus;
		this.jsappId = jsappId;
		this.jsappSex = jsappSex;
		this.jsappBirth = jsappBirth;
		this.jsappAdd = jsappAdd;
		this.jsclaims = jsclaims;
		this.jsfact = jsfact;
	}

	// Property accessors

	public Integer getJsid() {
		return this.jsid;
	}

	public void setJsid(Integer jsid) {
		this.jsid = jsid;
	}

	public Integer getUserNumber() {
		return this.userNumber;
	}

	public void setUserNumber(Integer userNumber) {
		this.userNumber = userNumber;
	}

	public String getJsstatus() {
		return this.jsstatus;
	}

	public void setJsstatus(String jsstatus) {
		this.jsstatus = jsstatus;
	}

	public Integer getJsappId() {
		return this.jsappId;
	}

	public void setJsappId(Integer jsappId) {
		this.jsappId = jsappId;
	}

	public String getJsappSex() {
		return this.jsappSex;
	}

	public void setJsappSex(String jsappSex) {
		this.jsappSex = jsappSex;
	}

	public Date getJsappBirth() {
		return this.jsappBirth;
	}

	public void setJsappBirth(Date jsappBirth) {
		this.jsappBirth = jsappBirth;
	}

	public String getJsappAdd() {
		return this.jsappAdd;
	}

	public void setJsappAdd(String jsappAdd) {
		this.jsappAdd = jsappAdd;
	}

	public String getJsclaims() {
		return this.jsclaims;
	}

	public void setJsclaims(String jsclaims) {
		this.jsclaims = jsclaims;
	}

	public String getJsfact() {
		return this.jsfact;
	}

	public void setJsfact(String jsfact) {
		this.jsfact = jsfact;
	}

}