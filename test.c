#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
enum op
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MOD,
	DIS,
	SORT,
	CLR
};//对应switch（）
void menu()
{
	printf("****  1.add      2.del     ****\n");
	printf("****  3.search   4. modify ****\n");
	printf("****  5.dis      6.sort    ****\n");
	printf("****  7.clear    0.exit    ****\n");

}
int main()
{
	Con My_con;//电话本
	init_contact(&My_con);//初始化电话本
	int input = 1;
	while (input)
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			_add(&My_con);
			break;
		case DEL:
			_del(&My_con);
			break;
		case SEARCH:
			_search(&My_con);
			break;
		case MOD:
			_mod(&My_con);
			break;
		case DIS:
			_dis(&My_con);
			break;
		case CLR:
			_clr(&My_con);
			break;
		case SORT:
			_sort(&My_con);
			break;
		case EXIT:
			save(&My_con);
			break;
		default:
			printf("选择错误");
			break;
		}
	}
	return 0;
}



//#include "contact.h"
//#define _CRT_SECURE_NO_WARNINGS 1
//
//enum op
//{
//	EXIT,
//	ADD,
//	DEL,
//	SEARCH,
//	MOD,
//	DIS,
//	SORT,
//	CLEAR,
//};
//
//void menu()
//{
//	printf("1.add      2.del   \n");
//	printf("3.search   4.modify \n");
//	printf("5.dis      6.sort   \n");
//	printf("7.clear    0.exit   \n");
//}
//int main()
//{
//	
//	Contact con;
//	Contact *my_con = &con;
//
//	int input = 1;
//	while (input)
//	{
//		menu();
//		printf("请选择");
//		scanf("%d,&input");
//		switch (input)
//		{
//		case ADD:
//				_add_contact(my_con);
//				break;
//		case DEL:
//			_del_contact(my_con);
//			break;
//		case SEARCH:
//			_search_contact(my_con);
//			break;
//		case MOD:
//			_mod_contact(my_con);
//			break;
//		case DIS:
//			_dis_contact(my_con);
//			break;
//		case CLEAR:
//			_clr_contact(my_con);
//			break;
//		case SORT:
//			_sort_contact(my_con);
//			break;
//		case EXIT:
//			Save_contact(&my_con);
//			_exit_contact(my_con);
//			break;
//		default:
//			printf("选择错误");
//         }
//		return 0;
//	}
//}
//
////int main()
////{
////	Contact mycontact;
////	pcon p = &mycontact;
////	_init_contact(p);
////	_add_contact(&mycontact);
////	//_del_contact(&mycontact);
////	FindEntry(&mycontact, "abc");
////	printf("%d", mycontact.sz);
////	return 0;
////}
