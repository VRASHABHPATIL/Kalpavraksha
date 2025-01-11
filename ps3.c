#include<stdio.h>
#include<string.h>

int wordfind(char line[100],char word[50])
{
    int linelen,wordlen,i,j,track;
    
    linelen=strlen(line);
    wordlen=strlen(word);

   
    j=0;
    for(i=0;i<linelen;i++)
    {
        if(line[i]==word[j])
        {
            j=j+1;
            track=i;
        }
        else if(j==wordlen)
        {
            break;

        }
        else
        {
            j=0;
        }

    }
    if(j==wordlen)
    {
        return track-j+1;
    }
    else
    {
        return -1;
    }

}
int main()
{
    char line1[100],word1[50];
    printf("Enter the line : ");
    scanf("%[^\n]%*c",line1);

    printf("Enter the word to find : ");
    scanf("%s",word1);

    int output;

    output=wordfind(line1,word1);
    printf("Output : %d\n",output);
    
}