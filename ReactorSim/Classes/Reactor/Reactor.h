#ifndef CPP_PROJECTS_REACTOR_H
#define CPP_PROJECTS_REACTOR_H

class Reactor {
public:
	Reactor(float maxTemp, float maxPressure, float maxHeatOutput);

	void Update(float DeltaTime);

	void UpdateControlRodPosition(float Position);

	float GetPressure();

	float GetTemp();

private:
	float ControlRodPosition;
	float MaxHeatOutput;
	float MaxTemp;
	float MaxPressure;
	float HeatOutput;

	float currentTemp;
	float currentPressure;
	float currentHeatDelta;
	bool meltdown;
	bool kaboom;
};

#endif //CPP_PROJECTS_REACTOR_H
