#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
	int data1;
	int data2;
	struct node* link;
};
struct node* root = NULL;

void delete_node(){
	struct node* p;
	p=root;
	root=root->link;
	p->link=NULL;
	free(p);
}

void addAtLast(){
	cout<<root->data1<<' ';
	root->data2=(root->data2)-1;
	if(root->data2 == 0){
		if(root->link == NULL){
			//cout<<root->data1;
		}else{
			delete_node();
		}
	}else{
		struct node* p;
	    p=root;
    	while(p->link != NULL){
	    	p=p->link;
	    }
	    p->link=root;
	    p=p->link;
	    root=root->link;
	    p->link=NULL;
	}
}

void addAtLast_withoutSub(){
		struct node* p;
	    p=root;
    	while(p->link != NULL){
	    	p=p->link;
	    }
	    p->link=root;
	    p=p->link;
	    root=root->link;
	    p->link=NULL;
}

void NewNode(int data1,int data2){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data1=data1;
	temp->data2=data2;
	temp->link=NULL;
	if(root == NULL){
		root = temp;
	}else{
		struct node* p;
		p=root;
		while(p->link !=NULL){
			p=p->link;
		}
		p->link=temp;
	}
	
}

struct arrange{
	arrange(int Roll, int Arrival,int Burst):Roll(Roll),Arrival(Arrival),Burst(Burst)
	{}
	
	int Roll;
	int Arrival;
	int Burst;
};

bool compareByLength(const arrange &a, const arrange &b)
{
    return a.Arrival < b.Arrival;
};

int main(){
	int n;
	cin>>n;
	//vector<int> Roll(n);
	//vector<int> Arrival(n);
	//vector<int> Burst(n);
	int Roll;
	int Arrival;
	int Burst;
	vector<arrange> Info;
	
	for(int i = 0 ; i <n ; i++){
		cin>>Roll>>Arrival>>Burst;
		arrange a(Roll,Arrival,Burst);
		Info.push_back(a);
		}
	
	sort(Info.begin(),Info.end(),compareByLength);
	
	for(int i = 0 ; i < n ; i++){
		NewNode(Info.at(i).Roll,Info.at(i).Burst);
	}
	int total = 0;
	for(int i = 0 ; i < n ; i++){
		total = total + Info.at(i).Burst;
	}
	int max=Info.at(0).Arrival;
	for(int i = 1 ; i < n ; i++){
		if(Info.at(i).Arrival > max){
			max = Info.at(i).Arrival;
		}
	}
	//int total = accumulate(Info.begin().Burst,Info.end().Burst,0);
	//int max = *max_element(Info.begin().Arrival,Info.end().Arrival);
	total = total + Info.at(0).Arrival;
	int k=0;
	for(int i = Info.at(0).Arrival ; i < total ; i++){
		if(i <= max){
			if(i >= Info.at(k).Arrival){
				addAtLast();
				k++;
				k=k%n;
			}else{
				addAtLast_withoutSub();
				i--;
				k++;
				k=k%n;
			}
		}else{
			addAtLast();
		}
	}
	/*for(int i = 0 ; i < n ; i++){
		cout<<Info.at(i).Roll;
	}*/
	/*struct node* p;
	p=root;
	while(p->link != NULL){
		cout<<p->data1<<' ';
		p=p->link;
	}*/
	return 0;
}








