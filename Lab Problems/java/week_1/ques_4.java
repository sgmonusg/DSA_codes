import java.io.*;
import java.lang.*;
import java.util.*;
public class ques_4{

	String encode(String sentence , int breaks){
		StringBuffer sen= new StringBuffer(sentence);
		//System.out.println(sen);
		int len = sen.length();
		//System.out.println(len);
		int count =0;
		Integer start[] =new Integer[breaks];
		start[0]=0;
		Integer last[] =new Integer[breaks];
		for(int i=0;i<len ;i++){
			if(sen.charAt(i)==' '){
				last[count]=i;
				start[count+1]=i+1;
				count++;
			}
		}
		// debugging
		/*
		for(int i=0;i<count;i++){
			System.out.println(start[i]);
			System.out.println(last[i]);
		}
		*/
		for(int i=0; i<count ;i++){
			String s= sen.substring(start[i],last[i]);
			s=new StringBuilder(s).reverse().toString();
			sen.replace(start[i],last[i],s); 
		}
		/* another method for encoding unrelated to problem 
		StringBuffer s_encode =new StringBuffer(sentence);
		for(int i=0;i<len;i++){
			s_encode.setCharAt(((i),sen.charAt(i));
		}
		*/
		for(int i=0;i<len;i++){
			if(sen.charAt(i)!=' '){
				sen.setCharAt(i,(char)(((((int)sen.charAt(i)+3)-97)%26)+97));
			}
			
		}
		
		String s=sen.toString();
		return s;
	}

	String decode(String sentence){
		return sentence;
	}

	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		String sentence =sc.nextLine();
		StringTokenizer st =new StringTokenizer(sentence);
		int count= st.countTokens();
		ques_4 coder = new ques_4();
		String s=coder.encode(sentence , count);
		System.out.println(s);
	}
}