// COURSE RESULT MANAGEMENT SYSTEM
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;
class course
{
    private:
     char name[100],mom_name[100],dad_name[100],course[100],clg[100],rollno[100],result[100],dd[2],mm[2],yy[4];
    char grade;
    float percent,math,physics,chem,eg,cpro,bee;

    public:
      void intro();
      void insert();
      void update();
      void display();
      void deleterec(); 
};

void course::intro(){
    start:
     system("cls");
     cout<<"\t\t\t\t   _____"<<endl;
     cout<<"\t\t\t\t   STUDENT COURSE MANAGEMENT SYSTEM   \t\t\t\t"<<endl;
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
         deleterec();
         break;
        
        case 4:
          exit(0);

        default:
           cout<<"INVALID CHOICE!! PLEASE TRY AGAIN"<<endl;

    }
    cin>>x;
    goto start;
}
void course::insert(){
    fstream file;
    system("cls");
    cout<<"_______";
    cout<<"\t\t\t\t   Add Course details :"<<endl;
    cout<<"\t\t\t\t   enter your name-->"<<endl;
    cin>> name;
    cout<<"\t\t\t\t   enter Applied Physics marks-->"<<endl;
    cin>>physics;
    cout<<"\t\t\t\t   enter Applied Mathematics marks-->"<<endl;
    cin>>math;
    cout<<"\t\t\t\t   enter Basic Electrical Engineering marks-->"<<endl;
    cin>>bee;
    cout<<"\t\t\t\t   enter Programming in C-->"<<endl;
    cin>>cpro;
    cout<<"\t\t\t\t   enter Engineering Graphics marks-->"<<endl;
    cin>>eg;
    cout<<"\t\t\t\t   enter Applied Chemistry marks-->"<<endl;
    cin>>chem;
    
   file.open("courserecord.txt",ios::out|ios::app);
   file<<" "<<name<<" "<<physics<<" "<<math<<" "<<bee<<" "<<cpro<<" "<<eg<<" "<<chem<<" ";
   file.close();

}

void course::display()
{
    system("cls");
    fstream file2;
    cout<<"______________________________"<<endl;
    cout<<"COURSE RECORD TABLE"<<endl;
    cout<<"_______________________________"<<endl;
    file2.open("courserecord.txt",ios::in);
    if (!file2){
          cout<<"\t\t\t\t data not found"<<endl;
          file2.close();
    }else{
        file2>>name>>physics>>math>>bee>>cpro>>eg>>chem;
        while (!file2.eof()){
            cout<<"\n\t____________"<<endl;
            cout<<"\t |  STUDENT NAME  |\t APPLIED PHYSICS MARKS |\t APPLIED MATHEMATICS MARKS |\t BASIC ELECTRICAL ENGINEERING MARKS |\t PROGRAMMING IN C MARKS |\t ENGINEERING GRAPHICS MARKS |\t APPLIED CHEMISTRY MARKS"<<endl;
            cout<<"\t |  "<<name<<"    | \t"<<physics<<" |\t"<<math<<" |\t"<<bee<<"  |\t"<<cpro<<"   |\t"<<eg<<"    |\t"<<chem<<endl;

            file2>>name>>physics>>math>>bee>>cpro>>eg>>chem;
        }
    }
     file2.close();
    
}

void course::update(){
        fstream file2;
        system("cls");
        file2.open("courserecord.txt",ios::in);
        cout<<"_______";
        cout<<"\t\t\t\t   enter what type of data you want to update :"<<endl;
        cout<<"\t\t  1. STUDENT NAME"<<endl;
        cout<<"\t\t  2. APPLIED PHYSICS MARKS"<<endl;
        cout<<"\t\t  3. APPLIED MATHEMATICS MARKS"<<endl;
        cout<<"\t\t  4. BASIC ELECTRICAL ENGINEERING MARKS "<<endl;
        cout<<"\t\t  5. PROGRAMMING IN C MARKS"<<endl;
        cout<<"\t\t  6. ENGINEERING GRAPHICS MARKS"<<endl;
        cout<<"\t\t  7. APPLIED CHEMISTRY MARKS"<<endl;
        cout<<"\t\t  CHOOSE OPTION : [ 1 / 2 / 3 / 4 / 5 / 6 / 7 ]"<<endl;
        cout<<"\t\t\t\t   _____"<<endl;
        cout<<"\t\t\t\t   PLEASE ENTER CHOICE :"<<endl;
        int choice;
        char x;
        cin>>choice;
        switch(choice){
          case 1 :
            char name2[100]; 
            cout<<"enter updated student name";
            cin>>name2;
            strcpy(name,name2);
            break;

        case 2 :
            float physics2; 
            cout<<"enter updated physics marks";
            cin>>physics;
            physics=physics2;
            break;
        
        case 3 :
            float math2; 
            cout<<"enter updated mathematics marks";
            cin>>math2;
            math=math2;
            break;
        
        case 4:
          float bee2; 
          cout<<"enter updated basic electrical engineering marks";
          cin>>bee2;
          bee=bee2;
          break;

        case 5:
            float cpro2; 
            cout<<"enter updated Programming in C marks";
            cin>>cpro2;
            cpro=cpro2;
            break;
            
        case 6:
            float eg2; 
            cout<<"enter updated Engineering Graphics marks";
            cin>>eg2;
            eg=eg2;
            break;
            
        case 7:
            float chem2; 
            cout<<"enter updated Chemistry marks";
            cin>>chem2;
            chem=chem2;
            break;

        default:
           cout<<"INVALID CHOICE!! PLEASE TRY AGAIN"<<endl;

    }
}
void course::deleterec(){
  system("cls");
  fstream file2,file3;
  char roll_no[50];
  int found=0;
  cout<<"___"<<endl;
  cout<<"\t\t\t\t\t\t | Delete Student Record |"<<endl;
  cout<<"___"<<endl;
  file2.open("courserecord.txt",ios::in);
  if(!file2){
    cout<<"\n\t\t\t No Data Is Found ...";
    file2.close();
  }
  else{
    cout<<"\n\t\t\t--> Enter Name Of Student Which Needs To Be Deleted : ";
    cin>>name;
    file3.open("temp2.txt",ios::out | ios::app);
    file3>>name>>physics>>math>>bee>>cpro>>eg>>chem;
    while(!file3.eof()){
     char name2[100];
     if(strcmp(name,name2)){
      file3<<name<<" "<<physics<<" "<<math<<" "<<bee<<" "<<cpro<<" "<<eg<<" "<<chem;
    }else{
      found++;
      cout<<"\n\t\t\t Record Is Successfully Deleted..";
    }
    file2>>name>>physics>>math>>bee>>cpro>>eg>>chem;}
    if(found==0){
      cout<<"\n\t\t\t Student Name Is Not Found..";
    }
    file2.close();
    file3.close();
    remove("coursercord.txt");
    rename("temp2.txt","courserecord.txt");
    }
}
int main(){
    course c;
    c.intro();
    return 0;
}