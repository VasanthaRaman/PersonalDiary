#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
#include<stdio.h>
 class record
 {
 char date[12];
 char time[8];
 char name[30];
 char place[25];
 char duration[20];
 char phone[11];
 char note[500];
 public:
 void get(char d[],char t[]);
 void put();
 int checkdate(char d[],char t[]);
 void delrec(char d[],char t[]);
 void modify();
 }e;
 long int pointer;
 void addrecord();
 void viewrecord();
 void editrecord();
 void deleterecord();
 int password();
 void editpassword();
 ifstream fin;
 ofstream fout;
 int cnt;
 int main()
 {
 int ch; clrscr();
 cout<<"\n Welcome !!";
 while(1)
 {
 cout<<"\n Main Menu\n";
 cout<<"1.Add Record\n";
 cout<<"2.View Record\n";
 cout<<"3.Edit Record\n";
 cout<<"4.Delete Record\n";
 cout<<"5.Edit Password\n";
 cout<<"6.Exit\n";
 cout<<"Enter your choice\n";
 cin>>ch;
 switch(ch)
 {
 case 1: addrecord();
	 break;
 case 2: viewrecord();
	 break;
 case 3: editrecord();
	 break;
 case 4: deleterecord();
	 break;
 case 5: editpassword();
	 break;
 case 6: cout<<"\n THANK YOU";
	 getch();
	 exit(0);
default: cout<<"\n Wrong choice\n";
	 cout<<"Press any key to try again!\n";
	 getch();
	 break;
 }
clrscr();
}
return 0;
}
void addrecord()
{   int tu;
clrscr();
cout<<"\n Welcome to ADD MENU :)\n";
char another='Y';  char idate[12],itime[8];
fout.open("khh.dat",ios::app);
if(!fout)
{cout<<"\n System error";
cout<<"\n Press any key to exit";
getch();
return;}
while((another=='y')||(another=='Y'))
{
 cout<<"\n Enter date of record(dd-mm-yyyy)";
 cin>>idate;
 cout<<"\n Enter time of record(hh:mm)";
 cin>>itime;
 tu=e.checkdate(idate,itime);
 if(tu!=2)
 {ifstream fiin;fiin.open("cnt.txt");
 if(!fiin){cnt=0;}
 else{fiin>>cnt;}
 fiin.close();
 cnt++;
 e.get(idate,itime);
 fout.write((char*)&e,sizeof(e));
 ofstream off;off.open("cnt.txt");
 off<<cnt;off.close();
 cout<<"\n Enter another record? Y\N";
 cin>>another;
 }else
 {cout<<"\n There is a record already..!Try editing it in edit menu";
 cout<<"\n Try again..?(Y/N)";
 cin>>another;
 } }
 cout<<"\n Press any key to go to main menu";
 getch();
 fout.close();  ofstream fcnt; fcnt.open("cnt.txt");
  fcnt<<cnt; fcnt.close();
  cout<<cnt;
 return;
 }
void viewrecord()
{ cout<<"\n Welcome to view menu";
  char word[30],vdate[12],vtime[8],dec='y';
  int choice,k;    ifstream fh;
  check=password();
  if(check!=0)
  {return;}
  do
  {
  cout<<"\n Enter date(dd-mm-yyyy)";
  cin>>vdate;
  cout<<"\n Enter time(hh:mm)";
  cin>>vtime;
  k=e.checkdate(vdate,vtime);
  if(k==2)
  {fh.open("khh.dat",ios::in||ios::binary);
  fh.seekg(0,ios::beg);
   fh.seekg(pointer);
  e.put();
  fh.close(); }
  else if (k==3)
  {
  cout<<"\n No record on date";
  cout<<"\n Press any key to exit";
  getch(); fh.close();
  return;
  }
  cout<<"\n Want to continue";
  cin>>dec;
  }while((dec=='Y')||(dec=='y'));
  }
 void deleterecord()
 { char ddate[12], dtime[8], dec='y'; int choice;      ifstream ff;
 cout<<"\n Welcome to Delete menu \n";
 check=password();
  if(check!=0)
  {return;}
 while((dec=='Y')||(dec=='y'))
 {
 cout<<"\n Enter date(dd-mm-yyyy)";
 cin>>ddate;
 cout<<"\n Enter time(hh:mm)";
 cin>>dtime;
int k=e.checkdate(ddate,dtime);
if(k==2)
{ ff.open("khh.dat",ios::in);
  ff.seekg(pointer);
  ff.read((char*)&e,sizeof(e));
  e.put();
  cout<<"\n This record is deleted";
  ff.close();
 e.delrec(ddate,dtime);
 cout<<"\n Want to delete any other??";
 cin>>dec;
 }
 else
 {cout<<"\n No such record. Want to try again? Press y/n";
  cin>>dec;
 }}
 cout<<"\n Press any key to exit";
 getch();
 return;
 }
 void record:: delrec(char d[],char t[])
 {
 ifstream finr;
 ifstream fjj; fjj.open("cnt.txt",ios::nocreate);
 fjj>>cnt;
  fjj.close();
 if(cnt==1)
 {remove("khh.dat");cnt--;
 ofstream fd;fd.open("cnt.txt");
 fd<<cnt;
 fd.close();
 fstream fg;fg.open("xx.dat",ios::binary);fg.close();
 rename("xx.dat","khh.dat");
 }else
 {  finr.open("khh.dat",ios::in);fout.open("tepp.dat",ios::binary);
 finr.seekg(0,ios::beg);
 for(int i=0;i<cnt;i++)
 {
 finr.read((char*)&e,sizeof(e));
 if((strcmp(d,e.date)==0)&&(strcmp(t,e.time)==0))
 {cout<<' '<<'\b';   }
 else
 {fout.write((char*)&e,sizeof(e)); }
 } cnt--; ofstream fd; fd.open("cnt.txt");fd<<cnt;fd.close();
   finr.close();
   fout.close();
   remove ("khh.dat");
   rename("tepp.dat","khh.dat");
 }}
 void record :: get(char d[],char t[])
 {
 strcpy(e.date,d);
 strcpy(e.time,t);
 cout<<"\n enter name";
 gets(e.name);
 cout<<"\n enter phone no.";
 cin>>e.phone;
 cout<<"\n enter duration";
 gets(e.duration);
 cout<<"\n Enter the place of meeting";
 gets(e.place);
 cout<<"\n enter note. Give '$' at the end and press enter";
 cin.getline(e.note,500,'$');
 }
 int record::checkdate(char d[], char t[])
 {
 ifstream fcheck;
 fcheck.open("khh.dat",ios::binary||ios::in);
fcheck.seekg(0,ios::beg);
 while(fcheck)
 {
 fcheck.read((char*)&e,sizeof(e));
 if((strcmp(d,e.date)==0)&&(strcmp(t,e.time)==0))
 {pointer=fcheck.tellg();
  pointer-=(1+sizeof(e));
  fcheck.close();
 return 2;}  }
 fcheck.close();
 return 3;
 }
int password()
{ char ch,pass[15]={0},check[15]={0};
 int i=0,j;
 fstream finout;
  cout<<"\n Enter password";
   pass[0]=getch();
   while(pass[i]!='\r')
 { if(pass[i]=='\b')
   { i--;
   cout<<'\b';
   cout<<" ";
   cout<<'\b';
   pass[i]=getch();
   }
   else
 { cout<<'*';
   i++;
   pass[i]=getch();
 }
}
pass[i]='\0';
finout.open("password.txt",ios::in||ios::nocreate);
if (!finout)
{ cout<<"\n Password file missing. Press any key to exit";
  getch();
  return 6;
}
i=0;
while(1)
{ finout.get(ch);
  if(ch==EOF)
  {
   check[i]='\0';
    break;
  }
 check[i]=ch;
 i++;   }
if (strcmp(pass,check)==0)
 {cout<<"\n \t \t ACCESS GRANTED";
  return 0;
 }
 else cout<<"\n WRONG PASSWORD.press any key to exit";
getch();
finout.close();
return 1;
}
void editpassword()
{ clrscr();
  char pass[15]={0}, confirm[15]={0}, ch;
  int choice,i,check;
  fstream finout;
  check=password();
  if(check!=0)
  {return;}
  do
 {
 if(check==0)
 { i=0;
  choice=0;
  cout<<"\n Enter new password";
   pass[0]=getch();
   while(pass[i]!='\r')
 { if(pass[i]=='\b')
   { i--;
   cout<<'\b';
   cout<<" ";
   cout<<'\b';
   pass[i]=getch();
   }
   else
  {cout<<'*';
   i++;
   pass[i]=getch();
  }
 }
 pass[i]='\0';
 i=0;
 cout<<"\n Confirm password";
  confirm[0]=getch();
   while(confirm[i]!='\r')
 { if(confirm[i]=='\b')
   { i--;
   cout<<'\b';
   cout<<" ";
   cout<<'\b';
   confirm[i]=getch();
   }
   else
 { cout<<'*';
   i++;
   confirm[i]=getch();
 }
} confirm[i]='\0';
if (strcmp(pass,confirm)==0)
 { finout.open("tempo.txt",ios::out);
  i=0;
 while(pass[i]!='\0')
 { ch=pass[i];
   finout.put(ch);
   i++;
 }
finout.put(EOF);
finout.close();
remove("password.txt");
rename("tempo.txt","password.txt");
}
else
{ cout<<"\n New password does not much";
  choice=1;
}}
}while(choice==1);
cout<<"\n Password changed.Press any key to exit";
getch();
return;
}
void record::modify()
{
char ndate[12];
char ntime[8];
char nname[30];
char nplace[25];
char nduration[20];
char nphone[11];
char nnote[500];  long int h;
 fstream finr;
 finr.open("khh.dat",ios::nocreate||ios::binary||ios::in);
 fout.open("temp.dat",ios::binary);
 if(!finr)
 cout<<"\n Error";
 while(finr)
 {
 finr.read((char*)&e,sizeof(e));
 h=finr.tellg();  h-=(1+sizeof(e));
 if(h==pointer)
 { cout<<' '<<'\b';
   }
 else
 fout.write((char*)&e,sizeof(e));
 }
   finr.close();
   fout.close();
   remove ("khh.dat");
   rename("temp.dat","khh.dat");
cout<<"New date(dd-mm-yyyy): ( Enter'.' to Retain)";
gets(ndate);
cout<<"New time(hh:mm): ( Enter'.' to Retain)";
gets(ntime);
cout<<"New place: ( Enter'.' to Retain)";
gets(nplace);
cout<<"New Duration: (Enter '.' to Retain)";
gets(nduration);
cout<<"New phone number:(Enter '.' to retain)";
gets(nphone);
cout<<"New Note(Give '$' at the end and press enter)";
cin.getline(nnote,500,'$');
if(strcmp(ntime,".")!=0)
strcpy(time,ntime);
if(strcmp(ndate,".")!=0)
strcpy(date,ndate);
if(strcmp(place,".")!=0)
strcpy(place,nplace);
if(strcmp(nduration,".")!=0)
strcpy(duration,nduration);
if(strcmp(nphone,".")!=0)
strcpy(phone,nphone);
strcpy(note,nnote);   ofstream of;
of.open("khh.dat",ios::app);
of.write((char*)&e,sizeof(e));
of.close();
}
void editrecord()
{
 char mdate[12],mtime[8],che='y';
 int g,choice;
 cout<<"\n Welocome to Edit Menu \n";
 check=password();
  if(check!=0)
  {return;}
 while((che=='y')||(che=='Y'))
 {
 ifstream fiii;
 cout<<"\n Enter date of record to be modified(dd-mm-yyyy)";
 cin>>mdate;
 cout<<"\n Enter time of record to be modified(hh:mm)";
 cin>>mtime;
 g=e.checkdate(mdate,mtime);
 if(g==2)
 {fiii.open("khh.dat",ios::in);
  fiii.seekg(pointer);
  fiii.read((char*)&e,sizeof(e));
  e.put();
  cout<<"\n New details\n";
  fiii.close();
 e.modify();
 cout<<"\n Modify more?";
 cin>>che;
 }
 else
 {
  cout<<"\n No such record.Press y to try again";
  cin>>che;
  }}
  cout<<"\n press any key to return";
  getch();
  return;
 }
 void record::put()
 {cout<< "\n The name is ";puts(e.name);
  cout<<"\n The number is "<<e.phone;
  cout<<"\n The Date of the meeting is "<<e.date;
  cout<<"\n The time of meeting is "<<e.time;
  cout<<"\n the place of meeting is ";puts(e.place);
  cout<<"\n The duration is ";puts(e.duration);
  cout<<"\n The note is "<<e.note;
 }



















































