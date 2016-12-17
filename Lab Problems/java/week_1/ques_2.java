import java.io.*;
import java.lang.*;
import java.util.*;

public class ques_2{

	int wordInSen(String word , String sentence){
		int count =0;
		StringTokenizer st =new StringTokenizer(sentence);;
		while(st.hasMoreTokens()){
			if(st.nextToken().equals(word)){
				count++;
			}
		}
		return count;
	}
	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		String word =sc.nextLine();
		String sentence =sc.nextLine();
		ques_2 wordInSen = new ques_2();
		int n =wordInSen.wordInSen(word , sentence);
		System.out.println(n);
	}
}