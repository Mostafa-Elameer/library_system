
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

const int size_of_system = 100;
int book_id[size_of_system] = {};
string book_title[size_of_system] = {};
string book_author[size_of_system] = {};
bool book_status[size_of_system] = {};
int current_book_counter = 0;

//menu main 
void menu_main()
{
	system("color 4f");

	cout << "==============================\n";
	cout << "welcome to library system \n";
	cout << "==============================\n\n";

	cout << "CHOOSE OPTIONS \n";
	cout << "1- add new book \n";
	cout << "2- borrow book \n";
	cout << "3- return book \n";
	cout << "4- delet book \n";
	cout << "5- update book \n";
	cout << "6- searsh on book \n";
	cout << "7- list all book \n";
	cout << "8- exit program \n";
	cout << "enter an option \n";
}

//menu update 
void menu_update()
{
	system("color 2f");

	cout << "whit do you wont to update ?\n";
	cout << "1- update title \n";
	cout << "2- update author \n";
	cout << "3- update astutas \n";
	cout << "4- exit \n";
	cout << "enter an option \n";
}

//searsh id found or not 
int searsh_id(int id) {
	for (int i = 0; i < current_book_counter; i++) {
		if (id == book_id[i])
			return i;
	}
	return -1;
}

//add book 1
void add_book(string title, string author) {

	book_id[current_book_counter] = current_book_counter + 1;
	book_title  [current_book_counter] = title;
	book_author [current_book_counter] = author;
	book_status [current_book_counter] = true;
	current_book_counter++;
	cout << "\nthis book aded seccussflay\n";
}

//show book 
void display_info(int id) {

	if (searsh_id(id) == -1) {
		cout << "this id is not found \n";
		return;
	}

	cout << "========================\n";
	cout << "book id : "     << book_id      [id - 1] << endl;
	cout << "book title : "  << book_title   [id - 1] << endl;
	cout << "book author : " << book_author  [id - 1] << endl;
	cout << "status book : " << (book_status [id - 1] ? "avilabe" : "not avilabe") << endl;
	cout << "========================\n";

}

// borrow book 
void borrow_book(int id) {
	if (searsh_id(id) == -1) {
		cout << "this book is not found \n";
		return;
	}
	if (book_status[id - 1] == true) {
		book_status[id - 1] = false;
		cout << "tihs book is borrow successfolly\n";

		return;
	}
	if (book_status[id - 1] == false) {
		cout << "this book is alridy borrow\n";
		return;
	}
}

// return book 
void return_book(int id) {

	if (searsh_id(id) == -1) {
		cout << "this book is not fount \n";
		return;
	}
	if (book_status[id - 1] == false) {
		book_status[id - 1] = true;
		cout << "this book is return seccussfaly \n";
		return;
	}
	if (book_status[id - 1] == true) {
		cout << "this book is alrady avilabe \n";
		return;
	}
}

//delet book
void delet_book(int id) {
	if (searsh_id(id) == -1) {
		cout << "this id not found \n";
		return;
	}
	for (int i = book_id[searsh_id(id)]; i < current_book_counter; i++) {
		book_id     [i] = book_id    [i+1]-1;
		book_title  [i] = book_title [i + 1];
		book_author [i] = book_author[i + 1];
		book_status [i] = book_status[i + 1];
	}
	current_book_counter--;
	cout << "this book delet successfully \n\n";
}

//update book 
void update_book(int id) {
	if (searsh_id(id) == -1) {
		cout << "this id not found \n";
		return;
	}

	int choose;
	bool flag = true;
	while (flag) {
		menu_update();
		cin >> choose;
		string inbut;
		switch (choose) {
		case 1:
			cout << "enter new title ?\n";
			cin >> inbut;
			book_title[searsh_id(id)] = inbut;
			break;
		case 2:
			cout << "enter new author ?\n";
			cin >> inbut;
			book_author[searsh_id(id)] = inbut;
			break;
		case 3:
			break;
		case 4:
			flag = false;
			break;
		}
	}

}

// show one book for searsh 
void searsh_book(int id) {
	if (searsh_id(id) == -1) {
		cout << "this book is not found \n";
		return;
	}
	if (searsh_id(id) == id - 1) {
		display_info(id);
	}
}

//show all book 6
void show_all_books() {
	for (int i = 0; i < current_book_counter; i++) {
		display_info(book_id[i]);
	}

}

static void name() {
	system("color 2f");
	cout << "  ##       ###       ##  ######   ##       @@@@     @@@@        ###        ###      ######" << endl;
	cout << "  ##      ## ##      ##  ##       ##      @@      @@    @@     ## ##      ## ##     ##    " << endl;
	cout << "   ##     ##  ##    ##   ##       ##     @@      @@      @@   ##   ##     ##  ##    ##    " << endl;
	cout << "    ##   ##   ##   ##    ######   ##     @@      @@      @@   ##    ##   ##    ##   ######" << endl;
	cout << "     ## ##     ## ##     ##       ##      @@      @@    @@   ##      ## ##     ##   ##    " << endl;
	cout << "      ##        ###      ######   ######   @@@@     @@@@     ##       ###       ##  ######" << endl;
}

int main() {
	int id;
	string title, author;
	name();

	system("pause");
	system("cls");

	bool flag = true;
	while (flag) {
		menu_main();
		int choose_user;
		cin >> choose_user;
		switch (choose_user) {
		case 1:
			cout << "enter title book \n";
			cin.ignore();
			getline(cin, title);

			cout << "enter author book \n";
			/*cin.ignore();*/
			getline(cin, author);
			add_book(title, author);
			break;
		case 2:
			//borrow book
			cout << "enter book id do you wont borrow \n";
			cin >> id;
			borrow_book(id);
			break;
		case 3:
			// return book 
			cout << "enter id book yo want return \n";
			cin >> id;
			return_book(id);
			break;
		case 4: // delet book 
			cout << "enter id book do you wont delet \n";
			cin >> id;
			delet_book(id);
			break;
		case 5: // update book 
			cout << "enter id book do you wont update \n";
			cin >> id;
			update_book(id);
			break;
		case 6: // searsh on book 
			cout << "searsh book do you want \n";
			cin >> id;
			searsh_book(id);
			break;
		case 7:
			show_all_books();
			break;
		case 8:
			flag = false;
			cout << "thank you for used system \n";
			break;
		default:
			break;

		}
		system("pause");
		system("cls");
	}

	cout << "\n\n			made by ----> eng / mostafa elameer \n\n";

}