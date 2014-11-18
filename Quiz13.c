#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cd{
	char artistName[50];
	char albumName[50];
	int year;
	char genre[50];
	float rating;
	char studentName[50];
};
int fillStruct(FILE *,struct cd []);
void setCD(FILE *,struct cd *);
void printStructArray(FILE *,struct cd [],int );
int main()
{
	FILE *fp;
	FILE *fout;
    fout=fopen("quiz13.txt","w");
	fp=fopen("MasterCDList.txt","r");
	int numLines=0;
	struct cd CDList[175];
	struct cd MyCD;
    numLines=fillStruct(fp,CDList);
    setCD(fout,&MyCD);
	printStructArray(fout,CDList,numLines);
	fclose(fp);
	fclose(fout);
	return 0;
}
int fillStruct(FILE *fp,struct cd CDList[175])
{
	int i=0;
	char *token;
	char year[5], rating[4], temp[100], comma[2]=",\0";

    for(i=0;i<175;i++)
    {
        //printf("error\n %d",i); - testing

        fgets(temp,sizeof(temp),fp);
		token=strtok(temp,comma);
		strcpy(CDList[i].artistName,strdup(token));

        token=strtok(NULL,comma);
        strcpy(CDList[i].albumName,strdup(token));

        token=strtok(NULL,comma);
        strcpy(year,strdup(token));
        CDList[i].year=atoi(year);

        token=strtok(NULL,comma);
        strcpy(CDList[i].genre,strdup(token));

        token=strtok(NULL,comma);
        strcpy(rating,strdup(token));
        CDList[i].rating=atof(rating);

        token=strtok(NULL,comma);
        strcpy(CDList[i].studentName,strdup(token));

    }

    return(i);
}

void setCD(FILE *fout,struct cd *MyCD)
{
    char year[5], rating[4];
	printf("Enter the CD's artist: ");
	gets(MyCD->artistName);
	printf("Enter the album name: ");
	gets(MyCD->albumName);
	printf("Enter the year the album was released: ");
	gets(year);
	MyCD->year=atoi(year);
	printf("Enter the album's genre: ");
	gets(MyCD->genre);
	printf("Enter your rating (0.0-5.0): ");
	gets(rating);
	MyCD->rating=atof(rating);
	printf("Enter your name: ");
	gets(MyCD->studentName);
	printf("%s",MyCD->artistName);
}
void printStructArray(FILE *fout,struct cd CDList[],int n)
{
    int i;

    printf("\n\tArtist\t \tAlbum\t \tYear\t \tGenre\t \tRating\t \tStudent\t");

    for(i=0;i<175;i++)
    {

        printf("%s",CDList[i].artistName);
        printf("\t\t%s\t",CDList[i].albumName);
        printf("\t%d",CDList[i].year);
        printf("\t%s",CDList[i].genre);
        printf("\t%.1f",CDList[i].rating);
        printf("\t%s",CDList[i].studentName);
        printf("\n");

        fprintf(fout,"%s \t",CDList[i].artistName);
        fprintf(fout,"%s \t",CDList[i].albumName);
        fprintf(fout,"%d \t",CDList[i].year);
        fprintf(fout,"%s \t",CDList[i].genre);
        fprintf(fout,"%.1f \t",CDList[i].rating);
        fprintf(fout,"%s \t",CDList[i].studentName);
        fprintf(fout,"\n");

    }
}
