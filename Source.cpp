#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<windows.h>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
using namespace std;

//Global Variables
char choice;
const int MAX = 2500;
bool adminstatus; //For Admin Access Privilage
string gname, gpass; //Global name and pass
int p = 0; //Transaction Amount

//Instructions
struct person //Credentials
{
	string name, password, line[MAX];
	ifstream input;
	ofstream output;
};
struct temp_menu //Menu Objects
{
	string desc;
	double price;
}menu[200];
struct temp_sum //Price Objects
{
	string buy_history;
	int batchsize;
	double sum;
}SUM[100];

// Function Prototypes
void addREC();
void upREC();
void viewREC();
void viewFeedback();
void delREC();
void seaREC();
void errorMSG();
void reg();
void welcome();
void feedback();
bool ident(string a, string b);
void order(temp_menu menu[100], int);
void checkout();

int main()
{
	cout << fixed << setprecision(2);
		person p2;
		int choice;
		bool check = true;
		do
		{
			system("cls");
			//Fictional Company's TnC and Logo
			cout << "@Fiederick and Deutsch Foods Incorparated Terms and Conditions 2019" << endl << endl;
			cout << "MMMMMMMMMMMMMWXxc;,,,,,,,,;:::::::::::::::::::::::::;,,,,,:cccccccccccccccc:;,,,,,,,,,,cxKWMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMWXx:,,,,,,,,,,;dKXXXXXXXXXXXXXXXXXXXXXXKKx;,,,:ONNNNNNNNNNNNNNNXXK0Odl;,,,,,,,:dKWMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMNOc,,,,,,,,,,,,c0WMMMMMMMMMMMMMMMMMMMMMMWNd,,,,oXMMMMMMMMMMMMMMMMMMMMWN0xc,,,,,,,:kNMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMWKo;,,,,,,,,,,,,,oXMMMMMMMMMMMMMMMMMMMMMMWWKl,,,,xWMMMMMMMMMMMMMMMMMMMMMMMWKd;,,,,,,,oKWMMMMMMMMMM" << endl;
			cout << "MMMMMMMMW0l,,,,,,,,,,,,,,,xWMMMMMMMMWNNNNNNNNNNNNNNXk:,,,:0WMMMMMMMMN0OO00XWMMMMMMMMMNk:,,,,,,,cOWMMMMMMMM" << endl;
			cout << "MMMMMMMW0c,,,,,,,,,,,,,,,c0WMMMMMMMWOlcccccccccccccc:,,,,lXMMMMMMMMWk;,,,;:o0WMMMMMMMMNx;,,,,,,,:OWMMMMMMM" << endl;
			cout << "MMMMMMMXl,,,,,,,,,,,,,,,,oXMMMMMMMMXo,,,,,,,,,,,,,,,,,,,,xWMMMMMMMMXo,,,,,,,:OWMMMMMMMMXo,,,,,,,,lKMMMMMMM" << endl;
			cout << "MMMMMMWx;,,,,,,,,,,,,,,,,xWMMMMMMMW0c,,,,,,,,...........:0WMMMMMMMW0c,,,,,,,,oXMMMMMMMMWx,,,,,,,,,dNMMMMMM" << endl;
			cout << "MMMMMMXl,,,,,,,,,,,,,,,,c0WMMMMMMMMN0OOOOOd:,...........;xXWMMMMMMWx;,,,,,,,,lKWMMMMMMMWk;,,,,,,,,cKWMMMMM" << endl;
			cout << "MMMMMW0c,,,,,,,,,,,,,,,,oXMMMMMMMMMMMMMW0o,...............,oKWMMMMXo,,,,,,,,,lKWMMMMMMMWk;,,,,,,,,:OWMMMMM" << endl;
			cout << "MMMMMWO:,,,,,,,,,,,,,,,,xWMMMMMMMMMMMMNx,....:kOkc...,dOo...;kWMMW0c,,,,,,,,,oNMMMMMMMMWx,,,,,,,,,;kWMMMMM" << endl;
			cout << "MMMMMW0c,,,,,,,,,,,,,,,c0WMMMMMMMMWWWNx......dWMMXl..cXWx....,kWMWx;,,,,,,,,:OWMMMMMMMMXo,,,,,,,,,:OWMMMMM" << endl;
			cout << "MMMMMMXo,,,,,,,,,,,,,,,oXMMMMMMMMNxllc,.....;OMWWMKklxWNl.....cXMNo,,,,,,,,;xNMMMMMMMMWk;,,,,,,,,,lKMMMMMM" << endl;
			cout << "MMMMMMWO:,,,,,,,,,,,,,,xWMMMMMMMW0c,,.......cXMOdXMWXXW0;.....;0W0c,,,,,,,cONMMMMMMMMW0c,,,,,,,,,;kWMMMMMM" << endl;
			cout << "MMMMMMMNd,,,,,,,,,,,,,:0WMMMMMMMWx;,,.......dWNo.oNMMMWx......cXW0lcccloxOXWMMMMMMMMW0c,,,,,,,,,,oXMMMMMMM" << endl;
			cout << "MMMMMMMMXo,,,,,,,,,,,,oXMMMMMMMMNo,,,......,OWK:..o0XMNl.....;OWMWNNNNWWMMMMMMMMMMMNk:,,,,,,,,,,lKWMMMMMMM" << endl;
			cout << "MMMMMMMMMXd;,,,,,,,,,,xWMMMMMMMW0c,,,,......:.:....,:.:.....:OWMMMMMMMMMMMMMMMMMWNOl;,,,,,,,,,;oKWMMMMMMMM" << endl;
			cout << "MMMMMMMMMMNk:,,,,,,,,:0WMMMMMMMWx;,,,,,,..................:xXMMMMMMMMMMMMMMMMWX0dc,,,,,,,,,,,:xNMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMWKo;,,,,,,lKNNNNNNNNKl,,,,,,,,,.............;lx0KKKKKKKKKKKK00OOkxoc;,,,,,,,,,,,;o0WMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMN0o;,,,,;ccccccccc:;,,,,,,,,,,,,,........,;:;;;;;;;;;;;;;;;,,,,,,,,,,,,,,,,,;oONMMMMMMMMMMMMMM" << endl << endl;
			cout << "(1) Login\n(2) Register\n(3) Press any other key to exit\n";
			cout << "====================================================";
			cout << "\nChoice: ";

			while (!(cin >> choice)) //Error Checking
			{
				errorMSG();
			}
			cin.ignore(5, '\n');
			

			switch (choice) //Options for selection
			{

			case 2:
				reg();
				system("pause");
				break;
			case 1:				
				cout << "\nUsername: ";
				getline(cin, p2.name);
				cout << "\nPassword: ";
				getline(cin, p2.password);

				if (ident(p2.name, p2.password) == false)
				{
					cout << "\nInvalid Credentials! Please try again\n" << endl;
					check = true;
					system("pause");
				}
				else
				{
					

					if ((p2.name == "john") && (p2.password == "wick")) //Admin Privilage Account, name: john; pass: wick
					{
						gname = "john";
						gpass = "wick";
						adminstatus = true;
						welcome();
					}
					else //else allow access but without admin access
					{

						gname = p2.name;
						gpass = p2.password;
						adminstatus = false;
						welcome();
					}
				}
				break;
			default:
				exit(1);
				break;
			}
	
		} while (check == true); //Loops until a valid option is entered

	system("pause");

	return 0;
}

bool ident(string a, string b)
{
	ifstream iFile;
	string name[MAX], password[MAX];
	int i1 = 0, i2 = 0, x = 0, y = 0, count = 1;
	bool status = false;

	iFile.open("credentials.txt");

	if (!iFile.is_open())
	{
		cout << "Credential Verification system is currently down! Contact your network administrator" << endl;
	}
	else if (iFile.is_open())
	{
		while (!iFile.eof())
		{
			if (count % 2 != 0)
			{
				getline(iFile, name[i1]);
				x++;
				i1++;

			}
			else if (count % 2 == 0)
			{
				getline(iFile, password[i2]);
				y++;
				i2++;
			}

			count++;

		}

		//Name existence checking
		for (i1 = 0; i1 < x; i1++)
		{
			if (a == name[i1])
			{
				//Password check
				for (i2 = 0; i2 < y; i2++)
				{
					if (b == password[i2])
					{
						status = true;
					}
				}
			}
		}
	}

	return status;

}

void addREC()
{
	cout << fixed << setprecision(2);
	bool check = true;
	ofstream oFile;
	char filename[50] = "", line[MAX], yn = 'y';
	string file;

	do
	{
		system("cls");
		cout << "Welcome to the Add Records Menu (You may either add to a existing file or create a new file to add contents)" << endl;
		cout << "\n menu_chinese.txt\n menu_malay.txt\n menu_indian\n menu_japanese.txt\n menu_korean.txt\n menu_western.txt\n credentials.txt\n transaction.txt\n" << endl;
		cout << "Please enter the name of the text file you wish to add contents followed by the file extension (eg: data.txt): ";
		cin >> filename;
		cin.ignore(22, '\n');
		cout << endl;

		tolower(filename[0]);		// prevent case sensitivity
		file = filename;

		oFile.open(file, ios::app); //ios::app allows to add on from the end
	
	} while (!oFile.is_open());

	if (!oFile.is_open())
	{
		cout << "File not found! Please try again\n\n";
		system("pause");
	}
	else if (oFile.is_open())
	{
		do
		{
			//Collecting input from user
			cout << filename << " has been located!\n\n" << endl;
			cout << "Enter the contents you wish add and terminate by pressing '`' (tilde key, beside 1) followed by the Enter key: " << endl;
			cout << "Maximum 2500 characters" << endl;
			cout << "=======================================================================================================" << endl;
			cin.get(line, MAX, '`');
			cin.ignore(5, '\n');

			cout << "\nDo you wish to proceed with your current addition (y/n) or press anything else to quit: ";
			cin >> yn;
			cin.ignore(5, '\n');

			if ((yn != 'y') && (yn != 'n'))
			{
				check = false;
			}

		} while (yn == 'n');
		
		if (check == true)
		{
			//Input into file
			oFile << "\n" << line;

			//After adding to file
			cout << endl;
			cout << "Contents added succesfully! Check your file using the view records function\n" << endl;
		}
	}

	oFile.close();

	system("pause");
}

void upREC()
{
	cout << fixed << setprecision(2);
	//Variables
	char filename[50] = "", yn;
	string file, line[MAX], line_n;
	ifstream iFile;
	ofstream oFile;
	int count = 0, i = 0, num, Mcount = 1, n = 0;
	bool check = false, conf = true;
	person p1;

	system("cls");
	cout << "Welcome to the Update Records Menu\n" << endl;

	//Locating branch for either admin or member
	if (adminstatus == true)
	{
		do
		{
			cout << "\n menu_chinese.txt\n menu_malay.txt\n menu_indian\n menu_japanese.txt\n menu_korean.txt\n menu_western.txt\n credentials.txt\n transaction.txt\n" << endl;
			cout << "Please enter the name of the text file you wish to ammend followed by the file extension (eg: data.txt): ";
			cin >> filename;
			cin.ignore(22, '\n');
			cout << endl;

			tolower(filename[0]);
			file = filename;

			iFile.open(file);
		
			if (!iFile.is_open())
			{
				cout << "File not found! Please try again\n\n";
				system("cls");
			}
		
		} while (!iFile.is_open());

		
		if (iFile.is_open())
		{
			oFile.open("temp.txt");

			cout << filename << " has been located!\n\nDisplaying contents with their corresponding lines:\n" << endl;

			//Display
			while (!iFile.eof())
			{
				getline(iFile, line[i]);
				cout << ++count << " .| " << line[i] << endl;	//Saving each lines into an array
				i++;
			}

			cout << "\n\nPlease select the line that you wish to ammend (no. of line): ";
			cin >> num;
			cin.ignore(22, '\n');
			cout << "\nYou are making changes to the current line: " << line[num - 1];
			cout << "\n\nPlease enter the new content for that line: ";
			getline(cin, line_n);
			line[num - 1] = line_n;	// Replacing the line with a new line

			for (i = 0; i < count - 1; i++)
			{
				oFile << line[i] << endl;
			}

			cout << "\nChanges made! Please check using the view function\n\n";

			iFile.close();
			oFile.close();

			remove(file.c_str());
			rename("temp.txt", file.c_str());
		}
	}
	else if (adminstatus == false)
	{
		//Prompting for username
		system("cls");
		cout << "Welcome to the member credentials update page\n=================================================" << endl;
		cout << "Please key in your current username: ";
		getline(cin, p1.name);

		//Accesing credentials file
		p1.input.open("credentials.txt");
		p1.output.open("temp.txt");

		if (!p1.input.is_open())
		{
			cout << "Credential update server is currently down! Please contact your network administrator\n\n";
		}
		else if(p1.input.is_open())
		{
			while (!p1.input.eof())
			{
				getline(p1.input, line[i]);
				i++;
				n++;
			}

			for (i = 0; i < n; i++)
			{
				if (Mcount % 2 != 0)
				{
					if (p1.name == line[i])
					{
						check = true;

						//Getting new username
						cout << "\nEnter your new username: ";
						getline(cin, line_n);

						//Overwriting old username
						line[i] = line_n;

						do
						{
							cout << "\nDo you also wish to change your password? (y/n): ";
							while (!(cin >> yn))
							{
								errorMSG();
							}
							cin.ignore(5, '\n');

							if (yn == 'y')
							{
								//Prompting for new password
								cout << "\nEnter your new password: ";
								getline(cin, p1.password);

								line[i + 1] = p1.password;

							}
							else if (yn == 'n')
							{
								break;
							}
							else
							{
								cout << "\nBad input! Try again" << endl;
								cin.clear();
								cin.ignore(5, '\n');
								system("pause");
								system("cls");
							}

						} while ((yn != 'y') && (yn != 'n'));
							
					}

				}
				
				Mcount++;
			}

			if (check == true)
			{
				cout << "\n\nCredentials updated succesfully!\n\n";

				for (i = 0; i < n; i++)
				{
					p1.output << line[i] << endl;
				}

				p1.input.close();
				p1.output.close();

				remove("credentials.txt");
				rename("temp.txt", "credentials.txt");
			}
			else
			{
				p1.input.close();
				p1.output.close();
				cout << "\nUsername not found!\n" << endl;
			}
					
		}
	
	}
	
	system("pause");
}

void viewREC()
{
	cout << fixed << setprecision(2);
	ifstream iFile;
	char filename[50];
	string file, line;
	int count = 1;

	cout << "Welcome to the View Records Menu" << endl;
	
	do
	{
		//Getting file name
		cout << "As a admin you have access to the following files" << endl;
		cout << "\n menu_chinese.txt\n menu_malay.txt\n menu_indian\n menu_japanese.txt\n menu_korean.txt\n menu_western.txt\n credentials.txt\n transaction.txt\n" << endl;
		cout << "\nPlease enter the name of the text file you wish to view followed by the file extension : ";
		cin >> filename;
		cin.ignore(22, '\n');
		cout << endl;

		tolower(filename[0]); //Changing the first character to uppercase to avoid case sensitivity
		file = filename;

		iFile.open(file);

		if (!iFile.is_open())
		{
			cout << "File not found! Please try again\n\n";
			system("pause");
			system("cls");
		}
	
	} while (!iFile.is_open());

	//Getting inputs from file
	
	if (iFile.is_open())
	{
		cout << filename << " has been located!\n\nDisplaying contents below:\n" << endl;

		while (!iFile.eof())
		{
			getline(iFile, line);

			//if (count % 2 != 0)
			//{
			cout << line << endl;
			//}
			//count++;
		}

		iFile.close();
	}

	cout << endl;
	system("pause");
}

void viewFeedback()
{
	cout << fixed << setprecision(2);
	person feedback;
	string line;

	feedback.input.open("feedback.txt");

	cout << "Feedbacks\n=================" << endl;

	//View all feedback from the file
	while (!feedback.input.eof())
	{
		getline(feedback.input, line);
		cout << line << endl;
	}

	cout << endl;

	system("pause");
}

void memberviewREC()
{
	cout << fixed << setprecision(2);
	int index;
	int fchoice, count = 1, no = 1;
	ifstream iFile;
	string line, current;
	double p_line;

	index = 0; //Reinitialize the index for a new menu

	do
	{
		system("Cls");
		cout << "Welcome to the view menu page" << endl;
		cout << "Select a menu to be viewed\n============================\n1. Chinese\n2. Indian\n3. Japanese\n4. Korean\n5. Malay\n6. Western\n" << endl;
		cout << "Choose : ";
	
		while (!(cin >> fchoice))
		{
			errorMSG();
		}

		cin.ignore(5, '\n');

		switch (fchoice)
		{
		case 1:
			iFile.open("menu_chinese.txt");
			current = "Chinese Menu";
			break;
		case 2:
			iFile.open("menu_indian.txt");
			current = "Indian Menu";
			break;
		case 3:
			iFile.open("menu_japanese.txt");
			current = "Japanese Menu";
			break;
		case 4:
			iFile.open("menu_korean.txt");
			current = "Korean Menu";
			break;
		case 5:
			iFile.open("menu_malay.txt");
			current = "Malay Menu";
			break;
		case 6:
			iFile.open("menu_western.txt");
			current = "Western Menu";
			break;
		default:
			cout << "\nPlease select only between 1-6!" << endl;
			system("pause");
			break;
		}

	} while (!iFile.is_open());

	system("cls");

	cout << "Displaying " << current << "\n\n";

	//iFile get and print line while second line will be remembered as price
	while (!iFile.eof())
	{
		getline(iFile, line);
		cout << no++ << ". " << line << endl;
		iFile >> p_line;
		iFile.ignore();
		menu[index] = { line, p_line }; //Food Description and Price is saved into struct of menu
		index++;
	}
	cout << endl;
	iFile.close();

	
	do {
		cout << "Please select an option:\n1. Order\n2. Exit\nOption: ";
		while (!(cin >> fchoice))
		{
			errorMSG();
		}
		cin.ignore(5, '\n');


		switch (fchoice) {
		case 1: order(menu, index); //This function will be handling the ordering section
			break;
		case 2: welcome();
			break;
		default:
			cout << "\nPlease select only between 1-2!" << endl;
			system("pause");
			break;
		}
		cout << endl;
	} while (fchoice != 1 && fchoice != 2);


	system("pause");
}

void delREC()
{
	cout << fixed << setprecision(2);
	char filename[50]="";
	string file, search, line[MAX];
	int i = 0, count = 0, num, n = 0;
	ifstream iFile;
	ofstream oFile;

	cout << "Welcome to the Delete Records Menu\n" << endl;

	do
	{
		cout << "\n menu_chinese.txt\n menu_malay.txt\n menu_indian\n menu_japanese.txt\n menu_korean.txt\n menu_western.txt\n credentials.txt\n transaction.txt\n" << endl;
		cout << "Enter the file name to be deleted followed by the extension (eg: data.txt): ";
		cin >> filename;
		cin.ignore(22, '\n');

		tolower(filename[0]);
		file = filename;

		iFile.open(file);

		//Identifies the file
		if (!iFile.is_open())
		{
			cout << "\n\nFile not found! Please try again\n\n";
			system("pause");
			system("cls");
		}
		
		
	} while (!iFile.is_open());

	
	if (iFile.is_open())
	{
		oFile.open("temp.txt");
		cout << file << " has been located!\n\nDisplaying contents with their corresponding lines:\n" << endl;

		//Display
		while (!iFile.eof())
		{
			getline(iFile, line[i]);
			cout << ++count << " .| " << line[i] << endl;
			i++;
			n++;
		}

		cout << "\n\nEnter the number of the line you wish to delete: ";
		cin >> num;

		//Scans for that specific line and modifies it.
		for (i = 0; i < num - 1; i++)
		{
			oFile << line[i] << endl;
		}

		for (i = num; i < n; i++)
		{
			oFile << line[i] << endl;
		}

		cout << "\nThe line has been deleted, use the view function to check the file\n\n";

		iFile.close();
		oFile.close();

		remove(file.c_str());
		rename("temp.txt", file.c_str());

	}

	system("pause");
}

void seaREC()
{
	cout << fixed << setprecision(2);
	ifstream iFile;
	char filename[50]="";
	string file, search, line;
	int count = 0, save[MAX], i = 0, n = 0;

	if (adminstatus == true) {
		do
		{
			cout << "Welcome to the Search Records Menu\n" << endl;
			cout << "\n menu_chinese.txt\n menu_malay.txt\n menu_indian\n menu_japanese.txt\n menu_korean.txt\n menu_western.txt\n credentials.txt\n transaction.txt" << endl;
			cout << "Please enter the name of the text file you wish to search the contents of followed by the file extension (eg: data.txt): ";
			cin >> filename;
			cin.ignore(22, '\n');
			cout << endl;

			tolower(filename[0]);
			file = filename;

			iFile.open(file);

			//Identifies file
			if (!iFile.is_open())
			{
				cout << "File not found! Please try again\n\n";
				system("pause");
				system("cls");
			}

		} while (!iFile.is_open());

		if (iFile.is_open())
		{
			cout << "Enter the string you wish to find (case-sensitive): "; //Locate the specific line
			getline(cin, search);

			while (!iFile.eof())
			{
				getline(iFile, line);
				count++;

				if (search == line)
				{
					save[i] = count;
					i++;
					n++;
				}
			}

			//Searchs and output the location of the line
			if (i > 0)
			{
				cout << "\nYour string, " << char(34) << search << char(34) << " is located at line(s)\n";
				cout << "=======================================\n";
				for (i = 0; i < n; i++)
				{
					cout << save[i] << endl;
				}
			}
			else if (i == 0)
			{
				cout << "\n\nNo such string exist! Please try again!\n\n";
			}

		}

		iFile.close();
	}
	system("pause");
}

void reg()
{
	cout << fixed << setprecision(2);
	string name, pass, line[MAX];
	char yn;
	ofstream oFile;
	ifstream iFile;
	int count = 1, n = 0, i = 0;
	bool check;

	do
	{
		system("cls");
		cout << "Welcome to the Sign Up Page\n============================" << endl;

		do
		{	
			check = false;
				
				do
				{
				//Creating Username
				cout << "\nEnter your desired username: ";
				getline(cin, name);

				if (name.length() == 0)
				{
					cout << "\nEnter key was pressed! Try again!" << endl;
				}
		
				} while (name.length() == 0);
			

			iFile.open("credentials.txt");

			while (!iFile.eof())
			{
				if (count % 2 != 0)
				{
					getline(iFile, line[i]);
					i++;
					n++;
				}

				count++;
			}

			for (i = 0; i < n; i++)
			{
				if (name == line[i])
				{
					cout << "\nUsername already exists! Please use another name" << endl;
					check = true;
				}
			}	

		} while (check == true);
	
		do
		{
			//Creating Password
			cout << "\nEnter your password: ";
			getline(cin, pass);
			
			if (pass.length() == 0)
			{
				cout << "Enter key was pressed! Try again!\n\n" << endl;
			}
		
		} while (pass.length() == 0);

		//Confirmation
		cout << "\nConfirm your credentials? (y/n) or anything else to exit: ";
		cin >> yn;
		cin.ignore(22, '\n');

		if ((yn != 'n') && (yn != 'y'))
		{
			main();
		}	

	} while (yn == 'n');

	if (yn == 'y')
	{
		cout << "\nThank you for signing up!\n\n";

		oFile.open("credentials.txt", ios::app);

		if (oFile.is_open())
		{
			oFile << endl;
			oFile << name << endl;
			oFile << pass;
		}
	}

}

void feedback()
{
	cout << fixed << setprecision(2);
	person fback;
	char line[MAX], yn;
	bool check = true;

	fback.output.open("feedback.txt", ios::app);

	do 
	{
		system("cls");
		//Feedback comment, will end after the ` key
		cout << "Welcome to the feedback menu!\nEnter your feedback and terminate by pressing the tilde key '`' (the key beside '1')" << endl;
		cout << "=============================================================================================================================================" << endl;
		cin.get(line, MAX, '`');
		cin.ignore(5, '\n');
		
		cout << "\nDo you wish to proceed with your current feedback (y/n) or press anything else to quit: ";
		cin >> yn;
		cin.ignore(5, '\n');

		if ((yn != 'y') && (yn != 'n'))
		{
			check = false;
		}
	
	} while (yn == 'n');
	
	if (check == true) //Stores the feedback into a file
	{
		fback.output << "Feedback by user: " << gname << endl;
		fback.output << line;
		fback.output << "\n===============================END OF FEEDBACK===============================\n" << endl;

		cout << "\nFeedback received! Thanks for letting us hear from you" << endl;

	}
	
	fback.output.close();

	system("pause");

	
}

void errorMSG()
{
	cout << "\nError! Please try again";
	cin.clear();
	cin.ignore(5, '\n');
}

void welcome()
{
	cout << fixed << setprecision(2);
	ifstream iFile;
	string line, comp;
	char temp[MAX]="";
	bool check = false;

	if (adminstatus == true) //For admin only
	{		
		do
		{
			system("cls");
			cout << "@Administrator Option List" << endl;
			cout << "Choose one: " << endl;
			cout << "=====================" << endl;
			cout << "1. Add Record\n2. Update Record\n3. View Record\n4. Delete Record\n5. Search Record\n6. View Feedbacks\n7. Exit" << endl;
			cout << "Select: ";
			cin >> choice;
			cin.ignore(22, '\n');

			//Locating the branch to go
			switch (choice)
			{
		
			case 49:
				system("cls");
				addREC();
				break;
			case 50:
				system("cls");
				upREC();
				break;
			case 51:
				system("cls");
				viewREC();
				break;
			case 52:
				system("cls");
				delREC();
				break;
			case 53:
				system("cls");
				seaREC();
				break;
			case 54:
				system("cls");
				viewFeedback();
				break;
			case 55:
				exit(1);
				break;
			default:												//Error Checking 
				cout << "\nInvalid Input! Please try again\n\n";
				cin.clear();
				cin.ignore(100, '\n');
				system("pause");
				break;
			}
	
		} while (true);
	}
	else if (adminstatus == false) //For non admin
	{
		do 
		{	
			//Prompt and get the choice
			system("cls");
			cout << "@Member Option List" << endl;
			cout << "Choose one: " << endl;
			cout << "=====================" << endl;
			cout << "1. View Food Menu\n2. View Data\n3. Update Data\n4. Provide Feedback\n5. Exit" << endl;
			cout << "Select: ";
			cin >> choice;
			cin.ignore(22, '\n');

			//Locating the branch to go
			switch (choice)
			{
			case 49:
				system("cls");
				memberviewREC();
				break;
			case 50:
				system("cls");
				cout << "@User Credentials\n\n";

				cout << "Your username is: " << gname << endl;
				cout << "Your password is: " << gpass << endl << endl;
				cout << "Purchase History:\n\n";
				iFile.open("transaction.txt");

				while (!iFile.eof()) {
					getline(iFile, line);
					if (line == gname) { //Scans if the transaction user is the current user, it will display transaction of each END OF PURCHASE segments
						check = true;
						string end = "==========================END OF PURCHASE============================";
						while (line != end) {
							getline(iFile, line);
							cout << line << endl;
						}

					}
				}
				if (check == false) { //If non transaction, will display the following
					cout << "\n------------NO PURCHASE HISTORY FOUND------------\n\n";
				}
				iFile.close();
				system("pause");
				break;
			case 51:
				system("cls");
				upREC();
				break;
			case 52:
				system("cls");
				feedback();
				break;
			case 53:
				exit(1);
				break;
			default:												//Error Checking 
				cout << "\nInvalid Input! Please try again\n\n";
				cin.clear();
				cin.ignore(100, '\n');
				system("pause");
				break;
			}
		
		} while (true);

	}
}

void order(temp_menu menu[100], int index) {
	cout << fixed << setprecision(2);
	int fchoice, batch;
	bool check = true;
	double temp_price;
	char yn = 'y';

	
	cout << "Please enter the order number from THIS menu: ";
	while (!(cin >> fchoice))
	{
		errorMSG();
	}
	cin.ignore(5, '\n');

	//Identifies the food by matching it to the order number
	for (int i = 0; i < index; i++) {
		if (i == fchoice-1)
		{
			do {
				cout << menu[i].desc << endl; //Inputs the food identified from struct menu's description children object
				cout << "Comfirm selection? (y/n): "; 
				cin >> yn;
				cin.ignore(5, '\n');
				if ((yn != 'y') && (yn != 'n'))
				{
					check = false;
				}
				if (yn == 'y') {
					cout << "Please enter batch amount: "; //Incase user buys more than one, thus batch size
					cin >> batch;
					do {
						cout << "Comfirm selection? (y/n): ";
						cin >> yn;
						cin.ignore(5, '\n');
						if ((yn != 'y') && (yn != 'n'))
						{
							check = false;
						}
						if (yn == 'y') {
							temp_price = menu[i].price * batch; //Calculates the batch price by multiplying the identified food's struct price
							SUM[p] = { menu[i].desc,batch,temp_price };
							p++;
							cout << "Total Price: " << temp_price << endl;
							do {
								cout << "Comfirm Checkout? (y/n): "; //If no, then user will be able to buy other stuff before checking out, price sum is saved
								cin >> yn;
								cin.ignore(5, '\n');
								if ((yn != 'y') && (yn != 'n'))
								{
									check = false;
								}
								if (yn == 'y') {
									checkout();
								}
								else
									memberviewREC();
							} while (yn == 'n');

						}
						if (yn == 'n')
							order(menu, index);
					} while (yn == 'n');
				}
				if (yn == 'n') {
					order(menu, index);
				}
			} while (yn == 'n');
		}
	}

}

void checkout()
{
	cout << fixed << setprecision(2);
	ofstream oFile;
	char card[17];
	double totalS = 0;
	char yn;
	bool check = true;
	string passcheck, card1;

	system("cls");
	oFile.open("transaction.txt", ios::app);
	oFile << "Transaction by user:\n" << gname << endl;
	cout << "@THIS IS THE CHECK OUT RECEIPT: " << endl << endl;
	for (int i = 0; i < p; i++) {
		//Prints out all saved purchase for the current transaction
		cout << SUM[i].buy_history << endl << "Quantity: " << SUM[i].batchsize << endl << "Sum of Batch Price: RM " << SUM[i].sum << endl;
		cout << endl; 
		//Saved into a file
		oFile << SUM[i].buy_history << endl << "Quantity: " << SUM[i].batchsize << endl << "Sum of Batch Price: RM " << SUM[i].sum << endl;
		oFile << endl;
		totalS += SUM[i].sum;
	}
	cout << "Total Payment: RM " << totalS << endl << endl;
	oFile << "Total Payment: RM " << totalS << endl;
	oFile << "==========================END OF PURCHASE============================" << endl << endl; //This is a flag to segment between different user's transaction at view transaction history
	oFile.close();
	do {
		check = true;
		cout << "Please enter your card number [XXXX-XXXX-XXXX-XXXX] without dash: "; 
		cin >> card;
		cin.ignore(1, '\n');
		for (int i = 0; i < (sizeof(card) / sizeof(char)); i++) //Validates the card format
		{
			if (isalpha(card[i]))
			{
				cout << "Invalid Card Format! Try Again" << endl;
				check = false;
				break;
			}
		}

		card1 = card;

		if (check == true)
		{
			if (card1.length() != 16)
			{
				cout << "Invalid Card Format! Try Again" << endl;
				check = false;
			}
		}
	} while (check == false);
	do {
		cout << "Comfirm selection? (y/n): ";
		cin >> yn;
		cin.ignore(5, '\n');
		if ((yn != 'y') && (yn != 'n'))
		{
			check = false;
		}
		if (yn == 'y') {
			do {
				cout << "\nPlease enter your password: "; //Password is required for the final checkout
				getline(cin, passcheck);
				if (passcheck == gpass) {
					system("cls");
					cout << "Transaction Completed! Thank you for using our service." << endl; //Program termination, the transaction is completed
					exit(0);
				}
				errorMSG();
			} while (passcheck != gpass);
		}
		else {
			do { 
				check = true;
				cout << "Please enter your card number [XXXX-XXXX-XXXX-XXXX] without dash: ";
				cin >> card;
				cin.ignore(1, '\n');
				for (int i = 0; i < (sizeof(card) / sizeof(char)); i++)
				{
					if (isalpha(card[i]))
					{
						cout << "Invalid Card Format! Try Again" << endl;
						check = false;
						break;
					}
				}

				card1 = card;

				if (check == true)
				{
					if (card1.length() != 16)
					{
						cout << "Invalid Card Format! Try Again" << endl;
						check = false;
					}
				}
			} while (check == false);
		}
	} while (yn == 'n');
}
