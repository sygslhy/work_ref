/*
 * main.cpp
 *
 *  Created on: 13 juin 2018
 *      Author: Administrator
 */


#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	ifstream in("in.txt");
	typedef vector<vector<int>>  Mat;
	Mat matrix;
	string str;
	while(getline(in,str)){
		cout << str << endl;
		istringstream sin(str);
		vector<int> tmp;
		for(int i; sin>>i;){
			tmp.push_back(i);
			sort(tmp.begin(), tmp.end());
		}
		matrix.push_back(tmp);
	}

	for(unsigned int i=0; i<matrix.size(); i++){
		for(unsigned int j=0; j<matrix[i].size(); j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}

