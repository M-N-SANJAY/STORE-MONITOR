#include<stdio.h>
#include<string.h>

/*initialising store - Multi dimensional char array to sotre upto 100 item names.
    1D integer array quantity to keep track of the quantity of the product.
    cur denotes the end of the array and if cur==-1 means there's no element in the store array at that moment.
*/
char store[100][25];
int cur=-1,quantity[100];

//function to search for the required item
int search(char sitem[25]){
    if(cur==-1){     //store array is empty
        return -1;
    }
    for(int i=0;i<=cur;i++){
        if(strcmp(sitem,store[i])==0){
            return i;             //returning index of the item at the store array 
        }
    }
    return -1;    // item not found
}

//function to add item in store array
void additem(){
    if(cur==99){
        printf("\nStore full, delete any item first");     //store array full
        return;
    }

    //adding the item directly into the store array and updating its corresponding quantity
    printf("\nEnter the product name: ");     
    scanf("%s",&store[++cur]);
    printf("\nEnter the product quantity: ");
    scanf("%d",&quantity[cur]);
    printf("\nItem Added Succesfully");
}

//function to delete an item
void deleteitem(char ditem[25]){
    if(cur==-1){          // no item to delete
        printf("\nNo item in store");
        return;
    }
    int idx=search(ditem);    // we use our search fucntion to help us know whether the item exists or not, also if it exists it gives us the position of the item.
    if(idx==-1){
        printf("\nNo such item exist in the store");
        return;
    }
    for(int i=idx;i<cur-1;i++){            //left shift every item by 1 position to remove the item from the store array
        strcpy(store[i],store[i+1]);
        quantity[i]=quantity[i+1];
    }
    cur-=1;
    printf("\nItem Deleted Successfully");
}
void main(){
    int idx,choice;
    char sitem[25],ditem[25];
    
    //Menu
    printf("Options Available:-\n1.Add Item\n2.Search Item\n3.Delete Item\n4.Exit");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1){
            additem();
        }
        else if(choice==2){
            printf("\nEnter the product name you want to search: ");
            scanf("%s",sitem);
            idx=search(sitem);
            if(idx!=-1){
                printf("\nItem exist in store");
                printf("\n%s quanitity is %d",store[idx],quantity[idx]);
            }
            else{
                printf("\nItem does not exist in store");
            }
        }
        else if(choice==3){
            printf("\nEnter the product name you want to delete: ");
            scanf("%s",ditem);
            deleteitem(ditem);
        }
        else{
            break;
        }
    }
}
