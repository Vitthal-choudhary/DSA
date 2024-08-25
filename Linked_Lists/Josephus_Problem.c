#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int info;
	struct Node *link;
};

struct Node *ptr, *tail, *newNode, *save;
int N;

void create(){
    int count=1;
	printf("enter Number of Players ");
	scanf("%d", &N);
	ptr = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter Info for player 1 ");
	scanf("%d", &ptr->info);
	ptr->link = NULL;
	tail = ptr;
	while(count<=N-1)
	{
		newNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter Info for player %d ",count+1);
		scanf("%d", &newNode->info);
		newNode->link = NULL;
		tail->link = newNode;
		tail = newNode;
		count++;
	}
    tail->link = ptr;
}

void winner(int m, int n){
	ptr = tail->link;
	for(int i=n; i>1; i--){
		for(int j=1; j<m-1; j++){
			ptr = ptr->link;
		}
		printf("%d deleted \n", ptr->link->info);
		save = ptr->link;
		ptr->link = save->link;
		free(save);
		ptr = ptr->link;
	}
	printf("Winner is %d ", ptr->info);
}


int main(){
	int m;

	create();

	printf("Enter value for m  [mth player will be executed]\n");
	scanf("%d", &m);

	winner(m, N);
    return 0;
}