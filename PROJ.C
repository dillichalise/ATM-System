#include<stdio.h>
#include<conio.h>
#include<string.h>

struct atm
	{      	long int acc,amt;
		char name[50];
		int pin;
	}user[5]={{71010,10000,"Anup Pandey",1234},{71020,25000,"Bidur Nepali",4567},{71026,15000,"Dilli Raj Chalise",1000},{71041,20000,"Nikesh Bhattrai",2000}};


void inquiry(struct atm user[],int j)
{
	printf("your available balance is %d",user[j].amt);
	}

void withdraw(struct atm user[],int j)
{      int wamt;
	char more; withdraw:
	printf("\nEnter the amount you want to withdraw.(Multiple of 500)\t");
	scanf("%d",&wamt);
	if (wamt<user[j].amt&&wamt%500==0)
		{	 printf("Please collect your cash\a\a\a\a");
			 user[j].amt=user[j].amt-wamt;
		}
	else if (wamt%500!=0)
	       {	printf("Enter multiple of 500\n");
			goto withdraw;	}
	else
	       {	printf("Insufficient balance\t\a");
		printf("try more? (y/n)");
		more=getche();
		if(more=='y')
			goto withdraw;}
}

void fastcash(struct atm user[],int j)
{ 	int a;
	char more;
	fastcsh:
	printf("\nENTER CHOICE\n");
	printf(" 1.500 \t 2.1000\n 3.2000 \t 4.5000 \n");
	scanf("%d",&a);
	switch(a)
		{ case 1:
		       {	if(user[j].amt>500)
			      {	printf("Please collect cash\n\a\a\a");
				user[j].amt=user[j].amt-500;}
			else
				printf("insufficient balance\n");
			break;  }
		case 2:
		      {	if(user[j].amt>1000)
			      {	printf("Please collect cash\n\a\a\a");
				user[j].amt=user[j].amt-1000;}
			else
				printf("insufficient balance");
			break;    }
		case 3:
		      {	if(user[j].amt>2000)
			      {	printf("Please collect cash\n\a\a\a");
				user[j].amt=user[j].amt-2000;}
			else
				printf("insufficient balance");
			break;   }
		case 4:
		      {	if(user[j].amt>5000)
			      {	printf("Please collect cash\n\a\a\a");
				user[j].amt=user[j].amt-5000;}
			else
				printf("insufficient balance");
			break;   }
		default:
		      {	printf("\nInvalid choice\n");
			printf("Try more? (y/n)");
			more=getche();
			if(more=='y')
				goto fastcsh;}
	       }
}



void pin_change(struct atm user[],int j)
{	int ipin;
	printf("enter your old pin\t");
	scanf("%d",&ipin);
	if(user[j].pin==ipin)
		{	printf("enter new pin\t");
			scanf("%d",&ipin);
			if(ipin<=9999 && ipin>=1000)
			       {	printf("pin changed");
				user[j].pin=ipin;}
			else
				printf("\npin must be of four digits greater than 999 and less than 9999");
			}
	else
		printf("invalid pin");      }


void main()
{ 	long int ac;
	int choic,i,inpin,j,str;
	char more;
	clrscr();
	printf("   |||||||||      ||||||||||     |||||||||||||||\n  ");
	printf(" ||      ||     ||      ||            ||      \n  ");
	printf(" ||      ||     ||                    ||      \n  ");
	printf(" ||      ||     ||                    ||      \n  ");
	printf(" ||      ||     ||                    ||      \n  ");
	printf(" |||||||||      ||                    ||      \n  ");
	printf(" ||      ||     ||                    ||      \n  ");
	printf(" ||      ||     ||                    ||      \n  ");
	printf(" ||      ||     ||                    ||      \n  ");
	printf(" ||      ||     ||      ||            ||      \n  ");
	printf(" |||||||||       |||||||||            ||      \n  ");

	printf("\n\n**********************WELCOME TO BCT BANK**********************\n");
	printf("\t\t\tKALIMATI BRANCH\n\n\n");  top:
	printf("\nEnter your user acount number:\t");
	scanf("%ld",&ac);
	for (i=0;i<=3;i++)
		{ if(ac==user[i].acc)
		       {	printf("welcome %s\n",user[i].name);

			   j=i; break;
			}
		  else if(i==3)
			{	printf("Sorry you do not have account in our bank.\a\n");
				printf(" Try once more? (y/n)");
				more=getche();
					if(more=='y')
						goto top;
					else if (more!='y')
						goto finish;
			}
		  }   pin1:
		printf("enter your pin:");
		scanf("%d",&inpin);
		if(user[j].pin==inpin)
				{	choice1:
				printf("\nINPUT YOUR CHOICE\n");
				printf("1.Cash Withdrawl\t 2.Balance inquiry\n 3.Fast cash\t 4.Pin change\n 5.Cancel transaction\n\n");
				scanf("%d",&choic);
					switch(choic)
						{
							case 1:
								withdraw (user,j) ;
								  break;
							case 2:
								{ inquiry(user,j) ;
								   break;}
							case 3:
								{ fastcash(user,j) ;
								break;}
							case 4:
								{ pin_change(user,j) ;
								break;}
							case 5:
								goto finish;
							default:
								{  printf("Invalid choice.Try more (y/n)");
								   more=getche();
									if(more=='y')
										goto choice1;
									else
										goto finish;     }
						}
				}
		else
		       {	printf("\tInvalid pin\n \n\tTry more? (y/n)");
			more=getche();
			if (more=='y')
				goto pin1;
			else
				goto finish;  }


	      printf("\nany more transaction? (y/n)");
	      more=getche();
		if(more=='y')
			goto choice1;
		else
			goto finish;


finish:
printf("\n***************Thank you for using our service***************");
getch();
}









