#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order {
    int id;
    char customer[100];
    int status;
    char total[50];
}Order;
typedef struct nodeDouble {
    Order order;
    struct nodeDouble* next;
    struct nodeDouble* prev;
}nodeDouble;
typedef struct nodeSingle {
    Order order;
    struct nodeSingle* next;
}nodeSingle;
nodeDouble* creatDoubleNode(Order order) {
    nodeDouble* newNode=malloc((sizeof(nodeDouble)));
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->order=order;
    return newNode;
}
nodeSingle* creatSingleNode(Order order) {
    nodeSingle* newNode=malloc((sizeof(nodeSingle)));
    newNode->next=NULL;
    newNode->order=order;
    return newNode;
}
Order createOrder(nodeDouble* headDouble) {
    Order order;
    if (headDouble==NULL) {
        order.id=1;
    }else {
        nodeDouble* current=headDouble;
        while (current->next!=NULL) {
            current=current->next;
        }
        order.id=current->order.id+1;
    }
    getchar();
    do {
        printf("nhap khach hang: ");
        fgets(order.customer, 100, stdin);
        if (strcspn(order.customer, "\n")==strlen(order.customer)) {
            while (getchar()!='\n');
        }else {
            order.customer[strcspn(order.customer, "\n")]='\0';
        }
        if (order.customer[0]=='\0') {
            printf("khong hop le\n");
        }
    }while (order.customer[0]=='\0');
    do {
        printf("nhap trang thai don hang: ");
        scanf("%d", &order.status);
        if (!order.status) {
            printf("khong hop le\n");
        }
    }while (!order.status);
    getchar();
    do {
        printf("nhap gia tien: ");
        fgets(order.total, 50, stdin);
        if (strcspn(order.total, "\n")==strlen(order.total)) {
            while (getchar()!='\n');
        }else {
            order.total[strcspn(order.total, "\n")]='\0';
        }
        if (order.total[0]=='\0') {
            printf("khong hop le\n");
        }
    }while (order.total[0]=='\0');
    return order;
}
nodeDouble* push(nodeDouble* headDouble, Order order) {
    if (headDouble==NULL) {
        headDouble=creatDoubleNode(order);
        return headDouble;
    }
    nodeDouble* current=headDouble;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=creatDoubleNode(order);
    current->next->prev=current;
    return headDouble;
}
void showOrder(nodeDouble* headDouble, nodeSingle* headSingle) {
    if (headDouble==NULL) {
        printf("danh sach don hang rong\n");
    }else {
        printf("danh sach don hang: \n");
        nodeDouble* current=headDouble;
        while (current!=NULL) {
            printf("ID: %d\n", current->order.id);
            printf("Khach hang: %s\n", current->order.customer);
            printf("Trang thai: chua giao\n");
            printf("tong tien: %s\n\n", current->order.total);
            current=current->next;
        }
    }
    if (headSingle==NULL) {
        printf("danh sach don hang da giao rong\n");
    }else {
        printf("danh sach don hang da giao: \n");
        nodeSingle* current=headSingle;
        while (current!=NULL) {
            printf("ID: %d\n", current->order.id);
            printf("Khach hang: %s\n", current->order.customer);
            printf("Trang thai: da giao\n");
            printf("tong tien: %s\n\n", current->order.total);
            current=current->next;
        }
    }
}
nodeDouble* deleteOrder(nodeDouble* headDouble, int deleteId) {
    if (headDouble==NULL) {
        printf("danh sach don hang rong\n");
        return NULL;
    }
    if (headDouble->order.id==deleteId) {
        nodeDouble* temp=headDouble;
        headDouble=headDouble->next;
        free(temp);
        return headDouble;
    }
    nodeDouble* current=headDouble;
    while (current!=NULL && current->order.id!=deleteId) {
        current=current->next;
    }
    if (current==NULL) {
        printf("ID khong ton tai\n");
        return headDouble;
    }
    nodeDouble* temp=current;
    current->prev->next=current->next;
    current->next->prev=current->prev;
    free(temp);
    return headDouble;
}
void updateOrder(nodeDouble* headDouble, int updateId) {
    if (headDouble==NULL) {
        printf("danh sach don hang chua giao rong\n");
        return;
    }
    nodeDouble* current=headDouble;
    while (current!=NULL && current->order.id!=updateId) {
        current=current->next;
    }
    if (current==NULL) {
        printf("ID khong ton tai\n");
        return;
    }
    printf("thong tin don hang: \n");
    printf("ID: %d\n", current->order.id);
    printf("Khach hang: %s\n", current->order.customer);
    if (current->order.status) {
        printf("Trang thai: da giao\n");
    }else {
        printf("Trang thai: chua giao\n");
    }
    printf("tong tien: %s\n\n", current->order.total);
    getchar();
    do {
        printf("nhap khach hang: ");
        fgets(current->order.customer, 100, stdin);
        if (strcspn(current->order.customer, "\n")==strlen(current->order.customer)) {
            while (getchar()!='\n');
        }else {
            current->order.customer[strcspn(current->order.customer, "\n")]='\0';
        }
        if (current->order.customer[0]=='\0') {
            printf("khong hop le\n");
        }
    }while (current->order.customer[0]=='\0');
    do {
        printf("nhap gia tien: ");
        fgets(current->order.total, 50, stdin);
        if (strcspn(current->order.total, "\n")==strlen(current->order.total)) {
            while (getchar()!='\n');
        }else {
            current->order.total[strcspn(current->order.total, "\n")]='\0';
        }
        if (current->order.total[0]=='\0') {
            printf("khong hop le\n");
        }
    }while (current->order.total[0]=='\0');
}
nodeSingle* markAsShipped(nodeDouble* headDouble, nodeSingle* headSingle, int targetId, int *check) {
    nodeDouble* current=headDouble;
    while (current!=NULL && current->order.id!=targetId) {
        current=current->next;
    }
    if (current==NULL) {
        printf("ID khong ton tai\n");
        *check=1;
        return headSingle;
    }
    if (headSingle==NULL) {
        headSingle=creatSingleNode(current->order);
        return headSingle;
    }
    nodeSingle* temp=headSingle;
    while (temp!=NULL) {
        temp=temp->next;
    }
    temp->next=creatSingleNode(current->order);
    return headSingle;
}
void sortByTotal(nodeDouble* headDouble) {
    if (headDouble==NULL || headDouble->next==NULL) {
        printf("khong du don hang de sap xep\n");
        return;
    }
    nodeDouble* i=headDouble;

    while (i!=NULL) {
        nodeDouble* j=headDouble;
        while (j->next!=NULL) {
            if (strcmp(j->order.total, j->next->order.total)>0) {
                Order temp=j->order;
                j->order=j->next->order;
                j->next->order=temp;
            }
            j=j->next;
        }
        i=i->next;
    }
}
void searchByCustomer(nodeDouble* headDouble, nodeSingle* headSingle, char find[]) {
    nodeDouble* current=headDouble;
    int countDouble=0;
    printf("don hang chua giao: \n");
    while (current!=NULL) {
        if (strstr(current->order.customer, find)!=NULL) {
            printf("ID: %d\n", current->order.id);
            printf("Khach hang: %s\n", current->order.customer);
            if (current->order.status) {
                printf("Trang thai: da giao\n");
            }else {
                printf("Trang thai: chua giao\n");
            }
            printf("tong tien: %s\n\n", current->order.total);
            countDouble++;
        }
        current=current->next;
    }
    if (countDouble==0) {
        printf("khong co don hang chua giao voi khach hang nhu vay\n\n");
    }
    nodeSingle* temp=headSingle;
    int countSingle=0;
    printf("don hang da giao: \n");
    while (temp!=NULL) {
        if (strstr(temp->order.customer, find)!=NULL) {
            printf("ID: %d\n", temp->order.id);
            printf("Khach hang: %s\n", temp->order.customer);
            if (temp->order.status) {
                printf("Trang thai: da giao\n");
            }else {
                printf("Trang thai: chua giao\n");
            }
            printf("tong tien: %s\n\n", temp->order.total);
            countSingle++;
        }
        temp=temp->next;
    }
    if (countSingle==0) {
        printf("khong co don hang da giao voi khach hang nhu vay\n");
    }
}
int main(void) {
    int n;
    nodeDouble* headDouble=NULL;
    nodeSingle* headSingle=NULL;
    do {
        printf("\n======MENU======\n");
        printf("1. them don hang\n");
        printf("2. hien thi don hang\n");
        printf("3. xoa don hang\n");
        printf("4. cap nhat don hang\n");
        printf("5. danh dau don hang da giao\n");
        printf("6. sap xep don hang\n");
        printf("7. tim kiem don hang\n");
        printf("8. thoat\n");
        printf("==================\n");
        printf("nhap lua chon cua ban: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                Order order=createOrder(headDouble);
                headDouble=push(headDouble, order);
                break;
            case 2:
                showOrder(headDouble, headSingle);
                break;
            case 3:
                int deleteId;
                printf("nhap ID don hang muon xoa: ");
                scanf("%d", &deleteId);
                headDouble=deleteOrder(headDouble, deleteId);
                break;
            case 4:
                int updateId;
                printf("nhap ID don hang muon sua: ");
                scanf("%d", &updateId);
                updateOrder(headDouble, updateId);
                break;
            case 5:
                int targetId;
                int check=0;
                printf("nhap ID don hang muon danh dau da giao: ");
                scanf("%d", &targetId);
                headSingle=markAsShipped(headDouble, headSingle, targetId, &check);
                if (check==0) {
                    headDouble=deleteOrder(headDouble, targetId);
                }
                break;
            case 6:
                sortByTotal(headDouble);
                showOrder(headDouble, headSingle);
                break;
            case 7:
                char find[50];
                getchar();
                printf("nhap khach hang muon tim: ");
                fgets(find, 50, stdin);
                if (strcspn(find, "\n")==strlen(find)) {
                    while (getchar()!='\n');
                }else {
                    find[strcspn(find, "\n")]='\0';
                }
                searchByCustomer(headDouble, headSingle, find);
                break;
            case 8:
                break;
            default:
                printf("khong hop le!\n");

        }
    }while (n!=8);
    printf("da thoat chuong trinh!");
    return 0;
}