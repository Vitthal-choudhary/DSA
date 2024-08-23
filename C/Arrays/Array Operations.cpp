#include<stdio.h>
#include <process.h>

void Traverse(int arr[], int size){
	int i;
	for(int i=0; i<size; i++){
		printf("%d\n", arr[i]);
	}
}

int Insert_At_Begin(int arr[], int size){
	int i, item;
	printf("Enter item");
	scanf("%d", &item);
	for(i=size; i>0; i--){
		arr[i] = arr[i-1];
	}
	arr[0] = item;
	return ++size;
}

int Insert_At_End(int arr[], int size){
	int item;
	printf("Enter item");
	scanf("%d", &item);
	arr[size] = item;
	return ++size;
}

int Insert_At_any_Pos(int arr[], int size){
	int i, position, item;
	printf("Enter item");
	scanf("%d", &item);
	printf("Enter item at which u want to insert ");
	scanf("%d", &position);
	for(i=size; i>position; i--){
		arr[i] = arr[i-1];
	}
	arr[position] = item;
	return ++size;
}

int Delete_at_Begin(int arr[], int size){
	int i;
	for(i=0; i<size; i++){
		arr[i] = arr[i+1];
	}
	return --size;
}

int Delete_at_End(int size){
	return --size;
}

int Delete_at_Position(int arr[], int size)
{
	int i, position;
	printf("Enter position to delete ");
	scanf("%d", &position);
	
	for(i=position; i<size; i++){
		arr[i] = arr[i+1];
	}
	return --size;
}

int main(){
	int array[10], size, i, choice;
	printf("Enter size of array   [MAX 10]  \n");
	scanf("%d", &size);
	
	// Creation of Array
	for(i=0; i<size; i++){
		printf("Enter %d element ", i+1);
		scanf("%d", &array[i]);
	}
	do{
		printf("Enter choice\n1. Traverse\n2. Insert at begin\n3. Insert at End\n4. Insert at any position\n5. Delete from begin\n6. Delete at End\n7. Delete at any position\n8. EXIT\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				Traverse(array, size);
				break;
			case 2:
				size = Insert_At_Begin(array, size);
				break;
			case 3:
				size = Insert_At_End(array, size);
				break;
			case 4:
				size = Insert_At_any_Pos(array, size);
				break;
			case 5:
				size = Delete_at_Begin(array, size);
				break;
			case 6:
				size = Delete_at_End(size);
				break;
			case 7:
				size = Delete_at_Position(array, size);
				break;
			case 8:
				exit(0);
			default:
				printf("Wrong Choice\n");		
		}
	}while(choice!=8);
	
	return 0;
}
