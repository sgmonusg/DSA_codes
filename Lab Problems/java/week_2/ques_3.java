import java.io.*;
import java.lang.*;
import java.util.*;

public class ques_3{
	void sparse(int[] row , int[] col , int[] value , int count){
		for(int i=0 ; i< count ;i++){
			System.out.println("<"+row[i]+","+col[i]+","+value[i]+">");
		}
	}

	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		Integer[][] x =new Integer[6][6];
		int[] row =new int[36];
		int[] col =new int[36];
		int[] value =new int[36];
		int count =0;
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				x[i][j]=sc.nextInt();
				if(x[i][j]!=0){
					row[count]=i;
					col[count]=j;
					value[count]=x[i][j];
					count++;
				}
			}
		}
		if(count<6){
			System.out.println("sparse");
			ques_3 obj = new ques_3();
			obj.sparse(row ,col , value, count);
		}
		else{
			System.out.println("not sparse");
		}
	}
}