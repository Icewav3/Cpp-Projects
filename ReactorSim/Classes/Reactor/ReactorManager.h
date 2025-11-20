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
	float TotalRevenue;
	float RevenueRate;

public:
	ReactorManager();

	~ReactorManager();

	void Update(float DeltaTime);

	// Accessors for UI
	float GetReactorTemp() const;

	float GetReactorPressure() const;

	float GetCoolantTemp() const;

	float GetTurbineRPM() const;

	float GetTurbinePowerOut() const;

	float GetRevenue() const;

	bool IsMeltdown() const;

	bool IsKaboom() const;

	//input methods

	void SetControlRodPosition(float Position);

	void SetCoolantValve(float Position);
};

#endif //CPP_PROJECTS_REACTORMANAGER_H
