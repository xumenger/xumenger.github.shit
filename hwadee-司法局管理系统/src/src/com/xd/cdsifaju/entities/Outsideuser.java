package com.xd.cdsifaju.entities;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * Outsideuser entity. @author MyEclipse Persistence Tools
 */

@SuppressWarnings("serial")
@Entity
@Table(name="outsideuser")
public class Outsideuser implements java.io.Serializable {

	// Fields

	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	@Column(name="UserNumber")
	private int userNumber;
	
	@Column(name="Role")
	private String role;
	
	@Column(name="OutsideUserName")
	private String outsideUserName;
	
	@Column(name="OutsideUserStatus")
	private String outsideUserStatus;
	
	@Column(name="UserSex")
	private String userSex;
	
	@Column(name="BirthDate")
	private Date birthDate;
	
	@Column(name="CurrentADDR")
	private String currentAddr;
	
	@Column(name="Mobile")
	private Integer mobile;
	
	@Column(name="QQ")
	private String qq;
	
	@Column(name="MSN")
	private String msn;
	
	@Column(name="Phone")
	private String phone;
	
	@Column(name="ZipCode")
	private Integer zipCode;
	
	@Column(name="Address")
	private String address;
	
	@Column(name="password")
	private String password;

	public int getUserNumber() {
		return userNumber;
	}

	public void setUserNumber(int userNumber) {
		this.userNumber = userNumber;
	}

	public String getRole() {
		return role;
	}

	public void setRole(String role) {
		this.role = role;
	}

	public String getOutsideUserName() {
		return outsideUserName;
	}

	public void setOutsideUserName(String outsideUserName) {
		this.outsideUserName = outsideUserName;
	}

	public String getOutsideUserStatus() {
		return outsideUserStatus;
	}

	public void setOutsideUserStatus(String outsideUserStatus) {
		this.outsideUserStatus = outsideUserStatus;
	}

	public String getUserSex() {
		return userSex;
	}

	public void setUserSex(String userSex) {
		this.userSex = userSex;
	}

	public Date getBirthDate() {
		return birthDate;
	}

	public void setBirthDate(Date birthDate) {
		this.birthDate = birthDate;
	}

	public String getCurrentAddr() {
		return currentAddr;
	}

	public void setCurrentAddr(String currentAddr) {
		this.currentAddr = currentAddr;
	}

	public Integer getMobile() {
		return mobile;
	}

	public void setMobile(Integer mobile) {
		this.mobile = mobile;
	}

	public String getQq() {
		return qq;
	}

	public void setQq(String qq) {
		this.qq = qq;
	}

	public String getMsn() {
		return msn;
	}

	public void setMsn(String msn) {
		this.msn = msn;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public Integer getZipCode() {
		return zipCode;
	}

	public void setZipCode(Integer zipCode) {
		this.zipCode = zipCode;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}


	// Property accessors


}