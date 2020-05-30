#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *link;
};
struct node *root = NULL;
struct node *root1 = NULL;
struct node *root2 = NULL;
struct node *root3 = NULL;

void NewNode(int data){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	if(root == NULL){
		root = temp;
	}else{
		struct node* p;
		p = root;
		while(p->link != NULL){
			p=p->link;
		}
		p->link = temp;
	}
}

void NewNode1(int data){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	if(root1 == NULL){
		root1 = temp;
	}else{
		struct node* p;
		p = root1;
		while(p->link != NULL){
			p=p->link;
		}
		p->link = temp;
	}
}

void NewNode2(int data){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	if(root2 == NULL){
		root2 = temp;
	}else{
		struct node* p;
		p = root2;
		while(p->link != NULL){
			p=p->link;
		}
		p->link = temp;
	}
}
  
 void NewNode3(int data){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	if(root3 == NULL){
		root3 = temp;
	}else{
		struct node* p;
		p = root3;
		while(p->link != NULL){
			p=p->link;
		}
		p->link = temp;
	}
}
 

int main() {
	int n;
	cin>>n;
	vector<int> LL1(2*n);
    vector<int> LL2(n-1);
    vector<int> LL3(n-1);
    vector<int> LL1U(2*n-1);
	
	for(int i = 0 ; i < 2*n ;i++){
		cin>>LL1.at(i);
		NewNode(LL1.at(i));
	}
	
	for(int i = 0 ; i < LL2.size() ; i++){
		LL2.at(i) = LL1.at(2*i)+LL1.at((2*i)+2);
		LL3.at(i) = LL1.at((2*i)+1)+LL1.at(((2*i)+1)+2);
	}
	for(int i = 0 ; i < LL2.size() ; i++){
		NewNode1(LL2.at(i));
	}
	for(int i = 0 ; i < LL2.size() ; i++){
		NewNode2(LL3.at(i));
	}
	
	struct node* m;
	m = root1;
	while(m){
		cout<<m->data<<' ';
		m=m->link;
	}
	cout<<endl;
	free(m);
	
	for(int i = 0 ; i < n-1 ; i++){
		LL1U.at(i) = LL2.at(i);
	}
	
	struct node* x;
	x=root2;
	while(x){
		cout<<x->data<<' ';
		x=x->link;
	}
	cout<<endl;
	free(x);
	
	LL1U.at(n-1) = LL1.at(0)+LL1.at(2*n-1);
	cout<<LL1U.at(n-1)<<endl;
	
	for(int i = 0 ; i < n-1 ; i++){
		LL1U.at(i+n) = LL3.at(i);
	}
	for(int i = 0 ; i < 2*n-1 ; i++){
		NewNode3(LL1U.at(i));
	}
	int i = 0;
	bool turn = true;
	struct node* p ;
	struct node* q;
	struct node* r;
	p=root;
	r=root;
	q=root3;
	while(i <4*n-1){
		if(turn == true){
			p=p->link;
		    r->link = root3;
	        r=r->link;
			root3=p;
			turn = false;
			i++;
		}
		else{
		    q=q->link;
		    r->link = root3;
		    r=r->link;
			root3 = q;
			turn = true;
			i++;
		}
	}
	free(p);
	free(q);
	free(r);
	free(root3);
	
	int count =0;
	struct node *s;
	s = root;
	while(s){
		cout<<s->data<<' ';
		s=s->link;
		count++;
	}
	
	cout<<endl;
	cout<<count<<endl;
	return 0;
}

