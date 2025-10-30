#ifndef CPP_PROJECTS_REACTOR_H
#define CPP_PROJECTS_REACTOR_H


class Reactor {
public:
	Reactor(float controlRodPosition, float temp, float pressure, float heatOutput);
	void Update(float DeltaTime);
	void UpdateControlRodPosition(float Position);

	float GetPressure();
	float GetHeatOutput();
	float GetTemp();

private:
	float ControlRodPosition;
	float Temp;
	float Pressure;
	float HeatOutput;
};


#endif //CPP_PROJECTS_REACTOR_H
