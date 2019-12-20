#ifndef ZOO_H
#define ZOO_H
#include "./animal.h"
#include "./monkeys.h"
#include "./meerkat.h"
#include "./sea_otter.h"

class Zoo{
	private:
		Animal **monkeys;
		Animal **meerkats;
		Animal **seaotters;
		int monkeySize;
		int meerkatSize;
		int seaotterSize;
		float bank;
		int attenBoom;
	public:
		Zoo();
		~Zoo();
		Zoo(const Zoo &);
		const Zoo& operator = (const Zoo &);
		float get_bank_money();
		void make_revenue(int );
		void take_revenue(int );
		void animal_list(Animal *);
		void add_monkey(Animal *);
		void add_meerkat(Animal *);
		void add_seaotter(Animal *);
		void printTheAnimals();
		bool arraychecker(Animal **, int );
		void restructureArray(Animal **&, int&);
		
		void runGame(); 
		int foodCosts();
		void ChooseAnimal();
		void laterPurchases();
		void monkeyPurchase();
		void meerkatPurchase();
		void seaotterPurchase();
		void randomEvent();
		void sickAnimal();
		void babyBorn();
		void attendenceBoom();
		
		void sickMonkey();
		void deadMonkey();
		void sickMeerkat();
		void deadMeerkat();
		void sickSeaotter();
		void deadSeaotter();
		
		void deleteArrays();
		void animalGrowth();
		void display();
		int calcPay();
};
#endif
