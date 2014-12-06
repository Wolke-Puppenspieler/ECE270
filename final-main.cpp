/*Justin Newman
ECE 270 Final Project
12/6/14*/


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