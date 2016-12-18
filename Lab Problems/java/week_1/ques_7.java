/* ///Brian Kernighan’s Algorithm
reference geekforgeeks
Subtraction of 1 from a number toggles all the bits (from right to left) till the 
rightmost set bit(including the righmost set bit). So if we subtract a number by 1 and 
do bitwise & with itself (n & (n-1)), we unset the righmost set bit. If we do n & (n-1) in a loop 
and count the no of times loop executes we get the set bit count.
Beauty of the this solution is number of times it loops is equal to the number of set bits in a 
given integer.

sudo code: 
   1  Initialize count: = 0
   2  If integer n is not zero
      (a) Do bitwise & with (n-1) and assign the value back to n
          n: = n&(n-1)
      (b) Increment count by 1
      (c) go to step 2
   3  Else return count

*/
/// do be done using BIG INTEGER ///
//// IMP QUES //////
import java.io.*;
import java.lang.*;
import java.util.*;

class Brian_Kernighans_Algorithm{
	int count_set_bits(int n){
	    int count = 0;
	    while(n != 0){
	        n &= (n-1);
	        count++;
	    }
	    return count;
    }
    public static void main(String args[]){
    	Scanner sc =new Scanner(System.in);
    	int n =sc.nextLong();
    	Brian_Kernighans_Algorithm count =new Brian_Kernighans_Algorithm();
    	int num=count.count_set_bits(n);
    	System.out.println(num);
    }
}
