#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *llink,*rlink;
};
typedef struct node *NODE;
NODE head=NULL;
void CreateList(int val)
{
    NODE nd;
    if(head==NULL){
        nd=(NODE)malloc(sizeof(struct node));
        nd->llink=nd->rlink=NULL;
        nd->val=val;
        head=nd;
    }
    else{
        printf("List is already created\n");
    }
}
void insertIntoList(int before, int val)
{
NODE nd, newnd;
nd=head;
while (nd != NULL && nd->val != before)
nd = nd->rlink;
if (nd != NULL) {
newnd = (NODE)malloc(sizeof(struct node));
newnd->llink = newnd->rlink = NULL;
newnd->val = val;
if (nd->llink != NULL) {
nd->llink->rlink = newnd;
newnd->llink = nd->llink;
newnd->rlink = nd;
nd->llink = newnd;
}
else {
newnd->rlink = nd;
nd->llink = newnd;
head=newnd;
}
}
else
printf( "Unable to insert, node with value %d not found", val);
}
void deleteAll(int delVal)
{NODE nd,nxtNode;
nd = head;
while (nd != NULL) {
if (nd->val == delVal) {
if (nd->llink != NULL) {
nd-> llink ->rlink = nd -> rlink;
if (nd->rlink != NULL) {
nd->rlink->llink = nd->llink;
nxtNode = nd->rlink;
free(nd);
nd = nxtNode;
}
else {
nd->llink->rlink = NULL;
free(nd);
nd=NULL;
}
}
else {
if (nd->rlink != NULL) {
nd ->rlink->llink = NULL;
head = nd->rlink;
free(nd);
nd = head;
}
else {
free(nd);
head = nd = NULL;
}
}
}
else
nd = nd->rlink;
}
}
void searchNode(int searchVal) {
NODE nd;
nd=head;
while (nd != NULL) {
if (nd->val == searchVal)
printf( "Node is found with key %d\n", searchVal);
nd = nd->rlink;
}
}
void displayAll()
{
NODE nd;
nd = head;
while (nd != NULL) {
printf("Node with val %d\n", nd->val);
nd = nd->rlink;
}
}
int main() {
int choice, val,before;
do {
printf("1. Create List\n");
printf("2. Insert into List\n");
printf("3. Delete all by value\n");
printf("4. Search by value\n");
printf("5. Display all\n");
printf("6. Exit\n");
printf("Enter your choice :");
scanf("%d", &choice);
switch(choice) {
case 1: printf("Please enter the node value");
scanf("%d", &val);
CreateList(val);
break;
case 2: printf("Please enter the node value to insert ");
scanf("%d", &val);
printf("Please enter the node value before which new
node has to be inserted ");
scanf("%d", &before);
insertIntoList(before, val);
break;
case 3:printf("Enter the node value to be deleted ");
scanf("%d", &val);
deleteAll(val);
break;
case 4:printf("Enter the node value to be searched ");
scanf("%d", &val);
searchNode(val);
break;
case 5:displayAll();
break;
case 6:
break;
default:printf("Invalid choice ");
break;
}
}while(choice != 6);
return 0;
}g