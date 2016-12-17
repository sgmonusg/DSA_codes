import java.io.*;
import java.lang.*;
import java.util.*;

public class ques_3{

	public Integer[] count(String sentence){
		Integer[] count =new Integer[126];
		for(int i=0;i<126;i++){
			count[i]=0;
		}

		//System.out.println(sentence.charAt(10));
		for(int i=0; i<sentence.length();i++){
			int a=(int)sentence.charAt(i);
			//System.out.println(a);
			count[a]=count[a]+1;
		}
		return count;
		
	}
	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		String sentence =sc.nextLine();
		ques_3 count = new ques_3();
		Integer n[] =new Integer[126];
		n =count.count(sentence);
		for(int i =0 ;i<126;i++){
			if(n[i]!=0){
				System.out.println((char)i+" "+n[i]+" ");
			}
		} 
		System.out.println();
	}
}