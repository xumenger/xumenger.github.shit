import java.io.*;

public class ListFile{
	public static void main(String args[]){
		File f = new File("/home/perfect/mywork/0TEMP");

		listChildren(f, 0);
	}

	public static void listChildren(File f, int level){
		String pre = "";
		for(int i=0; i<level; i++)
			pre+="---";

		System.out.println(pre+f.getName());

		if(!f.isDirectory())
			return;

		File children[] = f.listFiles();

		for(int i=0; i<children.length; i++)
			listChildren(children[i], level+1);
	}
}
