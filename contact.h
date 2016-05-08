#define _CRT_SECURE_NO_WARNINGS 1
#define max_name 10
#define max_tele 12
#define max_addr 30
#define max_sex   3
#define contact_max 3   //�绰��������ʼ����
#define DEFAULTSZ 3    //Ĭ��������

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

}Peo;   //������Ϣ�ṹ

//typedef struct Contact
//{
//
//	Peo contact[contact_max];  //�绰������ÿ������Ϣ��
//	int sz;//��¼��ǰ�ж��ٸ���Ч��Ϣ 
//}Con,*pcon;

typedef struct Contact
{

	Peo *contact;  //ָ��绰��
	int sz;    //��¼��ǰ�ж��ٸ���Ч��Ϣ 
	int capacity; //����
}Con, *pcon;

void init_contact(pcon _con);//��ʼ��    //������õ�ַ���ݣ�
void _add(pcon _con); //����˵���Ϣ
void _dis(const pcon _con);//��ʾ��Ϣ
void _del(pcon _con);//ɾ�� ��Ϣ
void _search(pcon _con);//����
void _mod(pcon _con);//�༭��ʾ�˵���Ϣ
void _clr(pcon _con);//���
void _sort(pcon _con);//����
void check(pcon _con);//���ռ��Ƿ��㹻�����ӿռ�
void  load(pcon _con);//����
void save(pcon _con);//����