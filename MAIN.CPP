#include <iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>

class iodet
{
   public:
   fstream sout;

   typedef struct student
   {
    int roll, fee;
    char name[30];
   }student;

   iodet()
   {
    cout<<"Will be done later ...\n";
   }
};

class siodet:public iodet
{
	public:
		student stud;
	void sidet()
	{
		sout.open("sdb.dat", ios::app|ios::binary);
		cout<<"Enter the Name of the student.. - ";
		cin.getline(stud.name, 30);
		sout<<stud.name<<"\t";
		cout<<"Enter the roll of student .. - ";
		cin>>stud.roll;
		sout<<stud.roll<<"\t";
		cout<<"Enter the fee of the student.. - ";
		cin>>stud.fee;
		sout<<stud.fee<<"\n";
		sout.close();
	}
	void sodet()
	{
		student s;
		char ch='/';
		ifstream sin("sdb.dat");

		while(ch!=EOF)
		{
			sin>>s.name;
			cout<<s.name<<'\t';
			sin>>s.roll;
			cout<<s.roll<<'\t';
			sin>>s.fee;
			cout<<s.fee<<'\n';
			ch = sin.get();
			fflush(stdout);
		//	if((ch=='\n'))
		//	  break;
		}
		sin.close();
	}

	void sdelete()
	{
		char *name, sname;
		char ch='!';
		cout<<"Enter name to delete the record : ";
		cin>>name;
		fstream srw;
		srw.open("sdb.dat", ios::in|ios::binary);
		student s;
		while(ch != EOF)
		{
			srw>>s.name;
			cout<<s.name;
			ch = srw.get();
		}
	}
};


int main()
{
	cout<<"Program started."<<endl;
	siodet s1;
	s1.sidet();
	s1.sodet();
	//s1.sdelete();
	getch();
	return 0;
}