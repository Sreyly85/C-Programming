#include <stdio.h>
#include <stdlib.h>
int n;
int i;
int j;
int tmp;
int numbers[20];
int main(){
    int choice;
    int k;
    START:
    system("cls");
	printf("\n\t\t\t======================Input Your Choice======================\n\n");
	printf("\t\t\t\t[1] Input n elements\n");
	printf("\t\t\t\t[2] Print n elements\n");
	printf("\t\t\t\t[3] Finding max n elements\n");
	printf("\t\t\t\t[4] Finding min n elements\n");
	printf("\t\t\t\t[5] Searching n elements\n");
	printf("\t\t\t\t[6] Inserting n elements\n");
	printf("\t\t\t\t[7] Removing n elements\n");
	printf("\t\t\t\t[8] Updating n elements\n");
	printf("\t\t\t\t[9] Sorting n elements\n");
	printf("\t\t\t\t[10] Exit app\n");
	printf("\t\t\t\t\n\nInput your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            inputElements();
            printElements();
            break;
        case 2:
            initializeNumbers();
            printElements();
            break;
        case 3:
            findingMaxElements();
            break;
        case 4:
            findingMinElements();
            break;
        case 5:
            searchingElements();
            break;
        case 6:
            insertingElements();
            break;
        case 7:
            removingElement();
            break;
        case 8:
            updatingElements();
            break;
        case 9:
            sortingElement();
            break;
        case 10:
            goto EXIT;
            break;
        default:
            printf("\n\n============This option is not available!=================");
            break;
    }
    printf("\n\n\n\t\t\tEnter 0 to go back: ");
    scanf("%d", &k);
    if (k == 0) {
        goto START;
    }
    EXIT:
    return 0;
}
void initializeNumbers() {
    printf("\n\nInput n elements: ");
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        numbers[i] = i;
    }
}
void inputElements() {
    printf("\n\nInput n elements: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("\nEnter Numbers[%d] = ", i);
        scanf("%d", &numbers[i]);
    }
}
void printElements() {
    printf("\n========Element of Numbers===========\n");
    for(i=0; i<n; i++) {
        printf("\n\t==>%sNumbers[%d] = %d \n", "  ", i, numbers[i]);
    }
    printf("=========================================");
}
void findingMaxElements() {
    inputElements();
    for (i = 0; i <n; i++) {
    if (numbers[0] < numbers[i]) {
      numbers[0] = numbers[i];
    }
  }
  printf("\n\n========Largest numbers = %d============", numbers[0]);
}
void findingMinElements() {
    inputElements();
    for (i = 0; i <n; i++) {
    if (numbers[0] > numbers[i]) {
      numbers[0] = numbers[i];
    }
  }
  printf("\n\n========Smallest numbers = %d============", numbers[0]);
}
void searchingElements() {
    int search;
    int flag = 0;
    inputElements();
    printf("\nPlease Enter the Search Element  :  ");
  	scanf("%d", &search);
  	for(i=0; i<n; i++) {
   		if(numbers[i] == search)
     	{
       		flag = 1;
       		break;
	 	}
   	}
  	if(flag == 1) {
  		printf("\nWe found the Search Element %d at Position %d ", search, i + 1);
	}
	else {
		printf("\nSorry!! We haven't found the the Search Element %d ", search);
	}
}
void insertingElements() {
    int num;
    int pos;
    inputElements();
    printf("\nEnter element to insert : ");
    scanf("%d", &num);
    printf("\nEnter the element position : ");
    scanf("%d", &pos);
    if(pos > n+1 || pos <= 0) {
        printf("Invalid position! Please enter position between 1 to %d", n);
    } else {
        for(i=n; i>=pos; i--)
        {
            numbers[i] = numbers[i-1];
        }
        numbers[pos-1] = num;
        n++;
        printf("\n=========Array elements after insertion============");
        printElements();
    }
}
void removingElement() {
    int index;
    inputElements();
    printf("\nEnter the index where you wish to delete element: ");
    scanf("%d", &index);
    if (index >= n+1) {
        printf("Deletion not possible.\n");
    } else {
      for (i=index; i<n; i++) {
        numbers[i] = numbers[i+1];
      }
      printf("\n========Result after Removing Numbers===========\n");
      for(i = 0; i < n-1; i++)
      printf("\n\tNumber[%d]  = %d",i, numbers[i]);
   }
}
void updatingElements() {
    int newValue;
    int index;
    inputElements();
    printf("\nEnter the index to be updated:  ");
    scanf("%d", &index);
    printf("\nEnter the new element:");
    scanf("%d",&newValue);
    numbers[index] = newValue;
    printf("\n========After Updated===========\n");
    printElements();
}
void sortingElement() {
    printf("\n enter [1] for ascending order");
    printf("\n enter [2] for descending order");
    printf("\n enter your choice: ");
    scanf("%d", &j);
    if(j == 1) {
        sortingAscending();
        printf("==========Numbers after sorted=============\n");
        printElements();
    } else if(j == 2) {
        sortingDescending();
        printf("==========Numbers after sorted=============\n");
        printElements();
    } else {
        printf("invalid choice!");
    }
}
void sortingAscending() {
    inputElements();
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(numbers[j] < numbers[i])
            {
                tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }
}
void sortingDescending() {
    inputElements();
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(numbers[j] > numbers[i])
            {
                tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }
}
