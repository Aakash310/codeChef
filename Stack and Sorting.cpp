#include<bits/stdc++.h>
#include<stack>
#include<sstream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	bool need = true;
	stack<int> S1;
	stack<int> S2;
	
	for(int i = 0 ; i < n ; i++){
		int num ;
		cin>>num;
		S1.push(num);
	}
	//S2.push(4);
	//S2.push(3);
	if(S2.empty()){
		int temp = S1.top();
		S1.pop();
		S2.push(temp);
	}
	
     for(int i = 0 ; i < 2 ; i++){
     	need = true;
	if(S1.top()/10 == 0 && S2.top()/10 == 0){
		int x= S1.top();
		int y = S2.top();
		if((y-x == 1) || (x-y == 1)){
			S1.pop();
			S2.pop();
			if(x>y){
				int z;
				stringstream str1;
				str1<<x<<y;
				str1>>z;
				S2.push(z);
				need = false;
			}else{
				int z;
				stringstream str1;
				str1<<y<<x;
				str1>>z;
				S2.push(z);
				need = false;
			}
		}
	}
	else if(S1.top()/10 == 0 && S2.top()/10 != 0){
		vector<int> xab;
		int x = S1.top();
		int a = S2.top()/10;
		int b = S2.top()%10;
		xab.push_back(x);
		xab.push_back(a);
		xab.push_back(b);
		sort(xab.begin(),xab.end());
		if((x-a == 1) || (a-x == 1) || (b-x == 1) || (x-b == 1)){
			S1.pop();
			S2.pop();
			int z;
			stringstream str2;
			str2<<xab.at(2)<<xab.at(0);
			str2>>z;
			S2.push(z);
			need = false;
		}
		if( x > a){
			int temp = S1.top();
			S1.pop();
			S2.push(temp);
			need = false;
		}
	}
	else if( S1.top()/10 != 0 && S2.top()/10 == 0){
		vector<int> abx;
		int a = S1.top()/10;
		int b = S1.top()%10;
		int x = S2.top();
		abx.push_back(a);
		abx.push_back(b);
		abx.push_back(x);
		sort(abx.begin(),abx.end());
		if((a-x == 1) || (x-a == 1) || (b-x == 1) || (x-b == 1)){
			S1.pop();
			S2.pop();
			int z;
			stringstream str3;
			str3<<abx.at(2)<<abx.at(0);
			str3>>z;
			S2.push(z);
			need = false;
		}
	}
	else if(S1.top()/10 > 0 && S2.top()/10 > 0){
		vector<int> abcd;
		int a = S1.top()/10;
		int b = S1.top()%10;
		int c = S2.top()/10;
		int d = S2.top()%10;
		abcd.push_back(a);
		abcd.push_back(b);
		abcd.push_back(c);
		abcd.push_back(d);
		sort(abcd.begin(),abcd.end());
		if((a-d == 1) || (d-a == 1) || (b-c == 1) || (c-b == 1)){
			S1.pop();
			S2.pop();
			int z;
			stringstream str4;
			str4<<abcd.at(3)<<abcd.at(0);
			str4>>z;
			S2.push(z);
			need = false;
		}
	}
	else if((S1.top() < S2.top()) && need == true){
		int temp = S1.top();
		S1.pop();
	    int m = S2.top();
	    S2.pop();
	    S1.push(m);
	    need = false;
	    if(S2.empty()){
	    	S2.push(temp);
		}else{
			S1.push(temp);
		}
	}
	else if((S1.top() >= S2.top()) && (need == true)){
		int temp = S1.top();
		S1.pop();
		S2.push(temp);
		need = false;
	}
}
  
  while(!S2.empty()){
  	cout<<S2.top()<<' ';
  	S2.pop();
  }
}












