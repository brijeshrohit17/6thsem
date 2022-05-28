#include <iostream>
#include<iomanip>
using namespace std;

class Staff {
    protected:
    string code_name;
    string staff_name;

    public:
    void setStaffInfo(string code_name,string staff_name) {
        this->code_name = code_name;
        this->staff_name = staff_name;
    }
};

class Education {
    protected:
    string gen_edn;

    public:
    void setEducationInfo(string gen_education) {
        this->gen_edn = gen_education;
    }
};

class teacher : public Staff,public Education {
    string subject;
    string publication;

    public:
    void setTeacherInfo(string sub,string publ) {
        this->subject = sub;
        this->publication = publ;
    }
    void getTeacherInfo() {
        cout << this->staff_name << setw(15) << this->code_name << setw(20) << this->subject << setw(20);
        cout << this->publication << setw(20) << this->gen_edn <<"\n";
    }
};

class officer : public Staff,public Education {
    string grade;

    public:
    void setOfficerInfo(string offgrade) {
        this->grade = offgrade;
    }
    void getOfficerInfo() {
        cout << this->staff_name << setw(15) << this->code_name << setw(20) << this->grade << setw(20);
        cout << this->gen_edn <<"\n";
    }

};

class typist : public Staff {
    protected:
    int speed;

    public:
    void setSpeed(int sp) {
        this->speed = sp;
    }
};

class regular : public typist {
    float wages;
    public:
    void setWages(float wage) { 
        this->wages = wage;
    }
    void getRegularInfo() {
        cout << this->staff_name << setw(20) << this->code_name << setw(20) << this->speed << setw(20);
        cout << this->wages <<"\n";
    }
};

class casual : public typist {
    float daily_wages;

    public:
    void setDailyWages(float wage) { 
        this->daily_wages = wage;
    }
    void getCasualInfo() {
        cout << this->staff_name << setw(20) << this->code_name << setw(20) << this->speed << setw(20);
        cout << this->daily_wages <<"\n";
    }
};

int main()
{
    int no_teacher,no_officer,no_reg_typ,no_cas_typ;
    cout << "Enter no of teachers : ";
    cin >> no_teacher;

    cout << "Enter no of officers : ";
    cin >> no_officer;

    cout << "Enter no of regular typist : ";
    cin >> no_reg_typ;

    cout << "Enter no of casual typist : ";
    cin >> no_cas_typ;

    teacher *t1 = new teacher[no_teacher];
    officer *o1 = new officer[no_officer];
    regular *r1 = new regular[no_reg_typ];
    casual  *c1 = new casual[no_cas_typ];

    //Teachers
    cout << "\nDatabase of Teachers:\n";
    if(no_teacher<=0)
        cout << "!!-----Currently No Information Available-----!!\n\n";
    else{
        for(int i=0;i<no_teacher;i++)
        {
            string name,code,sub,publ,qual;
            cout <<"\nEnter Teacher Name : ";
            cin >> name;
            cout << "Enter Code Name     : ";
            cin >> code;
            cout << "Enter Subject       : ";
            cin >> sub;
            cout << "Enter Publication   : ";
            cin >> publ;
            cout << "Enter Qualification : ";
            cin >> qual;

            t1[i].setStaffInfo(code,name);
            t1[i].setEducationInfo(qual);
            t1[i].setTeacherInfo(sub,publ);
        }
    }

    //Officers
    cout << "\nDatabase of Officers:\n";
    if(no_officer<=0)
        cout << "!!-----Currently No Information Available-----!!\n\n";
    else{
        for(int i=0;i<no_officer;i++)
        {
            string name,code,grad,qual;
            cout << "\nEnter Officer Name  : ";
            cin >> name;
            cout << "Enter Code Name       : ";
            cin >> code;
            cout << "Enter Grade           : ";
            cin >> grad;
            cout << "Enter Qualification   : ";
            cin >> qual;

            o1[i].setStaffInfo(code,name);
            o1[i].setEducationInfo(qual);
            o1[i].setOfficerInfo(grad);
        }
    }

    //Regular typist
    cout << "\nDatabase of Regular Typist:\n";
    if(no_reg_typ<=0)
        cout << "!!-----Currently No Information Available-----!!\n\n";
    else{
        for(int i=0;i<no_reg_typ;i++)
        {
            string name,code;
            int speed;
            float salary;
            cout << "\nEnter Typist Name : ";
            cin >> name;
            cout << "Enter Code Name     : ";
            cin >> code;
            cout << "Enter Typing Speed  : ";
            cin >> speed;
            cout << "Enter Salary        : ";
            cin >> salary;

            r1[i].setStaffInfo(code,name);
            r1[i].setSpeed(speed);
            r1[i].setWages(salary);
        }
    }

    //Casual Typist
    cout << "\nDatabase of Casual Typist:\n";
    if(no_cas_typ<=0)
        cout << "!!-----Currently No Information Available-----!!\n\n";
    else{
        for(int i=0;i<no_cas_typ;i++)
        {
            string name,code;
            int speed;
            float wages;
            cout << "\nEnter Typist Name : ";
            cin >> name;
            cout << "Enter Code Name     : ";
            cin >> code;
            cout << "Enter Typing Speed  : ";
            cin >> speed;
            cout << "Enter Daily Wages   : ";
            cin >> wages;

            c1[i].setStaffInfo(code,name);
            c1[i].setSpeed(speed);
            c1[i].setDailyWages(wages);
        }
    }
        
    //Output Display
    if(no_teacher>0){
        cout << "\n-------------------------------List of Teachers--------------------------------\n";
        cout << "Sr.No" << setw(10) << "Name" << setw(17) << "Code" << setw(25) << "Subject" << setw(20);
        cout << "Publication" << setw(20) << "Qualification" <<"\n";
        for(int i=0;i<no_teacher;i++)
        {
            cout << i+1 << setw(15);
            t1[i].getTeacherInfo();
        }
    }
    delete []t1;

    if(no_officer>0){
        cout << "\n-------------------------------List of Officers--------------------------------\n";
        cout << "Sr.No" << setw(10) << "Name" << setw(17) << "Code" << setw(20) << "Grade" << setw(25);
        cout << "Qualification" <<"\n";
        for(int i=0;i<no_officer;i++)
        {
            cout << i+1 << setw(15);
            o1[i].getOfficerInfo();
        }
    }
    delete []o1;

    if(no_reg_typ>0){
        cout << "\n-------------------------------List of Regular Typist--------------------------------\n";
        cout << "Sr.No" << setw(10) << "Name" << setw(20) << "Code" << setw(22) << "Speed" << setw(20);
        cout << "Salary" <<"\n";
        for(int i=0;i<no_reg_typ;i++)
        {
            cout << i+1 << setw(15);
            r1[i].getRegularInfo();
        }
    }
    delete []r1;

    if(no_cas_typ>0){
        cout << "\n-------------------------------List of Casual Typist--------------------------------\n";
        cout << "Sr.No" << setw(10) << "Name" << setw(20) << "Code" << setw(22) << "Speed" << setw(20);
        cout << "Wages" <<"\n";
        for(int i=0;i<no_cas_typ;i++)
        {
            cout << i+1 << setw(15);
            c1[i].getCasualInfo();
        }
    }
    delete []c1;

    return 0;
}
