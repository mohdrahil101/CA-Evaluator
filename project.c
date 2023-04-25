#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student{
	int rno;
	int regno;
	char name[50];
	struct course{
		char cname[20];
		char ccode[20];
		int ca1;
		int ca2;
		int ca3;
		int finalca;
	}course[5];
}student;

void create(){
	FILE *fp;
	student *s;
	int n,i,j;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	s=(student*)calloc(n,sizeof(student));
	fp=fopen("carecord.txt","ab+");
	for(i=0;i<=n-1;i++){
		printf("\nEnter Roll no. of student %d: ",i+1);
		scanf("%d",&s[i]);
		fflush(stdin);
		printf("Enter Registration No. of student %d: ",i+1);
		scanf("%d",&s[i].regno);
		fflush(stdin);
		printf("Enter Name of student %d: ",i+1);
		gets(s[i].name);
		fflush(stdin);
		for(j=0;j<=4;j++){
			int sum=0, c1,c2,c3,p;float div;
			printf("\nEnter Name of Course %d: ",j+1);
			gets(s[i].course[j].cname);
			fflush(stdin);
			printf("Enter code of Course %d: ",j+1);
			gets(s[i].course[j].ccode);
			fflush(stdin);
			printf("Enter Marks of Course %d: \n",j+1);
			printf("Enter Marks of CA1: ");
			scanf("%d",&s[i].course[j].ca1);
			fflush(stdin);
			printf("Enter Marks of CA2: ");
			scanf("%d",&s[i].course[j].ca2);
			fflush(stdin);
			printf("Enter Marks of CA3: ");
			scanf("%d",&s[i].course[j].ca3);
			fflush(stdin);
			if(s[i].course[j].ca1<s[i].course[j].ca2 && s[i].course[j].ca1<s[i].course[j].ca3)
			{	c1=s[i].course[j].ca1;
				c2=s[i].course[j].ca2;
				c3=s[i].course[j].ca3;
				sum=c2+c3;
				div=(float)sum/60;
				p=div*25;
				s[i].course[j].finalca=p;
			}else if(s[i].course[j].ca2<s[i].course[j].ca1 && s[i].course[j].ca2<s[i].course[j].ca3)
			{
				c1=s[i].course[j].ca1;
				c2=s[i].course[j].ca2;
				c3=s[i].course[j].ca3;
				sum=c1+c3;
				div=(float)sum/60;
				p=div*25;
				s[i].course[j].finalca=p;
			}else
			{
				c1=s[i].course[j].ca1;
				c2=s[i].course[j].ca2;
				c3=s[i].course[j].ca3;
				sum=c1+c2;
				div=(float)sum/60;
				p=div*25;
				s[i].course[j].finalca=p;
		}
		}
		fwrite(&s[i],sizeof(student),1,fp);
	}
	printf("\nRecord created!\n");
	fclose(fp);
}


void search(){
	student s1;
	FILE *fp;
	int j,flag=0,rno;
	fp=fopen("carecord.txt","rb+");
	printf("\nEnter Roll No. to search: ");
	scanf("%d",&rno);
	while(fread(&s1,sizeof(student),1,fp)==1)
		{	
			if(rno==s1.rno)
			{
				flag=1;
				printf("\n");
				printf("------------------------------------------------------------------");
				printf("\n     Roll No.     Registration No.          Name\n");
				printf("------------------------------------------------------------------");
				printf("\n%10d%17d%20s\n",s1.rno,s1.regno,s1.name);
				printf("\n");
				for(j=0;j<=4;j++){
					printf("   Course %d---> Course Name: %s    |    Course Code: %s     |    Final CA: %5d\n",j+1,s1.course[j].cname,s1.course[j].ccode,s1.course[j].finalca);				}
			}
		}
		if(flag==0)
		printf("Record not found!\n");
	fclose(fp);
	
}


void modify(){
	student s1;
	FILE *fp, *fp1;
	int j,flag=0,rno;
	fp=fopen("carecord.txt","rb+");
	fp1=fopen("temp.txt","wb+");
	printf("\nEnter Roll No. to modify: ");
	scanf("%d",&rno);
	while(fread(&s1,sizeof(student),1,fp)==1)
		{	
			if(rno==s1.rno)
			{
				flag=1;
		        fflush(stdin);
				printf("Enter New registration No. of the student: ");
				scanf("%d",&s1.regno);
				fflush(stdin);
				printf("Enter New name of the student: ");
				gets(s1.name);
				fflush(stdin);
				for(j=0;j<=4;j++){
					int sum=0, c1,c2,c3,p;float div;
					printf("\nEnter New name of Course %d: ",j+1);
					gets(s1.course[j].cname);
					fflush(stdin);
					printf("Enter New code of Course %d: ",j+1);
					gets(s1.course[j].ccode);
					fflush(stdin);
					printf("Enter New Marks of Course %d: \n",j+1);
					printf("Enter Marks of CA1: ");
					scanf("%d",&s1.course[j].ca1);
					fflush(stdin);
					printf("Enter Marks of CA2: ");
					scanf("%d",&s1.course[j].ca2);
					fflush(stdin);
					printf("Enter Marks of CA3: ");
					scanf("%d",&s1.course[j].ca3);
					fflush(stdin);
					if(s1.course[j].ca1<s1.course[j].ca2 && s1.course[j].ca1<s1.course[j].ca3)
					{	c1=s1.course[j].ca1;
						c2=s1.course[j].ca2;
						c3=s1.course[j].ca3;
						sum=c2+c3;
						div=(float)sum/60;
						p=div*25;
						s1.course[j].finalca=p;
					}else if(s1.course[j].ca2<s1.course[j].ca1 && s1.course[j].ca2<s1.course[j].ca3)
					{
						c1=s1.course[j].ca1;
						c2=s1.course[j].ca2;
						c3=s1.course[j].ca3;
						sum=c1+c3;
						div=(float)sum/60;
						p=div*25;
						s1.course[j].finalca=p;
					}else
					{
						c1=s1.course[j].ca1;
						c2=s1.course[j].ca2;
						c3=s1.course[j].ca3;
						sum=c1+c2;
						div=(float)sum/60;
						p=div*25;
						s1.course[j].finalca=p;
				   }
				}
				} 
			fwrite(&s1,sizeof(student),1,fp1);
			
		}
			fclose(fp);
			fclose(fp1);
		if(flag==1){
			fp1=fopen("temp.txt","rb+");
			fp=fopen("carecord.txt","wb+");
			while(fread(&s1,sizeof(student),1,fp1)){
				fwrite(&s1,sizeof(student),1,fp);
			}
			fclose(fp);
			fclose(fp1);
			remove("temp.txt");
			printf("Record modified!\n");
		}
		else
		printf("Record not found!\n");		
	
}


void deleterec(){
	
    FILE *fp,*fp1;
    student s1;
    int rno;
    printf("Enter roll no. of the Student to delete record: ");
    scanf("%d",&rno);
    if(rno!=s1.rno)
	printf("\nRecord not found!\n");
	else{
	
    fp = fopen("carecord.txt","rb+");
    fp1 = fopen("temp.txt","wb+");
    
    if(fp == NULL)
        printf("Error opening file!");
        
    if(fp1 == NULL)
        printf("Error opening file!");
        
    while(fread(&s1,sizeof(student),1,fp) == 1){
        if(rno!=s1.rno)
            fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    remove("carecord.txt");
    rename("temp.txt","carecord.txt");
    printf("Record deleted!");
	
}
}


void display(){
	student s1;
	FILE *fp;
	fp=fopen("carecord.txt","rb+");
	if(fp == NULL)
        printf("\nNo Record found!\n");
	else{ 
		int j;

		while(fread(&s1,sizeof(student),1,fp)==1)
		{	printf("\n");
			printf("------------------------------------------------------------------");
			printf("\n     Roll No.     Registration No.          Name\n");
			printf("------------------------------------------------------------------");
			printf("\n%10d%17d%20s\n",s1.rno,s1.regno,s1.name);
			printf("\n");
			for(j=0;j<=4;j++){
				printf("   Course %d---> Course Name: %s    |    Course Code: %s     |    Final CA: %5d\n",j+1,s1.course[j].cname,s1.course[j].ccode,s1.course[j].finalca);	
			}
		}
	}
	fclose(fp);
}


int main(){
	int pwd; char usr[20];
	printf("Welcome to CA evaluator system!\n");
	printf("\nEnter Username: ");
	scanf("%s",&usr);
	printf("Enter Password: ",&pwd);
	scanf("%d",&pwd);
	if(usr!="newuser" && pwd!=123456)
		printf("Invalid username or password!");
	else{
			int ch;
	do{
		printf("\n\n<----MENU---->\n");
		printf("\n 1--> Create Record");
		printf("\n 2--> Search Record");
		printf("\n 3--> Modify Record");
		printf("\n 4--> Delete Record");
		printf("\n 5--> Display Record");
		printf("\n 6--> Exit");
		
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				create();
				break;
			case 2:
				search();
				break;
			case 3:
				modify();
				break;
			case 4:
				deleterec();
				break;
			case 5:
				display();
				break;
			case 6:
				printf("Thanks!");
				break;
			default:
				printf("Invalid input!\n");
				break;
		}
	}while(ch!=6);
	
	}                                                      

}
