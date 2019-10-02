#pragma once

#include"Visitor.h"
#include"Stack.h"

class Casher :public Visitor {
public:
	Casher() = default;
	void VisitStack(Stack& stack) override;
	void VisitCrowd(Crowd& stack) override;
};
