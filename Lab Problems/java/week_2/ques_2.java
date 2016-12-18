import java.io.*;
import java.lang.*;
import java.util.*;


public class ques_2{
	boolean Luhn_formula(String n){
		StringBuffer sen =new StringBuffer(n);
		int len = n.length();
		System.out.println(len);
		char check_digit =n.charAt(len-1);
		sen.deleteCharAt(len-1);
		len=len-1;
		int sum =0;
		sen =sen.reverse();
		for(int i=0; i< len;i++){
			int x= (((int)sen.charAt(i))-48);
			//System.out.println("oldx"+x);
			if(i%2==0){
				x=x*2;
				if(x/10!=0){
					x=(1+(x%10));
				}
				sum=sum+x;
				System.out.println("xc"+x);
			}
			else{
				System.out.println("x"+x);
				sum=sum+x;
			}
		}
		System.out.println(sen);
		System.out.println(sum);
		if((sum+(((int)(check_digit)-48)))%10==0){
			return true;
		}
		return false;

	}
	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		String s =sc.next();
		//String s=  String.valueOf(x);
		ques_2 obj =new ques_2();
		boolean x =obj.Luhn_formula(s);
		System.out.println(x);
	}
}
