// Created by Infinity
// problem link -> https://leetcode.com/problems/binary-search/

#include <bits/stdc++.h>

using namespace std;

#define ll             long long int
#define mod            1000000007
#define inf            1e18

void init_code() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



int lowerBound(vector<int>&arr, int n, int target) {
	int low = 0;
	int high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == target) {
			high = mid - 1;
		}
		else if (arr[mid] > target) {
			high = mid - 1;
		}
		else low = mid + 1;
	}

	return low ;
}

int UpperBound(vector<int>&arr, int n, int target) {
	int low = 0;
	int high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] == target)low = mid + 1;
		else if (arr[mid] > target)high = mid - 1;
		else low = mid + 1;
	}
	return high + 1;
}


class Person {
public:
	string name;
	string id;
	string phoneNo;
	Person() {

	}
	Person(string name, string id, string phoneNo) {
		this->name = name;
		this->id = id;
		this->phoneNo = phoneNo;
	}

	bool operator <(Person p1) {

		return this->id < p1.id;
	}
	bool operator >(Person p1) {

		return this->id > p1.id;
	}

	bool operator ==(Person p1) {
		return this->name == p1.name and this->id == p1.id and this->phoneNo == p1.phoneNo;

	}

	friend istream& operator >>(istream & is, Person & p);
	friend ostream& operator <<(ostream & os, const Person& p);
};

istream& operator >>(istream & is, Person& p) {
	is >> p.name >> p.id >> p.phoneNo;
	return is;
}

ostream& operator <<(ostream & os, const Person& p) {
	os << "name : " << p.name << endl;
	os << "AdhaarId : " << p.id << endl;
	os << "phoneNo : " << p.phoneNo << endl;
	return os;
}


string GetPhoneNo(vector<Person>& p, int n, string targetAdharId) {
	int low = 0 , high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (p[mid].id == targetAdharId)return p[mid].phoneNo;
		else if (p[mid].id > targetAdharId)high = mid - 1;
		else low = mid + 1;
	}

	return "AdhaarId not found";
}



int main()
{
	init_code();

	int n;
	cin >> n;
	string  target;
	cin >> target;
	vector<Person>p;
	for (int i = 0; i < n; i++) {
		Person x;
		cin >> x;
		p.push_back(x);
	}

	sort(p.begin(), p.end());

	for (auto e : p) {
		cout << e ;
		cout << endl;
	}

	string g = GetPhoneNo(p, n, target);
	cout << g << endl;




	// STL implementation of BinarySearch
	/*
		 bool ans = binary_search(arr.begin(), arr.end(), target);
		 cout << ans << endl;

	*/





	return 0;
}