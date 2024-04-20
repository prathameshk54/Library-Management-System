/* 
 * #include "admin.h"
 * #include "superadmin.h"
 * #include "user.h"
 * #include<string.h>
 */

int check_login();
user* ulogin();
admin* alogin();
superadmin* slogin();
int ulogout(user*);
int alogout(admin*);
int slogout(superdmin*);
