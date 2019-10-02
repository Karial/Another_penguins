#include"stdafx.h"
#include"Casher.h"

void Casher::VisitStack(Stack& stack) {
	stack.Pop();
}

void Casher::VisitCrowd(Crowd& crowd) {
	crowd.DeleteRandomHuman();
}