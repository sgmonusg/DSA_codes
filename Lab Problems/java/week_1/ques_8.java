import java.io.*;
import java.lang.*;
import java.util.*;

public class ques_8{
	boolean stringExist(String s , String w){
		boolean x =false;
		int j=0;
		int len =s.length();
		for(int i=0;i<w.length();i++){
			if(s.charAt(j)==w.charAt(i)){
				if(j<len-1){
					j++;
				}
				else{
					x=true;
					break;
				}
			}
			if(j<len){
				x=false;
			}
		}
		return x;
	}
	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		String s ="goodbye";
		String w = sc.next();
		ques_8 stringExist = new ques_8();
		boolean x = stringExist.stringExist(s ,w);
		System.out.println(x);
	}
}