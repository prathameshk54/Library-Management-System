#include<iostream>
#include<string.h>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
/*class stringo {
	int id;
	string name;
	float salary;
	public:
		void getData() {
			salary = 13;
			id = 1;
		//	strcpy(name, "pranali");
			name = "pranali";
		}
		void putData() {
			cout<<name<<endl;
		}

};
*/

 void write() {
	fstream file("data.dat", ios::binary | ios::app);
	if(!file) {
		cout<<"Error in opening the file";
		return;
	}
//	file.seekp(ios::end);
	vector<int> str;
//	str.getData();
//	strcpy(str, "pranali");
	str.push_back(13);
	str.push_back(14);
	file.write((char*) &str, sizeof(str));
	file.close();
}	
void read() {
	fstream file("data.dat", ios::binary  | ios::in);
	if(!file) {
		cout<<"Error in opening the file";
		return;
	}
//	char str[20];
	vector<int> str;
	while(1) {
		file.read((char*)& str, sizeof(str));
		if(file.eof())
			break;
//		cout<<str<<endl;
		for(size_t i = 0; i < str.size(); i++) {
			cout<<str[i]<<endl;
		}
//		str.putData();
		
		
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

	cout<<sizeof(string)<<" "<<sizeof(float)<<" "<<sizeof(int);
	return 0;
}
