package com.xd.cdsifaju.entities;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * Outlink entity. @author MyEclipse Persistence Tools
 */

@SuppressWarnings("serial")
@Entity
@Table(name="outlink")
public class Outlink implements java.io.Serializable {

	// Fields
	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	@Column(name="LinkID")
	private int linkId;
	
	@Column(name="UserID")
	private Integer userId;
	
	@Column(name="LinkName")
	private String linkName;
	
	@Column(name="Linkadd")
	private String linkadd;

	// Constructors



	// Property accessors

	public int getLinkId() {
		return this.linkId;
	}

	public void setLinkId(int linkId) {
		this.linkId = linkId;
	}

	public Integer getUserId() {
		return this.userId;
	}

	public void setUserId(Integer userId) {
		this.userId = userId;
	}

	public String getLinkName() {
		return this.linkName;
	}

	public void setLinkName(String linkName) {
		this.linkName = linkName;
	}

	public String getLinkadd() {
		return this.linkadd;
	}

	public void setLinkadd(String linkadd) {
		this.linkadd = linkadd;
	}

}