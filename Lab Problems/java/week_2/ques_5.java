import java.io.*;
import java.lang.*;
import java.util.*;

public class ques_5{
	String railfence(String s , int key){
		StringBuffer sen =new StringBuffer();
		int i=0;
		int len=s.length();
		int j=key;
		while(j>0){
			i=key-j;
			while(i<len){
				sen.append(s.charAt(i));
				i=i+key;
			}
			j--;
		}
		return sen.toString();
		
		

	}
	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		String s = sc.nextLine();
		int len =s.length();
		int[] arr =new int[len];
		int j=0;
		StringBuffer sen =new StringBuffer(s);
		for(int i=0 ;i<len;i++){
			if(sen.charAt(i)==' '){
				arr[j]=i-j;
				j++;
			}
		}
		for(int i=0;i<j;i++){
			sen.deleteCharAt(arr[i]);
		}
		//System.out.println(sen);
		int key =sc.nextInt();
		ques_5 obj =new ques_5();
		String f =obj.railfence(sen.toString(),key);
		System.out.println(f);
	}
}