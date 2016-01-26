#ifndef __SORT_H__
#define __SORT_H__

#include<iostream>
#include<vector>

using namespace std;

namespace alg{

	template<typename T>
	class SortClass{
	public:
		SortClass(vector<T>& sort_list, bool(*comp)(T,T), void(*_swap)(T&, T&)){
			m_sort_list = &sort_list;
			compare = comp;
			swap = _swap;
		}	
	
		~SortClass(){}
	
		//
		//Print List
		//
		void displaySort(){
			for(size_t i=0; i!=m_sort_list->size();++i){
				cout<<(*m_sort_list)[i]<<"\t";
			}
			cout<<"\n";
		}
		
		//
		//Insert Sort
		//
		void insertSort(){
			int j;
			T temp;
			for(size_t i=1; i!=m_sort_list->size(); ++i){
				temp = (*m_sort_list)[i];
				j=i-1;
				while(j>=0 && compare((*m_sort_list)[j],(*m_sort_list)[j+1])){
					swap((*m_sort_list)[j],(*m_sort_list)[j+1]);
					--j;
				}
				(*m_sort_list)[++j]=temp;
			}
		}
		
	private:
		vector<T> *m_sort_list;
		vector<T> m_merge_list;
		bool (*compare)(T, T);
		void(*swap)(T&, T&);
	};
}

#endif