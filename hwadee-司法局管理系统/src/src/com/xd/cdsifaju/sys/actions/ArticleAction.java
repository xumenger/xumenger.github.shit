package com.xd.cdsifaju.sys.actions;


import java.util.Date;
import java.util.List;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;

import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;
import org.apache.struts2.interceptor.ServletRequestAware;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;


import com.opensymphony.xwork2.ActionSupport;
import com.xd.cdsifaju.entities.Article;
import com.xd.cdsifaju.sys.services.interfaces.IArticleService;

@Controller        //����
@Scope("prototype")//����
@ParentPackage(value="struts-default")
@Results({
   // @Result(name="success",value="fun",params={"contentType","text/plain","root","fun","excludeNullProperties","true"},type=JSONResult.class),
    @Result(name="add",value="/admin/article_add.jsp"),
    @Result(name="list",value="/admin/article_list.jsp"),
    @Result(name="detail",value="/admin/article_update.jsp"),
    @Result(name="howtouse",value="/admin/howtouse.jsp"),
    @Result(name="adminleft",value="/admin/admin_lef.jsp"),
    @Result(name="admintop",value="/admin/admin_top.jsp"),
    @Result(name="admin",value="/admin/admin.jsp"),
    @Result(name="index",value="/index/index.jsp"),
    @Result(name="login",value="/admin/login.jsp"),
    @Result(name="show",value="/index/artcshow.jsp")
})
public class ArticleAction extends ActionSupport implements ServletRequestAware{
	
	private static final long serialVersionUID = 1L;

	/**
	 * @param args
	 */
	@Resource(name="artcservice")
	private IArticleService artcservice;
	
	private Article article;
	private List<Article> listartc;

	public Article getArticle() {
		return article;
	}

	public void setArticle(Article article) {
		this.article = article;
	}

	public List<Article> getListartc() {
		return listartc;
	}

	public void setListartc(List<Article> listartc) {
		this.listartc = listartc;
	}
	
	
	public String detail() throws Exception
	{
			article=artcservice.detail(article);
			return "detail";
	}
	
	public String delete() throws Exception
	{
		artcservice.delete(article);
		return list();
	}
	
	public String add() throws Exception
	{
		artcservice.add(article);
		return list();
	}
	
	public String search()throws Exception{
		listartc=artcservice.list(article);
		return "list";
	}
	
	public String list() throws Exception
	{
		listartc=artcservice.list();
		return "list";
	}
	
	public String edit() throws Exception
	{
		//this.article.setUpdateTime(new Date());
		/*
		Date d=new Date();
		Simple
		*/
		artcservice.edit(article);
		return list();
	}
	public String gotoedit() throws Exception
	{
		//article=artcservice.findbyid(article);
		return "edit";
	}
	
	public String gotolist() throws Exception
	{
		listartc=artcservice.list();
		return "list";
	}

	public String gotoadd() throws Exception
	{
		return "add";
	}
	
	public String gotoindex()throws Exception{
		list();
		return "index";
	}
	
	public String howtouse()throws Exception{
		return "howtouse";
	}
	
	public String adminleft()throws Exception{
		return "adminleft";
	}
	
	public String admintop()throws Exception{
		return "admintop";
	}
	
	public String admin()throws Exception{
		return "admin";
	}
	
	public String gotologin() throws Exception{
		return "login";
	}
	
	public String gotoartc()throws Exception{
		detail();
		return "show";
	}
	
	public void setServletRequest(HttpServletRequest arg0) {
		
		
	}
}
