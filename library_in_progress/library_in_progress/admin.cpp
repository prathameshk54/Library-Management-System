#include"admin.h"
#include"user.h"
#include<iostream>
#include<string.h>
#include<fstream>


void admin::set_data(char* id, char* pwd, long pos, char* nm, char* mb) {
	strcpy(iD, id);
	strcpy(pass, pwd);
	strcpy(name, nm);
	strcpy(mob, mb);
	posn = pos;
}

long admin::getPos() {
	return posn;
}

char* admin::get_id() {
	char id[10];
	strcpy(id, iD);
	return id;
}

//returns true if validated, false otherwise
bool admin::validate_login(char *id, char *pwd) {
	if(strcmp(id, iD) == 0 && strcmp(pass, pwd) == 0)
		return true;
	else
		return false;
}

//returns 1 on success, -1 on failure
int admin::change_pwd() {
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

//returns 1 on successful creation, else returns -1
int admin::new_user() {
	char id[10], pass[30], repass[30], name[20], mob[10];
	cout<<"Enter New User ID: ";
        gets(id);
	cout<<"Enter Name: ";
	gets(name);
	cout<<"Enter Mobile No: ";
	gets(mob);
        cout<<"Enter Password : ";
        gets(pass);
        cout<<"Re-Enter Password : ";
        gets(repass);
       	if(!strcmp(pass, repass)) {
		user u;
		fstream file;
                file.open("user.dat", ios::binary | ios::app);

                if(!file) {
                	cout<<"Error opening the file\n";
                        return -1; 
                }   

                u.set_data(id, pass, file.tellp(), name, mob);                         
                file.write((char*) &u, sizeof(u));
                file.close();
                return 1;
	}   
        else {
                cout<<"Re-entered password doesn't match\n";
                return -1; 
        }   

}
	
//returns 1 on successful deletion, -1 otherwise
int admin::delete_user() {
	char id[10];
	cout<<"Enter User-ID to be deleted\n";
	gets(id);
	fstream file;
	file.open("user.dat", ios::binary | ios::in);
	if(!file) {
		cout<<"Error opening file\nProbably user is never created before\n";
		return -1;
	}
	fstream tfile;
	file.open("newuser.dat", ios::binary | ios::out);
	if(!tfile) {
		cout<<"Error opening file\n";
		return -1;
	}
	user u;
	int flag = 0;
	while(1) {
		file.read((char*) &u, sizeof(u));
		if(file.eof()) {
			break;
		}
		if(strcmp(u.get_id(), id) == 0)	{
			flag = 1;
			continue;	
		}
	
		u.posn = tfile.tellp();
		tfile.write((char*) &u, sizeof(u));
		
	}
	file.close();
	tfile.close();

	remove("user.dat");
	rename("newuser.dat", "user.dat");

	if(flag) {
		cout<<"User deleted succesfully\n";
		return 1;
	}
	else {
		cout<<"User couldn't be deleted\n";
		return -1;
	}
}

int update_user_info();

int add_new_book();
int delete_book();
int update_book_info();

int new_issue();
//to undo issue, do submit

int new_submit();
//to undo submit, so issue


