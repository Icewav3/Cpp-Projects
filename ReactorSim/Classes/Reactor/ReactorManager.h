#ifndef CPP_PROJECTS_REACTORMANAGER_H
#define CPP_PROJECTS_REACTORMANAGER_H

#include "Reactor.h"
#include "Turbine.h"
#include "Coolant.h"

class ReactorManager {
private:
	Reactor *reactor;
	Turbine *turbine;
	Coolant *coolant;

public:
	void Update(float DeltaTime);
};

#endif //CPP_PROJECTS_REACTORMANAGER_H
