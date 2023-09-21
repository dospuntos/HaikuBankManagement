#include "App.h"
#include "MainWindow.h"
#include "AccountQuery.h"

App::App(void)
		:		BApplication("application/x-vnd.dpd-BankManagement")
{
	MainWindow *mainwin = new MainWindow();
	mainwin->Show();	
}

int main(void)
{

	App *app = new App(); 
	app->Run();
	delete app;

/*	account_query A;
	int choice;
	
	cout << "***Account Information System***" << endl;
	while(true)
	{
		cout << "Select one option below ";
		cout << "\n\t1. -->Add record to file";
		cout << "\n\t2. -->Show record from file";
		cout << "\n\t3. -->Search Record from file";
		cout << "\n\t4. -->Update Record";
		cout << "\n\t5. -->Delete Record";
		cout << "\n\t6. -->Quit";
		cout << "\nEnter your choice: ";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				A.write_rec();
				break;
			case 2:
				A.read_rec();
				break;
			case 3:
				A.search_rec();
				break;
			case 4:
				A.edit_rec();
				break;
			case 5:
				A.delete_rec();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout << "\nEnter correct choice";
				exit(0);
				break;
		}
	}
	
	system("pause"); */
	
	
	return 0;
}
