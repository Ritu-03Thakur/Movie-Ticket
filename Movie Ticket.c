#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCTURE
typedef struct{
        char showname[20];
        char date[12];
        char time[6];
        char gate[2];
}Show;
Show show={"GNIT FILES","15-02-2022","20:30","7"};

typedef struct{
        char name[30];
        char booking_ID[3];
        int seats;
}Seat;
Seat choice[20];  

void displaymenu();
void booking();
void cancel();
void seat();
void ticket();
void records();
void menudriven();
void exit_();
        
//Variables
int selection;  
int i;
int j;
int seats_num[20]={0};
int booking_ID=100;
int seatsAvailable=20;



int main()
{

        displaymenu();
        
        
        while(selection!=5)
        {
                menudriven();
        }
        
        return 0;
        
}
                
        void displaymenu()
        
		{
			
        printf("\n");
        printf("\t \xdbMOVIE BOOKING CENTER\xdb\n"
                  "\t=======================\n"
                  "\t    GN GROUPS CINEMA   \n"
                  "\t=======================\n"
                  "\n\t1> TICKET BOOKING    \n"
                  "\n\t2> CANCEL YOUR TICKET\n"
                  "\n\t3> AVAILABLE SEATS   \n"
                  "\n\t4> SHOW LAST BOOKING \n"
                  "\n\t5> EXIT PROGRAM    \n\n");

        printf("\tEnter your selection : ");
        scanf("%d",&selection);
        menudriven();
        return;
        }

        //menudriven()
        void menudriven()
        {       
        switch(selection)
                {
                case 1:
                        booking();
                        break;
                        
                case 2: 
                        cancel();
                        break;        
                case 3:
                        seat();
                        break;
                case 4:
                        records();
                        break;
                case 5:
                        exit_();
                        break;
                default:
                printf("\tInvalid selecion.Try again\n");
                displaymenu();
        }
        return;
        }
        
        //booking       
        void booking()
        {
                for(i=1;i<=20;i++)
                {                       
                printf("\n\tPlease enter number of seats  : ");
                scanf("%d",&choice[i].seats);
                
                if(choice[i].seats<=seatsAvailable){
                        printf("\tPlease enter customer name : ");
                        scanf("%s",choice[i].name);
                        booking_ID++;
                        seatsAvailable=seatsAvailable-choice[i].seats;
                        ticket();
                        displaymenu();
                }
                else if (seatsAvailable<0)
                {
                        printf("\n");
                        printf("\tSORRY, The Show Is Fully Booked\n");
                        printf("\t=================END=================\n\n");
                        displaymenu();
                }
                
                else if(choice[i].seats>seatsAvailable)
                       {
                                printf("\n");
                                printf("\tThe show leave %d seats\n",seatsAvailable);
                                displaymenu();
                        }
                }
        return;
        }
        
        void ticket()
        {
        printf("\n\n");
        
        printf("\t*********************** THEATER BOOKED SEATS **********************\n");
        printf("\t===================================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : %s\n",booking_ID,show.showname);
        printf("\t Customer  : %s\n",choice[i].name);
        printf("\t\t\t                              Date      : %s\n",show.date);
        printf("\t                                              Time      : %s\n",__TIME__);
        printf("\t                                              Hall      : %s\n",show.gate);
        printf("\t                                              Seats No. : %d%c  \n\n",i+1);
        printf("\t====================================================================\n");
        return;
        }

        
        // cancel
         void cancel()
         {
              char cancelcustomername[80];
              printf("Enter customer name to be cancel:");
              scanf("%s",cancelcustomername);
              for(int i=1; i<=50 ; i++)
              {
        
                          if (strcmp(choice[i].name , cancelcustomername) == 0)
                          {
                                         //seats_num++;
                                         choice[i].seats = 0 ;
                                         ticket();
                                         printf("\n            ==========  THIS RESERVATION HAS BEEN CANCELLED   ==========\n");
                                         displaymenu();
                                         return ;
                          }
                      
              }
          }
        //seat
        void seat()
        {       
                printf("  A   B   C       D     E\n");
                for(j=0;j<5;j++)
                {
                printf("%d  ",booking_ID); 
                }
                for(i=0;i<4;i++)
                {
                        printf("\n");
                        printf("%d\n",i+1);
                }
                displaymenu();
        }

        void records()   //For Staff to View the Show's records
        {
                printf("\t====================================\n");
                printf("\tDISPLAYING ALL RECORDS\n");  
                printf("\t====================================\n");
                printf("\tSeats Available left : %d \n",seatsAvailable);
                ticket();
                displaymenu();
                      
        return;
        }

        void exit_()
        {
        printf("\tThank you for using this system by janhvi\n");
        exit(1);
        return;
        }
        
        
        
        
    
        