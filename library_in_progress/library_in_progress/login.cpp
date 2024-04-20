//this will login to the admin /  super admin / user account and return corresponding object from the file

#include<iostream>
#include<fstream>
#include "login.h"
#include "admin.h"
#include "user.h"
#include "superadminadmin.h"
#include<string.h>
#include<stdlib.h>

//main funtion will call check_login first to check whether there exists superadmin or not
//returns 0 if exists, else creates a superadmin and returns 1, if creation failed returns -1
int check_login() {
	fstream file;
	char id[10], pass[30], repass[30];
	file.open("superadmin.dat", ios::binary | ios::in);
	if(!file) {
		cout<<"System needs a superadmin\n";
		cout<<"Enter New Superadmin ID: ";
		gets(id);
		cout<<"Enter Password : ";
		gets(pass);
		cout<<"Re-Enter Password : ";
		gets(repass);
		if(!strcmp(pass, repass)) {
			superadmin s;
			file.open("superadmin.dat", ios::binary | ios::app);

			if(!file) {
				cout<<"Error opening the file\n";
				return -1;
			}

			s.set_data(id, pass, file.tellp());			
			file.write((char*) &s, sizeof(s));
			file.close();
			return 1;
		}
		else {
			cout<<"Re-entered password doesn't match\n";
			return -1;
		}
		
	}
	else {
		file.close();
		return 0;
	}
}


/*	int opt;
	count<<"1. User\t2.Admin\t3. Superadmin\n";
	cout<<"Enter your choice for login: ";
	cin>>opt; */



//returns special value for unsucessful login and corresponding object for sucessful login

user* ulogin() {
	fstream file;
	file.open("user.dat", ios::binary | ios::in); 
	if(!file) {
		cout<<"Error! Contact Admin\n";
		return special_value;
	}
	else {
		user *u = new user;
		cout<<"Enter ID : ";
		gets(id);
		cout<<"Enter Password : ";
		gets(pass);
		while(1) {
			file.read((char*) u, sizeof(*u));
			if(file.eof()) {
				cout<<"Enter valid ID-Password\n";
				file.close();	
				free(u);
				return special_value;
			}
			if((*u).validate_login(id, pass)) 
				break;
		}
		file.close();
		return u;
	}
		
}

admin* alogin() {
	fstream file;
	file.open("admin.dat", ios::binary | ios::in);
	if(!file) {
		cout<<"Error! Contact Superdmin\n";
		return special_value;
	}
	else {
		admin *a = new admin;
		cout<<"Enter ID : ";
		gets(id);
		cout<<"Enter Password : ";
		gets(pass);
		while(1) {
			file.read((char*) a, sizeof(*a));
			if(file.eof()) {
				cout<<"Enter valid ID-Password\n";
				file.close();
				return special_value;
			}
			if((*a).validate_login(id, pass)) 
				break;
		}
		file.close();
		return a;
	}	
}
	
superadmin* slogin() {
	fstream file;
	file.open("superadmin.dat", ios::binary | ios::in);
	if(!file) {
		cout<<"Error! Restart the application\n";
		return special_value;
	}
	else {
		superadmin *s = new superadmin;
		cout<<"Enter ID : ";
		gets(id);
		cout<<"Enter Password : ";
		gets(pass);
		while(1) {
			file.read((char*) s, sizeof(*s));
			if(file.eof()) {
				cout<<"Enter valid ID-Password\n";
				file.close();
				return special_value;
			}
			if((*s).validate_login(id, pass)) 
				break;
		}
		file.close();
		return s;
	}
		

}

int ulogout(user* u) {
	if(u == NULL)
		return -1;
	fstream file;
	file.open("user.dat", ios::binary | ios::in | ios::out);
	if(!file) {
		cout<<"Error opening the file\n";
		return -1;
	}
	long pos = (*u).getPos();
	file.seekp(pos);
	file.write((char*) u, sizeof(*u));
	file.close();
	delete u;
	u = NULL;
	cout<<"Successfully logged out\n";
	return 1;
}

int alogout(admin *a) {
	if(a == NULL)
		return -1;
	fstream file;
	file.open("admin.dat", ios::binary | ios::in | ios::out);
	if(!file) {
		cout<<"Error opening the file\n";
		return -1;	
	}
	long pos = (*a).getPos();
	file.seekp(pos);
	file.write((char*) a, sizeof(*a));
	file.close();
	delete a;
	a = NULL;
	cout<<"Sucessfully logged out\n";
	return 1;
}

int slogout(superadmin *s) {
	if(s == NULL)
		return -1;
	fstream file;
	file.open("superadmin.dat", ios::binary | ios::in | ios::out);
	if(!file) {
		cout<<"Error opening the file\n";
		return -1;	
	}
	long pos = (*s).getPos();
	file.seekp(pos);
	file.write((char*) s, sizeof(*s));
	file.close();
	delete s;
	s = NULL;
	cout<<"Sucessfully logged out\n";
	return 1;
}
