#pragma once

class Stack;
class Crowd;

class Visitor {
public:
	virtual void VisitStack(Stack& stack) = 0;
	virtual void VisitCrowd(Crowd& crowd) = 0;
};