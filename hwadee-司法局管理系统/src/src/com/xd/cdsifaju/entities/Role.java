package com.xd.cdsifaju.entities;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * Role entity. @author MyEclipse Persistence Tools
 */

@SuppressWarnings("serial")
@Entity
@Table(name="role")
public class Role implements java.io.Serializable {

	// Fields

	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	@Column(name="RoleId")
	private int roleId;
	
	@Column(name="RoleName")
	private String roleName;
	
	@Column(name="EditRight")
	private Integer editRight;
	
	@Column(name="ApplyRight")
	private Integer applyRight;
	
	@Column(name="NotarizationRight")
	private Integer notarizationRight;
	
	@Column(name="UserRight")
	private Integer userRight;
	
	@Column(name="RoleRight")
	private Integer roleRight;

	// Property accessors

	public int getRoleId() {
		return roleId;
	}

	public void setRoleId(int roleId) {
		this.roleId = roleId;
	}

	public String getRoleName() {
		return roleName;
	}

	public void setRoleName(String roleName) {
		this.roleName = roleName;
	}

	public Integer getEditRight() {
		return this.editRight;
	}
	
	public void setEditRight(Integer editRight) {
		this.editRight = editRight;
	}

	public Integer getApplyRight() {
		return this.applyRight;
	}

	public void setApplyRight(Integer applyRight) {
		this.applyRight = applyRight;
	}

	public Integer getNotarizationRight() {
		return this.notarizationRight;
	}

	public void setNotarizationRight(Integer notarizationRight) {
		this.notarizationRight = notarizationRight;
	}

	public Integer getUserRight() {
		return this.userRight;
	}

	public void setUserRight(Integer userRight) {
		this.userRight = userRight;
	}

	public Integer getRoleRight() {
		return this.roleRight;
	}

	public void setRoleRight(Integer roleRight) {
		this.roleRight = roleRight;
	}

}