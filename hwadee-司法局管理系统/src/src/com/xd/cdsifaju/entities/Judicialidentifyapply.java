package com.xd.cdsifaju.entities;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * Judicialidentifyapply entity. @author MyEclipse Persistence Tools
 */

@SuppressWarnings("serial")
@Entity
@Table(name="judicialidentifyapply")
public class Judicialidentifyapply implements java.io.Serializable {

	// Fields

	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	@Column(name="JudicialIdentifyApplyNumber")
	private  Integer judicialIdentifyApplyNumber;
	
	@Column(name="UserNumber")
	private Integer userNumber;
	
	@Column(name="JIStatus")
	private String jistatus;
	
	@Column(name="JIAppID")
	private Integer jiappId;
	
	@Column(name="JIAppSex")
	private String jiappSex;
	
	@Column(name="JIAppBirthday")
	private Date jiappBirthday;
	
	@Column(name="JIAppAdd")
	private String jiappAdd;
	
	@Column(name="JIClaims1")
	private String jiclaims1;

	// Constructors

	/** default constructor */
	public Judicialidentifyapply() {
	}

	/*full constructor 
	public Judicialidentifyapply(Integer userNumber, String jistatus,
			Integer jiappId, String jiappSex, Date jiappBirthday,
			String jiappAdd, String jiclaims1) {
		this.userNumber = userNumber;
		this.jistatus = jistatus;
		this.jiappId = jiappId;
		this.jiappSex = jiappSex;
		this.jiappBirthday = jiappBirthday;
		this.jiappAdd = jiappAdd;
		this.jiclaims1 = jiclaims1;
	}
	*/

	// Property accessors

	public Integer getJudicialIdentifyApplyNumber() {
		return this.judicialIdentifyApplyNumber;
	}

	public void setJudicialIdentifyApplyNumber(
			Integer judicialIdentifyApplyNumber) {
		this.judicialIdentifyApplyNumber = judicialIdentifyApplyNumber;
	}

	public Integer getUserNumber() {
		return this.userNumber;
	}

	public void setUserNumber(Integer userNumber) {
		this.userNumber = userNumber;
	}

	public String getJistatus() {
		return this.jistatus;
	}

	public void setJistatus(String jistatus) {
		this.jistatus = jistatus;
	}

	public Integer getJiappId() {
		return this.jiappId;
	}

	public void setJiappId(Integer jiappId) {
		this.jiappId = jiappId;
	}

	public String getJiappSex() {
		return this.jiappSex;
	}

	public void setJiappSex(String jiappSex) {
		this.jiappSex = jiappSex;
	}

	public Date getJiappBirthday() {
		return this.jiappBirthday;
	}

	public void setJiappBirthday(Date jiappBirthday) {
		this.jiappBirthday = jiappBirthday;
	}

	public String getJiappAdd() {
		return this.jiappAdd;
	}

	public void setJiappAdd(String jiappAdd) {
		this.jiappAdd = jiappAdd;
	}

	public String getJiclaims1() {
		return this.jiclaims1;
	}

	public void setJiclaims1(String jiclaims1) {
		this.jiclaims1 = jiclaims1;
	}

}