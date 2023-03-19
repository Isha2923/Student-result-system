
// STUDENT RESULT MANAGEMENT SYSTEM
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;

class student
{
    private:
    char name[100],mom_name[100],dad_name[100],course[100],clg[100],result[100],dd[2],mm[2],yy[4];
    char grade;
    float percent,math,physics,chem,eg,cpro,bee;
    long long int rollno;

    public:
      void intro();
      void insert();
      void update();
      void display();
      void deleterec(); 
};

void student::intro(){
    start:
     system("cls");
     cout<<"\t\t\t\t   _____"<<endl;
     cout<<"\t\t\t\t   STUDENT RESULT MANAGEMENT SYSTEM   \t\t\t\t"<<endl;
     cout<<"\t\t\t\t   _____"<<endl;
     cout<<"CHOOSE ANY ONE OF THE OPTIONS GIVEN BELOW"<<endl;
     cout<<"\t\t  1. CREATE NEW RECORD"<<endl;
     cout<<"\t\t  2. DISPLAY RECORD"<<endl;
     cout<<"\t\t  3. UPDATE RECORD"<<endl;
     cout<<"\t\t  4. DELETE RECORD"<<endl;
     cout<<"\t\t  5. EXIT"<<endl;
     cout<<"\t\t  CHOOSE OPTION : [ 1 / 2 / 3 / 4 / 5 ]"<<endl;
     cout<<"\t\t\t\t   _____"<<endl;
     cout<<"\t\t\t\t   PLEASE ENTER CHOICE :"<<endl;

    
    int choice;
    char x;
    cin>>choice;
    switch(choice){
        case 1 :
        do{
            insert();
            cout<<"ADD NEW RECORD (y/n)";
            cin>>x;
        }while (x=='Y'||x=='y');
        break;

        case 2 :
         display();
         break;
        
        case 3 :
         update();
         break;
        
        case 4:
          deleterec();
          break;
        
        case 5:
          exit(0);

        default:
           cout<<"INVALID CHOICE!! PLEASE TRY AGAIN"<<endl;

    }
    cin>>x;
    goto start;
}
void student::insert(){
    fstream file;
    system("cls");
    cout<<"_______";
    cout<<"\t\t\t\t   Add student details :"<<endl;
    cout<<"\t\t\t\t   Enter your name-->"<<endl;
    cin>> name;
    cout<<"\t\t\t\t   Enter mother's name-->"<<endl;
    cin>>mom_name;
    cout<<"\t\t\t\t   Enter father's name-->"<<endl;
    cin>>dad_name;
    cout<<"\t\t\t\t   Enter college name-->"<<endl;
    cin>>clg;
    cout<<"\t\t\t\t   Enter course name-->"<<endl;
    cin>>course;
    cout<<"\t\t\t\t   Enter roll number-->"<<endl;
    cin>>rollno;
    cout<<"\t\t\t\t   Enter date of birth(DD/MM/YY)->"<<endl;
    cin>>dd>>mm>>yy;
    
   file.open("studentrecord.txt",ios::out|ios::app);
   file<<" "<<name<<" "<<mom_name<<" "<<dad_name<<" "<<clg<<" "<<course<<" "<<rollno<<" "<<dd<<" "<<mm<<" "<<yy<<" ";
   file.close();

}

void student::display()
{
    system("cls");
    fstream file;
    cout<<"__________________________________________________________________________________________________________________"<<endl;
    cout<<"\t\t\t\t                        STUDENT RECORD TABLE                              \t\t"<<endl;
    cout<<"_______________________________________"<<endl;
    file.open("studentrecord.txt",ios::in);
    if (!file){
          cout<<"\t\t\t\t data not found"<<endl;
          file.close();
    }else{
        file>>name>>mom_name>>dad_name>>clg>>course>>rollno>>dd>>mm>>yy;
        while (!file.eof()){
            cout<<"\n\t____________"<<endl;
            cout<<" |  STUDENT NAME  |\t MOTHER'S NAME |\t FATHER'S NAME |\t NAME OF COLLEGE |\t COURSE        |\t  ROLL NO       |\t DATE OF BIRTH"<<endl;
            cout<<" |  "<<name<<"         |\t"<<mom_name<<"           |\t"<<dad_name<<"            |\t"<<clg<<"              |\t"<<course<<"              |\t"<<rollno<<"          |\t"<<dd<<"/"<<mm<<"/"<<yy<<endl;

            file>>name>>mom_name>>dad_name>>clg>>course>>rollno>>dd>>mm>>yy;
        }
    }
     file.close();
    
}

void student::update(){
        fstream file;
        system("cls");
        file.open("studentrecord.txt",ios::in);
        cout<<"\t\t Enter what type of data you want to update :"<<endl;
        cout<<"\t\t  1. STUDENT NAME"<<endl;
        cout<<"\t\t  2. MOTHER 'S NAME"<<endl;
        cout<<"\t\t  3. FATHER'S NAME"<<endl;
        cout<<"\t\t  4. COLLEGE NAME "<<endl;
        cout<<"\t\t  5. ROLL NO."<<endl;
        cout<<"\t\t  6. DATE OF BIRTH"<<endl;
        cout<<"\t\t  CHOOSE OPTION : [ 1 / 2 / 3 / 4 / 5 /  6]"<<endl;
        cout<<"\t\t\t\t   _____"<<endl;
        cout<<"\t\t\t\t   PLEASE ENTER CHOICE :"<<endl;
        int choice;
        char x;
        cin>>choice;
        switch(choice){
          case 1 :
            char name2[50]; 
            cout<<"enter updated student name";
            cin>>name2;
            strcpy(name,name2);
            break;

        case 2 :
            char mom_name2[50]; 
            cout<<"enter updated mother's name";
            cin>>mom_name2;
            strcpy(mom_name,mom_name2);
            break;
        
        case 3 :
            char dad_name2[50]; 
            cout<<"enter updated father's name";
            cin>>dad_name2;
            strcpy(dad_name,dad_name2);
            break;
        
        case 4:
          char clg2[50]; 
          cout<<"enter updated college's name";
          cin>>clg2;
          strcpy(clg,clg2);
          break;

        case 5:
            long long int rollno2; 
            cout<<"enter updated rollno";
            cin>>rollno2;
            rollno=rollno2;
            break;

        default:
           cout<<"INVALID CHOICE!! PLEASE TRY AGAIN"<<endl;

    }
}
void student::deleterec(){
  system("cls");
  fstream file,file1;
  long long int roll_no;
  int found=0;
  cout<<"___"<<endl;
  cout<<"\t\t\t\t\t\t | Delete Student Record |"<<endl;
  cout<<"___"<<endl;
  file.open("studentresult.txt",ios::in);
  if(!file){
    cout<<"\n\t\t\t No Data Is Found ...";
    file.close();
  }
  else{
    cout<<"\n\t\t\t--> Enter Roll No. Of Student Which Needs To Be Deleted : ";
    cin>>rollno;
    file1.open("temp.txt",ios::out | ios::app);
    file>>name>>mom_name>>dad_name>>course>>clg>>rollno>>dd>>mm>>yy>>;
    while(!file.eof()){
      if(rollno!=roll_no){
       //rollno!=roll_no
       file1<<" "<<name<<" "<<dad_name<<" "<<mom_name<<" "<<course<<" "<<roll_no<<" "<<clg<<" "<<dd<<" "<<mm<<" "<<yy<<" ";/*>>" ">>math>>" ">>physics>>" ">>" ">>chem>>" ">>eg>>" ">>cpro>>" ">>bee>>" " >>grade>>" ">>result*/
      }else{
       found++;
       cout<<"\n\t\t\t Record Is Successfully Deleted..";
      }
      file>>name>>mom_name>>dad_name>>course>>clg>>rollno>>result>>dd>>mm>>yy;
    }/*>>math>>physics>>chem>>eg>>cpro>>bee>>grade*/
    if(found==0){
      cout<<"\n\t\t\t Student Roll Number Is Not Found..";
    }
    file.close();
    file1.close();
    remove("studentresult.txt");
    rename("temp.txt","studentresult.txt");
    }
}
int main(){
    student s;
    s.intro();
    return 0;
}