import java.io.*;
import java.lang.*;
import java.util.*;

public class ques_9{
	int sum(Integer[][] mat){
		int sum=0;
		for(int i=0;i<p;i++){
			for(int j=0;j<n;j++){
				sum=sum+mat_2[i][j];
			}
		}
		return sum;
	}

	Integer[][] multipy(Integer[][] mat1, Integer[][] mat_2){

	}

	
	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		// matrix 1
		int m =sc.nextInt();
		int p =sc.nextInt();
		Integer[][] mat_1 =new Integer[m][p];
		for(int i=0;i<m;i++){
			for(int j=0;j<p;j++){
				mat_1[i][j]=sc.nextInteger();
			}
		}
		// matrix 2
		int p =sc.nextInt();
		int n =sc.nextInt();
		Integer[][] mat_2 =new Integer[p][n];
		for(int i=0;i<p;i++){
			for(int j=0;j<n;j++){
				mat_2[i][j]=sc.nextInteger();
			}
		}


	}
}