#include <stdio.h>
#include <stdlib.h>

struct bank {
  float money;
  struct bank *newptr;
};
typedef struct bank Bank;
typedef Bank *newptr;


void insert(newptr *ptr,float money);
float deletee(newptr *newp, float money);
void print(newptr p);

int main(void) {
 
newptr newp= NULL ;
 float money ;

 int choice;
 printf("enter your choice \n 1-insert \n 2-delete \n 3-end\n");
 scanf("%d",&choice);

 while(choice != 3){

   switch(choice){
     case 1 :
     printf("enter a value of money: ");
     scanf("%f",&money);
     insert(&newp,money);
     print(newp);
     break;

    case 2:
     if(newp!= NULL){
       printf("enter a character to be deleted: ");
       scanf("%f",&money);
       if(deletee(&newp,money)){
         printf("deleted!");
         print(newp);
       }
       else{
         printf("person is not found!");
       }
     }
     else{
       puts("list is empty!");
     }
   break;
   }
printf ("%s","?");
scanf("%d",&choice);
}
puts("end of run");

 }
 


void insert(newptr *ptr,float money) {
  newptr newp;
  newptr previous;
  newptr current;

  newp=malloc(sizeof(newptr));
  if(newp != NULL){
    newp->money=money;
    newp->newptr=NULL;
    previous=NULL;
    current=newp;
  
  while(current!=NULL && money> current->money){
    previous=current;
    current=current->newptr;
  }
  if (previous==NULL){
    newp->newptr=*ptr;
    *ptr=newp;
     }
  else{
    previous->newptr=newp;
    newp->newptr=current;
  }   
  }
else{
  printf("not inserted!");
}
}

 float deletee(newptr *newp, float money){
   newptr previous;
   newptr current;
   newptr temp;
   if(money== (*newp)->money){
     temp=*newp;
     *newp=(*newp)->newptr;
     free(temp);
     return money;
   }
   else{
     previous=*newp;
     current=(*newp)->newptr;
  
      while(current != NULL && current->money !=money){
        previous=current;
        current=current->newptr;
      }
      if(current !=NULL){
        temp=current;
        previous->newptr=current->newptr;
        free(temp);
        return money;
      }
   }
   return '\0';
 }
 void print(newptr p)
 {
  if(p==NULL){
    printf("list is empty");
  }
  else{
     puts("list is:");

     while(p!=NULL){
       printf("%f-->",p->money);
       p=p->newptr;
     }

     puts("NULL\n");
  }
    
   

 }
