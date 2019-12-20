#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct wizard {
	string name;
	int id;
	string password;
	string position_title; 
	float beard_length;
};

struct spell {
	string name;
	float success_rate;
	string effect;
};
struct spellbook {
	string title;
	string author;
	int num_pages;
	int edition;
	int num_spells;
	float avg_success_rate;
	struct spell *s;
};

void error_handle(string *temp);
spellbook *create_spellbooks(int);
void get_spellbook_data(spellbook *, int, ifstream&);
spell *create_spells(int);
void get_spell_data(spell *,int,ifstream &);
void delete_info(wizard**,spellbook**,int);   
void starting_Part(wizard*, int);
wizard* boonk(char* );
void display_status(wizard *arr, int index);
void password(wizard *,int, int);         
void swap(int , int );
void sort_by_pages(spellbook* , int amt);
void option_sort(spellbook* ,int amt, spell*, int);
void transfer_num_pages(string[], int [],int );
void spell_type_sort(spell *, int );
spell* get_spell(spell *, int, ifstream &);
void sort_avg_succ(spellbook *, int );
void transfer_num_succ(string [], float [],int);
