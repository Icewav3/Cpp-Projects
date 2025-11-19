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
	float CurrentControlRodPosition;
	float CurrentCoolantValuePosition;

public:
	ReactorManager();

	~ReactorManager();

	void Update(float DeltaTime);

	// Accessors for UI
	float GetReactorTemp() const;

	float GetCoolantTemp() const;

	float GetTurbineRPM() const;

	float GetTurbinePowerOut() const;

	//input methods

	void SetControlRodPosition(float Position);

	void SetCoolantValve(float Position);
};

#endif //CPP_PROJECTS_REACTORMANAGER_H
