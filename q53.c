#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int length(struct Node* head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* intersection(struct Node* head1, struct Node* head2) {
    int l1 = length(head1);
    int l2 = length(head2);

    struct Node *p1 = head1, *p2 = head2;

    int diff = abs(l1 - l2);

    if(l1 > l2)
        while(diff--) p1 = p1->next;
    else
        while(diff--) p2 = p2->next;

    while(p1 && p2) {
        if(p1 == p2)
            return p1;

        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;

    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        head1 = append(head1,x);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        head2 = append(head2,x);
    }

    struct Node* inter = intersection(head1, head2);

    if(inter)
        printf("%d", inter->data);
    else
        printf("No Intersection");

    return 0;
}