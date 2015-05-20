import java.util.*;

public class BasicContainer{
	public static void main(String args[]){
		Collection c= new HashSet();
		c.add("hello");
		c.add(new Name("f1","l1"));
		c.add(new Integer(100));
		c.remove("hello");
		c.remove(new Integer(100));
		System.out,println(c.remove(new Name("f1","l1")));
		System.out.println(c);
	}
}

class Name implements Comparable{
	private String firstName, lastName;
	public Name(String firstName, String lastName){
		this.firstName = firstName;
		this.lastName = lastName;
	}
	public String getFirstName(){
		return this.firstName;
	}
	public String getlastName(){
		return this.lastName;
	}
	public String toString(){
		return firstNAme + " " + lastName;
	}

	public boolean equals(Object obj){
		if(obj instanceof Name){
			Name name = (Name)obj;
			return(firstName.equals(name.firstName)&&(lastName.equals(name.lastName)));
		}
		return super.equals(obj);
	}

	public int hashCode(){
		return firstName.hashCode();
	}

	public int compareTo(Object o){
		Name n = (Name)o;
		int lastCmp = lastName.compareTo(n.lastName);
		return (lastCmp!=0 ? lastCmp :firstNAme.compareTo(n.firstName));
	}
}
