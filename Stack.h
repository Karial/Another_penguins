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

class AbstractIterator {
	virtual std::string Val() const = 0;
	virtual bool Next() = 0;
	virtual bool Prev() = 0;
	virtual bool HasNext() const = 0;
	virtual bool HasPrev() const = 0;
	virtual bool IsValid() const = 0;
};

class StackIterator: public AbstractIterator {
private:
	const Stack* s;
	int ind;
public:
	StackIterator() = default;
	StackIterator(const Stack& s_, const int ind_ = 0);
	std::string Val() const override;
	bool Next() override;
	bool Prev() override;
	bool HasNext() const override;
	bool HasPrev() const override;
	bool IsValid() const override;
	void Copy(const StackIterator& copy);
};

bool operator==(const Stack& lhs, const Stack& rhs);