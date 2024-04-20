#include<iostream>
#include<string.h>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class stringo {
	int id;
	string name;
	float salary;
	vector<int> v;
	public:
		void getData() {
			salary = 13;
			id = 1;
		//	strcpy(name, "pranali");
			name = "pranali";
			v.push_back(13);
			v.push_back(14);
		}
		void putData() {
			cout<<name<<endl;
			for(size_t i = 0; i < v.size(); i++) {
				cout<<v[i]<<endl;
			}
		}

};

 void write() {
	fstream file("data.dat", ios::binary | ios::app);
	if(!file) {
		cout<<"Error in opening the file";
		return;
	}
//	file.seekp(ios::end);
	stringo str;
	str.getData();
	file.write((char*) &str, sizeof(stringo));
	file.close();
}	
void read() {
	fstream file("data.dat", ios::binary  | ios::in);
	if(!file) {
		cout<<"Error in opening the file";
		return;
	}
	stringo str;
	while(1) {
		file.read((char*) &str, sizeof(stringo));
		if(file.eof())
			break;
//	cout<<str<<endl;
		str.putData();
		
	}
	file.close();
} 
int main() {
	char ch;
	int opt;
	do {
		cout<<"Select the option\n1. Write\t2. Read\n";
		cin>>opt;	
		switch(opt) {
			case 1:
				write();
				break;
			case 2:
				read();
				break;
			default:
				cout<<"Invalid Option\n";
				break;
		}
		cout<<"Do you want to contiue? (Y|y)";
		cin>>ch;
		
	} while(ch =='y' || ch == 'Y');

	cout<<sizeof(stringo)<<" "<<sizeof(float)<<" "<<sizeof(int);
	return 0;
}
