package com.xd.cdsifaju.entities;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * Insideuser entity. @author MyEclipse Persistence Tools
 */

@SuppressWarnings("serial")
@Entity
@Table(name="insideuser")
public class Insideuser implements java.io.Serializable {

	// Fields
	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	@Column(name="UserID")
	private int userId;
	
	@Column(name="Role")
	private String role;
	
	@Column(name="InsideUserStatus")
	private String insideUserStatus;
	
	@Column(name="LoginName")
	private String loginName;
	
	@Column(name="UserPassword")
	private String userPassword;
	
	@Column(name="Department")
	private String department;

	// Property accessors

	public int getUserId() {
		return this.userId;
	}

	public void setUserId(int userId) {
		this.userId = userId;
	}

	public String getRole() {
		return this.role;
	}

	public void setRole(String role) {
		this.role = role;
	}

	public String getInsideUserStatus() {
		return this.insideUserStatus;
	}

	public void setInsideUserStatus(String insideUserStatus) {
		this.insideUserStatus = insideUserStatus;
	}

	public String getLoginName() {
		return this.loginName;
	}

	public void setLoginName(String loginName) {
		this.loginName = loginName;
	}

	public String getUserPassword() {
		return this.userPassword;
	}

	public void setUserPassword(String userPassword) {
		this.userPassword = userPassword;
	}

	public String getDepartment() {
		return this.department;
	}

	public void setDepartment(String department) {
		this.department = department;
	}

}