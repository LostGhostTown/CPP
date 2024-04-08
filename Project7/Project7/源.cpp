#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
struct node {
    int d;
    node* left;
    node* right;
    node(int num):d(num),left(nullptr),right(nullptr){}
};
int main(){
    node* mtree = new node(1);
    node* arr[100];
    arr[0] = mtree;
    node* temp = new node(2);
    mtree->left = temp;
    arr[1] = temp;
    temp = new node(3);
    arr[1]->left = temp;
    cout << mtree->left->left->d;

    system("pause");
    return 0;
}
