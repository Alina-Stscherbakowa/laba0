#include "set.h"
#include <iostream>


int* Set::copyIntArray(int* changed, int* copied, int size_copied, int start_place = 0, int advance = 0, int del_el = -1){


	int space = 0;

	for (int i = start_place; i < size_copied; i++){

		if (i == del_el){
			space++;
			continue;
		}

		changed[i - space + advance] = copied[i];

	}

	return changed;

}


Set::Set(){
	values = NULL;
	size = 0;
}

Set::Set(Set *set){

	if (set){

		size = set->getSize();
		values = new int[size];
		copyIntArray(values, set->getValues(), size);

	}


}

Set::Set(int* values, int size){

	this->values = values;
	this->size = size;

}

Set::~Set(){

	if (values != NULL){
		delete values;
	}

}


bool Set::add_(int val, int num){
	
	if (num <= size && num >= 0){
		tmp = new int[size + 1];
		if (size > 0){
			copyIntArray(tmp, values, num, 0);
			copyIntArray(tmp, values, size, num, 1);
			delete values;
			values = new int[size + 1];
			copyIntArray(values, tmp, size+1);
			delete tmp;
		}
		else{
			values = new int[1];
		}
		values[num] = val;
		size++;

		return 1;
	}
	else{
		return 0;
	}

}


bool Set::add(int val){

	if (size > 0){
		for (int i = 0; i < size; i++){
			if (values[i] == val){
				return 0;
			}
			if (values[i] > val){
				return add_(val, i);
			}
		}
		return add_(val, size);
	}
	else{
		add_(val, 0);
	}



}


bool Set::remove_(int num){

	if (size>num && num >= 0){

		if (size == 1){
			delete values;
			values = NULL;
		}
		else{
			tmp = new int[size - 1];
			copyIntArray(tmp, values, size, 0, 0, num);
			delete values;
			values = new int[size - 1];
			copyIntArray(values, tmp, size-1);
			delete tmp;
		}
		size--;

		return 1;
	}
	else{
		return 0;
	}


}


bool Set::remove(int value){

	for (int i = 0; i < size; i++){

		if (values[i] == value){
			return remove_(i);
		}

	}

	return 0;

}


Set* Set::intersection(Set* set){//пересенчение {1,2,3,4}~{3,4,5,6}={3,4} a~b=b~a


	Set* intersection = new Set;

	if (size && set != NULL){

		for (int i = 0; i < size; i++){

			for (int j = 0; j < set->size; j++){
				if (values[i] == set->values[j]){
					intersection->add(values[i]);
					break;
				}
			}

		}
	}

	return intersection;


}


Set* Set::difference(Set* set){//разность a={1,2,3,4} b={3,4,5,6,7} a/b={1,2} b/a={5,6,7}

	Set* difference = new Set;

	if (size && set != NULL){

		for (int i = 0; i < size; i++){
			int j = 0;
			for (; j < set->size; j++){
				if (values[i] == set->values[j]){
					break;
				}
			}
			if (j == set->size){
				difference->add(values[i]);
			}

		}
	}

	return difference;

}

void Set::see(){

	for (int i = 0; i < size; i++){

		std::cout << values[i] << std::endl;

	}

}


int* Set::getValues(){

	tmp = new int[size];
	copyIntArray(tmp, values, size);
	return tmp;

}

int Set::getSize(){

	return size;

}

void Set::setValues(int *values, int size){

	if (size < 0){
		size = 0;
	}

	if (this->values){
		delete this->values;
	}

	this->values = values;
	this->size = size;

}
