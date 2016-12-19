import java.io.*;
import java.lang.*;
import java.util.*;

public class ques_7{
	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		int x= sc.nextInt();
		String s =String.valueOf(x)	;
		int len=s.length();
		int sum =0;
		System.out.println(len);
		for(int i=0;i<len;i++){
			sum = sum+ Math.pow(3,i);
			//break;
		}	
	}
}