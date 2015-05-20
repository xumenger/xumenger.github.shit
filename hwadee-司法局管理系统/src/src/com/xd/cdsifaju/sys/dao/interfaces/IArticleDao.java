package com.xd.cdsifaju.sys.dao.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Article;
import com.xd.cdsifaju.entities.Outlink;




public interface IArticleDao {

	String add(Article article);
	List<Article> getArticles();
	List<Article> list(Article article);
	String edit(Article article);
	Article detail(Article article);
	String delete(Article article);
}
