/*
Header file for Shell Project

You can use this template for implementing your project

feel free to do any modifications, you are not forced !
but you should have a reasonable reason for changing some parts of it !


Also keep in your mind that Global Variables Are Bad !!
	-> http://c2.com/cgi/wiki?GlobalVariablesAreBad 

	
Basic programming course
Dr.Shiri @ 2014-2015


Revision : 1.0
*/

#pragma once //Read more about this : http://www.cprogramming.com/reference/preprocessor/pragma.html

#define max_dir_childs 32

#define bool char // bool exists in the current ANSI C - C99, but not in C89/90 !

//-------------------------------------------------------------------------------------------------
//--- Structures
//-------------------------------------------------------------------------------------------------

struct dir {
	char name[30];
	bool is_home;
	struct dir *childs[max_dir_childs];//null terminated
};

struct user {
	char username[30];
	char password[30];
	bool is_root;
	
	//you can use it for implementing a linked list
	struct user* next_user;
};

struct session {
	struct user* user;
	struct dir* home_dir;
	struct dir* current_dir;
};

//-------------------------------------------------------------------------------------------------
//--- Some helper functions
//-------------------------------------------------------------------------------------------------

//create new user
struct user* user(const char* username,const char* password,bool is_root);

//load users file passwd.txt into a Linked list of User
struct user* load_users();

//Save back users file to passwd.txt
void save_users(struct user* first_user);

//create new session
struct session* session(struct user* user,struct dir* home_dir,struct dir* current_dir);

//do login
struct session* do_login(struct user* users,struct dir* home_dir);

//create new directory structure
struct dir* dir(const char* name,bool is_home);

//Splits command with space to an array of strings (char*)
char** tokenize(char* command);

//Returns pointer to directory from path
struct dir* getDir(struct session* session,const char* path);

//Executes the command
int exec_command(struct session* session,const char* cmd,struct user* users);

//-------------------------------------------------------------------------------------------------
// Commands 
// they return an integer number ( 0 of no error or any other number in case of error )
//-------------------------------------------------------------------------------------------------

//print current working directory's full address
int pwd(struct session* session);

//Create directory with name 
int mkdir(struct session* session,const char* name,const char* path);

//Changes session->current_dir to new path
//Don't forget to check permissions !
int cd(struct session* session,const char* path);

//Print contents of current directory or path if path is not NULL
int ls(struct session* session,const char* path);

//Create a user 
//Don't forget to check permissions !
int addUser(struct session* session,const char* name,struct user* users);

//Removes a user
//Don't forget to check permissions !
int rmUser(struct session* session,const char* name,struct user* users); // user or root cannot delete itself !!

//Changes current user password
//Don't forget to check permissions !
int passwd(struct session* session,struct user* users);


//TODO : define su command
//int su(.......);
