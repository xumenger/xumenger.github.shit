package com.xd.cdsifaju.sys.services.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Article;



public interface IArticleService {

	String add(Article article);
	List<Article> list();
	List<Article> list(Article article);
	String edit(Article article);
	String delete(Article article);
	Article detail(Article article);
}
