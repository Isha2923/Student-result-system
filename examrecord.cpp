// EXAM RESULT MANAGEMENT SYSTEM
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;

class exam
{
    private:
     char name[100],mom_name[100],dad_name[100],course[100],clg[100],rollno[100],result[100],dd[2],mm[2],yy[4];
    char grade;
    float percent,math,physics,chem,eg,cpro,bee,totalm,avg;

    public:
      void intro();
      void insert();
      void update();
      void display();
      void deleterec(); 
};

void exam::intro(){
    start:
     system("cls");
     cout<<"\t\t\t\t   _____"<<endl;
     cout<<"\t\t\t\t   STUDENT EXAM MANAGEMENT SYSTEM   \t\t\t\t"<<endl;
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
void exam::insert(){
    fstream file5;
    system("cls");
    cout<<"________________________________________________";
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
    
   file5.open("examrecord.txt",ios::out|ios::app);
   file5<<" "<<name<<" "<<physics<<" "<<math<<" "<<bee<<" "<<cpro<<" "<<eg<<" "<<chem<<" ";
   file5.close();

}

void exam::display()
{
    system("cls");
    fstream file5;
    cout<<"_______________________________________________________"<<endl;
    cout<<"\t\t             EXAM RECORD TABLE                     \t\t "<<endl;
    cout<<"_______________________________________________________"<<endl;
    file5.open("examrecord.txt",ios::in);
    if (!file5){
          cout<<"\t\t\t\t data not found"<<endl;
          file5.close();
    }else{
        file5>>name>>physics>>math>>bee>>cpro>>eg>>chem;
        while (!file5.eof()){
            cout<<"\n\t______________________________"<<endl;
            cout<<"Student name: ";
            cin>>name;
            cout<<name<<endl;
            cout<<"\t |  PHYSICS  |\t MATHEMATICS |\t BASIC ELECTRICAL ENGINEERING |\t PROGRAMMING IN C |\t ENGINEERING GRAPHICS |\t CHEMISTRY |\t GRADE |\t PERCENTAGE \t| TOTAL MARKS(OUT OF 600) \t|"<<endl;
            totalm=(math+bee+chem+cpro+eg+physics);
            percent=(totalm/600)*100;
            avg=(totalm/6);
            if(totalm>560){
                grade='A';
            }else if((totalm>400)&&(totalm<=560)){
                grade='B';
            }else if((totalm>=300)&&(totalm<=400)){
                grade='C';
            }else{
                grade='F';   //F STANDS FOR FAIL  
            }
            cout<<physics<<" |\t"<<math<<" |\t"<<bee<<"  |\t"<<cpro<<"   |\t"<<eg<<"    |\t"<<chem<<"    |\t"<<grade<<"    |\t"<<percent<<"    |\t"<<totalm<<"    |\t"<<avg<<endl;

            file5>>name>>physics>>math>>bee>>cpro>>eg>>chem>>grade>>percent>>totalm>>avg;
        }
    }
    file5.close();
    
}

void exam::update(){
        fstream file5;
        system("cls");
        cout<<"____________________________________________________________"<<endl;
        cout<<"\t\t\t\t   enter what type of data you want to update :"<<endl;
        cout<<"\t\t  1. STUDENT NAME"<<endl;
        cout<<"\t\t  2. APPLIED PHYSICS MARKS"<<endl;
        cout<<"\t\t  3. APPLIED MATHEMATICS MARKS"<<endl;
        cout<<"\t\t  4. BASIC ELECTRICAL ENGINEERING MARKS "<<endl;
        cout<<"\t\t  5. PROGRAMMING IN C MARKS"<<endl;
        cout<<"\t\t  6. ENGINEERING GRAPHICS MARKS"<<endl;
        cout<<"\t\t  7. APPLIED CHEMISTRY MARKS"<<endl;
        cout<<"\t\t  CHOOSE OPTION : [ 1 / 2 / 3 / 4 / 5 / 6 / 7 ]"<<endl;
        cout<<"\t\t   ______________________________________________________"<<endl;
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
void exam::deleterec(){
  system("cls");
  fstream file5,file6;
  char roll_no[50];
  int found=0;
  cout<<"___"<<endl;
  cout<<"\t\t\t\t\t\t | Delete Student Record |"<<endl;
  cout<<"___"<<endl;
  file5.open("studentresult.txt",ios::in);
  if(!file5){
    cout<<"\n\t\t\t No Data Is Found ...";
    file5.close();
  }
  else{
    cout<<"\n\t\t\t--> Enter Name Of Student Which Needs To Be Deleted : ";
    cin>>name;
    file6.open("temp.txt",ios::out | ios::app);
    file6>>name>>physics>>math>>bee>>cpro>>eg>>chem;
    while(!file6.eof()){
     char name2[100];
     if(strcmp(name,name2)){
      file6<<name<<" "<<physics<<" "<<math<<" "<<bee<<" "<<cpro<<" "<<eg<<" "<<chem;
    }else{
      found++;
      cout<<"\n\t\t\t Record Is Successfully Deleted..";
    }
    file5>>name>>physics>>math>>bee>>cpro>>eg>>chem;}
    if(found==0){
      cout<<"\n\t\t\t Student Name Is Not Found..";
    }
    file5.close();
    file6.close();
    remove("examresult.txt");
    rename("temp3.txt","examresult.txt");
    }
}
int main(){
    exam e;
    e.intro();
    return 0;
}