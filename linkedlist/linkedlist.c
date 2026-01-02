#include <stdio.h>
#include <stdlib.h>

/*구조체 node를 정의 next를 통한 다음 주소를 알아보기 위해서
자기 자신을 참조함 해당 노드를 malloc 함수를 사용해 동적할당하여
새로운 노드끼리의 연결을 나타내기 위해서 생성*/
typedef struct node{
    int value;          //값을 저장할 벨류 값
    struct node* next;  //다음 링크할 노드 
}node;

/*노드의 헤드라는 포인터를 생성하고 널로 표기
해당 값은 처음 값을 판단할 헤드 구조체.*/
node* head=NULL;
void print_list() {
    node* cur = head;

    printf("list: ");
    while (cur != NULL) {
        printf("%d -> ", cur->value);
        cur = cur->next;
    }
    printf("NULL\n");
}

void insert_node (){
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
        head=updateNode;
        return;
    }
    /*만약 다음 노드의 설정이 되어있다면 연결되어있는 다음 노드를 체크하고 다음 노드의 값*/
    updateNode->next=head;
    head=updateNode;
}

int main() {
    printf("값을 하나씩 입력하세요 (총 3번):\n");

    insert_node();
    print_list();

    insert_node();
    print_list();

    insert_node();
    print_list();

    return 0;
}
