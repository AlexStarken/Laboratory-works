#include  <iostream>
#include <string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS



class User {

public:
	char login[50];
	char password[50];
	char post[50];

	User(const char* login = "Unknown", const char* password = "Unknown", const char* post = "Unknown");
	

	void Print() {
		cout << "The login is: " << login << "\n" << "The password is: " << password << "\n" << "And the post is: " << post << endl;
	}

	const char* GetLogin() {
		return login;
	}
	const char* GetPass() {
		return password;
	}
	const char* GetPost() {
		return post;
	}
	void SetLogin( const char* Login) {
		strcpy_s(login, Login);

	}
	void SetPass(const char* Pass) {
		strcpy_s(password, Pass);
	}
	void SetPost(const char* Post) {
		strcpy_s(post, Post);
	}

};

User::User(const char* login_, const char* password_, const char* post_) {
	strcpy_s(login, login_);
	strcpy_s(password, password_);
	strcpy_s(post, post_);
}

class Website {

public:
	int amount;
	User* geek_arr = new User[amount];
	Website(int amount = 0) : amount(amount), geek_arr(new User[amount]) {}
	Website(const Website& other) {
		amount = other.amount;
		geek_arr = new User[amount];
		for (int i = 0; i < amount; i++)
			geek_arr[i] = other.geek_arr[i];
	}
	~Website() {
		delete[] geek_arr;
	}

};


void Add_user(Website some_arr, int size_of_arr);

int main() {

	int number;

	cout << "Input the number of users:\n";
	cin >> number;

	Website website(number);

	for (int i = 0; i < number; i++) {

		//geek_arr[i].SetLogin("Logan");
		//geek_arr[i].SetPass("Sanders");
		//geek_arr[i].SetPost("Arrives");

		char log[50];
		char pass[50];
		char poser[50];

		cout << "Input the data about the user\n";

		cin >> log;
		cin >> pass;
		cin >> poser;


		website.geek_arr[i] = User{ log, pass, poser };

	}
	for (int i = 0; i < number; i++) {
		cout << "User" << i + 1 << ":\n";
		website.geek_arr[i].Print();
	}

	while (true) {

		cout << "\nChoose the option between following:\n\n";
		cout << "1. See the info about Users\n";
		cout << "2. Add one more user\n";
		cout << "3. Change info about user\n";
		cout << "4. Delete user\n";
		cout << "5. Exit the program\n";

		int choice;
		cin >> choice;

		switch (choice) {
			case 1:
				system("cls");
				for (int i = 0; i < number; i++) {
					cout << "User" << i + 1 << ":\n";
					website.geek_arr[i].Print();
				}
				continue;

			case 2:
				//Add_user(website, number);
				Website proksi(number + 1);
				for (int i = 0; i < number; i++) {
					proksi.geek_arr[i] = website.geek_arr[i];
				}
				char logi[50];
				char passi[50];
				char poseri[50];

				cout << "\nLogin:";
				cin >> logi;
				cout << "\nPassword:";
				cin >> passi;
				cout << "\nPost:";
				cin >> poseri;
				proksi.geek_arr[number] = User{ logi, passi, poseri };

				website = proksi;
				number++;
			
			
				continue;

			case 3:
				return 0;

			case 4: 
				return 0;

			case 5:
				return 0;

		}
	}


	return 0;

}

void Add_user(Website some_arr, int size_of_arr) {

	cout << "Input the data about new user:";

	/*Website proksi(size_of_arr + 1);


	for (int i = 0; i < size_of_arr; i++) {

		proksi.geek_arr[i] = some_arr.geek_arr[i];

	}

	char log[50];
	char pass[50];
	char poser[50];

	cout << "\nLogin:";
	cin >> log;
	cout << "\nPassword:";
	cin >> pass;
	cout << "\nPost:";
	cin >> poser;

	proksi.geek_arr[size_of_arr] = User{ log, pass, poser };

	
	some_arr = proksi;

	size_of_arr++;

*/
}


