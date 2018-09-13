#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

enum gender{
    male = 1,
    famale = 2,
    other = 3
};

struct personal_time{
    bool whole[7][5];
};

class time{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    time(){
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
    }
    time(int y, int m, int d, int h = 0, int minute = 0, int s = 0){
        year = y;
        month = m;
        day = d;
        hour = h;
        this->minute = minute;
        second = s;
    }
};

class staff{
private:
    //personal information, updating or historocal recording
    string name;
    int staff_id;
    gender gen;
    long long phone_number;
    class time birthday;
    bool experienced;
    bool is_manager;
    
    //scheduling_related
    int num_orders; //default as last week.
    personal_time avaliable_time;
    
public:
    staff(string n, int id, gender g, long long p, bool e, bool m, int n_o, personal_time a, int y, int mon, int d);
};

staff::staff(string n, int id, gender g, long long p, bool e, bool m, int n_o, personal_time a, int y, int mon, int d):birthday(y, mon, d){
    
}
class orders{
    staff the_scheduling[7][5];
    class time weeks;
};

class staff_list{
    int num_members;
    staff list[1000];
    
};






int main(){
    string path = "./log";
    
    
    
    
	return 0;
}
