#include <cstdlib>
#include <iostream>
#include <time.h>
#include "../include/sort.h"

using namespace std;
using namespace alg;

/////////////////////////////
//
//	custom compare function
//	
/////////////////////////////
bool comp(int a, int b){
	return a>=b?true:false;
}

/////////////////////////////
//
//	custom swap function
//
///////////////////////////////
void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

/////////////////////////////
//
//	make array function
//
///////////////////////////////
void makeArray(vector<int>& array, int num){
	array.clear();
	srand(time(NULL));
	for(size_t i=0; i!=num; ++i){
		array.push_back(rand()%100);
	}
}

int main (int argc, char const *argv[])
{
	vector<int> a;
	
	alg::SortClass<int> sort(a,comp,swap);
	
	makeArray(a,10);
	cout << "############### insert sort ###############" << endl;
	cout << "before sort::: " ;
	sort.displaySort();
	sort.insertSort();
	cout << "after sort ::: ";
	sort.displaySort();
	cout << endl;
	
	makeArray(a,10);
	cout << "############### swap sort ###############" << endl;
	cout << "before sort::: " ;
	sort.displaySort();
	sort.swapSort();
	cout << "after sort ::: ";
	sort.displaySort();
	cout << endl;
	
	makeArray(a,10);
	cout << "############### bubble sort ###############" << endl;
	cout << "before sort::: " ;
	sort.displaySort();
	sort.bubbleSort();
	cout << "after sort ::: ";
	sort.displaySort();
	cout << endl;
	
	makeArray(a,10);
	cout << "########### bubble sort Improved ###########" << endl;
	cout << "before sort::: " ;
	sort.displaySort();
	sort.bubbleSortImproved();
	cout << "after sort ::: ";
	sort.displaySort();
	cout << endl;
	
	makeArray(a,10);
	cout << "############### selection sort ###############" << endl;
	cout << "before sort::: " ;
	sort.displaySort();
	sort.selectionSort();
	cout << "after sort ::: ";
	sort.displaySort();
	cout << endl;
	
	makeArray(a,10);
	cout << "################# heap sort #################" << endl;
	cout << "before sort::: " ;
	sort.displaySort();
	sort.heapSort();
	cout << "after sort ::: ";
	sort.displaySort();
	cout << endl;
	
	makeArray(a,10);
	cout << "########### merge sort top down ###########" << endl;
	cout << "before sort::: " ;
	sort.displaySort();
	sort.mergeSortTopDown();
	cout << "after sort ::: ";
	sort.displaySort();
	cout << endl;
	
	makeArray(a,10);
	cout << "################# quick sort ##################" << endl;
	cout << "before sort::: " ;
	sort.displaySort();
	sort.quickSort();
	cout << "after sort ::: ";
	sort.displaySort();
	cout << endl;
	
	return 0;
}
