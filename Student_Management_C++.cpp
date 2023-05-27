
/*
* File: Student_Management_C++.cpp
* Author: Huy Nguyen
* Date: 15/04/2023
* Description: This is file for student management
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

/********************************************Class Student*****************************************/

class Student{
    private:
       int id;
       char name[30];
       int age;
       char sex[5];
       float math;
       float chemistry;
       float physics;
       float average;
       std::string Rank;
    public:
       Student( char name[] , int age , const char* sex , float math , float physics , float chemistry );
       Student(){char name[] = "\0" ; int age ; const char* sex ; float math ; float physics ; float chemistry; }
       int get_Id()           { return Student::id ; }
       char *get_Name()       { return Student::name ; }
       int get_Age()          { return Student::age ; }
       char* get_Sex()        { return Student::sex ; }
       float get_Math()       { return Student::math ; }
       float get_Physiscs()   { return Student::physics ; }
       float get_Chemistry()  { return Student::chemistry ; }
       float get_Average()    { return Student::average ; }
       string academic_Ability();

       void set_Name(char name[])             { strcpy(this->name , name) ; }
       void set_Age(int age)                  { Student::age = age ; }
       void set_Sex(char* sex)                { strcpy(this->sex , sex) ; }
       void set_Math(float math)              { Student::math = math ; }
       void set_Physics(float physics)        { Student::physics = physics ; }
       void set_Chemistry(float chemistry)    { Student::chemistry = chemistry ; }
       void set_Average()                     { Student::average = ( get_Math() + get_Chemistry() + get_Physiscs() ) / 3 ; }
       string get_Rank();
       //string get_Sex();
};

Student::Student( char name[] , int age , const char* sex , float math , float physics , float chemistry )
{
    static int id = 100;    
    this->id = id;
    id++;
    strcpy(this->name , name);
    this->age = age;
    strcpy(this->sex , sex);
    this->math = math;
    this->physics = physics;
    this->chemistry = chemistry;

    this->set_Average();
    this->academic_Ability();
}

string Student::academic_Ability()
{
    float Score = get_Average();
     if(Score >= 9.5)
    {
         Student::Rank = "EXCELLENT";
    }
    else if (Score < 9.5 && Score >= 8)
    {
        this->Rank = "VERY GOOD";
    }
    else if (Score < 8 && Score >= 6.5)
    {
        this->Rank = "GOOD";
    }
    else if (Score < 6.5 && Score >= 5)
    {
        this->Rank = "AVERAGE";
    }   
    else
    {
        this->Rank = "WEAK";
    }

    return this->Rank;

}

/********************************************Class Menu*****************************************/

class Menu{
    private :
        vector<Student> database;
        int check_Sex(const char* sex);
    public : 
        void showListCommand();
        void run_Program();
        void add_Student();
        void update_Student();
        void delete_Sudent();
        void find_Student();
        void arrange_Student_By_GPA();
        void arrange_Student_By_Name();
        void show_ListStudent();
        
};

/* Kiểm tra giới tính ( nếu đúng out,sai nhập lại ) */

int Menu::check_Sex(const char* sex){
    if((strcmp((const char*)"Nam", sex) != 0) && (strcmp((const char*)"Nu", sex) != 0)){
        printf("ERROR! NHAP GIOI TINH KHONG CHINH XAC\n");
        printf("MOI BAN NHAP LAI : \n");
        return 1;
    }
    else{
        return 0;
    }
}

/* Hiển thị danh sách những công cụ trong menu */

void Menu::showListCommand()
{
    printf("\n");
    printf("* CHUONG TRINH DANH SACH SINH VIEN \n");
    printf("------------------------------------\n");

    printf("DANH SACH LENH: \n");
    printf("1. THEM SINH VIEN\n");
    printf("2. CAP NHAT THONG TIN SINH VIEN THEO ID\n");
    printf("3. XOA SINH VIEN THEO ID\n");
    printf("4. TIM KIEM SINH VIEN THEO TEN\n");
    printf("5. SAP XEP SINH VIEN THEO GPA\n");
    printf("6. SAP XEP SINH VIEN THEO TEN\n");  
    printf("7. HIEN THI THONG TIN SINH VIEN\n");   
    printf("------------------------------------\n");
    

}

/* Hàm chạy những lựa chọn mà người dùng lựa chọn */

void Menu::run_Program()
{
    int select = 0;
 
        printf("LUA CHON CUA BAN ? \n");
        scanf(" %d", &select);
        printf("BAN CHON [%d] : ", select); 

        switch (select)
        {
        case 1 :
            printf("THEM SINH VIEN \n");
            add_Student();
            break;

        case 2 :
            printf("CAP NHAT THONG TIN SINH VIEN \n");
            update_Student();
            break;            

        case 3 :
            printf("XOA THONG TIN SINH VIÊN \n");
            delete_Sudent();
            break; 

        case 4 :
            printf("TIM SINH VIEN \n");
            find_Student();
            break;

        case 5 :
            printf("SAP XEP THEO GPA \n");
            arrange_Student_By_GPA();
            break;            

        case 6 :
            printf("Sort name by student\n");
            arrange_Student_By_Name();
            break; 

        case 7 :
            printf("Show list student\n");
            show_ListStudent();
             break; 

        default:
            printf("Exit program\n");
            break;
        }

}

/* Thêm sinh viên */

void Menu::add_Student()
{
    int number = 1;
    char name[30];
    int age;
    char sex[5];
    float math;
    float chemistry;
    float physics;

    //printf("\n");
    printf("------------------------------------\n");
    printf("- THEM SINH VIEN MOI \n");
    
    while (number)
    {

    // printf("Nhan 1 de nhap - 0 de thoat : \n");
    // scanf("%d",&number);
   
    printf("+ NHAP TEN CUA SINH VIEN : ");
    scanf(" %[^\n]s", &name);

    printf("+ NHAP DO TUOI CUA SINH VIEN : ");
    scanf("%d", &age);
    
    do
    {
    printf("+ NHAP GIOI TINH CUA SINH VIEN (Nam/Nu) : ");
    scanf("%s", &sex);
    } while (check_Sex(sex));
    
    printf("+ NHAP SO DIEM TOAN : ");
    scanf("%f", &math);

    printf("+ NHAP SO DIEM LY : ");
    scanf("%f", &chemistry);    

    printf("+ NHAP SO DIEM HOA : ");
    scanf("%f", &physics);

    Student s1(name , age , sex , math , chemistry , physics);
    database.push_back(s1);                                      // Đẩy dữ liệu vào database
    printf("THEM SINH VIEN THANH CONG\n\n");
    printf("Nhan 1 de nhap - 0 de thoat : \n");
    scanf("%d",&number);
    }
    
}

/* Hiển thị danh sách sinh viên ra màn hình */

void Menu::show_ListStudent()
{
    int number = 1;

    if(database.empty()){ 
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");  //Kiểm tra
        return;
    }

    printf("\nID\t TEN\t\t TUOI\t SEX\t TOAN\t LY\t HOA\t GPA\t HOC LUC\t \n"); 
    while(number)
    {
    for(Student item:database)  // Vòng lặp để lấy dữ liệu trong database
    {
        printf("%d\t %s\t %d\t %s\t %.2lf\t %.2lf\t %.2lf\t %.2f\t %s\t \n",item.get_Id(),item.get_Name(),item.get_Age(),item.get_Sex(),item.get_Math(),item.get_Physiscs(),item.get_Chemistry(),item.get_Average(),item.academic_Ability().c_str() );
    } 
    printf("---Nhan 0 de thoat---\n");
    scanf("%d",&number);
    }
}

void Menu::update_Student()
{
    int number = 1;
    int id_Student = 0;
    char name[30];
    int age;
    char sex[5];
    float math;
    float chemistry;
    float physics;

    int index;
    int check = 1;
    int select = 0;
    int var = 0;


    printf("------------------------------------\n");

    if(database.empty()){ 
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }
    
    while(check){
    printf("- NHAP SO ID BAN MUON CAP NHAT : "); 
    scanf("%d",&id_Student);
    
    for(int i=0;i<database.size();i++)
    {
        if((database.at(i).get_Id() == id_Student))
        {
            var = 1;
            while (check)
            {
                printf("\nDANH SACH LENH CAP NHAT SINH VIEN: \n");
                printf("1. CAP NHAT TEN SINH VIEN\n");
                printf("2. CAP NHAT TUOI\n");
                printf("3. CAP NHAT GIOI TINH\n");
                printf("4. CAP NHAT DIEM TOAN\n");
                printf("5. CAP NHAT DIEM LY\n");
                printf("6. CAP NHAT DIEM HOA\n");

                scanf("%d",&select);
                switch (select)
                {
                case 1 :
                    printf("CAP NHAT TEN MOI\n");
                    scanf(" %s", &name);
                    database.at(i).set_Name(name);
                    break;
                case 2 :
                    printf("CAP NHAT TUOI MOI\n");
                    scanf(" %d", &age);
                    database.at(i).set_Age(age);
                    break;  
                case 3 :
                    printf("CAP NHAT DIA CHI MOI\n");
                    scanf(" %s", &sex);
                    database.at(i).set_Sex(sex);
                    break;
                case 4 :
                    printf("CAP NHAT DIEM TOAN MOI\n");
                    scanf(" %f", &math);
                    database.at(i).set_Math(math);
                    break;
                case 5 :
                    printf("CAP NHAT DIEM LY MOI\n");
                    scanf(" %f", &physics);
                    database.at(i).set_Physics(physics);
                    break; 
                case 6 :
                    printf("CAP NHAT DIEM HOA MOI\n");
                    scanf(" %f", &chemistry);
                    database.at(i).set_Chemistry(chemistry);
                    break; 
                default:
                    printf("CAP NHAT THANH CONG\n");
                    break;
                }
                printf("THAY DOI THONG TIN THANH CONG \n");
                printf("NHAN PHIM 1 DE TIEP TUC - PHIM 0 DE THOAT \n");
                scanf("%d",&check);
            }
            
        }
        if(var == 0) printf("BAN DA NHAP SAI ID, MOI BAN NHAP LAI \n");
    }
    }
}

void Menu::delete_Sudent()
{
    int id_Student;
    int check = 1;
    int var = 0;

    printf("------------------------------------\n");

    if(database.empty()){ 
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }
    
    while (check)
    {
        printf("- NHAP SO ID BAN MUON XOA : "); 
        scanf("%d",&id_Student);

        for(int i=0;i<database.size();i++)
        {
            if((database.at(i).get_Id() == id_Student))
            {
               database.erase(database.begin()+i);
               i = database.size();
               printf("BAN DA XOA THONG TIN THANH CONG");
               var = 1;
            }
        }
        if(var == 0) printf("BAN DA NHAP SAI ID, MOI BAN NHAP LAI \n");
        printf("NHAN PHIM 1 DE TIEP TUC - PHIM 0 DE THOAT \n");
        scanf("%d",&check);
    }
    
}

void Menu::find_Student()
{
    char name[30];
    int check = 1;
    int var = 0;

    printf("------------------------------------\n");

    if(database.empty()){ 
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }
    
    while (check)
    {
        printf("- NHAP TEN SINH VIEN BAN MUON TIM : ");
        scanf("%s",&name);

        for(int i=0;i<database.size();i++)
        {
            if(strcmp(database[i].get_Name(), name) == 0)
            {
                printf("\nID\t TEN\t\t TUOI\t Sex\t TOAN\t LY\t HOA\t \n"); 
                printf("%d\t %s\t %d\t %s\t %.2lf\t %.2lf\t %.2lf\t \n",database[i].get_Id() , database[i].get_Name() , database[i].get_Age() , database[i].get_Sex() , database[i].get_Math() , database[i].get_Physiscs() , database[i].get_Chemistry() );
                var = 1;
            }
        }
        if(var == 0) printf("KHONG CO SINH VIEN BAN TIM \n");
        printf("BAN MUON TIM THEM SINH VIEN NAO NUA KHONG ? \n");
        printf("NHAN PHIM 1 DE TIEP TUC - PHIM 0 DE THOAT \n");
        scanf("%d",&check);
    }
     
}

void Menu::arrange_Student_By_GPA()
{
    int number = 1;

    printf("------------------------------------\n");

    if(database.empty()){ 
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }

    vector<Student> database_Copy;
    database_Copy = database;
    Student sv;

    for(int i=0;i<database_Copy.size() - 1;i++)
    {
        for(int j=i+1;j<database_Copy.size();j++)
        {
            if(database_Copy[i].get_Average() > database_Copy[j].get_Average())
            {
                sv = database_Copy[i];
                database_Copy[i] = database_Copy[j];
                database_Copy[j] = sv;
            }
        }
    }

    printf("\nID\t TEN\t\t TUOI\t SEX\t TOAN\t LY\t HOA\t GPA\t HOC LUC\t \n"); 
    while(number)
    {
    for(Student item:database_Copy)
    {
        printf("%d\t %s\t %d\t %s\t %.2lf\t %.2lf\t %.2lf\t %.2f\t %s\t \n",item.get_Id(),item.get_Name(),item.get_Age(),item.get_Sex(),item.get_Math(),item.get_Physiscs(),item.get_Chemistry(),item.get_Average(),item.academic_Ability().c_str() );
    } 
    printf("---Nhan 0 de thoat---\n");
    scanf("%d",&number);
    }
}

void Menu::arrange_Student_By_Name()
{
    int number = 1;

    printf("------------------------------------\n");

    if(database.empty()){ 
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }

    vector<Student> database_Copy;
    database_Copy = database;
    Student sv;

    for(int i=0;i<database_Copy.size()-1;i++)
    {
        for(int j=i+1;j<database_Copy.size();j++)
        {
            if( strcmp(database_Copy[i].get_Name() , database_Copy[j].get_Name()) > 0 )
            {
                sv = database_Copy[i];
                database_Copy[i] = database_Copy[j];
                database_Copy[j] = sv;
            }
        }
    }

    printf("\nID\t TEN\t\t TUOI\t SEX\t TOAN\t LY\t HOA\t GPA\t HOC LUC\t \n"); 
    while(number)
    {
    for(Student item:database_Copy)
    {
        printf("%d\t %s\t %d\t %s\t %.2lf\t %.2lf\t %.2lf\t %.2f\t %s\t \n",item.get_Id(),item.get_Name(),item.get_Age(),item.get_Sex(),item.get_Math(),item.get_Physiscs(),item.get_Chemistry(),item.get_Average(),item.academic_Ability().c_str() );
    } 
    printf("---Nhan 0 de thoat---\n");
    scanf("%d",&number);
    }
}

int main(int argc, char const *argv[])
{
    //Student s1( "Nguyen Van A" , 18 , 123 , 5 , 6 , 7 );
    //Student s2( "Nguyen Van B" , 20 , 456 , 9 , 8 , 7 );
    //printf(" ID: %d\t Ho va ten: %s\t Tuoi: %d\t Dia chi: %d\t Diem Trung Binh: %0.2f\t Hanh Kiem:%s \n", s1.get_Id() , s1.get_Name() , s1.get_Age() , s1.get_Address() , s1.get_Average() , s1.academic_Ability().c_str() );
    //printf(" ID: %d\t Ho va ten: %s\t Tuoi: %d\t Dia chi: %d\t Diem Trung Binh: %0.2f\t Hanh Kiem:%s \n", s2.get_Id() , s2.get_Name() , s2.get_Age() , s2.get_Address() , s2.get_Average() , s2.academic_Ability().c_str() );
    Menu menu;
    while(1){
    menu.showListCommand();    
    menu.run_Program();
    }

    return 0;
}
