#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;
void student();										//options for any student to facilitate from library management system
void stu_login();
void lib_login();
void add_book();									//to add book in the library stock
void edit();										//to update any book at any time
void view_all();									// to view all available books
void delete_book();
void issue_book();
void search_book();									//to search book by bookname 'authorname

													//option for students to return the b
													
													
void add_member();
void lib();											//actions performed to be by the librarian
													//to issue book to any student


struct bookinfo
{
	string name;
	string author_name;
	long int id;
	double copies;
	double shelf_no;
};
bookinfo shelfi[1000];

struct add
{
	string name;
	string authorname;
	long int id;
	double copies;
	double shelf_no;
};
add shelf[1000];
int main ()
{
	char a='1';
	while(a!='3')
	{
		system("cls");
		cout<<"**********************************************"<<endl;
		cout<<"***********   WELCOME TO LIBRARY MANAGENENT SYSTEM   ***********"<<endl;
		cout<<"**********************************************"<<endl;
		cout<<"1. login as a student"<<endl;
		cout<<"2. login as a librarian"<<endl;
		cout<<"3. exit"<<endl;
		cout<<"choose your option: ";
		cin>>a;
		if (a=='1')
		{
			system("cls");
			
			stu_login();
			system("cls");
			student();
			system("pause");
		}
		else if (a=='2')
		{
			system("cls");
			
			lib_login();
			system("cls");
			lib();
			
		}
		else if(a=='3')
		{
			system("cls");
			cout<<"THANKS FOR VISITING THE LIBRARY MANAGEMENT SYSTEM"<<endl<<"HAVE A NICE DAY !!!!!!!!!!!";
			system("exit");
			
		}
		else
		{
			system("cls");
			cout<<"choose a number from 1-3"<<endl;
			system("pause");
		}
	}
return 0;
}
void lib()							//function for the librarian to be performed by the librARUIAN
{
	int a;
	char w,r;

	
	
	
	
	
		do
		{
			system("cls");
			cout<<"**************************************WELCOME TO LIBRARY MANAGEMENT SYSTEM*******************************************"<<endl;
			cout<<"CHOOSE WHAT YOU WANT TO DO.......... "<<std::endl<<"PRESS THE RESPECTIVE NUMBER---------------"<<endl;
	
			cout<<" 1 : to add a book"<<endl;
			cout<<" 2 : to update a book"<<endl;
			cout<<" 3 : to delete a book"<<endl;
			cout<<" 4 : to search a book"<<endl;
			cout<<" 5 : to issue a book"<<endl;
			cout<<" 6 : to view all books "<<endl;
			
			cout<<" 7 : to add member "<<endl;
			cout<<" 8: back to main menue "<<endl;
			cin>>a;
		    if(a==1)
			{
				add_book();
			}
			else if(a==2)
			{
				edit();
			}
			else if(a==3)
			{
				delete_book();
				
			}
			else if(a==4)
			{
				search_book();
				
			}
			else if(a==6)
			{
				view_all();
			}
			else if(a==5)
			{
				issue_book();
			}
		
			else if(a==7)
			{
				add_member();
			}
		
			else if(a==8)
			{
				main();
			}
			else
			{
				cout<<"CHOOSE ONLY FROM 1-9"<<endl;
				system("pause");
				lib();
				
		
			}
		}while(a!=9);
		
	
	
		
	
}
void student()				//FUNCYIONS TO BE PERFORMED BY THE RECEPTIONIST
{
	cout<<"**************************************WELCOME TO LIBRARY MANAGEMENT SYSTEM*******************************************"<<endl;
	cout<<"CHOOSE WHAT YOU WANT TO DO.......... "<<endl<<"PRESS THE RESPECTIVE NUMBER---------------"<<endl;
	int e;
	
	
	
	do
	{
		cout<<" 1 : view_all books"<<endl;
		cout<<" 2 : issue a book "<<endl;
		cout<<" 3 : back to main menue "<<endl;
		
		cin>>e;
	
		if(e==1)
		{
			view_all();
			
		}
		if(e==2)
		{
			issue_book();
		}
		else if(e==3)
		{
			main();
		}
		else
		{
			main();
		}
		system("pause");
	}while(e!=4);
}
void stu_login()
{
	string username="lms.uet";
	string password="2018ce229";
	cout<<"PLEASE ENTER USERNAME : ";
	cin>>username;
	cout<<"PLEASE ENTER PASSWORD : ";
	cin>>password;
	
}
void lib_login()
{
	string username="librarian";
	string password="2018ce237";
	cout<<"PLEASE ENTER USERNAME : ";
	cin>>username;
	cout<<"PLEASE ENTER PASSWORD : ";
	cin>>password;
}
void add_book()                      	//to add the book in members record
{
	char b;
	string a,e;
	int c,d;
	
	ofstream write;
	write.open("123.txt",ios::app);
	int i=0;
	do
	{
			if(shelf[i].id==0 && shelf[i].copies==0)
			{
				cout<<"PLease enter book name :"<<endl;
				cin>>shelf[i].name;
			
				cout<<"Please enter author name : "<<endl;
				cin>>shelf[i].authorname;
		
				cout<<" PLease enter id : "<<endl;
				cin>>shelf[i].id;
				
				cout<<"Please enter copies : " <<endl;
				cin>>shelf[i].copies;
				write<<shelf[i].name<<" "<<shelf[i].authorname<<" "<<shelf[i].id<<" "<<shelf[i].copies<<endl;
				shelf[i].shelf_no=i;
			}
		
		cout<<"DO you want to add another ()y/n : "<<endl;
		cin>>b;
		i++;
	}while(b=='y');
		
		write.close();
		cout<<i;
}
void search_book()
{
	int b_id,index=0;
	int p=0;
	string b_name;
	ifstream abc;
	abc.open("123.txt");

	cout<<" you want to seach book by "<<endl;
	cout<<" 1 : search book by id ";
	cout<<" 2 : search book by name ";
	cout<<" 3 : return to librarian account";
	cin>>p;
	if(p==1)
	{
		cout<<" enter book id "<<endl;
		cin>>b_id;
		for(int i=1;i<=999;i++)
		{
			if(b_id==shelfi[i].id)
			{
				index=i;
				break;
			}
		}
	}
	if(p==2)
	{
		cout<<" please enter book name "<<endl;
		cin>>b_name;
		for(int j=1;j<=999;j++)
		{
			if(b_name==shelfi[j].name)
			{
				index=j;
				break;
				
			}
		}
		
	}
	if(p==3)
	{
		lib();
	}
	for(int k=0;k<=20;k++)
	{
		
	
		abc>>shelfi[k].name>>shelfi[k].author_name>>shelfi[k].id>>shelfi[k].copies;
		
	}
	abc.close();

	cout<<"*******************************************************************************"<<endl;
	cout<<"NAME            "<<"AUTHORNAME        "<<"       ID           "<<"COPIES           "<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<shelfi[index].name<<setw(20)<<shelfi[index].author_name<<setw(20)<<shelfi[index].id<<setw(20)<<shelfi[index].copies;
	cout<<endl<<"*********************************************************************************"<<endl;
	cout<<endl;
	search_book();
}
void edit()
{
	int b_id,index=0;
	int c=0;
	string b_name	;
	ifstream abc;
	abc.open("123.txt");
	ofstream adc;
	adc.open("123.txt",ios::app);

	cout<<" you want to seach book by "<<endl;
	cout<<" 1 : search book by id ";
	cout<<" 2 : search book by name ";
	cout<<" 3: to return back to main menue";
	cin>>c;
	if(c==1)
	{
		cout<<" enter book id "<<endl;
		cin>>b_id;
		for(int i=1;i<=999;i++)
		{
			if(b_id==shelfi[i].id)
			{
				index=i;
				break;
			}
		}
	}
	if(c==2)
	{
		cout<<" please enter book name "<<endl;
		cin>>b_name;
		for(int j=1;j<=999;j++)
		{
			if(b_name==shelfi[j].name)
			{
				index=j;
				break;
				
			}
		}
		
	}
	if(c==3)
	{
		lib();
	}
	for(int k=0;k<=20;k++)
	{
		
	
		abc>>shelfi[k].name>>shelfi[k].author_name>>shelfi[k].id>>shelfi[k].copies;
		
	}
	abc.close();

	cout<<"*******************************************************************************"<<endl;
	cout<<"NAME            "<<"AUTHORNAME        "<<"       ID           "<<"COPIES           "<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<shelfi[index].name<<setw(20)<<shelfi[index].author_name<<setw(20)<<shelfi[index].id<<setw(20)<<shelfi[index].copies;
	cout<<endl<<"*********************************************************************************"<<endl;
	cout<<endl;
		int s,id;
	string name,authorname;
	if(index!=0)
	{
		cout<<"please enter book name : "<<endl;
		cin>>name;
		shelfi[index].name=name;
		cout<<"please enter authorname : "<<endl;
		cin>>authorname;
		shelfi[index].author_name=authorname;
		cout<<"please enter id no"<<endl;
		shelfi[index].id=id;
		cout<<"please enter number of copies "<<endl;
		cin>>s;
		shelfi[index].copies=s;
		cout<<"YOUR BOOK RECORD HAS BEEN UPDATED /EDITED .................."<<endl;
		adc<<shelfi[index].name<<shelfi[index].author_name<<shelfi[index].id<<shelfi[index].copies;
	}
	else
	{
		cout<<" SORRY.....WE HAVE BEEN UNSUCCESSFUL TO FIND YOUR CONCERNED BOOK !!!!!"<<endl;
	}
	adc.close();

	edit();
	lib();
}
void  delete_book()
{
	//search the book to delete it
	int b_id,index=0;
	int c=0;
	string b_name	;
	cout<<" you want to seach book by "<<endl;
	cout<<" 1 : search book by id ";
	cout<<" 2 : search book by name ";
	cin>>c;
	view_all();
	ifstream del;
	del.open("123.txt");
	for (int k=0;k<=999;k++)
	{
		del>>shelfi[k].name>>shelfi[k].author_name>>shelfi[k].id>>shelfi[k].copies;
	}
	del.close();
	if(c==1)
	{
		cout<<" enter book id "<<endl;
		cin>>b_id;
		for(int i=1;i<=999;i++)
		{
			if(b_id==shelfi[i].id)
			{
				index=i;
				break;
			}
		}
		for(int i=index;i<=999;i++)
			{
				if(shelfi[i].id!=0 && shelfi[i].copies!=0)
				{
				shelfi[i].author_name=shelfi[i+1].author_name;
				shelfi[i].copies=shelfi[i+1].copies;
				shelfi[i].id=shelfi[i+1].id;
				shelfi[i].name=shelfi[i+1].name;
				}
			}
			cout<<"book deleted"<<endl;
		}
		
	
	else if(c==2)
	{
		cout<<" please enter book name "<<endl;
		cin>>b_name;
		for(int j=1;j<=999;j++)
		{
			if(b_name==shelfi[j].name)
			{
				index=j;
				break;
				
			}
		}
			if(index!=0)		//deleting the index quantity 
		{
			for(int i=index;i<=999;i++)
			{
				if(shelfi[i].id!=0 && shelfi[i].copies!=0)
				{
				shelfi[i].author_name=shelfi[i+1].author_name;
				shelfi[i].copies=shelfi[i+1].copies;
				shelfi[i].id=shelfi[i+1].id;
				shelfi[i].name=shelfi[i+1].name;
				}
			}
		}
		cout<<"book deleted"<<endl;
	}
	ofstream rel;
	rel.open("123.txt");
	for(int i=0;i<=999;i++)
	{
		rel<<shelfi[i].name<<" "<<shelfi[i].author_name<<" "<<shelfi[i].id<<" "<<shelfi[i].copies<<endl;
	}
	rel.close(); 
	system("pause"); 
}
struct members
{
	string name;
	string reg_no;
	int phone_no;
};
members mem[100000];

void add_member()
{
	char b;
	

	
	ofstream write;
	write.open("member.txt",ios::app);
	int i=0;
	do
	{

		cout<<"PLease enter member name :"<<endl;
		cin>>mem[i].name;
	
		cout<<"Please enter reg no : "<<endl;
		cin>>mem[i].reg_no;

		cout<<" PLease enter phone no : "<<endl;
		cin>>mem[i].phone_no;
		
	
		write<<mem[i].name<<" "<<mem[i].reg_no<<" "<<mem[i].phone_no<<endl;
		mem[i].reg_no=i;
	
		
		cout<<"DO you want to add another ()y/n : "<<endl;
		cin>>b;
		i++;
	}while(b=='y');
			
	write.close();
	lib();
}
void view_all()
{


	char b;
	

	
	cout<<"BOOKNAME	  AUTHOR NAME		        	BOOK ID 		COPIES"<<endl;
	ifstream file1;
	file1.open("123.txt");
	
	
		for(int i=1;i<=10;i++)
		{
				
					
			file1>>shelf[i].name>>shelf[i].authorname>>shelf[i].id>>shelf[i].copies;
			cout<<shelf[i].name<<setw(20)<<shelf[i].authorname<<setw(35)<<shelf[i].id<<setw(20)<<shelf[i].copies<<endl;
		
			
		}
	
			
	file1.close();
	system("pause");
}
void issue_book()
{
	int a,b,d;
	int b_id,index=0;
	int o=0;
	string b_name	;
	ifstream abc;
	abc.open("123.txt");

	cout<<" you want to seach book by "<<endl;
	cout<<" 1 : search book by id ";
	cout<<" 2 : search book by name ";
	cin>>o;
	if(o==1)
	{
		cout<<" enter book id "<<endl;
		cin>>b_id;
		for(int i=1;i<=999;i++)
		{
			if(b_id==shelfi[i].id)
			{
				index=i;
				break;
			}
		}
	}
	if(o==2)
	{
		cout<<" please enter book name "<<endl;
		cin>>b_name;
		for(int j=1;j<=999;j++)
		{
			if(b_name==shelfi[j].name)
			{
				index=j;
				break;
				
			}
		}
		
	}
	if(o==3)
	{
		lib();
	}
	for(int k=0;k<=20;k++)
	{
		
	
		abc>>shelfi[k].name>>shelfi[k].author_name>>shelfi[k].id>>shelfi[k].copies;
		
	}
	abc.close();

	cout<<"*******************************************************************************"<<endl;
	cout<<"NAME            "<<"AUTHORNAME        "<<"       ID           "<<"COPIES           "<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<shelfi[index].name<<setw(20)<<shelfi[index].author_name<<setw(20)<<shelfi[index].id<<setw(20)<<shelfi[index].copies;
	cout<<endl<<"*********************************************************************************"<<endl;
	cout<<endl;
	cout<<"enter date in the format  dd/mm/yyyy"<<endl;
	cout<<"enter date "<<endl;
	cin>>a;
	cout<<"enter month "<<endl;
	cin>>b;
	cout<<"enter year "<<endl;
	cin>>d;
	string reg_no;
	cout<<"Enter registration num :";
	cin>>reg_no;
	ofstream fel;
	fel.open("issue.txt",ios::app);
	for(int i=0;i<20;i++)
	{
	if(reg_no==mem[i].reg_no)
	{
	
	fel<<shelfi[i].name<<setw(20)<<shelfi[i].author_name<<setw(20)<<shelfi[i].id<<setw(20)<<shelfi[i].copies<<mem[i].reg_no<<a<<"/"<<b<<"/"<<d;
	
	}}
	fel.close();
	cout<<"book has been issued on date "<<a<<"/"<<b<<"/"<<d<<endl;
	
	issue_book();
}


