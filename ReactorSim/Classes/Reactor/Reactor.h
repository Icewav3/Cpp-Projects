#ifndef CPP_PROJECTS_REACTOR_H
#define CPP_PROJECTS_REACTOR_H

class Reactor {
public:
	Reactor(float maxTemp, float maxPressure, float maxHeatOutput);

	void Update(float DeltaTime);

	void UpdateControlRodPosition(float Position);

	float GetPressure();

	float GetTemp();

	float GetHeatOutput() const;

	void RemoveHeat(float heatAmount);

	bool IsMeltdown() const;

	bool IsKaboom() const;

private:
	float ControlRodPosition;
	float TargetControlRodPosition;
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
