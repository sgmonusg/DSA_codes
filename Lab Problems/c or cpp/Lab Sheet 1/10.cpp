/*

	Problem 10>

	Write a program to read n and find the value of n! where 0 ≤ n ≤ 200. 
	You have to take care of how to handle large numbers.

	Sample Input:
	5
	Sample Output:
	120

*/


#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;

	// The result wont go beyond 1000 :)
	int store[1001] = {0};

	store[0] = 1;

	int limit = 0;

	// Multiplying the number with each element of array
	for(int mul = 1; mul <= n;mul++){

		// First Multiplying
		for(int j = 0;j <= limit;j++){

			store[j] *= mul;

		}

		// Then adding the REMAINDER
		for(int j = 0;j <= limit;j++){

			if(j == limit){
				if(store[j]/10 != 0){
					limit++;
				}
			}

			store[j+1] += store[j]/10;
			store[j] = store[j]%10;

			
			}

		}

	
	// Printing the RESULT
	for(int i = limit;i >= 0;i-- ){
		cout << store[i];
	}
	cout << endl;

	return 0;
}