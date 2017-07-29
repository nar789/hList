/*
*-- Copyright 2017 all rights reserved by (c)HUME
*-- Written by Junghun,Lee
*-- HList
*-- July 29, 2017
*/
#pragma once
#include<iostream>
#define INTMAX 0x7fffffff
using namespace std;
struct D {
	int x;
	int y;
	D() :x(0), y(0) {};
	D(int _x, int _y) :x(_x), y(_y) {};
	D(const D& ref) {
		x = ref.x; y = ref.y;
	}
	D& operator=(const D& ref) {
		x = ref.x;
		y = ref.y;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const D& ref) {
		os << "[" << ref.x << "," << ref.y << "]";
		return os;
	}
};
struct E {
	D d;
	E* next = 0;
	E() :next(NULL) {};
	E(D arg) :d(arg) { E::E(); };
	bool operator!=(E& ref) {
		if (d.x == ref.d.x && d.y == ref.d.y && next == ref.next)
			return false;
		return true;
	}
	E& operator=(E& rhs) {
		d = rhs.d;
		next = rhs.next;
		return *this;
	}
	E& operator++() {
		if (next == NULL)
			operator=(E(D(INTMAX, INTMAX)));
		else
			operator=(*next);
		return *this;
	}
	E& operator*() {
		return *this;
	}
	friend ostream& operator<<(ostream& os, E& rhs) {
		os << rhs.d;
		return os;
	}
};
class hList {
private:
	E* tail;
	E* parent;
	int size;
public:
	hList() :parent(new E()), size(0), tail(new E(D(INTMAX, INTMAX))) {};
	~hList() { delete tail; delete parent; }
	int Size() { return size; }
	void Clear() { delete parent; parent = new E(); size = 0; }
	D& operator[](int n) {
		if (n + 1 > size) {
			cout << "overflow." << endl;
			return parent->d;
		}
		E* itr = parent;
		for (int cnt = -1; cnt != n; cnt++, itr = itr->next) {}
		return itr->d;
	}
	hList& operator+(D arg) {
		E* itr = parent;
		while (itr->next != NULL) {
			itr = itr->next;
		}
		itr->next = new E(arg);
		size++;
		return *this;
	}
	friend ostream& operator<<(ostream& os, hList& ref)
	{
		if (ref.size == 0) { os << "empty."; return os; }
		int cnt = 0;
		for (E* itr = ref.parent->next; cnt != ref.size; cnt++, itr = itr->next) {
			os << itr->d << " ";
		}
		return os;
	}
	hList& operator--() {
		E* tmp = parent->next;
		parent->next = parent->next->next;
		delete tmp;
		size--;
		return *this;
	}
	hList& operator--(int) {
		E* itr = parent;
		E* prev = parent;
		while (itr->next != NULL) {
			prev = itr;
			itr = itr->next;
		}
		E* tmp = prev->next;
		prev->next = NULL;
		delete tmp;
		size--;
		return *this;
	}
	E& begin() {
		return *parent->next;
	}
	E& end() {
		return *tail;
	}
};