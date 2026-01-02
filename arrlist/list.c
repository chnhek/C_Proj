#include <stdio.h>
#define SIZE 5

void list_insert (int listData[], int *count);
void list_delete (int listData[], int *count);
void list_print (int listData[], int count);

int main()
{
   int Linked[SIZE] = {0,};
   int count = 0;
   int insert = 0;
     
    while (1)
    {
        printf ("       list        \n--------------------------------\n");
        printf ("1. 입력    2. 삭제    3.확인    4.종료\n");
        printf ("메뉴 선택 : ");
        scanf("%d", &insert);
        
        if (insert == 1) list_insert(Linked, &count); 
        else if (insert == 2) list_delete(Linked, &count);
        else if (insert == 3) list_print(Linked, count);
        else if (insert == 4)
        {
            printf ("종료합니다.");
            break;
        }
        else{
            printf("잘못된 선택입니다.\n\n");
        }    
    }
    return 0;
}

// 입력
void list_insert (int listData[], int *count){
    if (*count >= SIZE){
        printf ("리스트에 공간이 없습니다.\n");
        return;
    }
    else{
        int i, j;
        int insData = 0;
        printf ("저장할 데이터 : ");
        scanf("%d", &insData);

        for (i = 0; i < *count; i++){
            if (listData[i] > insData){
                for (j = *count; j > i; j--){
                    listData[j] = listData[j - 1];
                }
                listData[i] = insData;
                (*count)++;
                return;
            }
        }
        listData[*count] = insData;
        (*count)++;
    }
}

// 삭제
void list_delete (int listData[], int *count){
    if (*count == 0) {
        printf("리스트에 값이 없습니다.\n");
        return;
    }
    else{
        int i, j;
        int delData = 0;
        scanf ("%d", &delData);

        for (i = 0; i < *count; i++){
            if (listData[i] == delData){
                for (j = i; j < *count; j++){
                    listData[j] = listData[j + 1];
                }
                (*count)--;
                printf("데이터 %d를 삭제했습니다.\n", delData);
                return;
            }
        }
    }
}

// 출력
void list_print (int listData[], int count){
    if (count == 0){
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    else{
        int i;
        printf("리스트에는 ");
        for (i = 0; i < count; i++){
            printf("%d ", listData[i]);
        }
        printf("이 저장되어 있습니다.\n");
    }
}
