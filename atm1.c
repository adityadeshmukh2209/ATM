//atm 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX_SIZE 200
int main()
{       
        int balance=0;
        int pin =1231;
        int tempin;//pin the user will enter
        int anothertransaction;//for performing another transaction
	int option;
	int amtwithdraw;
	int amtdeposit;
        printf("PLEASE ENTER YOUR PIN:\n");
        scanf("%d",& tempin);

        
        if (tempin!=1231) //if pin is not equal to 1231
        {
            printf("INVALID PIN\n");
            return 0;
        } 
       do//entering it in loop so we can reuse it
       
        {
           
            printf("********Welcome to ATM Service**********\n");
            printf("WHAT DO YOU WANT TO DO ? \n");
            printf("1-CHECK YOUR BALANCE\n");
            printf("2-DEPOSIT\n");
            printf("3-WITHDRAW\n");
            printf("4-QUIT\n");
            printf("****************************************\n\n");
            scanf("%d",&option); //if=scanf
        
            
            if( option == 1) //check balance
        {
            printf("YOUR BALANCE IS: %d\n",balance);
        }
        else if( option == 2)//deposit
        {
            
            printf("HOW MUCH AMOUNT DO YOU WANT TO DEPOSIT:");
            scanf("%d",& amtdeposit);
            
        
        if (amtdeposit>0)
        {
            balance+=amtdeposit;//balance+deposite
            printf("YOUR BALANCE IS %d\n", balance);
        }
        else
        {
            printf("INVALID DEPOSIT AMOUNT!!\n");                                                                                            
        }
        }
        else if(option == 3)//3-withdraw
        {
           
            printf("HOW MUCH AMOUNT DO YOU WANT TO WITHDRAW:");
            scanf("%d",& amtwithdraw);
            
            
            if(amtwithdraw<=balance)
            {
                balance-=amtwithdraw;
                printf("\n\n PLEASE COLLECT CASH");

    	     	printf("\n YOUR CURRENT BALANCE IS %d", balance);
            }
            else
            {
                printf("SORRY BUT YOU DONT HAVE ENOUGH MONEY\n TRANSACTION DECLINED!!!\n");
                
            }
            
        }
        else if (option==4)
        {
        		printf("\n THANK FOR USING OUR ATM SERVICE");
        		break;
     	}
		    else 
            {
                printf("INVALID TRANSACTION\n");
            }
            
            anothertransaction=0;
            
            
            while (anothertransaction!=1 &&anothertransaction!=2)
            {
                printf("\nDO YOU WANT ANOTHER TRANSACTION:\n");
                printf("1-YES\n2-NO\n");
                scanf("%d",&anothertransaction);
                if(anothertransaction==2)
		{
		time_t t=time(NULL);
		struct tm tm=*localtime(&t);
		printf("YOUR TRANSACTION WAS RECORDED ON:%d-%02d-%02d %02d:%02d:%02d %02d\nTHANK YOU FOR USING OUR ATM SERVICE!!!\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900,tm.tm_hour,tm.tm_min,tm.tm_sec,tm.tm_isdst);
			FILE *f1;
			f1=fopen("transaction.txt","w");
			fprintf(f1,"YOU HAVE WITHDRAWED %d AND DEPOSITED %d ON %d-%02d-%02d %02d:%02d:%02d\n",amtwithdraw,amtdeposit,tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900,tm.tm_hour,tm.tm_min,tm.tm_sec);
			fclose(f1);	}		//to store option amtwithdraw amtdeposited and date of transaction
	    
                  
                
					  
            }
        }
        
        while(anothertransaction==1);
        
        
        
        return 0;
}
            
