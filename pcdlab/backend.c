#include<stdio.h>
#include<ctype.h>
#include<string.h>
int ag=0,z=1;
void main()
{
char
a[50],id[50],mov[]="MOVF",mul[]="MULF",div[]="DIVF",add[]="ADDF",sub[]="SUBF";
int i=0,j=0,len=0,s=0,e=0,r=1;
FILE *fp;
fp=fopen("out.txt","w");
printf("\nEnter the code:");
gets(a);
len=strlen(a);
for(i=0;i<len;i++)
{
if(a[i]=='=')
{
for(j=i;j<len;j++)
if(a[j]=='i')
{
fprintf(fp,"\n%s ",mov);
fprintf(fp,"%c%c%c,R%d",a[j],a[j+1],a[j+2],r++);
}
}
else if((a[i]<=57)&&(a[i]>=48))
if((a[i+1]<=57)&&(a[i+1]>=48))
fprintf(fp,"\n%s #%c%c,R%d",mov,a[i],a[i+1],r++);
}
for(i=len-1;i>=0;i--)
{
if(a[i]=='+')
{
fprintf(fp,"\n%s ",add);
e=a[i-1];
e--;
s=e;
if(a[i+1]=='i')
fprintf(fp,"R%c,R%d",e,r-1);
}
else if(a[i]=='-')
{
fprintf(fp,"\n%s ",sub);
e=a[i-1];
e--;
s=e;
if(a[i+1]=='i')
fprintf(fp,"R%c,R%c",(a[i+3]-1),s);
else
fprintf(fp,"R%c,R%d",e,r-1);
}
else if(a[i]=='*')
{
fprintf(fp,"\n%s ",mul);
e=a[i-1];
e--;
s=e;
if(a[i+1]=='i')
fprintf(fp,"R%c,R%c",(a[i+3]-1),s);
else
fprintf(fp,"R%c,R%d",e,r-1);
}
else if(a[i]=='/')
{
fprintf(fp,"\n%s ",div);
e=a[i-1];
e--;
s=e;
if(a[i+1]=='i')
fprintf(fp,"R%c,R%c",(a[i+3]-1),s);
else
fprintf(fp,"R%c,R%d",e,r-1);
}
}
fprintf(fp,"\n%s R1,id1",mov);
}