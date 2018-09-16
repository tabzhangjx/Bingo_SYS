#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string path_log_file = "./log";
string path_staff_file = "./staff_file";



enum gender{ male = 1, famale = 2, other = 3, alian = 4 };

class personal_time{
public:
    bool whole[7][5];
    personal_time(string p_t){
        for(int i=0; i<7;i++) for(int j =0; j<5; j++) whole[i][j] = p_t[i]-'0';
    }
    ~personal_time(){}
    void update_time(string p_t){
        for(int i=0; i<7;i++) for(int j =0; j<5; j++) whole[i][j] = p_t[i]-'0';
    }
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
    ~time(){}
    void change_time(int y, int m, int d, int h = 0, int minute = 0, int s = 0){
        year = y;
        month = m;
        day = d;
        hour = h;
        this->minute = minute;
        second = s;
    }
};

class staff{
public:
    //personal information, updating or historocal recording
    string name;
    int staff_id;
    gender gen;
    long long phone_number;
    class time birthday;
    
    //status
    bool experienced;
    bool is_manager;
    bool olded;
    bool is_fired;
    
    //work_related
    float whole_work_time;
    
    //scheduling_related
    int num_orders; //default as last week.
    int num_avaliable_time;
    personal_time avaliable_time;
    
    staff(string n, int id, int g, long long p, bool e, bool m, bool o, bool i_f, float w_w_t, int n_o, int n_a_t, string p_t, int y, int mon, int d):birthday(y, mon, d), avaliable_time(p_t){
        name = n;
        staff_id = id;
        gen = gender(g);
        phone_number = p;
        experienced = e;
        is_manager = m;
        olded = o;
        is_fired = i_f;
        whole_work_time = w_w_t;
        num_orders = n_o;
        num_avaliable_time = n_a_t;
    }
    void update_info_name(string n){ name = n; }
    void update_info_id(int id){ staff_id = id; }
    void update_info_gender(int g){ gen = gender(g); }
    void update_info_phone(long long p){ phone_number = p; }
    void update_info_birth(int y, int m, int d){ birthday.change_time(y, m, d); }
    void update_info_experienced(bool e){ experienced = e; }
    void update_info_manager(bool m){ is_manager = m; }
    void update_info_olded(bool o){ olded = o; }
    void update_info_is_fired(bool i_f){ is_fired = i_f; }
    void update_info_whole_work_time(float w){ whole_work_time = w; }
    void update_info_num_orders(int n){ num_orders = n; }
    void update_info_num_avaliable_time(int n){ num_avaliable_time = n; }
    void update_info_avaliable_time(string a){ avaliable_time.update_time(a); }
};

struct staff_in_list{
    staff s;
    staff_in_list *next;
};

class schedule{
    staff_in_list the_scheduling[7][5];
    class time the_week;
    
};

class staff_list{
public:
    int num_members;
    staff_in_list *head;
    staff_in_list *curr;
    staff_in_list *tail;
    staff_list(){
        head = NULL;
        curr = NULL;
        tail = NULL;
    }
    ~staff_list(){
        staff_in_list *p = head;
        while(head){
            p = head;
            head = head->next;
            delete p;
        }
    }
    void get_staff_list_from_file(){
        ifstream fin("./staff_file");
        fin>>this->num_members;
        for(int i = 0; i < num_members; i++){
            string n; int id; int g; long long p; int y; int mon; int d; char emoi; bool e; bool m; bool o; bool i_f;
            float w_w_t; int n_o; int n_a_t;
            string p_t;
            fin>>n>>id>>g>>p>>y>>mon>>d;
            fin>>emoi;
            e = emoi-'0';
            fin>>emoi;
            m = emoi-'0';
            fin>>emoi;
            o = emoi-'0';
            fin>>emoi;
            i_f = emoi-'0';
            fin>>w_w_t>>n_o>>n_a_t;
            fin>>p_t;
            fin>>emoi;
            staff person(n, id, g, p, e, m, o, i_f, w_w_t, n_o, n_a_t, p_t, y, mon, d);
            curr->s = person;
            if(i == 0) head = curr;
            curr = curr->next;
            tail = curr;
        }
        return;
    }
};






int main(){
    staff_list sl;
    sl.get_staff_list_from_file();
    
	return 0;
}
