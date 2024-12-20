#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct SinglyLinkedList {
    Node* head;
} SinglyLL;

SinglyLL* init() {
    SinglyLL* list = (SinglyLL*)malloc(sizeof(SinglyLL));
    list->head = NULL;
    return list;
}

Node* createNode(int n) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Cannot be allocated...\n");
        return NULL;
    }
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

void Insertion_at_beginning(SinglyLL* list, int n) {
    Node* newNode = createNode(n);
    if (newNode == NULL) return;
    newNode->next = list->head;
    list->head = newNode;
}

void Insertion_at_end(SinglyLL* list, int n) {
    Node* newNode = createNode(n);
    if (newNode == NULL) return;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* ptr = list->head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void Insert_At_position(SinglyLL* list, int n, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        Insertion_at_beginning(list, n);
        return;
    }
    Node* newNode = createNode(n);
    if (newNode == NULL) return;
    Node* ptr = list->head;
    for (int i = 1; ptr != NULL && i < pos - 1; i++) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void Delete_At_Beginning(SinglyLL* list) {
    if (list->head == NULL) {
        printf("No nodes are present...\n");
        return;
    }
    Node* ptr = list->head;
    list->head = list->head->next;
    printf("%d deleted\n", ptr->data);
    free(ptr);
}

void Delete_at_end(SinglyLL* list) {
    if (list->head == NULL) {
        printf("No nodes are present...\n");
        return;
    }
    if (list->head->next == NULL) {
        printf("%d deleted\n", list->head->data);
        free(list->head);
        list->head = NULL;
        return;
    }
    Node* ptr = list->head;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    Node* temp = ptr->next;
    ptr->next = NULL;
    printf("%d deleted\n", temp->data);
    free(temp);
}

void Delete_at_position(SinglyLL* list, int pos) {
    if (list->head == NULL) {
        printf("No nodes are present...\n");
        return;
    }
    if (pos == 1) {
        Delete_At_Beginning(list);
        return;
    }
    Node* ptr = list->head;
    for (int i = 1; ptr != NULL && i < pos - 1; i++) {
        ptr = ptr->next;
    }
    if (ptr == NULL || ptr->next == NULL) {
        printf("Given Position Does Not Exist\n");
        return;
    }
    Node* temp = ptr->next;
    ptr->next = ptr->next->next;
    printf("%d deleted\n", temp->data);
    free(temp);
}

void Traversal_in_Order(SinglyLL* list) {
    if (list->head == NULL) {
        printf("No Nodes present\n");
        return;
    }
    Node* ptr = list->head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void Traversal_in_Reverse_Helper(Node* head) {
    if (head == NULL) return;
    Traversal_in_Reverse_Helper(head->next);
    printf("%d ", head->data);
}

void Traversal_in_Reverse(SinglyLL* list) {
    Traversal_in_Reverse_Helper(list->head);
    printf("\n");
}

Node* search(SinglyLL* list, int key) {
    Node* ptr = list->head;
    while (ptr != NULL) {
        if (ptr->data == key) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void freeList(SinglyLL* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    int c, n, key, pos;
    SinglyLL* list = init();
    do {
        printf("1. Insert at beginning\n2. Insert at end\n"
               "3. Insert at position\n4. Deletion at beginning\n"
               "5. Deletion at end\n6. Deletion at position\n"
               "7. Traverse in Order\n8. Traverse in Reverse\n"
               "9. Search a node\n-1. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &n);
                Insertion_at_beginning(list, n);
                break;
            case 2:
                printf("Enter the number: ");
                scanf("%d", &n);
                Insertion_at_end(list, n);
                break;
            case 3:
                printf("Enter the number: ");
                scanf("%d", &n);
                printf("Enter the position: ");
                scanf("%d", &pos);
                Insert_At_position(list, n, pos);
                break;
            case 4:
                Delete_At_Beginning(list);
                break;
            case 5:
                Delete_at_end(list);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                Delete_at_position(list, pos);
                break;
            case 7:
                Traversal_in_Order(list);
                break;
            case 8:
                Traversal_in_Reverse(list);
                break;
            case 9:
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                Node* ptr = search(list, key);
                if (ptr == NULL)
                    printf("Element not present\n");
                else
                    printf("Element is present\n");
                break;
            case -1:
                freeList(list);
                break;
            default:
                printf("Invalid choice...\n");
                break;
        }
    } while (c != -1);

    ///Enter the Name here:  Ex. printf("Alice/n");
    printf("/n");
    ///Enter the Roll Number here:  Ex. printf("123456789");
    printf("");

    return 0;
}
