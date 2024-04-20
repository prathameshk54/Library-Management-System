class client {
	char iD[10];
        char pass[30]; 
        long posn;
	
	//private - only admin can acess it (not even superadmin)	
        void set_data(char* id, char* pwd, long pos);
	long getPos();
	public:
        char* get_id();
        bool validate_login(char *id, char *pwd);
	int change_pwd();

	//this is for user	
	friend class admin;
	friend int ulogout(user *u);
};
