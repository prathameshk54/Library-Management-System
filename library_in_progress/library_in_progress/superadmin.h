class superadmin {
	char iD[10];
	char pass[30];	
	long posn;

	// keeping intentionally public as superadmin doent have any parent controlling it
	//for admin and user it must be private
	public:
	void set_data(char* id, char* pwd, long pos);
	long getPos();
	public:
	char* get_id();
	bool validate_login(char *id, char *pwd);
	int change_pwd(); 

	int new_admin();
	int delete_admin();
};


