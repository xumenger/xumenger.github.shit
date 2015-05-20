package com.xd.cdsifaju.sys.actions;

import java.util.List;

import javax.annotation.Resource;

import org.apache.struts2.config.ParentPackage;
import org.apache.struts2.config.Result;
import org.apache.struts2.config.Results;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Controller;

import com.opensymphony.xwork2.ActionSupport;
import com.xd.cdsifaju.entities.Notarization;
import com.xd.cdsifaju.sys.services.interfaces.INotarizationService;

@Controller
//����
@Scope("prototype")
//����
@ParentPackage(value = "struts-default")
@Results({
//@Result(name="success",value="fun",params={"contentType","text/plain","root","fun","excludeNullProperties","true"},type=JSONResult.class),
@Result(name = "list", value = "/admin/notarization_list.jsp"),
@Result(name = "success", value = "/index/success.jsp") })
public class NotarizationAction extends ActionSupport{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	@Resource(name="notarizationservice")
	private INotarizationService notaservice;
	private Notarization nota;
	private List<Notarization> listnota;
	public Notarization getNota() {
		return nota;
	}
	public void setNota(Notarization nota) {
		this.nota = nota;
	}
	public List<Notarization> getListnota() {
		return listnota;
	}
	public void setListnota(List<Notarization> listnota) {
		this.listnota = listnota;
	}
	public String list() throws Exception{
		listnota=notaservice.findAll();
		return "list";
		
	}
	public String add() throws Exception{
		notaservice.add(nota);
		return "success";
	}

}
