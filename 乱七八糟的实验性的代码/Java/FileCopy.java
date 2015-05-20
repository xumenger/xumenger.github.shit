import java.io.*;

public class FileCopy{
	static public void main(String[] args){
		FileReader in = null;
		FileWriter out = null;
		int b = 0;
		try{
			in = new FileReader("/home/perfect/mywork/0TEMP/FileCopy.java");
			out = new FileWriter("/home/perfect/mywork/0TEMP/ll.l");
			while((b=in.read())!=-1){
				out.write(b);
			}
			in.close();
			out.close();
		}catch(Exception e){
			e.printStackTrace();
		}

		System.out.println("Success");
	}
}
