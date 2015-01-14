/*
Source code for Shell Project

You have to implement your functions here

Basic programming course
Dr.Shiri - Amirkabir university @ 2014-2015

Revision : 1.0
*/

#include "Shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	
	struct user* first_user=load_users();
	
	struct dir* home_dir = dir("home",1);
	
	while(true){
	
		struct session* s = do_login(first_user,home_dir);
		
		printf("User %s successfully logged in !\n",s->user->username);
		
		while(true) {
			printf("%s$ ",s->user->username);
			
			char cmd[100];
			gets(cmd);
			if(strcmp(cmd,"exit")==0)break;
			
			int return_code = exec_command(s,cmd,first_user);
			if(return_code!=0)
				printf("Error executing command or command not implemented !\n");	
		}
		save_users(first_user);
		printf("Logged out !\n");
	}
	
	return 0;
}

//-----------------------------------------------------------------------------------

struct user* user(const char* username,const char* password,bool is_root) {
	struct user* user = (struct user*)malloc(sizeof(struct user));

	strcpy(user->username,username);
	strcpy(user->password,password);
	user->is_root=is_root;
	user->next_user=NULL;
	
	return user;
}

//-----------------------------------------------------------------------------------

struct user* load_users() {
	struct user* first_user;
	
	//TODO : implement me !
	first_user = user("jack","123",0);
	
	return first_user;
}

//-----------------------------------------------------------------------------------

void save_users(struct user* first_user) {


	//TODO : implement me !
	
	
}

//-----------------------------------------------------------------------------------

struct session* session(struct user* user,struct dir* home_dir,struct dir* current_dir) {
	struct session* s = (struct session*)malloc(sizeof(struct session));

	s->user=user;
	s->home_dir=home_dir;
	s->current_dir=current_dir;
	
	return s;
}

//-----------------------------------------------------------------------------------

struct session* do_login(struct user* users,struct dir* home_dir) {
	
	
	//TODO : implement me !
	return session(&users[0],home_dir,home_dir);
	
	
}

//-----------------------------------------------------------------------------------

struct dir* dir(const char* name,bool is_home) {
	struct dir* dir = (struct dir*)malloc(sizeof(struct dir));
	strcpy(dir->name,name);
	dir->is_home=is_home;
	dir->childs[0]=NULL;
	return dir;
}

//-----------------------------------------------------------------------------------

char** tokenize(const char* command) {
	
	
	//TODO : implement me !
	return NULL;
	
	
}

//-----------------------------------------------------------------------------------

struct dir* getDir(struct session* session,const char* path) {
	
	
	//TODO : implement me !
	return NULL;
	
	
}

//-----------------------------------------------------------------------------------

int exec_command(struct session* session,const char* cmd,struct user* users) {
	
	
	//TODO : implement me !
	return -1;
	
	
}

//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------

int pwd(struct session* session) {
	
	
	//TODO : implement me !
	return -1;
	
	
}

//-----------------------------------------------------------------------------------

int mkdir(struct session* session,const char* name,const char* path){
	
	
	//TODO : implement me !
	return -1;
	
	
}

//-----------------------------------------------------------------------------------

int cd(struct session* session,const char* path){
	
	
	//TODO : implement me !
	return -1;
	
	
}

//-----------------------------------------------------------------------------------

int ls(struct session* session,const char* path){
	
	
	//TODO : implement me !
	return -1;
	
	
}

//-----------------------------------------------------------------------------------

int addUser(struct session* session,const char* name,struct user* users){
	
	
	//TODO : implement me !
	return -1;
	
	
}

//-----------------------------------------------------------------------------------

int rmUser(struct session* session,const char* name){
	
	
	//TODO : implement me !
	return -1;
	
	
}

//-----------------------------------------------------------------------------------

int passwd(struct session* session,struct user* users){
	
	
	//TODO : implement me !
	return -1;
	
	
}

//-----------------------------------------------------------------------------------

//TODO : implement su command
//int su(.......) {


//}
