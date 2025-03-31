#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *pLeft;
    BSTNode *pRight;
};

int insert(int x, BSTNode *&root)
{
    if (root == NULL) // TH1 root rong
    {
        root = new BSTNode(); // Cap phat dong nut moi
        if (root == NULL)     // Neu cap phat dong loi
        {
            return -1;
        }
        else
        { // Cap phat dong khong loi thi khoi tao nut
            root->data = x;
            root->pLeft = NULL;
            root->pRight = NULL;
            return 1;
        }
    }
    else
    {                        // TH2 root khong rong
        if (root->data == x) // Neu da ton tai gia tri nay trong cay
        {
            return 0;
        }
        else
        { // Neu chua ton tai, ta dua vao gia tri x de tim kiem ( Cay nhi phan tim kiem)
            if (x < root->data)
            {
                return insert(x, root->pLeft); // Goi de quy de tim vi tri chen thich hop tu ben trai
            }
            else
            {
                return insert(x, root->pRight); // Goi de quy de tim vi tri chen thich hop tu ben phai
            }
        }
    }
}

// Duyet NLR
void preOrder(BSTNode *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        preOrder(root->pLeft);
        preOrder(root->pRight);
    }
}

// LNR
void inOrder(BSTNode *root)
{
    if (root != NULL)
    {
        inOrder(root->pLeft);
        cout << root->data << endl;
        preOrder(root->pRight);
    }
}

// LRN
void postOrder(BSTNode *root)
{
    if (root != NULL)
    {
        postOrder(root->pLeft);
        postOrder(root->pRight);
        cout << root->data << endl;
    }
}

BSTNode *find(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;
    // Neu root khac rong, ta so sanh root voi value de goi de quy
    if (root->data < value)
    {
        return find(root->pRight, value);
    }
    else if (root->data > value)
    {
        return find(root->pLeft, value);
    }
    else
    { // TH nay nghia la root->data = value
        return root;
    }
}

BSTNode *findMin(BSTNode *root)
{
    /*Tu tuong : Tim ve phia ben trai den khi not ben trai ngoai cung chua tro vao node khac ( hay noi cach khac la
    tro vao NUll) thi no la node nho nhat
    */
    if (root == NULL)
    {
        return NULL;
    }
    if (root->pLeft == NULL)
    {
        return root;
    }
    else
    {
        return findMin(root->pLeft);
    }
}

BSTNode *findMax(BSTNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->pRight == NULL)
    {
        return root;
    }
    else
    {
        return findMax(root->pRight);
    }
}

int deleteNode(int x, BSTNode *&root)
{
    if (root == NULL)
        return 0;

    if (x < root->data)
    {
        return deleteNode(x, root->pLeft);
    }
    else if (x > root->data)
    {
        return deleteNode(x, root->pRight);
    }
    else
    {
        // Node cần xóa được tìm thấy
        if (root->pLeft && root->pRight)
        {
            // Trường hợp có 2 con: Tìm node lớn nhất ở cây con trái
            BSTNode *p = findMax(root->pLeft);
            root->data = p->data;
            return deleteNode(p->data, root->pLeft); // Sửa: Xóa node p từ cây con trái
        }
        else
        {
            // Trường hợp có 1 con hoặc không có con
            BSTNode *p = root;
            if (root->pLeft == NULL)
            {
                root = root->pRight;
            }
            else
            {
                root = root->pLeft;
            }
            delete p; // Giải phóng bộ nhớ
            return 1;
        }
    }
}

int main()
{
    BSTNode *root = NULL;
    insert(5, root);
    insert(7, root);
    insert(3, root);
    insert(2, root);
    insert(15, root);
    cout << "--Con tro co chua gia tri 3 la--" << endl;
    BSTNode *kq = find(root, 3);
    cout << "Gia tri cua con tro do la : " << kq->data << endl;
    BSTNode *min = findMin(root);
    cout << "Gia tri cua node nho nhat la: " << min->data << endl;
    BSTNode *max = findMax(root);
    cout << "Gia tri cua node lon nhat la: " << max->data << endl;
    cout << "--Xoa nut 5--- : ";
    deleteNode(7, root);
    inOrder(root);
}
