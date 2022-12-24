#include<iostream>
using namespace std;
#include<string>
#define max 1000
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Address;
};
struct AddressBook
{
	struct Person personArr[max];
	int m_Size;
};
void showMenu() {//打印目录
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl;
}
void addPerson(AddressBook *books){//添加
	if (books->m_Size == max) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		books->personArr[books->m_Size].m_Name = name;

		int sex = 0;
		while (1) {
			cout << "请输入性别：\n1.男\n2.女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
			books->personArr[books->m_Size].m_Sex = sex;
			break;
			}
		}

		int age;
		cout << "请输入年龄： " << endl;
		cin >> age;
		books->personArr[books->m_Size].m_Age = age;

		string phone;
		cout << "请输入联系电话： " << endl;
		cin >> phone;
		books->personArr[books->m_Size].m_Phone = phone;

		string add;
		cout << "请输入住址" << endl;
		cin >> add;
		books->personArr[books->m_Size].m_Address = add;

		books->m_Size++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏
	}
}
void showPerson(AddressBook books) {
	if (books.m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < books.m_Size; i++) {
			cout << "姓名：" << books.personArr[i].m_Name << endl;
			cout << "性别：" << (books.personArr[i].m_Sex==1?"男":"女") << endl;
			cout << "年龄：" << books.personArr[i].m_Age << endl;
			cout << "电话：" << books.personArr[i].m_Phone << endl;
			cout << "住址：" << books.personArr[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(AddressBook books, string name) {
	
	for (int i = 0; i < books.m_Size; i++) {
		if (books.personArr[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}
void deletePerson(AddressBook* books) {
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(*books, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		for (int i = ret; i < books->m_Size; i++) {
			books->personArr[i] = books->personArr[i + 1];
		}
		books->m_Size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(AddressBook books) {
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(books, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "姓名：" << books.personArr[ret].m_Name << endl;
		cout << "性别：" << (books.personArr[ret].m_Sex == 1 ? "男" : "女") << endl;
		cout << "年龄：" << books.personArr[ret].m_Age << endl;
		cout << "电话：" << books.personArr[ret].m_Phone << endl;
		cout << "住址：" << books.personArr[ret].m_Address << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(AddressBook* books) {
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(*books, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "请输入姓名： " << endl;
		cin >> name;
		books->personArr[ret].m_Name = name;

		int sex = 0;
		while (1) {
			cout << "请输入性别：\n1.男\n2.女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				books->personArr[ret].m_Sex = sex;
				break;
			}
		}

		int age;
		cout << "请输入年龄： " << endl;
		cin >> age;
		books->personArr[ret].m_Age = age;

		string phone;
		cout << "请输入联系电话： " << endl;
		cin >> phone;
		books->personArr[ret].m_Phone = phone;

		string add;
		cout << "请输入住址" << endl;
		cin >> add;
		books->personArr[ret].m_Address = add;

		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(AddressBook* books) {
	books->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main(){
	int select = -1;
	AddressBook books;
	books.m_Size = 0;//初始化
	

	while (1) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&books);
			break;
		case 2://显示联系人
			showPerson(books);
			break;
		case 3://删除联系人
			deletePerson(&books);
			break;
		case 4://查找联系人
			findPerson(books);
			break;
		case 5://修改联系人
			modifyPerson(&books);
			break;
		case 6://清空联系人
			cleanPerson(&books);
			break;
		case 0://退出通讯
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "请输入所选功能前的数字" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}