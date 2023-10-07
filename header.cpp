#include<iostream>
#include "header.h"
#include<string>
using namespace std;


// ISERTING PLAYER IN THE GAME 
void dual_node::insert(string n){
	NODE* new_node = new NODE();
	new_node->name = n;
	
	if(tail == NULL){
		new_node->next = new_node;
		tail = new_node;
		cout<<"PLAYER"<<new_node->name<<" Has Inserted"<<endl;
	}
	else{
		NODE* temp = tail;
		new_node->next = tail->next;
		temp->next = new_node;
		tail = new_node;
		cout<<"PLAYER"<<new_node->name<<" Has Inserted"<<endl;

	}

}

// DELETE PLAYER FROM THE GAME
void dual_node::delete_last(){
	// IF NO NODE EXIST
	if(tail == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	
	// IF ONEY 1 NODE EXIST
	if(tail->next == tail){
		delete(tail);
		tail = NULL;
		cout<<"PLAYER"<<new_node->name<<" HAS QUIT "<<endl;

		return;
	}
	
	NODE* temp = tail->next;
	while(temp->next != tail){
		temp = temp->next;
	}
	temp->next = tail->next;
	delete(tail);
	tail = temp;
	cout<<"PLAYER"<<new_node->name<<" HAS QUIT "<<endl;
	
}

// DISPLAYING UPDATED LIST OF PLAYERS 
void dual_node::
print() {
    if (tail == NULL) {
        cout <<"\nNO PLAYER IN THE GAME" << endl;
        return;
    }

    NODE* temp = tail->next;
    cout << "\nPLAYERS ARE : ";
    do {
        cout << temp->name << ", ";
        temp = temp->next;
    } while (temp != tail->next);
}
