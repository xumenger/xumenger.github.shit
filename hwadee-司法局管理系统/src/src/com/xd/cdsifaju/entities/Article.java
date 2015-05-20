package com.xd.cdsifaju.entities;

import java.util.Date;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@SuppressWarnings("serial")
@Entity
@Table(name="Article")

//����
public class Article {
	
	static final String SERIAL = "serial";

	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	@Column(name="ArticleID")
	private int articleID;//����ID������
	
	@Column(name="UserID")
	private int userID;//�û�ID
	
	@Column(name="ArticleName")
	private String articleName;//�������
	
	@Column(name="ArticleContent")
	private String articleContent;//��������
	
	@Column(name="ArticleType")
	private Integer articleType;//��������

	@Column(name="UpdateTime")
	private Date updateTime;
	
	@Column(name="Author")
	private String author;
	
	@Column(name="ArticleStatus")
	private Integer articleStatus;

	public int getArticleID() {
		return articleID;
	}

	public void setArticleID(int articleID) {
		this.articleID = articleID;
	}

	public int getUserID() {
		return userID;
	}

	public void setUserID(int userID) {
		this.userID = userID;
	}

	public String getArticleName() {
		return articleName;
	}

	public void setArticleName(String articleName) {
		this.articleName = articleName;
	}

	public String getArticleContent() {
		return articleContent;
	}

	public void setArticleContent(String articleContent) {
		this.articleContent = articleContent;
	}

	public Integer getArticleType() {
		return articleType;
	}

	public void setArticleType(Integer articleType) {
		this.articleType = articleType;
	}

	public Date getUpdateTime() {
		return updateTime;
	}

	public void setUpdateTime(Date updateTime) {
		this.updateTime = updateTime;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public Integer getArticleStatus() {
		return articleStatus;
	}

	public void setArticleStatus(Integer articleStatus) {
		this.articleStatus = articleStatus;
	}
}
