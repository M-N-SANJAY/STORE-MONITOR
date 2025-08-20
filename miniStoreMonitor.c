#include<stdio.h>
#include<string.h>

char store[100][25];
int cur=-1,quantity[100];
int search(char sitem[25]){
    if(cur==-1){
        return -1;
    }
    for(int i=0;i<=cur;i++){
        if(strcmp(sitem,store[i])==0){
            return i;
        }
    }
    return -1;
}
void additem(){
    if(cur==99){
        printf("\nStore full, delete any item first");
        return;
    }
    printf("\nEnter the product name: ");
    scanf("%s",&store[++cur]);
    printf("\nEnter the product quantity: ");
    scanf("%d",&quantity[cur]);
    printf("\nItem Added Succesfully");
}
void deleteitem(char ditem[25]){
    if(cur==-1){
        printf("\nNo item in store");
        return;
    }
    int idx=search(ditem);
    if(idx==-1){
        printf("\nNo such item exist in the store");
        return;
    }
    for(int i=idx;i<cur-1;i++){
        strcpy(store[i],store[i+1]);
        quantity[i]=quantity[i+1];
    }
    cur-=1;
    printf("\nItem Deleted Successfully");
}
void main(){
    int idx,choice;
    char sitem[25],ditem[25];
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
