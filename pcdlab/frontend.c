#include<stdio.h> 
#include<ctype.h>
#include<string.h> 
int ag=0,z=1;
void main() 
{ char 
a[50],id[50],b[50],op[50],mov[]="MOVF",mul[]="MULF",div[]="DIVF",add[]="ADDF",sub[] 
= "SUBF",ti=0; 
int i=0,j=0,k=0,len=0,s=0,e=0,r=1,count; FILE *fp; fp=fopen("out.txt","w"); printf("\nEnter the code:"); scanf("%s",a); strcpy(b,a); len=strlen(a); for ( i=0;i<strlen(b);i++ ){ if ( b[i] == '*' || b[i] == '/' ){ 
for ( j=i-1;b[j]!='-'&&b[j]!='+'&&b[j]!='*'&&b[j]!='/'&&b[j]!='=';j--); k=j+1; count=0; 
printf("\nt%d=",ti++); 
for ( j=j+1;count<2&&b[j]!='\0';j++ ){ 
if ( b[j+1] == '+' || b[j+1] == '-' || b[j+1] == '*' || b[j+1] == '/' ) count++; printf("%c",b[j]); 
} b[k++]='t'; b[k++]=ti-1+48; 
for ( j=j,k=k;k<strlen(b);k++,j++ ) b[k]=b[j]; i=0; } } for ( i=0;i<strlen(b);i++ ){ 
if ( b[i] == '+' || b[i] == '-' ){ 
for ( j=i-1;b[j]!='-'&&b[j]!='+'&&b[j]!='=';j--); k=j+1; count=0; 
printf("\nt%d=",ti++); 
for ( j=j+1;count<2&&b[j]!='\0';j++ ) 
{ 
if ( b[j+1] == '+' || b[j+1] == '-' ) 
count++; printf("%c",b[j]); 
} b[k++]='t'; b[k++]=ti-1+48; 
for ( j=j,k=k;k<strlen(b);k++,j++ ) b[k]=b[j]; 
} } 
printf("\n%s",b); 
} 