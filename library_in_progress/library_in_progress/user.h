class user {
	char iD[10];
        char pass[30]; 
	char name[20];
	char mob[10];
        long posn;
	
	//private - only admin can acess it (not even superadmin)	
        void set_data(char* id, char* pwd, long pos, char* nm, char* mb);
	long getPos();
	public:
        char* get_id();
        bool validate_login(char *id, char *pwd);
	int change_pwd();
	
	friend class admin;
	friend int ulogout(user *u);
};
