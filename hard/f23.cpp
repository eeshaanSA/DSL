#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;


void addstudent(){
    string name,addr;
    string r_no;
    char div;
    ofstream f("db.txt",ios::app);
    cout<<"Enter the name of student :"<<endl;
    cin>>name;
    cout<<"Rollno :";
    cin>>r_no;
    cout<<"div :";
    cin>>div;
    cout<<"address : ";
    cin>>addr;
    f<<setw(10)<<r_no<<setw(10)<<name<<setw(10)<<div<<setw(10)<<addr<<endl;
    f.close();
}

void dispstudent(){
    ifstream f("db.txt",ios::in);
    string line;
    while(getline(f,line)){
        cout<<line<<endl;
    }
    f.close();
}

void searchstudent(){
    ifstream f("db.txt");
    string value;
    string line;
    cout<<"Enter the data to be searched:"<<endl;
    cin>>value;
    bool flag=false;
    while(getline(f,line)){
        if(line.find(value)!=string::npos){
            cout<<"student details:"<<endl;
            cout<<line<<endl;
            flag=true;
            break;
        }
    }
    
    if(!flag){
        cout<<"Not found";
    }
}
void deletestudent(){
    ifstream f("db.txt",ios::in);
    string line,filedata;
    string val;
    cout<<"Enter the number to be deleted"<<endl;
    cin>>val;
    while(getline(f,line)){
        if(line.find(val)==string::npos){
            filedata += line;
            filedata="\n";
        }
    }
    f.close();

    ofstream f1("db.txt",ios::out);
    f1<<filedata<<endl;
    f1.close();
}
int main(){
  ofstream f("db.txt",ios::out);
  f<<setw(15)<<"Roll"<<setw(15)<<"Name"<<setw(15)<<"Division"<<setw(15)<<"Address"<<endl;
  f.close();
  int ch;
  do{
    cout<<"Enter a choice : "<<"\n1.Add a student"<<"\n2.Display TAble"<<"\n3.Search Data"<<"\n4.Delete DAta"<<"\n5.Exit"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
        addstudent();
        break;
        case 2:
        dispstudent();
        break;
        case 3:
        searchstudent();
        break;
        case 4:
        deletestudent();
        break;
        case 5:
        return 0;
        break;
       
        default:
        cout<<"Enter proper choice";
        break;
    }
  }while(ch!=5);
  return 0;
}
