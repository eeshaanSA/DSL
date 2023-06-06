/*
F-23
Department maintains a student information. file contains roll no div etc etc
*/
#include<iostream>
using namespace std;
#include<fstream>
#include<string.h>

class student{
    int r;
    string na;
    int div;
    string addr;

    public:

    student(){
        r=0;
        na=' ';
        div=0;
        addr=' ';
    }

    int groll();
    void getd();
    void putd();

};

void student::getd(){
    cout<<"enter roll no.:";
    cin>>r;
    cout<<"\nenter name:";
    cin>>na;
    cout<<"\nenter div:";
    cin>>div;
    cout<<"\nenter address:";
    cin>>addr;
}

void student::putd(){
    cout<<"\n";
    cout<<"roll no.:"<<r<<endl;
    cout<<"Name:"<<na<<endl;
    cout<<"div:"<<div<<endl;
    cout<<"address:"<<addr<<endl;
    cout<<"\n";
}

int student::groll(){
    return r;
}

class file{
    ifstream fin;
    ofstream fout;
    fstream fs;

    public:
    void insert();
    void display();
    void search(int);
    int Delete(int);
};

void file::insert(){
    student s;
    s.getd();
    fout.open("studentDB",ios::ate| ios::app);
    fout.write((char*)&s,sizeof(s));
    fout.close();
}

void file::display(){
    student s;
    fin.open("studentDB");
    fin.seekg(0,ios::beg);
    while(fin.read((char*)&s,sizeof(s))){
        s.putd();
    }
    fin.close();

}

void file::search(int r){
    student s;
    int flag=0;
    fin.open("studentDB");
    fin.seekg(0,ios::beg);
    while(fin.read((char*)&s,sizeof(s))){
        if(s.groll()==r){
            flag=1;
            break;
        }
    }
    fin.close();
    if(flag==1){
        cout<<"record found"<<endl;
        s.putd();
    }
    else{
        cout<<"record not found"<<endl;
    }
}

int file::Delete(int r){
    student s;
    int flag=0;
    fin.open("studentDB");
    fout.open("temp", ios::ate | ios::app);
    fin.seekg(0,ios::beg);
    while(fin.read((char*)&s,sizeof(s))){
        if(s.groll()==r){
            flag=1;
        }
        else{
            fout.write((char*)&s,sizeof(s));
        }
    }
    fin.close();
    fout.close();
    remove("studentDB");
    rename("temp","studentDB");
    return flag;
}    

int main(){
    file f;
    int ch,n,i;
    do{
        cout<<"\nMenu \n1.insert \n2.display \n3.search \n4.delete \n5.exit";
        cout<<"\nenter your choice:";
        cin>>ch;
        switch (ch)
        {
        case 1:
            f.insert();
            break;
        
        case 2:
            f.display();
            break;

        case 3:
            cout<<"enter roll no to search:";
            cin>>n;
            f.search(n);
            break;

        case 4:
            cout<<"enter roll no to delete:";
            cin>>n;
            i=f.Delete(n); 
            if(i==1){
                cout<<"record deleted"<<endl;
            }
            else{
                cout<<"not found"<<endl;
            }
            break;           
        case 5:
            cout<<"exited...";
            break;
        default:
            cout<<"enter valid choice"<<endl;
            break;
        }
    }
    while(ch!=5);
    return 0;
}