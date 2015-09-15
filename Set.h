

class Set{


	int *values;//массив значений множества
	int *tmp;//доп массив для операций над множеством
	int size;
	int* copyIntArray(int* changed, int* copied, int size_copied, int start_place, int advance, int del_el);
	bool remove_(int num);
	bool add_(int value, int num);


public:

	Set();

	Set(Set *set);

	Set::Set(int* values, int size);

	~Set();

	bool add(int value);

	bool remove(int value);

	Set* intersection(Set* set);//пересечение множеств

	Set* difference(Set* set);//разность множеств

	void see();//вывод множества

	int getSize();

	int* getValues();

	void setValues(int *values, int size);//смена массива значений множества


};
