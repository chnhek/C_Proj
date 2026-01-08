#include <stdio.h>
#include <stdlib.h>

void print_list();
void insert_node();
void del_node();

/*구조체 node를 정의 next를 통한 다음 주소를 알아보기 위해서
자기 자신을 참조함 해당 노드를 malloc 함수를 사용해 동적할당하여
새로운 노드끼리의 연결을 나타내기 위해서 생성*/
typedef struct node{
    int value;          //값을 저장할 벨류 값
    struct node* next;  //다음 링크할 노드 
}node;
node* head=NULL;        /*노드의 헤드라는 포인터를 생성하고 널로 표기 해당 값은 처음 값을 판단할 헤드 구조체.*/

//test
int main() {
    int insert = 0;
    while (1)
    {
        printf ("       list        \n--------------------------------\n\n");
        printf ("1. 입력    2. 삭제    3.확인    4.종료\n");
        printf ("메뉴 선택 : ");
        scanf("%d",&insert);
        if (insert == 1) insert_node();
        if (insert == 2) del_node();
        if (insert == 3) print_list();
        if (insert == 4) break;
    }
    return 0;
}

void print_list(){
    node* cur = head;
    printf("list: ");
    while (cur != NULL) { 
        printf("(%p),%d,(%p) → ",cur,cur->value,cur->next);
        cur = cur->next;
    }
    printf("NULL\n\n");
}

void insert_node (){
    printf ("저장할 데이터 : ");
    /*전역변수에 정의가 되어있는 node의 구조체를 메모리 동적 할당을
    통해서 힙 영역에 updateNode라는 다음 연결할 부분을 구조체로 할당*/
    node* updateNode;
    updateNode=(node*)malloc(sizeof(node));
    //scanf를 통한 동적할당된 새로운 노드의 값에 입력 받을 벨류 값을 설정
    scanf("%d",&updateNode->value);
    //다음 주소를 아직 가르키고 있지 않기 때문에 새로운 노드의 다음 값은 널값으로 초기화
    updateNode->next=NULL;
    /*head의 값이 NULL이라면 아직 헤드가 가르키는 처음의 값이 저장되어 있지 않은 상태이므로
    해당 head가 가르키는 값을 새로운 방을 만든 updateNode로 설정해주고 반환시킨다(앞 부분 삽입)
    만약 null값이 아니라면 해당 노드는 첫번째 방을 가르키고 있었으므로 다음 값을 생성하면 앞 부분에
    삽입을 할 예정이기에 update한 값을 head값이 방을 참조하게 끔*/

    if (head==NULL){
        head=updateNode;    //헤드가 다음 주소를 가르키고 있지 않다면 방다음 주소를 새로 만든 방으로..
        return;
    }
    node* cur = head;       //순회할 cur포인터를 헤드로 설정
    node* prev = NULL;      //이전 노드를 담을 prev 포인터를 NULL로 설정
    while (cur != NULL){    //순회할 cur의 next값이 NULL을 만날때까지 반복
        if(cur->value >=updateNode->value) break;   //반복하는 경우 cur의 벨류값과 다음 노드의 벨류값을 비교해서 바꿔야 하는 값을 발견하면 반복문을 멈춤
        prev = cur;         //순회할 때 마다 이동한 주소의 값을 이전 주소값을 담을 prev 포인터에 담아서 값을 보존
        cur = cur->next;    //한뒤 다음 노드로 이동
    }
    if (prev == NULL) {     //이전 노드를 담을 prev의 값이 NULL이라면 아직 첫번째 방이므로 다음 리스트를 그대로 업데이트 해줌
        updateNode->next = head;    
        head = updateNode;
    }
    else {                  
        //그렇지 않다면 첫번째 방이 아닌 바꿔야하는 벨류값을 만난 상태이므로 이전 주소를 가진 prev가 가르키는 주소를 updatenode의 주소로 주고
        //updatenode의 다음 주소는 순회하여야하는 cur 즉 head의 값을 넘겨줌
        prev->next = updateNode;
        updateNode->next = cur;
    }
}

void del_node (){
    node *prev = NULL;
    node *cur = head;// 순회
    node *target=NULL;
    int del_key = 0;
    
    printf("삭제 받을 값을 입력하세요 : ");
    scanf("%d",&del_key);

    if(head==NULL){
    printf("삭제할 값이 없습니다..\n");
    return;
    }

    if (del_key==head->value){
        node *temp = head;
        head = head->next;
        free(temp);
        printf("마지막 값 삭제 완료.");
        return;
    }
    
    while (cur != NULL && cur->next != NULL){
        if(del_key == cur->next->value){
            target=cur->next;
            prev=cur;
            prev->next = target ->next;
            free(target);
            break;
        }
        cur=cur->next;
    }
    printf("삭제 할 값을 리스트에서 찾지 못했습니다.\n");
}