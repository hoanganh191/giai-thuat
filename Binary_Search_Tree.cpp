#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* pLeft;
    BSTNode* pRight;
};

BSTNode* makeNode(int value){
    BSTNode *newNode = new BSTNode();
    newNode->data = value;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;
    return newNode;
}


int insert(int x,BSTNode *&root){
    if (root == NULL) //TH1 root rong
    {
        root = new BSTNode(); //Cap phat dong nut moi
        if (root == NULL) //Neu cap phat dong loi
        {
            return -1;
        } else { //Cap phat dong khong loi thi khoi tao nut
            root->data = x;
            root->pLeft = NULL;
            root->pRight = NULL;
            return 1;
        }
        
    }
    else { //TH2 root khong rong
        if (root->data == x) //Neu da ton tai gia tri nay trong cay
        {
            return 0; 
        }
        else { //Neu chua ton tai, ta dua vao gia tri x de tim kiem ( Cay nhi phan tim kiem)
            if (x < root->data)
            {
                return insert(x,root->pLeft); //Goi de quy de tim vi tri chen thich hop tu ben trai
            } else {
                return insert(x,root->pRight); //Goi de quy de tim vi tri chen thich hop tu ben phai
            }
            
        }
        
    }
    
}

void preOrder(BSTNode *root){
    if (root != NULL)
    {
        cout << root->data << endl;
        preOrder(root->pLeft);
        preOrder(root->pRight);
    } 
    
}



int main(){
    BSTNode *root = NULL;
    insert(5,root);
    insert(7,root);
    insert(3,root);
    cout << "\n" << "Ket qua duyet cay la : " << endl;
    preOrder(root);

}
