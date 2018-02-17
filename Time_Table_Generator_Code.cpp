/* 
*
*	Created by Aakash Sunil, Peter Hudson, Ankit Prasad
*
*	
*	This is a simple and basic implementation of generating a timetable for a single class 
*	depending on the timing preferences entered by the lecturers.
*	
*/
 #include<iostream>
 #include<stdio.h>
 #include<string.h>
 #include<conio.h>
 #include<fstream>
 #include<windows.h>

  using namespace std;
  class semester
  {
  	int no_sub,no_lab;												//Semester and Number of subjects
  	char sem[10],a[100],dept[10],subs[10][30],labs[4][30];			//Subject names
  	int noc_sub[10],tno_class;										//Number of classes per subject for a week & total number of classes for the week
  	public:
  	semeseter()
  	{
  		tno_class=0;
	}
  	void getdata()
  	{
  		cout<<"Enter Department: ";
  		cin>>dept;
  		cout<<"Enter Semester: ";
		cin>>sem;
		cout<<"Enter number of subjects: ";
		cin>>no_sub;
		cout<<"Enter the "<<no_sub<<" subjects: "<<endl;
		for(int i=0;i<no_sub;i++)
				cin>>subs[i];
		cout<<"Enter number of classes for each subject entered: "<<endl;
		tno_class=0;
		for(int i=0;i<no_sub;i++)
		{
			cin>>noc_sub[i];
			tno_class+=noc_sub[i];
		}		
		cout<<"Enter number of Labs: ";
		cin>>no_lab;
		cout<<"Enter the "<<no_lab<<" Labs: "<<endl;
		for(int i=0;i<no_lab;i++)
				cin>>labs[i];
				
		strcpy(a,dept);
		strcat(a,sem);
		strcat(a,".txt");
		ofstream myfile(a);
		myfile<<"Department: "<<dept<<endl<<"Semester: "<<sem<<endl<<"No. of Subjects: "<<no_sub<<endl;
		for(int i=0;i<no_sub;i++)
				myfile<<subs[i]<<endl;
		myfile<<"Total no. hours: "<<tno_class<<endl;		
		myfile.close();
		}
	 void dispdata()
	 {
	 	cout<<"Semester : "<<sem<<endl;
	 	cout<<"No. Of Subjects : "<<no_sub<<endl;
	 	cout<<"Total classes : "<<tno_class<<endl;
	 	for(int i=0;i<no_sub;i++)
				cout<<subs[i]<<endl;
		
	 }
	 int ret_nos()
	 {
	 	return no_sub;
	 }
	 int ret_nol()
	 {
	 	return no_lab;
	 }
	 void nosarray(int *arr)   															//returning array with number of hours for a subject in a week		
	 {
	 	for(int i=0;i<no_sub;i++)
	 	arr[i]=noc_sub[i];
	 }
  };
  class teacher
  {
  	protected:
  	char name[50];
  	int pos;
  	char subject[30];
  	int pref;
	public:
	teacher()
	{
		strcpy(subject,"-");
	}
  	virtual void getdata()
  	{
  		cout<<"Faculty Details: "<<endl;
  		cout<<"Enter Name: ";
  		cin>>name;
		cout<<"Enter subject: ";
  		cin>>subject;
		cout<<"Pref(0,1,2): ";
  		cin>>pref;
  	}
  	virtual void dispdata()
  	{
  		
  		cout<<"Name: "<<name<<endl;
  		cout<<"Subject: "<<subject<<endl;
  		char temp[10];
		if(pref==1)
  			strcpy(temp,"Morning");
  		else if(pref==2)
  			strcpy(temp,"Noon");
  		else 
  			strcpy(temp,"None");
  			
  		cout<<"Preference: "<<temp<<endl;
	}
  	int chkpref()
  	{
  		return pref;
	}
	void operator =(teacher t) 														//for preparing the timetable
	{
		strcpy(name,t.name);
		strcpy(subject,t.subject);
		pref=t.pref;
	}
	void select_pos(int i)
	{
		pos=i;
	}
	char* dispsub()
	{
		return subject;
	}
	char *ret_sub()
	{
		return subject;
	}
  };
  class lab:public teacher
  {
  	char labday[10];
  	int dayno;
  	public:
  	lab()
  	{
  		strcpy(name,"Lab");
	}
  	void getdata()
  	{
  		cout<<"Lab Details: "<<endl;
  		cout<<"Enter subject: ";
  		cin>>subject;
  		cout<<"Enter day of the week: ";
  		cin>>labday;
		cout<<"Pref(1,2): ";
  		cin>>pref;
  	}
  	void dispdata()
  	{
  		cout<<"Name: "<<name<<endl;
  		cout<<"Subject: "<<subject<<endl;
  		char temp[10];
		if(pref==1)
  			strcpy(temp,"Morning");
  		else
  			strcpy(temp,"Noon");
  		cout<<"Preference: "<<temp<<endl;
	}
	int ldayno()
	{
		if(strcmpi(labday,"Monday")==0)
			dayno=1;
		else if(strcmpi(labday,"Tuesday")==0)
			dayno=2;
		else if(strcmpi(labday,"Wednesday")==0)
			dayno=3;
		else if(strcmpi(labday,"Thursday")==0)
			dayno=4;
		else if(strcmpi(labday,"Friday")==0)
			dayno=5;
		else 
			dayno=6;
		
		return dayno;
	}
  };
  
  teacher table(semester,teacher *,teacher day1[6][7],lab *);
  void display(teacher day1[6][7]);
  
  int main()
  {
  	char ch1;
  	cout<<endl<<endl<<endl<<endl;
  	cout<<"\t.-----------------------------------------------------."<<endl;
  	cout<<"\t|                                                     |"<<endl;
  	cout<<"\t|                                                     |"<<endl;
  	cout<<"\t|        Welcome To The Time Table Generator          |"<<endl;
  	cout<<"\t|                                                     |"<<endl;
  	cout<<"\t|                                                     |"<<endl;
  	cout<<"\t|                                                     |"<<endl;
  	cout<<"\t|                     Done By                         |"<<endl;
  	cout<<"\t|                                                     |"<<endl;
  	cout<<"\t|                                                     |"<<endl;
  	cout<<"\t|        A. Peter Hudson-------[1NT14CS001]           |"<<endl;
  	cout<<"\t|        Aakash Sunil----------[1NT14CS002]           |"<<endl;
  	cout<<"\t|        Ankit Prasad----------[1NT14CS022]           |"<<endl;
  	cout<<"\t|                                                     |"<<endl;
  	cout<<"\t|                                                     |"<<endl;
  	cout<<"\t|                                                     |"<<endl;
  	cout<<"\t.-----------------------------------------------------."<<endl;
  	cout<<endl<<endl<<endl<<endl;
  	cout<<"Press Enter to continue";
  	getchar();
  	system("cls");
  	char ch;
  	semester obj;
  	teacher obj1[10],ob2;
  	lab l[5],l2;
  	int nof=0,nol=0;															//number of faculty and no. of labs
  	obj.getdata();
  	system("cls");
  	obj.dispdata();
  	cout<<endl;
  	nof=obj.ret_nos();
  	nol=obj.ret_nol();
  	for(int i=0;i<nof;i++)
  	{	obj1[i].getdata();
  		cout<<endl;
  	}
  	for(int i=0;i<nol;i++)
  	{	
	  	l[i].getdata();
  		cout<<endl;
  	}
  	cout<<endl;
    teacher day1[6][7];
    table(obj,obj1,day1,l);
    display(day1);
    for(int i=0;i<nof;i++)
  	{	
	  	obj1[i].dispdata();
  		cout<<endl;
  	}
}
  teacher table(semester s,teacher *t,teacher day1[6][7],lab *l)
  {
  	int arr[10];
  	s.nosarray(arr);
  	int nos=s.ret_nos();
  	int nol=s.ret_nol();
  	for(int i=0;i<nos;i++)
  		cout<<arr[i]<<" ";
  	cout<<endl;
  	int zpref_arr[10],p=0,pref=0,morn=0,rom=0,aft=0,roa=0;
  	int dno,labarr[4],lindex=0;
  	for(int i=0;i<nol;i++)
  	{
  		pref=l[i].chkpref();
  		dno=l[i].ldayno();
  		dno--;
  		labarr[lindex++]=dno;
  		switch(pref)
  		{
  			case 1: day1[dno][0]=l[i];
			  		day1[dno][1]=l[i];
					day1[dno][2]=l[i];
  					break;
  			case 2: day1[dno][4]=l[i];
			  		day1[dno][5]=l[i];
					day1[dno][6]=l[i];
  					break;
		  }
  	}
  	int weekday=0,k=0;
	while(weekday<6)
  	{
  		p=0;
  		morn = 0 ; aft = 3;
  		rom = 3  ; roa = 7; 
  		if(weekday==labarr[k])
  		{
			pref=l[k].chkpref();
			switch(pref)
			{
				case 1: morn = 3;
						rom  = 3;
						break;
				case 2: aft = 3;
						roa = 4;
						break;
			}
			k++;
		}
		for(int i=0;i<nos;i++)
  		{   
  			pref=t[i].chkpref();
  			switch(pref)
  		{
  			case 1: if(morn<rom && arr[i]!=0)
			  		{
			  			day1[weekday][morn++]=t[i];
			  			--arr[i];
			  		}
  					break;
  			case 2: if(aft<roa && arr[i]!=0)
  					{
			  			day1[weekday][aft++]=t[i];
			  			--arr[i];
			  		}
  					break;
  			default:zpref_arr[p++]=i;
			  		break; 
		  }
  		}
  		for(int i=0;i<p;i++)
  		{
  			if(morn<rom && arr[zpref_arr[i]]!=0)
  			{
			  	day1[weekday][morn++]=t[zpref_arr[i]];
			  	--arr[zpref_arr[i]];
			}
			else if(aft<roa && arr[zpref_arr[i]]!=0)
			{
				day1[weekday][aft++]=t[zpref_arr[i]];
				--arr[zpref_arr[i]];
		    }
		}
		weekday++;
	}
	if(weekday==6)
  	{
  		p=0;
  		morn = 0 ;
  		rom =  4 ; 
  		if(weekday==labarr[k])
  		{
			pref=l[k].chkpref();
			switch(pref)
			{
				case 1: morn = 3;
						break;
			}
			k++;
		}
		for(int i=0;i<nos;i++)
  		{
  			pref=t[i].chkpref();
  			switch(pref)
  		{
  			case 1: if(morn<rom && arr[i]!=0)
			  		{
			  			day1[weekday][morn++]=t[i];
			  			--arr[i];
			  		}
  					break;
  			default:zpref_arr[p++]=i;
			  		break; 
		  }
  		}
  		for(int i=0;i<p;i++)
  		{
  			if(morn<rom && arr[zpref_arr[i]]!=0)
  			{
				day1[weekday][morn++]=t[zpref_arr[i]];	
				--arr[zpref_arr[i]];
			}
		}
	}
	for(int i=0;i<nos;i++)
  		cout<<arr[i]<<" ";
  	char *temp;
  	
  	//place the remaining classes in the table according to the gaps left
  	
  	for(int i=0;i<nos;i++)
    {
    	while(arr[i]>0)
    	{
    		for(int j=0;j<6;j++)
    			for(int k=0;k<7;k++)
    			{
					temp=day1[j][k].ret_sub();
    				if(strcmp(temp,"-")==0)
    				{
						day1[j][k]=t[i];
						--arr[i];
    				}
				}
		}
	}	
	lindex=0;
	teacher d;
	for(int i=1;i<5;i++)
	{
		if(labarr[lindex]==i)
    	{
    		for(int k=0;k<3;k++)
    		{
    			if(i%4==1 && k==0)
    			{
    				temp=day1[i][k+1].ret_sub();
    				if(strcmp(temp,"-")!=0)
    				{
    					d=day1[i][k+2];
						day1[i][k+2]=day1[i][k+1];
						day1[i][k+1]=day1[i][k];
						day1[i][k]=d;
					}
				}
				if(i%4==3 && k==0)
    			{
    				temp=day1[i][k+1].ret_sub();
    				if(strcmp(temp,"-")!=0)
    				{
    					d=day1[i][k+2];
						day1[i][k+2]=day1[i][k+1];
						day1[i][k+1]=day1[i][k];
						day1[i][k]=d;
					}
				}
				if(i%4==2 && k==1)
    			{
    				temp=day1[i][k+1].ret_sub();
    				if(strcmp(temp,"-")!=0)
    				{
    					d=day1[i][k-1];
						day1[i][k-1]=day1[i][k];
						day1[i][k]=day1[i][k+1];
						day1[i][k+1]=d;
					}
				}
			}
		}
		else if(labarr[lindex]!=0)
		{
			for(int k=0;k<3;k++)
    		{
    			if(i%4==1 && k==0)
    			{
    				temp=day1[i][k+1].ret_sub();
    				if(strcmp(temp,"-")!=0)
    				{
    					d=day1[i][k+2];
						day1[i][k+2]=day1[i][k+1];
						day1[i][k+1]=day1[i][k];
						day1[i][k]=d;
					}
				}
				if(i%4==3 && k==0)
    			{
    				temp=day1[i][k+1].ret_sub();
    				if(strcmp(temp,"-")!=0)
    				{
    					d=day1[i][k+2];
						day1[i][k+2]=day1[i][k+1];
						day1[i][k+1]=day1[i][k];
						day1[i][k]=d;
					}
				}
				if(i%4==2 && k==1)
    			{
    				temp=day1[i][k+1].ret_sub();
    				if(strcmp(temp,"-")!=0)
    				{
    					d=day1[i][k-1];
						day1[i][k-1]=day1[i][k];
						day1[i][k]=day1[i][k+1];
						day1[i][k+1]=d;
					}
				}
			}
			for(int k=3;k<6;k++)
			{
				if(i%4==1)
    			{
    				temp=day1[i][k+1].ret_sub();
    				if(strcmp(temp,"-")!=0)
    				{
    					d=day1[i][k];
						day1[i][k]=day1[i][k+1];
						day1[i][k+1]=d;
					}
				}
				if(i%4==2 && k==4)
    			{
    				temp=day1[i][k+1].ret_sub();
    				if(strcmp(temp,"-")!=0)
    				{
    					d=day1[i][k-1];
						day1[i][k-1]=day1[i][k];
						day1[i][k]=day1[i][k+1];
						day1[i][k+1]=d;
					}
				}
				if(i%4==3 && k==3)
    			{
    				temp=day1[i][k+1].ret_sub();
    				if(strcmp(temp,"-")!=0)
    				{
    					d=day1[i][k+2];
						day1[i][k+2]=day1[i][k+1];
						day1[i][k+1]=day1[i][k];
						day1[i][k]=d;
					}
				}
				if(i%4==0 && k==5)
    			{
    				temp=day1[i][k+1].ret_sub();
    				if(strcmp(temp,"-")!=0)
    				{
    					d=day1[i][k-1];
						day1[i][k-1]=day1[i][k];
						day1[i][k]=day1[i][k+1];
						day1[i][k+1]=d;
					}
				}
	    	}
	    }
	    else lindex++;
    }
}
void display(teacher day1[6][7])
{
	char *temp1;
	cout<<"Generating";
	cout<<".";
	Sleep(1000);
	cout<<".";
	Sleep(1000);
	cout<<".";
	Sleep(1000);	
  	system("cls");
	int j,k;
	for(int i=0;i<25;i++)
	{
		if(i%4==0)
		{
			
			cout<<".";
			cout.fill('-');
				cout.width(64);
			cout<<"."<<endl;
		}
		else
		{
			j=0;k=2;
			while(j<=8)
			{
				//------------------------------Monday----------------------------
				if((i==2)&&(j==1))
				{
					temp1=day1[0][0].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==2)&&(j==2))
				{
					temp1=day1[0][1].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==2)&&(j==3))
				{
					temp1=day1[0][2].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==2)&&(j==5))
				{
					temp1=day1[0][3].dispsub();
				strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==2)&&(j==6))
				{
					temp1=day1[0][4].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==2)&&(j==7))
				{
					temp1=day1[0][5].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==2)&&(j==8))
				{
					temp1=day1[0][6].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==2)&&(j==4))
				{
					cout<<"L   |";
					cout.width(8);
				}
				//------------------------------Tuesday-------------------------------------------
				else if((i==6)&&(j==1))
				{
					temp1=day1[1][0].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==6)&&(j==2))
				{
					temp1=day1[1][1].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==6)&&(j==3))
				{
					temp1=day1[1][2].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==6)&&(j==5))
				{
					temp1=day1[1][3].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==6)&&(j==6))
				{
					temp1=day1[1][4].dispsub();
					strcat(temp1,"  |");
						cout<<temp1;
					cout.width(8);
				}
				else if((i==6)&&(j==7))
				{
					temp1=day1[1][5].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==6)&&(j==8))
				{
					temp1=day1[1][6].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
			}
				else if((i==6)&&(j==4))
				{
					cout<<"U   |";
					cout.width(8);
				}
				//-----------------------------Wednesday---------------------------------------
				else if((i==10)&&(j==1))
				{
					temp1=day1[2][0].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==10)&&(j==2))
				{
					temp1=day1[2][1].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==10)&&(j==3))
				{
					temp1=day1[2][2].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==10)&&(j==5))
				{
					temp1=day1[2][3].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==10)&&(j==6))
				{
					temp1=day1[2][4].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==10)&&(j==7))
				{
					temp1=day1[2][5].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==10)&&(j==8))
				{
					temp1=day1[2][6].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==10)&&(j==4))
				{
					cout<<"N   |";
					cout.width(8);
				}
				//---------------------------------Thursday---------------------------------------
				else if((i==14)&&(j==1))
				{
					temp1=day1[3][0].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==14)&&(j==2))
				{
					temp1=day1[3][1].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==14)&&(j==3))
				{
					temp1=day1[3][2].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==14)&&(j==5))
				{
					temp1=day1[3][3].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==14)&&(j==6))
				{
					temp1=day1[3][4].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==14)&&(j==7))
				{
					temp1=day1[3][5].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==14)&&(j==8))
				{
					temp1=day1[3][6].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==14)&&(j==4))
				{
					cout<<"C   |";
					cout.width(8);
				}
				//-------------------------------------Friday-------------------------------------------
				else if((i==18)&&(j==1))
				{
					temp1=day1[4][0].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==18)&&(j==2))
				{
					temp1=day1[4][1].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==18)&&(j==3))
				{
					temp1=day1[4][2].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==18)&&(j==5))
				{
					temp1=day1[4][3].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==18)&&(j==6))
				{
					temp1=day1[4][4].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==18)&&(j==7))
				{
					temp1=day1[4][5].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==18)&&(j==8))
				{
					temp1=day1[4][6].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==18)&&(j==4))
				{
					cout<<"H   |";
					cout.width(8);
				}
				//--------------------------------------Saturday First Half----------------------------------------------------------
				else if((i==22)&&(j==1))
				{
					temp1=day1[5][0].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==22)&&(j==2))
				{
					temp1=day1[5][1].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==22)&&(j==3))
				{
					temp1=day1[5][2].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				else if((i==22)&&(j==4))
				{
					temp1=day1[5][3].dispsub();
					strcat(temp1,"  |");
					cout<<temp1;
					cout.width(8);
				}
				
				//-------------------------------Saturday Second Half--------------------------------------------------
				
					else if((i==22)&&((j>=5)))
					{
						cout<<"-   |";
						cout.width(8);
					}
					else 
					{
						
						cout<<"|";
						cout.fill(' ');
						cout.width(8);
					}
						j++;
						k+=4;
				}
				if(i==22)
				cout<<" "<<endl;
				else
				cout<<" "<<endl;	
			}
		}
	}
