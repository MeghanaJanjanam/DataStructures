# include <stdio.h>

struct DNode{
	int data;
	struct DNode *next;
	struct DNode *prev;	
};

typedef struct DNode* pdnode;
typedef struct DNode dnode;

pdnode getDNode(int d){
	pdnode p;
	p = (pdnode)malloc(sizeof(dnode));
	if(p==NULL){
		printf("Memorry allocation problem");
		return;
	}
	p->data = d;
	p->next = p->prev = NULL;
	return p;
}

pdnode createList(int n){
	int i, d;
	pdnode p, list=NULL;
	
	if(n>0){
		printf("Enter First Data Item: ");
		scanf("%d", &d);
		list = getDNode(d);
	}
	
	for(i=1; i<n; i++){
		printf("Enter Data Item: ");
		scanf("%d", &d);
		p = getDNode(d);
		p->next = list;
		list->prev = p;	
		list = p;
	}
	
	return list;
}

void fdisplay(pdnode dlist){
	printf("\nForward Display: ");
	if(dlist == NULL){
		printf("List empty ...");
		return;
	}
	while(dlist!=NULL){
		printf("%d ", dlist->data);
		dlist = dlist->next;
	}	
}

void bdisplay(pdnode dlist){
	printf("\nBackward Display: ");
	if(dlist == NULL){
		printf("List empty ...");
		return;
	}
	while(dlist->next != NULL){
		dlist = dlist->next;
	}
	
	while(dlist!=NULL){
		printf("%d ", dlist->data);
		dlist = dlist->prev;
	}	
		
}

pdnode insertFront(pdnode list, int d){
	pdnode p;
	p = getDNode(d);
	if(list==NULL)
		list = p;
	else{
		list->prev = p;
		p->next = list;
		list = p;	
	}
	return list;	
}

pdnode insertRare(pdnode list, int d){
	pdnode p, q;
	
	p = getDNode(d);
	
	if(list == NULL){
		return p;			
	}	

	for(q=list; q->next!=NULL; q=q->next);
	
	q->next= p;
	p->prev = q;
	
	return list;	
}
main(){
	int n, d, k, opt;
	pdnode dlist = NULL;
	
	
	while(1){
		printf("\n1. Create list\n2. Display Forward\n3. Display Backward");
		printf("\n4. Insert Front\n5. Insert Rare\n6. Insert after");
		printf("\n7. Delete a Node\n8. Delete List");
		printf("\n10. Exit");
		printf("\nEnter your option: ");
		scanf("%d", &opt);
		switch(opt){
			case 1: printf("Enter number of nodes: ");
	 				scanf("%d", &n);
					dlist = createList(n);
					break;
			
			case 2: fdisplay(dlist);
					break;
			
			case 3: bdisplay(dlist);
					break;
					
			case 4: printf("Enter data: ");
	 				scanf("%d", &d);
					dlist = insertFront(dlist, d);
					break;
					
			case 5: printf("Enter data: ");
	 				scanf("%d", &d);
					dlist = insertRare(dlist, d);
					break;
					
			case 10: return;
			
			default: printf("Invalid option");
		}

	}	
}