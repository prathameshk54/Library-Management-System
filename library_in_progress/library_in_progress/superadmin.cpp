#include"superadmin.h"
#include"admin.h"
#include<iostream>
#include<string.h>
#include<fstream>


void superadmin::set_data(char* id, char* pwd, long pos) {
	strcpy(iD, id);
	strcpy(pass, pwd);
	posn = pos;
}

long superadmin::getPos() {
	return posn;
}

char* superadmin::get_id() {
	char id[10];
	strcpy(id, iD);
	return id;
}

//returns true if validated, false otherwise
bool superadmin::validate_login(char *id, char *pwd) {
	if(strcmp(id, iD) == 0 && strcmp(pass, pwd) == 0)
		return true;
	else
		return false;
}

//returns 1 on success, -1 on failure
int superadmin::change_pwd() {
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
int superadmin::new_admin() {
	char id[10], pass[30], repass[30], name[20], mob[10];
	cout<<"Enter New Admin ID: ";
        gets(id);
	cout<<"Enter Name: ";
	gets(name);
	cout<<"Enter Mobile Number: ";
	gets(mob);
        cout<<"Enter Password : ";
        gets(pass);
        cout<<"Re-Enter Password : ";
        gets(repass);
       	if(!strcmp(pass, repass)) {
		admin a;
		fstream file;
                file.open("admin.dat", ios::binary | ios::app);

                if(!file) {
                	cout<<"Error opening the file\n";
                        return -1; 
                }   

                a.set_data(id, pass, file.tellp(), name, mob);                         
                file.write((char*) &a, sizeof(a));
                file.close();
                return 1;
	}   
        else {
                cout<<"Re-entered password doesn't match\n";
                return -1; 
        }   

}
	
//returns 1 on successful deletion, -1 otherwise
int superadmin::delete_admin() {
	char id[10];
	cout<<"Enter Admin-ID to be deleted\n";
	gets(id);
	fstream file;
	file.open("admin.dat", ios::binary | ios::in);
	if(!file) {
		cout<<"Error opening file\nProbably admin is never created before\n";
		return -1;
	}
	fstream tfile;
	file.open("newadmin.dat", ios::binary | ios::out);
	if(!tfile) {
		cout<<"Error opening file\n";
		return -1;
	}
	admin a;
	int flag = 0;
	while(1) {
		file.read((char*) &a, sizeof(a));
		if(file.eof()) {
			break;
		}
		if(strcmp(a.get_id(), id) == 0)	{
			flag = 1;
			continue;	
		}
	
		a.posn = tfile.tellp();
		tfile.write((char*) &a, sizeof(a));
		
	}
	file.close();
	tfile.close();

	remove("admin.dat");
	rename("newadmin.dat", "admin.dat");

	if(flag) {
		cout<<"Admin deleted succesfully\n";
		return 1;
	}
	else {
		cout<<"Admin couldn't be deleted\n";
		return -1;
	}
}
