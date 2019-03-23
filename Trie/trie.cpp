#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct node{
	map<char, node*> children;
	bool end;

	node(){
		end = false;
	}
};

class trie{
	node* root;
public:
	trie();
	void insert(string str);
	bool search(string str);
};

trie::trie(){
	root = new node();
}

void trie::insert(string str){
	node* current = root;
	for(int i = 0; i< str.size(); i++){
		node* tmp = current -> children [str[i]];
		if(!tmp){
			tmp = new node();
			current -> children [str[i]] = tmp;
		}
		current = tmp;
	}
	current-> end = true;
}

bool trie::search(string str){
	node* current = root; 
	for(int i = 0; i< str.size(); i++){
		current = current -> children [str[i]];
		if(!current){
			return false;
		}
	}
	if(current->end){return true;}
	return false;
}


int main(){
	trie* T = new trie();
	T-> insert("Haseeb");
	T-> insert("aseeb");
	T-> insert("seeb");
	T-> insert("eeb");
	T-> insert("eb");
	T-> insert("b");
	// T-> insert("Haseeb");
	// T-> insert("Ashfaq");
	// T-> insert("Manan");
	// T-> insert("Rehan");

	cout << T-> search("Haseeb") << endl;
	return 0;
}