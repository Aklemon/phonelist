#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void check(pcon _con)
{
	if ((_con->sz) >= (_con->capacity))
	{
		_con->contact = (Peo*)realloc(_con->contact, (_con->capacity + DEFAULTSZ)*sizeof(Peo));
		_con->capacity = _con->capacity + DEFAULTSZ;
	}
	if (_con->capacity == NULL)
	{
		perror("����ʧ��");
		exit(NULL_FAILURE);
	}

}
void _add(pcon _con)
{
	check(_con);
	/*if (_con->sz >= contact_max)
	{
	printf("�绰�����ˣ�\n");
	return;
	}*/
	printf("�������֣�");
	scanf("%s", _con->contact[_con->sz].name);
	printf("�����Ա�");
	scanf("%s", _con->contact[_con->sz].sex);
	printf("�������䣺");
	scanf("%d", &_con->contact[_con->sz].age);//ע�������ȡ��ַ
	printf("����绰��");
	scanf("%s", _con->contact[_con->sz].tele);
	printf("�����ַ: ");
	scanf("%s", _con->contact[_con->sz].addr);
	_con->sz++;
	printf("��ӳɹ�\n");
}

void _dis(const pcon _con)
{
	int i = 0;
	if (_con->sz <= 0)
	{
		printf("�绰��Ϊ��\n");
		return;
	}
	//�������
	printf("%10s\t%5s\t%3s\t%12s\t%10s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (; i < _con->sz; i++)
	{
		printf("%10s\t%5s\t%3d\t%12s\t%10s\n",
			_con->contact[i].name,
			_con->contact[i].sex,
			_con->contact[i].age,
			_con->contact[i].tele,
			_con->contact[i].addr);
	}
}

//void init_contact(pcon _con)     //��ʼ���绰��
//{
//	_con->sz = 0;
//	memset(_con->contact,0, contact_max*sizeof(Peo));
//}

void init_contact(pcon _con)     //��ʼ��
{
	_con->sz = 0;
	_con->contact = (Peo*)malloc(contact_max*sizeof(Peo));
	if (NULL == _con->contact)
	{
		printf("out of memory");
		exit(NULL_FAILURE);
	}
	memset(_con->contact, 0, contact_max*sizeof(Peo));
	_con->capacity = contact_max;
	load(_con);

}

int find_entry(pcon _con, char *find_name)//����
{
	int i = 0;
	for (; i < _con->sz; i++)
	{
		if (strcmp(find_name, _con->contact[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void _del(pcon _con)
{
	int pos = 0;
	int i = 0;
	char name[max_name];
	if (_con->sz <= 0)
	{
		printf("�绰��Ϊ��");
		return;
	}
	printf("����Ҫɾ���˵����֣� ");
	scanf("%s", name);

	pos = find_entry(_con, name);
	if (pos == -1)
	{
		printf("������");
		return;
	}
	for (i = pos; i < _con->sz - 1; i++)
		//���һ������Ҫ�ƶ�
	{
		_con->contact[i] = _con->contact[i + 1];
	}

	_con->sz--;
	printf("ɾ���ɹ�\n");
}

void view(pcon _con, int pos)
{
	printf("%10s\t%5s\t%3d\t%12s\t%10s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	printf("%10s\t%5s\t%3d\t%12s\t%10s\n",
		_con->contact[pos].name,
		_con->contact[pos].sex,
		_con->contact[pos].age,
		_con->contact[pos].tele,
		_con->contact[pos].addr);
}
void _search(pcon _con)
{
	int pos = 0;
	char name[max_name];
	printf("�������֣�");
	scanf("%s", name);
	pos = find_entry(_con, name);
	view(_con, pos);
}

void _mod(pcon _con)
{
	int pos = 0;
	char name[max_name];
	pos = find_entry(_con, name);
	if (pos == -1)
	{
		printf("û�������ϵ�ˣ�\n");
		return;
	}
	//_add(_con);
	//_con->sz--;
	view(_con, pos);
	printf("�༭��ϵ��\n");
	printf("�������֣�");
	scanf("%s", _con->contact[_con->sz].name);
	printf("�Ա�");
	scanf("%s", _con->contact[pos].sex);
	printf("���䣺");
	scanf("%s", &_con->contact[pos].age);
	printf("�绰��");
	scanf("%s", _con->contact[pos].tele);
	printf("��ַ: ");
	scanf("%s", _con->contact[pos].addr);
	printf("�༭�ɹ���\n");
}
//���������ϵ��
void _clr(pcon _con)
{
	_con->sz = 0;
	memset(_con->contact, NULL, contact_max*sizeof(Peo));
}
//������ϵ��
void _sort(pcon _con)
{
	int i = 0;
	int j = 0;
	if (_con->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	for (i = 0; i < _con->sz; i++)
	{
		for (j = 0; j < _con->sz - 1 - i; j++)
		{
			//����������
			if (strcmp(_con->contact[j].name, _con->contact[j + 1].name)>0)
			{
				Peo  tmp = _con->contact[j];
				_con->contact[j] = _con->contact[j + 1];
				_con->contact[j + 1] = tmp;
			}
		}
	}
	return;
}

void  load(pcon _con)
{
	int i = 0;
	FILE * read = fopen(FILENAME, "r");
	if (read == NULL)
	{
		perror("open file contact.dat for read");
		exit(EXIT_FAILURE);
	}

	while (fread(&(_con->contact[_con->sz]), sizeof(Peo), 1, read))
	{
		_con->sz++;
	}
	//_con->sz = i;
	check(_con);

	fclose(read);
}

void save(pcon _con)
{
	int i = 0;
	FILE * write = fopen(FILENAME, "w");
	if (write == NULL)
	{
		perror("open file contact.dat for write");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < _con->sz; i++)
	{
		fwrite(&(_con->contact[i]), sizeof(Peo), 1, write);
	}
	fclose(write);
	free(_con->contact);
}







//#define _CRT_SECURE_NO_WARNINGS 1
//#include "contact.h"
//int sz;
//int capacity;
//
//
//void _init_contact(Contact *_con)
//{
//	_con->sz = 0;
//	memset(_con->con, 0, MAX*sizeof(Peo));
//}
//
//void _add_contact(Contact *_con ,Peo*p)
//{
//	{
//		check_capacity(_con);
//		_con->con[_con->sz] = *p;
//		_con->sz++;
//	}
//
//	/*if (_con->sz >= MAX)
//	{
//		printf("�绰������\n");
//		return;
//	}*/
//
//	printf("����������");
//	scanf("%s", _con->con[_con->sz].name);
//	printf("�������Ա�");
//	scanf("%s", _con->con[_con->sz].sex);
//	printf("����������");
//	scanf("%d", &_con->con[_con->sz].age);
//	printf("������绰");
//	scanf("%s", _con->con[_con->sz].tele);
//	printf("�������ַ");
//	scanf("%s", _con->con[_con->sz].addr);
//	_con->sz++;
//	printf("��ӳɹ�\n");
//}
//void init_contact(Contact *_con)
//{
//	_con->sz = 0;
//	_con->con = (Peo*)malloc(DEFAULT_sz*sizeof(Peo));
//	if (NULL == _con->sz)
//	{
//		printf("out of memory\n");
//		exit(EXIT_FAILURE);
//	}
//	memset(_con->con, 0, (DEFAULT_sz)*sizeof(Peo));
//	_con->con = DEFAULT_sz;
//}
//void check_capacity(Contact *_con)
//{
//	if (_con->sz = _con->capacity)//��Ҫ����
//	{
//		int sz = (_con->capacity) + DEFAULT_sz*sizeof(Peo);
//		_con->con = relloc(_con->con, sz);
//		Peo*tmp = (Peo*)relloc(_con->con, sz);
//		if (tmp != NULL)
//		{
//			_con->con = tmp;
//		}
//		_con->con = _con->capacity + DEFAULT_sz;
//	}
//}
//void load_Contact(Contact *_con)
//{
//	Peo peo = { 0 };
//	FILE*Read = fopen(FILENAME, "r");
//	if (Read == NULL)
//	{
//		perror("open file contact.data for read");
//		exit(EXIT_FAILURE);
//    }
//	while (fread(&peo, sizeof(Peo), 1, Read))
//	{
//		_add(_con, &peo);
//	}
//}
//
//void save_Contact(Contact *_con)
//{
//	FILE*write = fopen(FILENAME, "w");
//	if (write = NULL)
//	{
//		perror("open file contact.data for wwrite");
//		exit(EXIT_FAILURE);
//	}
//	int i = 0;
//	for (i = 0; i < _con->sz; i++)
//	{
//		fwrite(&(_con->con[i]), sizeof(Peo), 1, write);
//	}
//}
//
//int FindEntry(pcon _con, char*findname)
//{
//	int i = 0;
//	for (i = 0; i < _con->sz; i++)
//	{
//		if (strcmp(findname, _con->con[i].name) == 0)
//		{
//			return i;
//		}
//	}
//	return-1;
//}
//
//
//
//
//
//	void _del_contact(Contact *_con)
//	{
//		int pos = 0;
//		int i = 0;
//		char name[MAX_NAME] = { 0 };
//		if (_con->sz == 0)
//		{
//			printf("�绰���ѿ�");
//			return;
//		}
//		printf("������Ҫɾ���˵�����");
//		scanf("%s", &name);
//		pos = FindEntry(_con, name);
//		if (pos == -1)
//		{
//			printf("Ҫɾ�����˲�����");
//		}
//		for (i = pos; i < _con->sz - 1; i++)
//		{
//			_con->con[i] = _con->con[i + 1];
//		}
//
//	}
//
//
//	
//	
//	/*
//	char toBedel[MAX_NAME];
//	printf("������Ҫɾ�����˵�����");
//	scanf("%s", toBedel);
//
//	strcmp(toBedel,_con->sz);
//	int i = 0;
//	printf("%10s\t%5s\t%3s\t%12s\t%10s\n",
//		"name", "sex", "age", "tele", "addr");
//	for (i = 0; i < _con->sz; i++)
//	{
//
//		printf("%10s\t%5s\t%3s\t%12s\t%10s\n",
//			_con->con[i].name,
//			_con->con[i].sex,
//			_con->con[i].age,
//			_con->con[i].tele,
//			_con->con[i].addr);
//
//	}
//}
//
//
//*/
//
///*
//
//
//int FindEntry(pCon _con char*findname)
//{
//	int i = 0;
//	for (i = 0; i < _con->sz; i++)
//	{
//		if (stecmp(findname, _con->con[i].name) == 0)
//		{
//			return i;
//		}
//	}
//	return-1;
//}
//
//
//void _del_contact(pCon _con);
//{
//	int pos = 0;
//	int i = 0;
//	char name[MAX_NAME] = { 0 };
//	if (_con->sz == 0)
//	{
//		printf("�绰���ѿ�")��
//			return;
//	}
//	printf("������Ҫɾ���˵�����");
//	scanf("%s", &name);
//	pos = FindEntry(_con, name);
//	if (pos == -1)
//	{
//		printf("Ҫɾ�����˲�����");
//	}
//	for (i = pos; i < _con.sz-1; i++)
//	{
//		_con->con[i] = con->con[i+1]
//	}
//
//
//
//
//}
//void _search_contact(pCon _con);
//void _modify_contact(pCon _con);
//void _clear_contact(pCon _con);
//void _sort_contact(pCon _con);
//*/