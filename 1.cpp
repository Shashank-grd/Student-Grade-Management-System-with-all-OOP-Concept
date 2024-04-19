#include<iostream>
#include<cstring>
using namespace std;
class student{
    protected:
    char name[50];
    int roll;
    public:
    void getdata(){
        cout<<"Enter the name :";
        cin.ignore();
        gets(name);
        cout<<"Enter the roll :";
        cin>>roll;
    }
    void display(){
        cout<<"Name of student :"<<name<<"\n";
        cout<<"Roll no. :"<<roll<<"\n";
    }
    char* returname(){
        char* ptr=name;
        return ptr;
    }

};
class T1T2T3:virtual public student{
    protected:
    float marks_t1;
    float marks_t2;
    float marks_t3;
    public:
    void getdata(){
        cout<<"Enter marks of T1 :";
        cin>>marks_t1;
        cout<<"Enter marks of T2 :";
        cin>>marks_t2;
        cout<<"Enter marks of T3 :";
        cin>>marks_t3;
    }
    void display(){
        cout<<"Marks in T1 :"<<marks_t1<<"\n";
        cout<<"Marks in T2 :"<<marks_t2<<"\n";
        cout<<"Marks in T3 :"<<marks_t3<<"\n";
    }
};
class P1P2:virtual public student{
    protected:
    float marks_p1;
    float marks_p2;
    public:
    void getdata(){
        cout<<"Enter marks of P1 :";
        cin>>marks_p1;
        cout<<"Enter marks of P2 :";
        cin>>marks_p2;
    }
    void display(){
        cout<<"Marks in P1 :"<<marks_p1<<"\n";
        cout<<"Marks in P2 :"<<marks_p2<<"\n";
        }
};
class attendance:virtual public student{
    protected:
    float per;
    public:
    void getdata(){
        cout<<"Enter the attendence percentage :";
        cin>>per;
    }
    void display(){
        cout<<"Percentage is :"<<per<<"\n";
    }
};
class total:public T1T2T3,public P1P2,public attendance{
    protected:
    float total;
    char grade;
    public:
    void put(){
         total=marks_t1 + marks_t2 + marks_t3 + marks_p1 + marks_p2;
        float pr;
        pr= (total/130)*100;
        if(pr >= 80)
        grade='A';
        else if(pr >= 70)
        grade ='B';
        else if(pr >= 60)
        grade ='C';
        else if(pr >= 50)
        grade ='D';
        else
        grade= 'E';
        }
    void display(){
        student::display();
        cout<<"Total marks :"<<total<<"\n";
        cout<<"Grade secured :"<<grade<<"\n";
    }
    char returngrade(){
        return grade;
    }
};
class faculty{
    public:
    void assign(total& t){
        t.T1T2T3::getdata();
        t.P1P2::getdata();
        t.attendance::getdata();
    }
};
class administration{
    public:
    void assign(total& t){
        t.student::getdata();
        t.T1T2T3::getdata();
        t.P1P2::getdata();
        t.attendance::getdata();
        t.put();
    }
    void searchGrade(total ar[], int n, char* firstName) {
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(strncmp(firstName, ar[i].student::returname(), strlen(firstName)) == 0) {
           ar[i].display();
            found = true;
        }
    }
    if(!found) {
        cout << "No student found with the given first name.\n";
    }
}
 };
 

int main()
{ 
    int i,j,n;
    cout<<"Enter the no. of student :";
    cin>>n;
    administration arr[n],obj;
    total ar[n];
   
    for(i=0;i<n;i++)
        arr[i].assign(ar[i]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(ar[j].returngrade() > ar[j+1].returngrade())
            {
                swap(ar[j], ar[j+1]);
            }
            else if(ar[j].returngrade() == ar[j+1].returngrade())
            {
                
                if (strcmp(ar[j].student::returname(), ar[j+1].student::returname()) > 0)
                     {
                     swap(ar[j], ar[j+1]);
                      }

            }
        }
    }
    for(i=0;i<n;i++)
    {
        ar[i].display();
    }
char firstName[50];
cout << "Enter the first name of the student to search: ";
cin >> firstName;

obj.searchGrade(ar, n, firstName);
    return 0;
}

