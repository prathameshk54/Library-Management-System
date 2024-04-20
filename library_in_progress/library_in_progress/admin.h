class admin {
	char iD[10];
        char pass[30]; 
        long posn;
	char name[20];
	char mob[10];
	
	//private - only superadmin can access it
        void set_data(char* id, char* pwd, long pos, char* nm, char* mb);
	long getPos();
	public;
        char* get_id();
        bool validate_login(char *id, char *pwd);
	int change_pwd();

	
	//admin specific new methods (might need correction in the declarations)
	int new_user();
	int delete_user();
	int update_user_info();

	int add_new_book();
	int delete_book();
	int update_book_info();

	int new_issue();
	//to undo issue, do submit

	int new_submit();
	//to undo submit, so issue

	friend class superadmin;
	friend int alogout(admin *a);
};
