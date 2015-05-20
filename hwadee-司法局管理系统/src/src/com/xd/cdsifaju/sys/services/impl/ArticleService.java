package com.xd.cdsifaju.sys.services.impl;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.xd.cdsifaju.entities.Article;
import com.xd.cdsifaju.sys.dao.interfaces.IArticleDao;
import com.xd.cdsifaju.sys.services.interfaces.IArticleService;



@Service("artcservice")
public class ArticleService implements IArticleService{

	/**
	 * @param args
	 */
	@Resource(name="artcdao")
	private IArticleDao artcdao;
	
	public String add(Article article) {
		// TODO Auto-generated method stub
		//return null;
		return artcdao.add(article);
	}

	public List<Article> list() {
		// TODO Auto-generated method stub
		return artcdao.getArticles();
	}
	
	public List<Article> list(Article article) {
		// TODO Auto-generated method stub
		return artcdao.list(article);
	}

	public String edit(Article article) {
		// TODO Auto-generated method stub
		//return null;
		return artcdao.edit(article);
	}

	public String delete(Article article) {
		// TODO Auto-generated method stub
		return artcdao.delete(article);
	}

	public Article detail(Article article) {
		// TODO Auto-generated method stub
		return artcdao.detail(article);
	}

}
