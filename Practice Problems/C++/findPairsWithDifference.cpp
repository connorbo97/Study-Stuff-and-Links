#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

struct Pair{
	int a;
	int b;

};


//given an array arr of size n, return a  vector of pairs with a difference
//of difference. Ex [1,2,4,5,8] with a difference of 3 would return a vector
//[(1,4), (2,5), (5,8)]
vector<Pair> findPairsWithDifference(int n, int difference, int arr[]){
	unordered_set<int> setArr;
	vector<Pair> result;

	if(difference == 0){
		Pair temp;
		for(int i = 0; i < n; i++){
			if(setArr.find(arr[i]) != setArr.end()){
				temp.a = arr[i];
				temp.b = arr[i];
				result.push_back(temp);
			} else {
				setArr.insert(arr[i]);
			}
		}
		return result;
	}


	for(int i=0; i < n; i++)
		setArr.insert(arr[i]);

	unordered_set<int>::iterator it = setArr.begin();
	Pair temp;
	while(it != setArr.end()){
		unordered_set<int>::iterator node = setArr.find((*it) + difference);
		if(node != setArr.end()){
				temp.a = *it;
				temp.b = *node;
			result.push_back(temp);
		}
		it++;
	}
}
void printVectorPair(vector<Pair> vec){
	for(int i=0; i < vec.size(); i++){
		if(i == vec.size()-1){
			cout << "( " << vec[i].a <<", " << vec[i].b << ")\n";
		} else {
	 		cout << "( " << vec[i].a <<", " << vec[i].b << "), ";
	 	}
	}
}	

int main(int argc, char* argv[]){




	int test1[5] = {1,2,4,5,8};
	int test2[7] = {1,1,1,4,8,9,9};
	printVectorPair(findPairsWithDifference(5, 3, test1));
	printVectorPair(findPairsWithDifference(7, 0, test2));
	printVectorPair(findPairsWithDifference(5, -3, test1));
}