import java.io.*;
import java.lang.*;
class ques_1{
	int s_len(String s){
		int i=0;
		int len=0;
		while(s.charAt(i)!='\0'){
			len++;
		}
		len++;
		return len;
	}

	String s_copy(String des ,String source){
		des=source;
		return des;
	}

	String s_cat(string s1 , String s2){
		string s3 =new String();
		s3=s1+s2;
		return s3;
	}

	boolean s_end(String s , String t){
		boolean temp=false;
		l_s=s_len(s)
		l_t=s_len(t)
		for(int i=0;i<l_t;i++){
			if(s.charAt(l_s-l_t+i-1)==t.charAt(i)){
				temp=true;
			}
			else{
				temp=false;
				break;
			}
		}
		return temp;
	}

	boolean s_palindrome(String s){
		boolean temp =false;
		l_s=s_len();
		for(int i=0; i< l_s/2;i++){
			if(s.charAt(i)=s.charAt(l_s-i-1)){
				temp=true;
			}
			else{
				temp=false;
				break;
			}
		}
		return temp;
	}

	String s_reverse(String s){

	}

	public static void main(String args[]){
		//#implementing string functions

	}
}