#include <iostream>
using namespace std;



#include "set.h"


class SetHelper{

	bool ParityCheck(Set *set){//проверка множества на четность

		int *values = set->getValues();
		int size = set->getSize();
		if (size < 1){ return 0; }

		for (int i = 0; i < size; i++){
			if (values[i] % 2 != 0){
				return 0;
			}
		}

		return 1;

	}

	bool OddnessCheck(Set *set){//проверка множества нЕчетность

		int *values = set->getValues();
		int size = set->getSize();
		if (size < 1){ return 0; }

		for (int i = 0; i < size; i++){
			if (values[i] % 2 == 0){
				return 0;
			}
		}
		return 1;

	}

	bool negativeValues(Set *set){//содержит ли отрицательные значения

		int *values = set->getValues();
		int size = set->getSize();
		for (int i = 0; i < size; i++){
			if (values[i] < 0){
				return 1;
			}
		}
		return 0;

	}

public:
	void seeParity(Set *sets, int size){

		for (int i = 0; i < size; i++){

			if (ParityCheck(&sets[i])){
				cout << "-----SET #" << i <<" enabled"<< endl;
				sets[i].see();
			}
		}

	}

	void seeOddness(Set *sets, int size){

		for (int i = 0; i < size; i++){

			if (OddnessCheck(&sets[i])){
				cout << "-----SET #" << i << " enabled" << endl;
				sets[i].see();
			}
		}

	}

	void seeWithNegativeValues(Set *sets, int size){

		for (int i = 0; i < size; i++){

			if (negativeValues(&sets[i])){
				cout << "-----SET #" << i << " enabled" << endl;
				sets[i].see();
			}
		}

	}


};


void main(){

	
	/*
	*первая часть задания
	*
	*
	cout << "-------see set------" << endl;

	Set set;
	set.add(1);
	set.add(2);
	set.add(3);
	set.add(4);
	set.add(5);
	set.remove(5);//удаление значения 5
	set.see();

	cout << "-------see set2------" << endl;

	Set set2;
	set2.add(3);
	set2.add(4);
	set2.add(5);
	set2.add(6);
	set2.add(7);
	set2.see();


	cout << "-------see/set2------" << endl;
	set.difference(&set2)->see();
	cout << "-------set2/set------" << endl;
	set2.difference(&set)->see();


	cout << "-------see~set2------" << endl;
	set.intersection(&set2)->see();
	cout << "-------see2~set------" << endl;
	set2.intersection(&set)->see();
	*/

	

	Set *sets = new Set[3];

	sets[0].add(0);
	sets[0].add(2);
	sets[0].add(4);

	sets[1].add(1);
	sets[1].add(3);
	sets[1].add(-5);


	sets[2].add(0);
	sets[2].add(-2);
	sets[2].add(-100);

	SetHelper setHelper;
	cout << "-------seeParity------" << endl;
	setHelper.seeParity(sets, 3);
	cout << "-------seeOddness------" << endl;
	setHelper.seeOddness(sets, 3);
	cout << "-------seeWithNegativeValues------" << endl;
	setHelper.seeWithNegativeValues(sets, 3);



	system("pause");

}
