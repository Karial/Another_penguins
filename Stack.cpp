#include "stdafx.h"
#include"Stack.h"
#include<algorithm>
#include<string>

Stack::Stack() {
	capacity = 0;
	top = 0;
}

bool Stack::IsEmpty() const {
	return top == 0;
}

bool Stack::IsFull() const {
	return top == capacity;
}

void Stack::Resize(size_t new_capacity) {
	capacity = new_capacity;
	std::string* new_container = new std::string[new_capacity];
	int Min = min(top, new_capacity);
	for (int i = 0; i < Min; i++) {
		new_container[i] = container[i];
	}
	container = new_container;
}

void Stack::Push(std::string str) {
	if (IsFull()) {
		Resize((capacity + 1) * 2);
	}
	container[top] = str;
	top++;
}

void Stack::Pop() {
	if (this->IsEmpty()) {
		return;
	}
	top--;
	if (top * 2 <= capacity) {
		this->Resize(capacity / 2);
	}
}

int Stack::Size() const {
	return top;
}

std::string Stack::GetTopElement() const {
	if (!IsEmpty()) {
		return container[top - 1];
	}
	else {
		return "";
	}
}

std::string* Stack::GetArr() const {
	return container;
}

Stack::~Stack() {
	delete[] container;
}

void Stack::Accept(Visitor& vis) {
	vis.VisitStack(*this);
}

bool operator==(const Stack& lhs, const Stack& rhs) {
	if (lhs.Size() != rhs.Size()) {
		return false;
	}
	else {
		StackIterator it1(lhs), it2(rhs);
		while (it1.HasNext() && it2.HasNext()) {
			std::string str = it1.Val();
			str = it2.Val();
			if (it1.Val() != it2.Val()) {
				return false;
			}
			it1.Next();
			it2.Next();
		}
		return true;
	}
}

StackIterator Stack::begin() const {
	return StackIterator(*this, 0);
}

StackIterator::StackIterator(const Stack& s_, const int ind_) :s(&s_), ind(ind_) {}

std::string StackIterator::Val() const {
	return s->GetArr()[ind];
}

bool StackIterator::Next() {
	ind++;
	if (ind >= s->Size()) {
		return false;
	}
	else {
		return true;
	}
}

bool StackIterator::Prev() {
	ind--;
	if (ind < 0) {
		return false;
	}
	else {
		return true;
	}
}

bool StackIterator::HasNext() const {
	return (ind + 1 < s->Size());
}

bool StackIterator::HasPrev() const {
	return (ind - 1 >= 0);
}

bool StackIterator::IsValid() const {
	return (ind < s->Size());
}

void StackIterator::Copy(const StackIterator& copy) {
	ind = copy.ind;
}

Crowd::Crowd() {
	_crowd = {};
}

void Crowd::DeleteRandomHuman() {
	if (!_crowd.empty()) {
		_crowd.erase(begin(_crowd) + rand() % _crowd.size());
	}
}

std::string Crowd::GetHumanWithIndex(size_t ind) const {
	if (ind < _crowd.size()) {
		return _crowd[ind];
	}
	else {
		return "";
	}
}

void Crowd::RandomCrowd() {
	_crowd.resize(rand() % 15);
	for (int i = 0; i < _crowd.size(); ++i) {
		_crowd[i] = random_string[rand() % 12];
	}
}

size_t Crowd::GetSize() {
	return _crowd.size();
}

const std::vector<std::string> Crowd::GetArray() {
	return _crowd;
}

void Crowd::Accept(Visitor& vis) {
	vis.VisitCrowd(*this);
}