#include <iostream>

using namespace std;

typedef struct NODE
{
    int data;
    struct NODE *next;
} NODE;

NODE *makeNode(int x)
{
    NODE *newNode = new NODE();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(NODE *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

void pushFont(NODE **head, int x)
{
    NODE *newNode = makeNode(x);
    newNode->next = *(head);
    *head = newNode;
}

void insert_After(NODE **head, NODE *pM, int x)
{
    NODE *newNode = makeNode(x);
    if (pM == NULL)
    {
        cout << "Khong the them duoc";
        return;
    }

    if (*head == NULL) // Neu danh sach trong
    {
        *head = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = pM->next;
        pM->next = newNode;
    }

    return;
}

void insert_Before(NODE **head, NODE *pM, int x)
{
    NODE *newNode = makeNode(x);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = NULL;
    }
    // Head khong rong
    // ta them not dang sau va thay doi gia tri
    else
    {
        newNode->next = pM->next;
        pM->next = newNode;
        newNode->data = pM->data;
        pM->data = x;
    }
}

void addTrcViTri_K(NODE **head, int k, int x)
{
    if (k < 1)
    {
        cout << "khong ton tai vi tri am";
        return;
    }

    NODE *temp = *head;
    for (int i = 0; i < k - 1; i++)
    {
        temp = temp->next;
    }

    insert_Before(head, temp, x);
}

void addSauViTriK(NODE **head, int k, int x)
{
    if (k < 0)
    {
        cout << "khong ton tai vi tri";
        return;
    }

    NODE *temp = *head;
    for (int i = 0; i < k - 1; i++)
    {
        temp = temp->next;
    }

    insert_After(head, temp, x);
}

bool search(NODE *head, int x)
{
    if (head == NULL)
    {
        cout << "danh sach lien ket trong";
        return false;
    }
    int poi = 0;
    while (head != NULL && head->data != x)
    {
        head = head->next;
        poi++;
    }

    if (head != NULL)
    {
        cout << "co ton tai phan tu " << x << " tai vi tri " << poi;
        return true;
    }

    return false;
}

void xoa(NODE **head, NODE *pM)
{
    if (*head == NULL || pM == NULL)
    {
        cout << "Danh sach rong hoac con tro rong";
        return;
    }

    // TH nut tro boi M la nut dau tien cua danh sach
    if (*head == pM)
    {
        *head = pM->next;
        delete pM;
        return;
    }

    // Tim den nut dung trc con tro M
    NODE *temp = *head;
    while (temp->next != pM && temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Khong thay nut can xoa";
        return;
    }

    temp->next = pM->next;
    delete pM;
}

void xoaPhanTuK(NODE **head,int k){
    if (k < 0) {
        cout << "khong ton tai vi tri" << endl;
        return;
    }

    // Nếu xóa phần tử đầu tiên
    if (k == 0) {
        NODE *temp = *head;
        *head = temp->next; // Cập nhật head
        delete temp;
        return;
    }

    // Tìm phần tử trước vị trí k
    NODE *temp = *head;
    for (int i = 0; i < k - 1; i++) {
        if (temp == NULL || temp->next == NULL) { // Kiểm tra vượt quá danh sách
            cout << "Vi tri vuot qua do dai danh sach" << endl;
            return;
        }
        temp = temp->next;
    }

    // Gọi hàm xóa
    xoa(head, temp->next);
    
    
}

int main()
{
    NODE *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        pushFont(&head, i);
    }

    xoaPhanTuK(&head,1);

    duyet(head);
}
