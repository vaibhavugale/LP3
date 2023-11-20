#include<iostream>
#include <queue>
#include <unordered_map>
using namespace std;


class node{
    public:
    char ch;
    int fre;
    node* left=NULL,*right=NULL;
    node(char ch,int fre){
        this->ch = ch;
        this->fre = fre;
        right=NULL;
        left=NULL;
    }
};
class cmp {
    public:
     bool operator()(node* left , node* right){

    return left->fre>right->fre;
};
};


void genCode(node* root, unordered_map<char , string> &codes, string code){
    if(root==NULL){
        return;
    }
    if(root->ch!='$'){
        codes[root->ch]=code;
    }
    genCode(root->left,codes,"0"+code);
     genCode(root->right,codes,"1"+code);
}

node* huffman(string input){
    unordered_map<char,int> m1;
    for(int i=0;i<input.length();i++)
    {
        m1[input[i]]++;
    }

    priority_queue< node* , vector<node*> , cmp> pq;

    for (auto &pair :m1){
        pq.push(new node(pair.first,pair.second));
    }
    while(pq.size()>1){
        node* left = pq.top();
        pq.pop();
        node* right = pq.top();
        pq.pop();

        node* newNode = new node('$',left->fre+right->fre);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    node* root = pq.top();
    return pq.top();

}

int main(){

    string hi = "helloiamvaibhav";
   node* root =  huffman(hi);
   unordered_map<char , string> result;
   genCode(root,result,"");

   for(auto pair : result){
       cout<<pair.first <<" -> " << pair.second<<endl;
   }

    return 0;
}