#define _CRT_SECURE_NO_WARNINGS 1
#define max_name 10
#define max_tele 12
#define max_addr 30
#define max_sex   3
#define contact_max 3   //电话本人数初始容量
#define DEFAULTSZ 3    //默认增长数

#define NULL_FAILURE 1
#define FILENAME "contact.dat"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Peo
{
	char name[max_name];
	char sex[max_sex];
	int age;
	char tele[max_tele];
	char addr[max_addr];

}Peo;   //个人信息结构

//typedef struct Contact
//{
//
//	Peo contact[contact_max];  //电话本（存每个人信息）
//	int sz;//记录当前有多少个有效信息 
//}Con,*pcon;

typedef struct Contact
{

	Peo *contact;  //指向电话本
	int sz;    //记录当前有多少个有效信息 
	int capacity; //容量
}Con, *pcon;

void init_contact(pcon _con);//初始化    //这里采用地址传递！
void _add(pcon _con); //添加人的信息
void _dis(const pcon _con);//显示信息
void _del(pcon _con);//删除 信息
void _search(pcon _con);//查找
void _mod(pcon _con);//编辑显示人的信息
void _clr(pcon _con);//清空
void _sort(pcon _con);//分类
void check(pcon _con);//检查空间是否足够，增加空间
void  load(pcon _con);//下载
void save(pcon _con);//保存