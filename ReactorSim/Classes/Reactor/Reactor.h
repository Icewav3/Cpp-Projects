#ifndef CPP_PROJECTS_REACTOR_H
#define CPP_PROJECTS_REACTOR_H


class Reactor {
public:
	Reactor(float controlRodPosition, float maxTemp, float maxPressure, float maxHeatOutput);

	void Update(float DeltaTime);

	void UpdateControlRodPosition(float Position);

	float GetPressure();

	float GetTemp();

private:
	float ControlRodPosition;
	float MaxHeatOutput;
	float Temp;
	float Pressure;
	float HeatOutput;
};


#endif //CPP_PROJECTS_REACTOR_H
