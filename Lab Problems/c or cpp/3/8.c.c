#include<stdio.h>
int main(){
int arr[8][8];

int i=0;
int j=0;
for(i=0;i<8;i++){
	for(j=0;j<8;j++){
		arr[i][j]=0;
	}
}
int temp=1;
int temp1=0;
for(i=0;i<8;i++){
    for(j=0;j<8;j++){
        scanf("%d",&arr[i][j]);

        if(arr[i][j]==1){
            arr[i][j]=temp+1;
            temp++;
            int k=0;
            for(k=0;k<8;k++){
                if(arr[i][k]==0||arr[i][k]==arr[i][j]){
                    arr[i][k]=arr[i][j];

                }
                else{
                    printf("No");
                    temp1=1;
                    break;
                }
            }
            for(k=0;k<8&&temp1==0;k++){
                if(arr[k][j]==0){
                    arr[k][j]=arr[i][j];
                }
                else{
                    printf("No");
                    temp1=1;
                    break;
                }
            }
        }
        if(temp1==1){
        	break;
        }

    }
    if(temp1==1){
    	break;
    }
}


return 0;
}
