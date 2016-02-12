#ifndef __SORT_H__
#define __SORT_H__

#include<iostream>
#include<vector>
#include "generic.h"

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
		
		//
		//Swap Sort
		//
		void swapSort(){
			for(size_t i=0; i!=m_sort_list->size()-1; ++i){
				for(size_t j=i+1; j!=m_sort_list->size(); ++j){
					if(compare((*m_sort_list)[i],(*m_sort_list)[j])){
						swap((*m_sort_list)[i],(*m_sort_list)[j]);
					}
				}
			}
		}
		
		//
		//Bubble Sort
		//
		void bubbleSort(){
			for(size_t i=0; i!=m_sort_list->size()-1; ++i){
				for(size_t j=0; j!=m_sort_list->size()-1-i; ++j){
					if(compare((*m_sort_list)[j],(*m_sort_list)[j+1])){
						swap((*m_sort_list)[j],(*m_sort_list)[j+1]);
					}
				}
			}
		}
		
		//
		//Bubble Sort Improved
		//
		void bubbleSortImproved(){
			bool swapped = true;
			for(size_t i=0; i!=m_sort_list->size()-1&&swapped; ++i){
				swapped=false;
				for(size_t j=0; j!=m_sort_list->size()-1-i; ++j){
					if(compare((*m_sort_list)[j],(*m_sort_list)[j+1])){
						swap((*m_sort_list)[j],(*m_sort_list)[j+1]);
						swapped=true;
					}
				}
			}
		}
		
		//
		//Selection Sort
		//
		void selectionSort(){
			for(size_t i=0; i!=m_sort_list->size()-1; ++i){
				for(size_t j=i+1; j!=m_sort_list->size(); ++j){
					if(compare((*m_sort_list)[i],(*m_sort_list)[j])){
						swap((*m_sort_list)[i],(*m_sort_list)[j]);
					}
				}
			}
		}
		
		//
		//Heap Sort
		//
		void heapSort(){
			for(int i=m_sort_list->size()/2-1; i>=0; --i){
				heapAdjust(i, m_sort_list->size());
			}
			
			for(int i=m_sort_list->size()-1; i!=0; --i){
				swap((*m_sort_list)[i],(*m_sort_list)[0]);
				heapAdjust(0, i);
			}
		}
		
		//
		//Merge Sort
		//
		void mergeSortTopDown(){
			for(int i=0; i!=m_sort_list->size(); ++i){
				m_merge_list.push_back((*m_sort_list)[i]);
			}
		}
		
		//
		//Quick Sort
		//
		void quickSort(){
			_quickSort(0, m_sort_list->size());
		}
	
	private:
		void heapAdjust(int s, int m){
			T temp = (*m_sort_list)[s];
			
			for(size_t j=2*s+1; j<m; j=j*2+1){
				if(j+1<m && compare((*m_sort_list)[j+1],(*m_sort_list)[j])){
					++j;
				}
				if(compare(temp, (*m_sort_list)[j])){
					break;
				}
				(*m_sort_list)[s] = (*m_sort_list)[j];
				s=j;
			}
			(*m_sort_list)[s] = temp;
		}
		
		void _quickSort(int begin, int end){
			if(begin<end){
				int pivot_idx = partition(begin, end);
				_quickSort(begin, pivot_idx-1);
				_quickSort(pivot_idx+1, end);
			}
		}
		
		int partition(int begin, int end){
			int pivot_idx = RANDOM(begin, end);
			T pivot = (*m_sort_list)[pivot_idx];
			swap((*m_sort_list)[begin],(*m_sort_list)[pivot_idx]);
			
			while(begin<end){
				while(begin<end&&compare((*m_sort_list)[end],pivot)){
					--end;
				}
				swap((*m_sort_list)[begin],(*m_sort_list)[end]);
				while(begin<end&&compare(pivot,(*m_sort_list)[begin])){
					++begin;
				}
				swap((*m_sort_list)[begin],(*m_sort_list)[end]);
			}
			return end;
		}
		
		void topDownSplitMerge(int begin, int end){
			/* if size==1, 
			 * consider it's sorted
			 */
			if(end-begin<2){
				return;
			}
			
			int middle = (begin+end)/2;
			topDownSplitMerge(begin, middle);
			topDownSplitMerge(middle, end);
			topDownMerge(begin, middle, end);
			copyArray(begin, end);
		}
		
		void topDownMerge(int begin, int middle, int end){
			int i=begin, j=middle;
			for(int k=begin; k!=end; ++k){
				if(i<middle && (j>=end || compare((*m_sort_list)[j],(*m_sort_list)[i]))){
					m_merge_list[k] = (*m_sort_list)[i];
					++i;
				}
				else{
					m_merge_list[k] = (*m_sort_list)[j];
					++j;
				}
			}
		}
		
		void copyArray(int begin, int end){
			for(int i=begin; i!=end; ++i){
				(*m_sort_list)[i] = m_merge_list[i];
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