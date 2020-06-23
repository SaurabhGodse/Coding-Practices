#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

struct seats
{
	bool reserved = false;
	bool aisle = false;
};

unordered_map<string, vector<vector<seats>>> mp;

vector<string> splitString(string &st, char delimiter)
{
	stringstream ss(st);
	string token;
	vector<string> res;
	while(getline(ss, token, delimiter))
	{
		res.push_back(token);
	}
	return res;
}

bool reservation(string &screen, int &row, vector<int> &tores, vector<vector<seats>> &temp) {
	int cr = temp.size();
	int cc = temp[0].size();
	if(row <= 0 || row >= cr) {
		return false;	
	}
	int count = 0;
	bool flag = false;
	int i = 0;
	for(i = 0; i < tores.size(); i++) {
		if(tores[i] >= 1 && tores[i] < cc && row >= 1 && row < cr) {
			if(temp[row][tores[i]].reserved == false) {
				temp[row][tores[i]].reserved = true;
			}
			else {
				flag = true;
				break;
			}
		}
		else {
			flag = true;
			break;
		}
	}
	int new_i = i - 1;
	if(!flag) {
		return true;
	}
	for(int j = 1; j <= new_i; j++) {
		if(tores[j] >= 1 && tores[j] < cc && row >= 1 && row <= cr) {
			if(temp[row][tores[j]].reserved == true) {
				temp[row][tores[j]].reserved = false;
			}
		}
	}
	return false;
}


void addScreenFun(string &st) {
	vector<string> input = splitString(st, ' ');
	string screen = input[1];
	int row = stoi(input[2]);
	int col = stoi(input[3]);
	if(mp.find(screen) != mp.end()) {
		cout << "failure" << endl;
		return;
	}
	vector<vector<seats>> temp(row+1, vector<seats>(col+1));
	for(int i = 4; i < input.size(); i++) {
		for(int j = 1; j <= row; j++) {
			temp[j][stoi(input[i])].aisle = true;
		}
	}
	mp.insert({screen, temp});
	cout << "success" << endl;
	return;
}

void reserveSeatFun(string &st) {
	vector<string> input = splitString(st, ' ');
	string screen = input[1];
	int row = stoi(input[2]);
	vector<int> tores;
	for(int i = 3; i < input.size(); i++) {
		tores.push_back(stoi(input[i]));
	}
	auto pos = mp.find(screen);
	if(pos != mp.end()) {
		if(reservation(screen, row, tores, pos->second)) {
			cout << "success" << endl;
			return;
		}
		else {
			cout << "failure" << endl;
			return;
		}
	}
	else {
		cout << "failure" << endl;
		return;
	}
}

void getUnreservedSeatsFun(string &st) {
	vector<string> input = splitString(st, ' ');
	string screen = input[1];
	int row = stoi(input[2]);
	auto pos = mp.find(screen);
	if(pos == mp.end()) {
	    cout << "failure" << endl;
	    return;
	}
	int cr = temp.size();
	int cc = temp[0].size();
	if(row <= 0 || row >= cr) {
	    cout << "failure" << endl;
		return;
	}
	for(int i = 1; i >= 1 && i < cc; i++) {
		if(temp[row][i].reserved == false) {
			cout << i << " ";
		}
	}
	cout << endl;
	return;
}

void suggestContiguousSeatsFun(string &st) {
	vector<string> input = splitString(st, ' ');
	string screen = input[1];
	int noofseats = stoi(input[2]);
	int row = stoi(input[3]);
	int index = stoi(input[4]);
	auto pos = mp.find(screen);
	if(pos == mp.end()) {
	    cout << "failure" << endl;
	    return;
	}
	vector<vector<seats>> temp = pos->second;
	int cr = temp.size();
	int cc = temp[0].size();
	if(row <= 0 || row >= cr) {
		return;
	}
	int indicator = 0;
	int count = 0;
	for(int i = index; i >= 1 && i < cc && row >= 1 && row < cr; i++) {
		if(temp[row][i].reserved == false) {
			if(temp[row][i].aisle == true && indicator + 1 != i) {
				indicator = i;
			}	
			else if(temp[row][i].aisle == true && indicator + 1 == i) {
				count = 0;
				break;
			}
			count++;
			if(count == noofseats) {
				for(int j = 0; j < count; j++) {
				    cout << j + index << " ";
				}
				cout << endl;
				return;
			}
		}
		else {
			count = 0;
			break;
		}
	}
	count = 0;
	indicator = INT_MAX;
	for(int j = index; j >= 1 && j < cc && row >= 1 && row < cr; j--) {
		if(temp[row][j].reserved == false) {
			if(temp[row][j].aisle == true && indicator - 1 != j) {
				indicator = j;
			}
			else if(temp[row][j].aisle == true && indicator - 1 == j) {
				count = 0;
				break;
			}	
			count++;
			if(count == noofseats)
			{
				for(int k = 0; k < count; k++) {
				    cout << k + index - noofseats + 1 << " "; 
				}
				cout << endl;
				return;
			}
		}
		else {
			count = 0;
			break;
		}
	}
	cout << "none" << endl;
	return;
}

int main() {
	int n;
	string st;
	cin >> n;
	cin.ignore();
	while(n--) {
		getline(cin, st);
		int i = 0;
		string command = "";
		while(st[i] != ' ') {
			command += st[i];
			i++;
		}
		if(command == "add-screen") {
			addScreenFun(st);
		}
		else if(command == "reserve-seat") {
			reserveSeatFun(st);
		}
		else if(command == "get-unreserved-seats") {
			getUnreservedSeatsFun(st);		
		}
		else if(command == "suggest-contiguous-seats") {
			suggestContiguousSeatsFun(st);
		}
		else {
			cout << "invalid input" << endl;
		}
	}
	return 0;
}
