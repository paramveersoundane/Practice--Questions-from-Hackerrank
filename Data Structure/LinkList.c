#include <stdio.h>
#include <stdlib.h>

struct node{
   int data;
   struct node *next;
};
typedef struct node node;

void printList(node*);
void push(node**,int);
void insert(node **,int );
void append(node **,int );
void deleteNode(node *,int);
int getCount(struct node*);
int GetNth(struct node*, int);
int getMiddle(node *);
void DeleteLink_List(node **);
node *reverse(node *);
int getNthFromLast(node *, int);
int count(struct node* head, int x);
void swapNodes(struct node **head_ref, int x, int y);
int detectloop(node *head);
void MergeSort(node **headRef);
node *Merge(node *front,node *back);
void splitList(node *head,node **front,node **back);

int main(){
   node *head;
   node *second;
   node *third;

   head=(node*)malloc(sizeof(node));
   second=(node*)malloc(sizeof(node));
   third=(node*)malloc(sizeof(node));
   head->data=1;
   head->next=second;

   second->data=2;
   second->next=third;

   third->data=3;
   third->next=NULL;
   push(&head,4);
   push(&head,5);
   push(&head,8);
   push(&head,7);
   insert(&(head->next),98);
   append(&head,79);

   printList(head);
    printf("\n count of link-list is %d \n",getCount(head));
    printf("\n middle node is %d \n",getMiddle(head));
   deleteNode(head,3);
   printf("\n");
   printList(head);
   printf("\n count of link-list is %d \n",getCount(head));
   printf("\n data at 6th node is %d \n",GetNth(head,6));
   printf("\n last nth node is %d \n",getNthFromLast(head,6));
   printf("\n middle node is %d \n",getMiddle(head));
   head=reverse(head);// important part note: head should be reassigned
   printList( head);
   printf("\n last 6th node is %d \n",getNthFromLast(head,6));
   printf("\n count of 3 is %d \n",count(head,3));
   printf("\n swapping nodes\n");
   swapNodes(&head,3,5);
   printList(head);
   printf("\n if there is loop then 1 if not then 0, so the ans is %d\n",detectloop(head));
   MergeSort(&head);
   printList(head);

   return 0;
}
// Print the link list
void printList(node *p){
    while(p!=NULL){
        printf("%d ",p->data);

        if(p->next!=NULL){
            printf("->");
        }

        p=p->next;
    }
}
// Function for inserting node at the front
void push(node **p,int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=*p;
    *p=newnode;
}
void insert(node **p,int x){  // no need to take argument as pointer of pointer-> (wrong)//
    if (*p == NULL)
    {
       printf("the given previous node cannot be NULL");
       return;
    }
    struct node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=(*p)->next;
    (*p)->next=newnode;
}
void append(node **p,int x){

  node *newnode=(node*)malloc(sizeof(node)); //allocate node
  node *q = *p;
  newnode->data=x;  // put in data
   newnode->next=NULL; // set NULL
  /* 4. If the Linked List is empty, then make the new node as head */
  if (*p == NULL)
    {
       *p = newnode;
       return;
    }
    // traversing till last node
  while((q->next)!=NULL){
        q=q->next;
  }

  q->next=newnode;

}
// function for deleting node at any position
void deleteNode(node *head,int x){
    int i=1;
    node *p=head,*q;
    if(x==1){
         head=p->next;
         free(p);
    }
    else{
        while(p!=NULL && i<x){
            i++;
            q=p;
            p=p->next;
        }
        if(p==NULL){
            printf("Position does'nt exist");
            }
            else{
                q->next=p->next;
                free(p);
            }
        }
}
// function to get a count of link-list
int getCount(struct node* head){
  int count=0;
  struct node *p=head;
  while(p!=NULL){
      count++;
      p=p->next;
  }
  return count;
}
// Node at a given index in linked list (Function Problem)
int GetNth(struct node* head, int index){
  int i=1; // numbering of first node is 1 instead of 0
  struct node *p=head;
  while(p!=NULL && i<index){
      i++;
      p=p->next;
  }
  return (p->data); // returns value at node
}
//Finding middle element in a linked list (Function Problem)
int getMiddle(node *head){
    int i=0,j=1;
   struct node *p=head;
   if(head==NULL)
      return -1;
   while(p!=NULL){
       i++;
       p=p->next;
   }
   p=head;
   if(i%2 != 0){
       while(j<(i/2+1)){
           j++;
           p=p->next;
       }
       return (p->data);
   }
   else{
       while(j<(i/2 + 1)){
           j++;
           p=p->next;
       }
       return (p->data);

   }
}
//Delete whole link-list
void DeleteLink_List(node **p){
    node *iterator=*p,*dummy;
    while(iterator){
        dummy=iterator->next; // p stores head.
        free(iterator);
        iterator=dummy;
    }
    *p=NULL;
}
// Reverse the link-list
node* reverse(node *head){


  int count=1;
  node *p,*i,*dummy;
  p=head;
  dummy=p->next;
  p->next=NULL;
  p=dummy;
  i=head;
  while(p!=NULL){
      dummy=dummy->next;
      p->next=i;
      i=p;
      p=dummy;
  }

  return i;
}

int getNthFromLast(node *head, int n){

    if(n>getCount(head)){  return -1; }

   return (GetNth(head,getCount(head)-n+1));

}
//Occurence of an integer in a Linked List (Function Problem)
int count(struct node* head, int x){

    int counter=0;
    struct node *p=head;

    while(p!=NULL){

        if(p->data==x){

            counter++;
        }
        p=p->next;
    }
    return counter;

}

void swapNodes(struct node **head_ref, int x, int y){
   // Nothing to do if x and y are same
   if (x == y) return;

   // Search for x (keep track of prevX and CurrX
   struct node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->next;
   }

   // Search for y (keep track of prevY and CurrY
   struct node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->data != y)
   {
       prevY = currY;
       currY = currY->next;
   }

   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;

   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       *head_ref = currY;

   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currX;
   else  // Else make x as new head
       *head_ref = currX;

   // Swap next pointers
   struct node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}

int detectloop(node *head){
   node *first=head,*second=head;
   while(first &&  second && second->next){
       first=first->next;
       second=second->next->next;
       if(first == second){
           return 1;
       }

   }
    return 0;
}

void MergeSort(node **headRef){
    node *a,*b,*head=*headRef;
     if(head==NULL && head->next==NULL){
        return;
     }
     splitList(head,&a,&b);
     MergeSort(&a);
     MergeSort(&b);
     *headRef=Merge(a,b);

}
void splitList(node *head,node **front,node **back){
    node *sp,*fp;
    if(head->next==NULL && head==NULL){
        *front=head;
        *back=NULL;
    }
    else{
        sp=head;
        fp=head->next;
        while(fp!=NULL){
            fp=fp->next;
            if(fp!=NULL){
                sp=sp->next;
                fp=fp->next;
            }
        }
    }
    *front=head;
    *back=sp->next;
    sp->next=NULL;
}
node *Merge(node *front,node *back){
    node *result;
    if(front==NULL){
        return back;
    }
    else if(back==NULL){
        return front;
    }
    else if(front->data <= back->data){
        result = front;
        result->next=Merge(front->next,back);
    }
    else{
        result = back;
        result->next=Merge(front,back->next);
    }
    return result;

}
