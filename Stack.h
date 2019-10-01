#pragma once

#include<string>

class StackIterator;

class Iterable {
	virtual StackIterator begin() const = 0;
};

class Stack: public Iterable {
	friend StackIterator;
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
	StackIterator begin() const override;
};

class StackIterator {
private:
	const Stack* s;
	int ind;
public:
	StackIterator() = default;
	StackIterator(const Stack& s_, const int ind_ = 0);
	std::string Val() const;
	bool Next();
	bool Prev();
	bool HasNext() const;
	bool HasPrev() const;
	bool IsValid() const;
	void Copy(const StackIterator& copy);
};

bool operator==(const Stack& lhs, const Stack& rhs);