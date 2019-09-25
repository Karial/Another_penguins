#pragma once

#include<string>

class Stack {
private:
	std::string* container;
	size_t capacity;
	size_t top;
public:
	Stack();
	~Stack();
	bool IsEmpty() const;
	bool IsFull() const;
	void Resize(size_t new_capacity);
	void Push(std::string);
	void Pop();
	int Size() const;
	std::string GetTopElement() const;
	std::string* GetArr() const;
};

bool operator==(const Stack& lhs, const Stack& rhs);

class Iterator {
private:
	const Stack* s;
	int ind;
public:
	Iterator(const Stack& s_, const int ind_ = 0);
	std::string Val() const;
	bool Next();
	bool Prev();
	bool IsCorrect() const;
};