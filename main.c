#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int register_page();
int login_page();
int job_page();
int job_taker();
int view_fun();
struct User
  {
   char name[100];
   char email[200];
   int age;
   char psd[100];
   int reg_no;
   char gender[100];
   char jname[100];
  }U[100];
struct Job
{
 char name[100];
 char type[100];
 int time;
 char location[100];
 int experience;
 char requirement[100];
 char description[100];
 int salary;
}J;
int main()
{
  int ch;
  printf("\n 1 REGISTER");
  printf("\n 2 LOGIN");
  printf("\n 3 POST JOB");
  printf("\n 4 APPLY FOR JOB");
  printf("\n 5 EXIT");
  printf("\n ENTER THE CHOICE : ");
  scanf("%d",&ch);
  switch(ch)
    {
      case 1:
      register_page();
      break; 
      case 2:
      login_page();
      break;
      case 3:
      job_page();
      break;
      case 4:
      job_taker();
      break;
      case 5:
      printf("\n THANK YOU");
      break;
      default:
      printf("\n ENTER THE CORRECT CHOICE");
      main();
      break;
    }
  printf("\n");
  return 0;
}
int register_page()
{
  int i=0;
  printf("\n ENTER THE NAME : ");
  scanf("%s",U[i].name);
  printf(" ENTER THE EMAIL : ");
  scanf("%s",U[i].email);
  printf(" ENTER THE AGE : ");
  scanf("%d",&U[i].age);
  printf(" ENTER THE GENDER : ");
  scanf("%s",U[i].gender);
  printf(" ENTER THE PASSWORD : ");
  scanf("%s",U[i].psd);
  U[i].reg_no = i;
  printf("\n YOUR ACCOUNT HAS BEEN CREATED");
  printf("\n YOUR REGISTER ID IS %d",i);
  i++;
  main();
  return 0;
}
int login_page()
{
  char check_email[100];
  char check_psd[100];
  int a;
  int ch;
  printf("\n 1 LOGIN");
  printf("\n 2 FORGOT PASSWORD");
  printf("\n 3 FORGOT REGISTER NUMBER");
  printf("\n ENTER THE CHOICE : ");
  scanf("%d",&ch);
  switch(ch)
    {
      case 1:
      goto login;
      break;
      case 2:
      goto psd_ch;
      break;
      case 3:
      goto rn_ch;
      break;
      default:
      printf("\n ENTER THE CORRECT CHOICE : ");
      login_page();
      break;
    }
  login:
  printf("\n ENTER YOUR REGISTER NUMBER : ");
  scanf("%d",&a);
  printf(" ENTER THE EMAIL : ");
  scanf("%s",check_email);
  printf(" ENTER THE PASSWORD : ");
  scanf("%s",check_psd);
  if(strcmp(U[a].email,check_email)==0&&strcmp(U[a].psd,check_psd)==0&&(U[a].reg_no==a))
  {
    int b;
    printf("\n LOGIN SUCCESSFULLY");
    printf("\n WELCOME BACK %s",U[a].name);
    printf("\n 1 VIEW ACCOUNT DETAILS");
    printf("\n 2 SEARCH JOB");
    printf("\n 3 POST JOB");
    printf("\n ENTER THE CHOICE : ");
    scanf("%d",&b);
    switch(b)
      {
        case 1:
        view_fun();
        break;
        case 2:
        job_taker();
        break;
        case 3:
        job_page();
        break;
        default:
        printf("\n ENTER THE CORRECT CHOICE");
        goto login;
        break;
      }
  }
  else
  {
    printf("\n LOGIN UNSUCCESSFULLY");
    printf("\n 1 LOGIN AGAIN");
    printf("\n 2 REGISTER");
    int un_ch;
    printf("\n ENTER THE CHOICE : ");
    scanf("%d",&un_ch);
    switch(un_ch)
      {
        case 1:
        login_page();
        break;
        case 2:
        register_page();
        break;
        default:
        printf("\n ENTER THE CORRECT CHOICE");
        main();
        break;
      }
  }
  main();
  psd_ch:
  printf("\n ENTER THE EMAIL : ");
  scanf("%s",check_email);
  printf("\n ENTER THE REGISTER NUMBER : ");
  scanf("%d",&a);
  if((U[a].reg_no == a)&&strcmp(U[a].email,check_email)==0)
  {
    printf("\n THE EMAIL FOUND ");
    int ran_num = rand() %100000 + 1;
    printf("\n THE ONE TIME PASSWORD IS : %d",ran_num);
    int us_num;
    printf("\n ENTER THE ONE TIME PASSWORD TO VERIFY : ");
    scanf("%d",&us_num);
    if(ran_num == us_num)
    {
      printf("\n ACCOUNT IS VERFIED");
      printf("\n YOUR CURRENT PASSWORD IS : %s",U[a].psd);
      login_page();
    }
  }    
  else
    {
      printf("\n ACCOUNT IS UNVERIFIED");
      printf("\n 1 EXIT TO MENU");
      printf("\n 2 TRY AGAIN");
      printf("\n 3 LOGIN AGAIN");
      int ch_psd;
      printf("\n ENTER THE CHOICE : ");
      scanf("%d",&ch_psd);
      switch(ch_psd)
        {
          case 1:
          main();
          break;
          case 2:
          goto psd_ch;
          break;
          case 3:
          login_page();
          break;
          default:
          printf("\n ENTER THE CORRECT CHOICE ");
          main();
          break;
        }
    }
  main();
  rn_ch:
  printf("\n ENTER THE EMAIL : ");
  scanf("%s",check_email);
  printf("\n ENTER THE PASSWORD : ");
  scanf("%s",check_psd);
  int f =0;
  for(int i=0;i<=100;i++)
    {
     if(strcmp(U[i].email,check_email)==0&&strcmp(U[i].psd,check_psd)==0)
     {
      printf("\n EMAIL FOUND");
      f =1;
      int ran_num = rand() % 100000 + 1;
      printf("\n THE ONE TIME PASSWORD IS : %d",ran_num); 
      int us_num;
      printf("\n ENTER THE ONE TIME PASSWORD TO VERIFY : ");
      scanf("%d",&us_num);
      if(ran_num == us_num)
      {
      printf("\n ACCOUNT IS VERFIED");
      printf("\n YOUR CURRENT REGISTER NO IS : %d",U[i].reg_no);
      login_page();
      }
     }
    }
  if(f==0)
     {
      printf("\n ACCOUNT IS UNVERIFIED");
      printf("\n 1 EXIT TO MENU");
      printf("\n 2 TRY AGAIN");
      printf("\n 3 LOGIN AGAIN");
      int ch_psd;
      printf("\n ENTER THE CHOICE : ");
      scanf("%d",&ch_psd);
      switch(ch_psd)
        {
          case 1:
          main();
          break;
          case 2:
          goto psd_ch;
          break;
          case 3:
          login_page();
          break;
          default:
          printf("\n ENTER THE CORRECT CHOICE ");
          main();
          break;
        }
      }  
  main();
  return 0;
}
int job_page()
{
  FILE *File1;
  File1 = fopen("File1.txt","a");
  int a;
  printf("\n 1 POST JOB");
  printf("\n 2 EXIT TO MAIN PAGE");
  printf("\n ENTER THE CHOICE : ");
  scanf("%d",&a);
  switch(a)
    {
      case 1:
      goto post;
      break;
      case 2:
      main();
      default:
      printf("\n ENTER THE CORRECT CHOICE ");
      job_page();
      break;
    }
  post:
  printf("\n ENTER THE JOB NAME : ");
  scanf("%s",J.name);
  printf(" ENTER THE JOB TYPE : ");
  scanf("%s",J.type);
  printf(" ENTER THE JOB TIMING : ");
  scanf("%d",&J.time);
  printf(" ENTER THE JOB LOCATION : ");
  scanf("%s",J.location);
  printf(" ENTER THE JOB EXPERIENCE REQUIRED : ");
  scanf("%d",&J.experience);
  printf(" ENTER THE JOB REQUIREMENT : ");
  scanf("%s",J.requirement);
  printf(" ENTER THE JOB DESCRIPTION : ");
  scanf("%s",J.description);
  printf(" ENTER THE JOB SALARY : ");
  scanf("%d",&J.salary);
  printf("\n THANK YOU FOR ENTERING THE DETAILS");
  fwrite(&J,sizeof(struct Job),1,File1);
  printf("\n THE ENTERED DATA HAS BEEN STORED");
  fclose(File1);
  main();
  return 0;
}
int job_taker()
{
  int a;
  FILE *File1;
  File1 = fopen("File1.txt","r");
  if(fread(&J,sizeof(struct Job),1,File1) == NULL)
  {
    printf("\n NO JOBS FOUND");
  }
  else
  {
    while(fread(&J,sizeof(struct Job),1,File1) != NULL)
      {
        printf("\n THE JOB NAME IS        : %s",J.name);
        printf("\n THE JOB TYPE IS        : %s",J.type);
        printf("\n THE JOB TIME IS        : %d",J.time);
        printf("\n THE JOB LOCATION IS    : %s",J.location);
        printf("\n THE JOB EXPERIENCE IS  : %d",J.experience);
        printf("\n THE JOB REQUIREMENT IS : %s",J.requirement);
        printf("\n THE JOB DESCRIPTION IS : %s",J.description);
        printf("\n THE JOB SALARY IS      : %d",J.salary);
      }
    printf("\n ENTER THE REGISTER NUMBER : ");
    scanf("%d",&a);
    printf("\n ENTER THE JOB YOU WANT TO ENTER : ");
    scanf("%s",U[a].jname);
    printf("\n THE RECORD HAS BEEN SAVED. JOB HOLDER WILL CONTACT YOU SOON ");
    printf("\n");
  }
  main();
  return 0;
}
int view_fun()
{
  int a;
  printf("\n ENTER THE REGISTER NUMBER : ");
  scanf("%d",&a);
  printf("\n THE NAME OF THE USER IS        : %s",U[a].name);
  printf("\n THE EMAIL OF THE USER IS       : %s",U[a].email);
  printf("\n THE AGE OF THE USER IS         : %d",U[a].age);
  printf("\n THE GENDER OF THE USER IS      : %s",U[a].gender);  
  printf("\n THE PASSWORD OF THE USER IS    : %s",U[a].psd);
  printf("\n THE REGISTER NO OF THE USER IS : %d",U[a].reg_no);
  main();
  return 0;
}



