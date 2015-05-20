package com.xd.cdsifaju.sys.dao.impl;

import java.util.List;

import org.springframework.stereotype.Repository;

import com.xd.cdsifaju.common.dao.BasicSupportDao;
import com.xd.cdsifaju.entities.Article;
import com.xd.cdsifaju.entities.Outlink;
import com.xd.cdsifaju.sys.dao.interfaces.IArticleDao;



@Repository("artcdao")
class ArticleDao extends BasicSupportDao implements IArticleDao{

	private static final long serialVersionUID = 1L;

	public String add(Article article) {
		
		this.getHibernateTemplate().save(article);
		return "add";
	}

	@SuppressWarnings("unchecked")
	public List<Article> getArticles() {
		return this.getHibernateTemplate().find("from Article order by articleId");
	}
	
	public List<Article> list(Article article) {
		
		String queryString="select a from Article a ";
		if(article!=null && article.getArticleName()!=null){
			queryString+="where a.articleName = ?";
			return this.getHibernateTemplate().find(queryString,article.getArticleName());
		}
		else
			return this.getHibernateTemplate().find(queryString);
		/*if(article.getArticleType()==-1)
			return this.getHibernateTemplate().find(queryString);
		else{
			queryString+=" where a.ArticleType =?";
			return (List<Article>)this.getHibernateTemplate().find(queryString,article.getarticleType());
		}*/
	}

	public String edit(Article article) {
		
		this.getHibernateTemplate().saveOrUpdate(article);
		return "update";
	}

	public Article detail(Article article) {
		
		return this.getHibernateTemplate().get(Article.class, article.getArticleID());
	}
	
	public String delete(Article article) {

		this.getHibernateTemplate().delete(article);
		return "delete";
		
	}

}
