//*********************
// HEADER FILES USED
//*********************

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#define size 1000

//*****************************************
// CLASS CONTAINING ALL THE FUNCTIONS USED
//*****************************************

class book_shop
{
char book_name[size],writer_name[size],type[size];
char person_name[size],address[size],id[50],date[20],asked_type[50];
char phone_number[15];
float price,price2;
int total_books;
public:

//***********************
// TO TAKE BOOK DETAILS
//***********************

void getdata()
 {
 cout<<"enter the book_name,writer_name,id,type";
 gets(book_name);
 gets(writer_name);
 gets(id);
 gets(type);
 cout<<"enter price";
 cin>>price;
 cout<<"enter total books of this categeory";
 cin>>total_books;
 }

//***********************
// TO SHOW BOOK DETAILS
//***********************

void showdata()
   {
   cout<<"book id =\t";
   puts(id);
   cout<<"book name =\t";
   puts(book_name);
   cout<<"book`s writer =\t";
   puts(writer_name);
   cout<<"book`s category =";
   puts(type);
   cout<<"book`s price =\t"<<price<<endl;
   cout<<"total books are="<<total_books<<endl;
   cout<<"========================================";
   }

//*****************************
// FUNCTION TO RETURN CATEGORY
//*****************************

char *book_type()
       {
       return type;
       }

//***************************
// TO GET PERSON`S DETAILS
//***************************

void getperson_details()
 {
 cout<<"enter person`s name,address";
 gets(person_name);
 gets(address);
 cout<<"enter phone no. of the person";
 gets(phone_number);
 cout<<"enter the date of purchasing,id of book and name";
 gets(date);
 gets(id);
 gets(book_name);
 cout<<"enter the paid money";
 cin>>price2;
 }

//****************************
// TO SHOW PERSON`S DETAILS
//****************************

void showperson_details()
   {
   cout<<"name =";
   puts(person_name);
   cout<<"address =";
   puts(address);
   cout<<"phone number =";
   puts(phone_number);
   cout<<"date of purchasing =";
   puts(date);
   cout<<"book purchased :";
   cout<<"id=";
   puts(id);
   cout<<"book name=";
   puts(book_name);
   cout<<"money paid =";
   cout<<price2<<endl;
   }

//***********************
// FUNCTION TO RETURN ID
//***********************

char *getid()
      {
      return id;
      }

//*****************************
// TO TAKE INPUT OF THE BOOKS
//*****************************

void input_data()
{
fstream f("stock.dat",ios::out|ios::binary);
book_shop b;
char ch,re,ab,op,pu;
 do
  {
      b.getdata();
      cout<<"want to save the records ('y/n')";
      cin>>ch;
      if(tolower(ch)=='y')
	  {
	    f.write((char *)&b,sizeof(b));
	    cout<<"records saved_ _ _ _ _"<<endl;
	    cout<<"want to enter more records ('y/n')";
	    cin>>re;
	    }
     else if(tolower(ch)=='n')
	{
       cout<<"records not saved_ _ _ _ _"<<endl;
       cout<<"Do you again want to enter the records ('y/n')";
       cin>>ab;
		  if(tolower(ab)=='y')
		    {
			 do
		       {
			 b.getdata();
			 cout<<"want to save the records ('y/n')";
			 cin>>op;
			 if(tolower(op)=='y')
			   {
			    f.write((char *)&b,sizeof(b));
			    cout<<"records saved_ _ _ _ _"<<endl;
			    cout<<"want to enter more records ('y/n')";
			    cin>>pu;
			    }
		       }while(tolower(pu)=='y');
			  break;
		    }
	else
	 {
	 cout<<endl<<endl<<endl;
	 cout<<" No records entered_ _ _ _ _ _ _ _ _ _"<<endl;
	 }
       }
}while(tolower(re)=='y');
     f.close();
     cout<<endl<<endl;
     cout<<"Do you want to continue ('y/n')";
     cin>>ch;
	if(tolower(ch)=='y')
	 {
	  choice_function();
	 }
    else
     {
     cout<<endl<<endl;
     cout<<" PRESS ANY KEY TO EXIT........"<<endl;
     }
}

//*******************************
// TO SHOW THE STOCK IN THE SHOP
//*******************************

void show_data()
{
fstream f1("stock.dat",ios::in|ios::binary);
book_shop b1;
char ch;
while(f1.read((char *)&b1,sizeof(b1)))
  {
    b1.showdata();
    cout<<endl;
  }
f1.close();
cout<<endl<<endl;
cout<<"Do you want to continue ('y/n')";
     cin>>ch;
     if(tolower(ch)=='y')
     {
     choice_function();
     }
     else
	{
	cout<<endl<<endl;
	cout<<" PRESS ANY KEY TO EXIT........"<<endl;
	}
}

//********************
// TO MODIFY RECORDS
//********************

void modify_data()
{
fstream f6("stock.dat",ios::in|ios::out|ios::binary);
book_shop p3;
char id4[10],re,ch;
cout<<"do you want to modify some records ('y/n')";
cin>>re;
if(tolower(re)=='y')
{
do
{
     cout<<"enter the id which you want to modify";
     gets(id4);
     while(!f6.eof())
	{
	 f6.read((char *)&p3,sizeof(p3));
	 if(strcmpi(p3.getid(),id4)==0)
	    {
	      cout<<"enter the details"<<endl;
	      f6.seekg(f6.tellg()-sizeof(p3),ios::beg);
	      p3.getdata();
	      f6.write((char *)&p3,sizeof(p3));
	      break;
	    }
       }
     cout<<"want to modify more records ('y/n')";
     cin>>re;
   }while(tolower(re)=='y');
}
else
    {
    cout<<"========================"<<endl;
    cout<<" THANK YOU"<<endl;
    cout<<endl;
    }
f6.close();
cout<<endl<<endl;
cout<<"Do you want to continue ('y/n')";
     cin>>ch;
     if(tolower(ch)=='y')
     {
     choice_function();
     }
       else
	{
	 cout<<endl<<endl;
	 cout<<" PRESS ANY KEY TO EXIT........"<<endl;
	}
}

//******************************
// TO SHOW THE MODFIED DETALS
//******************************

void showmodified_data()
{
fstream f7("stock.dat",ios::in|ios::binary);
book_shop p4;
char ch;
cout<<"modified data :"<<endl<<endl;
while(f7.read((char *)&p4,sizeof(p4)))
  {
   p4.showdata();
   cout<<endl;
  }
f7.close();
cout<<endl<<endl;
cout<<"Do you want to continue ('y/n')";
     cin>>ch;
     if(tolower(ch)=='y')
     {
     choice_function();
     }
	else
	 {
	  cout<<endl<<endl;
	  cout<<" PRESS ANY KEY TO EXIT........"<<endl;
	 }
}

//*******************************************************
// TO SEARCH THE BOOKS OF THE PARTICULAR CATEGORY AND ID
//*******************************************************

void search_book()
{
fstream c("type.dat",ios::binary|ios::out);
book_shop b2;
char type2[10],ch,ab,id2[10];
do
{
fstream f2("stock.dat",ios::in|ios::binary);
cout<<"enter type to be searched";
gets(type2);
cout<<"enter id to be searched";
gets(id2);
while(!f2.eof())
  {
   f2.read((char *)&b2,sizeof(b2));
   if((strcmpi(b2.book_type(),type2)==0)&&(strcmpi(b2.getid(),id2)==0))
    {
      f2.seekg(0);
      c.write((char *)&b2,sizeof(b2));
      b2.showdata();
      cout<<endl;
      break;
    }
   }
      if(f2.eof())
	{
	 f2.seekg(0);
	 cout<<"---------------------------------------"<<endl;
	 cout<<" book of this id and type not in stock"<<endl;
	 cout<<"---------------------------------------"<<endl<<endl;
	 f2.close();
	}
cout<<"Do you want to search again ('y/n')";
cin>>ch;
}while(tolower(ch)=='y');
c.close();
cout<<endl<<endl;
cout<<"Do you want to continue ('y/n')";
     cin>>ab;
     if(tolower(ab)=='y')
     {
     choice_function();
     }
	else
	 {
	 cout<<endl<<endl;
	 cout<<" PRESS ANY KEY TO EXIT........"<<endl;
	 }
}


//*******************************************************
// TO ENTER PERSON`S DETAILS AND TO CONFIRM THAT HE/SHE
// WILL PURCHARE THE  BOOK OR NOT
//*******************************************************

void getper_details()
{
      fstream s("perdetail.dat",ios::out|ios::binary);
      book_shop e;
      char cp,ch;

do
{
      cout<<"do you want to purchase the book('y/n')";
      cin>>cp;
      if((tolower(cp)=='y'))
      {
      cout<<"enter the details of the person"<<endl;
      e.getperson_details();
      s.write((char *)&e,sizeof(e));
      }
cout<<"do you want to enter more records ('y/n')";
cin>>ch;
}while(tolower(ch)=='y');
cout<<"=========================="<<endl;
cout<<" THANK YOU"<<endl;
cout<<endl;
 s.close();
 cout<<endl<<endl;
 cout<<"Do you want to continue ('y/n')";
     cin>>ch;
     if(tolower(ch)=='y')
     {
     choice_function();
     }
	else
	 {
	  cout<<endl<<endl;
	  cout<<" PRESS ANY KEY TO EXIT........"<<endl;
	 }
}

//**************************
// TO SHOW PERSON`S DETAILS
//**************************

void showper_details()
{
fstream s1("perdetail.dat",ios::in|ios::binary);
book_shop e1;
char ch;
while(s1.read((char *)&e1,sizeof(e1)))
   {
     cout<<"person`s details are:"<<endl;
     cout<<"============================================================="<<endl;
     cout<<endl;
     e1.showperson_details();
     cout<<endl;
   }
 s1.close();
 cout<<endl<<endl;
 cout<<"Do you want to continue ('y/n')";
     cin>>ch;
     if(tolower(ch)=='y')
     {
     choice_function();
     }
       else
	{
	 cout<<endl<<endl;
	 cout<<" PRESS ANY KEY TO EXIT........"<<endl;
	}
}

//*******************************************
// TO DELETE THE RECORD OF THE BOOK PURCHASED
//*******************************************

void delete_records()
{
fstream f3("stock.dat",ios::in|ios::binary);
fstream d("stocks.dat",ios::out|ios::binary);
book_shop p;
char id3[10],ch,ph;
cout<<"want to delete any record ('y/n')";
cin>>ph;
	if(tolower(ph)=='y')
	 {
do
{
cout<<"enter the id which you want to delete";
gets(id3);
while(!f3.eof())
    {
     f3.read((char *)&p,sizeof(p));
     if(strcmpi(p.getid(),id3)!=0)
     d.write((char *)&p,sizeof(p));
    }
f3.close();
d.close();
remove("stock.dat");
rename("stocks.dat","stock.dat");
cout<<"want to delete more records ('y/n')";
cin>>ch;
}while(tolower(ch)=='y');
	 }
	  else
	    {
	    cout<<"========================="<<endl;
	    cout<<" THANK YOU";
	    cout<<endl;
	    }
cout<<endl<<endl;
cout<<"Do you want to continue ('y/n')";
     cin>>ch;
     if(tolower(ch)=='y')
     {
     choice_function();
     }
	else
	  {
	  cout<<endl<<endl;
	  cout<<" PRESS ANY KEY TO EXIT........"<<endl;
	  }
}

//**************************************
// TO SHOW THE BOOKS IN THE STOCK LEFT
//**************************************

void books_left()
{
  fstream f4("stock.dat",ios::in|ios::binary);
  book_shop p1;
  char ch;
  cout<<"stock in the shop left:"<<endl<<endl;
  while(f4.read((char *)&p1,sizeof(p1)))
	  {
	   p1.showdata();
	   cout<<endl;
	  }
  f4.close();
  cout<<endl<<endl;
  cout<<"Do you want to continue ('y/n')";
     cin>>ch;
     if(tolower(ch)=='y')
     {
     choice_function();
     }
     else
	 {
	 cout<<endl<<endl;
	 cout<<" PRESS ANY KEY TO EXIT........"<<endl;
	 }
}

//********************
// TO ADD NEW RECORDS
//********************

void add_data()
 {
fstream f5("stock.dat",ios::out|ios::app|ios::binary);
book_shop p2;
char dr,ch;
cout<<"do you want to add some new records ('y/n')";
cin>>dr;
if((tolower(dr)=='y'))
    {
      do
	{
	 p2.getdata();
	 f5.write((char *)&p2,sizeof(p2));
	 cout<<"do you want to enter more records ('y/n')";
	 cin>>dr;
	}while(tolower(dr)=='y');
    }
	else
	{
	cout<<"========================"<<endl;
	cout<<" THANK YOU"<<endl;
	cout<<endl;
	}
f5.close();
cout<<endl<<endl;
cout<<"Do you want to continue ('y/n')";
     cin>>ch;
     if(tolower(ch)=='y')
     {
     choice_function();
     }
      else
	{
	cout<<endl<<endl;
	cout<<" PRESS ANY KEY TO EXIT........"<<endl;
	}
 }

//********************************
// TO CHOOSE THE DESIRED FUNCTION
//********************************

void choose_function()
{
int no;
cout<<"enter your choice"<<endl;
cin>>no;
if(no==1)
{
textcolor(60);
clrscr();
input_data();
}
else if(no==2)
 {
 textcolor(2);
 clrscr();
 show_data();
 }
  else if(no==3)
   {
   textcolor(3);
    clrscr();
    modify_data();
   }
     else if(no==4)
      {
      textcolor(4);
       clrscr();
       showmodified_data();
      }
	    else if(no==5)
	       {
	       textcolor(6);
		clrscr();
		search_book();
	       }
       else if(no==6)
	 {
	 textcolor(62);
	  clrscr();
	  getper_details();
	 }
     else if(no==7)
      {
      textcolor(9);
       clrscr();
       showper_details();
      }
   else if(no==8)
   {
   textcolor(10);
     clrscr();
     delete_records();
   }
 else if(no==9)
 {
 textcolor(11);
   clrscr();
   books_left();
 }
else if(no==10)
{
textcolor(10);
clrscr();
add_data();
}
 else if(no==11)
 {
 exit(1);
 }
       else
	   {
	    cout<<"wrong input"<<endl;
	    cout<<"again enter your choice";
	    cin>>no;
 if(no==1)
 {
 textcolor(60);
  clrscr();
  input_data();
 }
else if(no==2)
 {
 textcolor(2);
 clrscr();
 show_data();
 }
  else if(no==3)
   {
   textcolor(3);
    clrscr();
    modify_data();
   }
     else if(no==4)
      {
      textcolor(4);
       clrscr();
       showmodified_data();
      }
	    else if(no==5)
	       {
	       textcolor(6);
		clrscr();
		search_book();
	       }
       else if(no==6)
	 {
	 textcolor(3);
	  clrscr();
	  getper_details();
	 }
     else if(no==7)
      {
      textcolor(9);
       clrscr();
       showper_details();
      }
   else if(no==8)
   {
   textcolor(10);
     clrscr();
     delete_records();
   }
 else if(no==9)
 {
 textcolor(10);
   clrscr();
   books_left();
 }
else if(no==10)
{
textcolor(12);
clrscr();
add_data();
}
 else
 {
 exit(1);
 }
	 }
}

//****************************
// TO ENTRE YOUR CHOICE
//****************************

void choice_function()
 {
 textcolor(5);
clrscr();
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout<<endl;
cout<<"================================CHOICE SCREEN================================="<<endl;
cout<<endl;
cout<<endl;
cout<<" # Enter 1: To enter the stock "<<endl;
cout<<" # Enter 2: To see the stock in the shop"<<endl;
cout<<" # Enter 3: To modify data"<<endl;
cout<<" # Enter 4: To see modified data"<<endl;
cout<<" # Enter 5: To search a perticular category and a id of book "<<endl;
cout<<" # Enter 6: To enter the person details"<<endl;
cout<<" # Enter 7: To see person`s details"<<endl;
cout<<" # Enter 8: To delete the records if you want"<<endl;
cout<<" # Enter 9: To see stock left after deleting"<<endl;
cout<<" # Enter 10: To add new records"<<endl;
cout<<" # Enter 11: To exit"<<endl;
cout<<endl;
cout<<"*******************************************************************************"<<endl;
cout<<endl;
choose_function();
 }

//***************************
// FUNCTION FOR FIRST PAGE
//***************************

void first_page()
{
   textcolor(11);
   clrscr();
   char ch;
   cout<<endl<<endl<<endl<<endl<<endl;
   cout<<"*************************************************************************"<<endl;
   cout<<" \t\t\t\t\t\t\t\t\t\t\t\t\t\tPROJECT ON "<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\tBOOK  SHOP"<<endl;
   cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t\t\tDeveloped by - - - - - - - - "<<endl;
   cout<<endl<<" \t\t\t\t\t\t\t\t\t\t\t\t\t\tSHAGUN AGRAWAL"<<endl<<endl;
   cout<<"************************************************************************"<<endl<<endl;
   cout<<endl<<endl;
   cout<<" To start press 'Y'"<<endl;
     cin>>ch;
     if(tolower(ch)=='y')
     {
     choice_function();
     }
       else
       {
	cout<<" PRESS ANY KEY TO EXIT _ _ _ _ _ _ _ _"<<endl;
       }
  }
    };
void main()
{
   clrscr();
   book_shop b;
   b.first_page();
   getch();
}






