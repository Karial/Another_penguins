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

bool operator==(const Stack& lhs, const Stack& rhs) {
	if (lhs.Size() != rhs.Size()) {
		return false;
	}
	else {
		Iterator it1(lhs), it2(rhs);
		while (it1.IsCorrect() && it2.IsCorrect()) {
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

Iterator::Iterator(const Stack& s_, const int ind_) :s(&s_), ind(ind_) {}

std::string Iterator::Val() const {
	return s->GetArr()[ind];
}

bool Iterator::Next() {
	ind++;
	if (ind >= s->Size()) {
		return false;
	}
	else {
		return true;
	}
}

bool Iterator::Prev() {
	ind--;
	if (ind < 0) {
		return false;
	}
	else {
		return true;
	}
}

bool Iterator::IsCorrect() const {
	return (ind >= 0 && ind < s->Size());
}