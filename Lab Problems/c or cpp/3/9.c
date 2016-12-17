#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp;

    fp=fopen("C:\\Users\\Kevin\\Desktop\\Stuff\\pikupiku\\prog.txt","r");

    char c1='a',c2;

    int lines=1,words=0,chars=-1;

    while(c1!=EOF)
    {
        c2=c1;
        c1=fgetc(fp);

        if(c1==32&&c2!=32)//ALways use ASCII value of space otherwise it wont recognize
        {
            words++;
        }
        else if(c1==10&&c2!=10)
        {
            words++;
        }
        else if(c1==EOF)
        {
            words++;
        }

        if(c1==10)//Always use ASCII value of \n
        {
            lines++;
        }

        if(c1!=10&&c1!=32)//characters excluding space and \n
        chars++;
    }

    printf("characters: %d\nwords: %d\nlines: %d",chars,words,lines);
    return 0;
}
