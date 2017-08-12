/**
**/
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

string reverseStr(string a){
    string newStr = "";

    string  tempStr = "";

    for(int i = 0; i < a.length(); i++){
      if(a[i] == ' '){
        newStr = tempStr+" "+newStr;
        tempStr = "";
      }
      else{
        tempStr += a[i];
      }
  }

  return " "+tempStr+" "+newStr;
}

queue<pair<struct node*, int>> q;

struct node* newNode(int data){
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

void levelOrderSpiralTraversal(node* root){
    q.push(make_pair(root,0));
    string finalStr = "";
    string currLevelElements = "";
    while(!q.empty()){
        pair<struct node*,int> currElement = q.front();
        q.pop();
        int currLevel = currElement.second;

        currLevelElements += std::to_string(currElement.first->data);
        // cout<<"curr "<<currElement.first->data<<endl;
        if(currElement.first->left) q.push(make_pair(currElement.first->left,currLevel+1));
        if(currElement.first->right) q.push(make_pair(currElement.first->right,currLevel+1));


        while(!q.empty()){
             pair<struct node*,int> currElement1 = q.front();
             int currLevel1 = currElement1.second;
             if(currLevel != currLevel1){

                break;
             }
             else{
                q.pop();
                currLevelElements += (" "+std::to_string(currElement1.first->data));

                if(currElement1.first->left) q.push(make_pair(currElement1.first->left,currLevel1+1));
               	if(currElement1.first->right) q.push(make_pair(currElement1.first->right,currLevel1+1));
             }
        }

        if(currLevel %2 == 0) currLevelElements = reverseStr(currLevelElements);

        finalStr += currLevelElements;
        currLevelElements = "";
    }

    cout<<finalStr;
}

int main(){
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->left->left  = newNode(7);
  root->left->right  = newNode(6);

  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9);

  root->right = newNode(3);
  root->right->left = newNode(5);
  root->right->right = newNode(4);

	levelOrderSpiralTraversal(root);
  
     
  return 0;
} 