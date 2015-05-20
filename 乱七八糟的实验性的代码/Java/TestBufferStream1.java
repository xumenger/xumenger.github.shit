import java.io.*;
public class TestBufferStream1{
	public static void main(String[] args){
		try{
			FileInputStream fis = new FileInputStream("/home/perfect/mywork/0TEMP/FileCopy.java");
			BufferedInputStream bis = new BufferedInputStream(fis);
			int c = 0;
			for(; (c=bis.read())!=-1; ){
				System.out.print((char)c);
			}

			bis.reset();
			for(; (c=bis.read())!=-1; ){
				System.out.print((char)c);
			}

			fis.close();
			bis.close();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}
