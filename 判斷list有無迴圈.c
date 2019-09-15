#include <stdio.h>
#include <stdlib.h>

struct _node { 
     
    int data; 
    struct _node *next; 
    }; 
    typedef struct _node node; 

node* CreateListWithCycle(int n1, int n2){
    int i;
    node *head, *ptr,*start_for_cycle; 
    head = (node *)malloc(sizeof(node)); 
    ptr = head;
    for( i =1;i<=n1;i++){
        ptr->data = i;
        ptr->next = (node *)malloc(sizeof(node)); 
        if(i ==n1)
            start_for_cycle = ptr;
        ptr = ptr->next;
    }
    
    for(i = n1+1;i<n1+n2;i++){
        ptr->data = i;
        if(i!=n1+n2-1){
        
        ptr->next = (node *)malloc(sizeof(node)); 
        ptr = ptr->next;
        }
        ptr->next = start_for_cycle;

    }
    
    return head;
    

    
    
}
node* CreateListWithoutCycle(int n1){
    int i;
    node *head,*ptr; 
    head = (node *)malloc(sizeof(node)); 
    ptr = head;
    for( i =1;i<=n1;i++){
        ptr->data = i;
        if(i==n1){
          ptr->next =NULL;
          return head;
        }
        ptr->next = (node *)malloc(sizeof(node));

        ptr = ptr->next;
    }

}
    
int HasCycle(node* head){
    int i;
    node *pslow,*pFast,*meet;
    
    pslow = head;
    pFast = head;
    
    for(i=1;;i++){
        pslow = pslow->next;
        pFast = pFast->next->next;
      //  if(2*i>(n1+n2)){
            if(pFast ==NULL)
              return 0;
            
            if(pFast ==pslow)
            	return 1;
    }
          		 	
}
	 
          		 
              
              
              
            
     //   }



int CycleLength(node* head){
	 int i,j;
    node *pslow,*pFast,*meet;
    
    pslow = head;
    pFast = head;
    
    for(i=1;;i++){
        pslow = pslow->next;
        pFast = pFast->next->next;
      //  if(2*i>(n1+n2)){
        if(pFast ==pslow){
        	meet = pFast;
        
        	for(j=1;;j++){
          		pslow = pslow->next;
          		if(pslow == meet)
          		 	return j;
    		}
    	}
          		 	
          		 	
	 }
	
}
 

          



int main(){
    int list_without_cycle;
    int list_add_cycle;
    node* headforlist;
//    scanf(" %d",list_without_cycle);
    list_without_cycle = 4;
//    scanf(" %d",list_add_cycle);
    list_add_cycle = 6;
//  CreateListWithCycle(list_without_cycle,list_add_cycle);
//	printf("%d\n", HasCycle(CreateListWithCycle(list_without_cycle,list_add_cycle))); 
 // printf("%d\n",HasCycle(CreateListWithoutCycle(10)));
 headforlist = CreateListWithCycle(list_without_cycle,list_add_cycle);
 if( HasCycle(headforlist) ==1){
 	printf("Cycle length = %d\n",CycleLength(headforlist));
 	
 	
 }
    
    
        
        
    
    
    
    
    
    
    
    
    
    return 0;
}
