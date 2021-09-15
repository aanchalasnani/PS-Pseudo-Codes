#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
}*first;

void display ( struct node *z) {
	
	while(z!=NULL) {
		printf("%d   ",z->data);
		z = z->next ;
	}
}


void create(int n) {
	
	struct node * temp ;
	struct node *last ;
	int item , i;
	
	first = (struct node*)malloc(sizeof(struct node));
	//printf("enter the data ==>  ");
	scanf("%d",&item);
	first->data = item ;
	first -> next = NULL ;
	last = first ;
	
	for(i=0;i<n-1; i++){
		//printf("enter the data ==>  ");
		scanf("%d",&item);
		temp = (struct node *) malloc(sizeof(struct node));
		temp->data = item ;
		temp->next = NULL ;
		
		last -> next = temp ;
		last = temp ;
	}
}

// void delete_node()
// {
// 	struct node *p;
// 	struct node *q;
// 	int index , i,x ;
// 	printf("from where to delete ===>  ");
// 	scanf("%d",&index);
// 	p=first;
// 	q = NULL;
// 	if(index == 1) {
		
// 		first = first->next;
// 		x=p->data;
// 		free(p);
		
// 	}
// 	else {
	
// 	for(i=0;i<index-1;i++)
// 	{
// 		q=p;
// 		p=p->next;
// 	}
// 	q->next = p->next;
// 	x = p->data;
// 	free(p);
// 	printf("\ndeleted value ===> %d\n",x);
// }

void delete_n() {
	struct node *ptr;
	ptr=first;

	while(ptr->next!=NULL) {
		ptr=ptr->next;
		if(ptr->next->next==NULL) {
			
		}
	}
	free(ptr);

	//ptr->next=NULL;
}
	


void reversing_elements(int z) {
	
	struct node *p=first;
	int n = z;
	int i=0,a[n];
	while(p!=NULL){
		
		a[i] = p->data;
		p=p->next;
		i++;
	}
	i--;
	p = first;
	while(p!=NULL){
		p->data = a[i];
		i--;
		p=p->next;
	}
}

void reverse_links()
{
	struct node *p,*r,*q;
	p=first;
	r=NULL;
	q=NULL;
	while(p!=NULL) {
		r=q;
		q=p;
		p=p->next;
		q->next = r;
	}
	first= q;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	//printf("how many nodes u want ==>  ");
	scanf("%d",&n);
	create(n);
//	reverse_links();
//	reversing_elements(n);
	delete_n();
	display(first);
	
}













