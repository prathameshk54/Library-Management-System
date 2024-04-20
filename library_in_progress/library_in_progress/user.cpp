#include"user.h"
//#include"admin.h"
#include<iostream>
#include<string.h>
#include<fstream>


void user::set_data(char* id, char* pwd, long pos, char* nm, char* mb) {
	strcpy(iD, id);
	strcpy(pass, pwd);
	strcpy(name, nm);
	strcpy(mob, mb);
	posn = pos;
}

long user::getPos() {
	return posn;
}

char* user::get_id() {
	char id[10];
	strcpy(id, iD);
	return id;
}

//returns true if validated, false otherwise
bool user::validate_login(char *id, char *pwd) {
	if(strcmp(id, iD) == 0 && strcmp(pass, pwd) == 0)
		return true;
	else
		return false;
}

//returns 1 on success, -1 on failure
int user::change_pwd() {
	char pwd[30], repwd[30];
	cout<<"Enter current password: ";
	gets(pwd);
	if(strcmp(pwd, pass) == 0) {
		cout<<"Enter new password: ";
		gets(pwd);
		cout<<"Re-enter new password: ";
		gets(repwd);
		if(strcmp(pwd, repwd) == 0) {
			strcpy(pass, pwd);
			return 1;
		}
		else {
			cout<<"Re-entered password doesnt match\n";
			return -1;
		}
	}
	else {
		cout<<"Wrong Password!\n";	
		return -1;
	}
}


