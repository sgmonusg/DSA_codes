#include<stdio.h>
#include<stdlib.h>
#include<math.h>



/*
 * Recursively checks for possible solutions to 123456789=100 problem
 * res is the target number to reach
 * num is the accumulated current value being parsed
 * cur is the operation string being constructed
 * s is the index to the next char to change in the result string
 * prev is the previous registered operation sign - 0 for +, 1 for minus
 * i is the current digit number
 */

//OK
void get100(int res,int num,char cur[],int s,int prev,int i)
{
	if(i>=9)
	{
  	/* reached the end of digits
     * if the remaining expected result effectively equals the current accumulated value, the solution is valid */
		if(res==num)
		{
      /* solution is valid, print it */
			cur[s]='9';
			cur[s+1]='\0';
			printf("%s\n",cur);
		}
		return;
	}
	else
	{
    /* add current digit */
		cur[s]=(char)(i+48);
    /* try with inserting plus */
		cur[s+1]='+';//till this its ok after this how do u make that recursion call??

    /* subtract the accumulated number
     * recurse with i+1 (next digit) as new accumulated value */
		get100(res-num,i+1,cur,s+2,0,i+1);
    /* try with inserting - */
		cur[s+1]='-';
    /* subtract the accumulated number
     * recurse with -i-1 (negative next digit) as new accumulated value */
		get100(res-num,-i-1,cur,s+2,1,i+1);
    /* try with inserting nothing */
		if(prev==0) {
      /* accumulating positive value
       * recurse with num*10+i+1 (current accumulated value + next digit, e.g. 1 -> 1 * 10 + 2 = 12) as new accumulated value */
			get100(res,(num*10)+i+1,cur,s+1,prev,i+1);
    }
		else {
      /* accumulating negative value
       * recurse with num*10-i-1 (current accumulated value + next digit, e.g. -2 -> -2 * 10 - 3 = -23) as new accumulated value */
			get100(res,(num*10)-i-1,cur,s+1,prev,i+1);
    }
	}
}
int main()
{
	char cur[100];
	get100(100,1,cur,0,0,1);
	return 0;
}
