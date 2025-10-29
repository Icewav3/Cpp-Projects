#ifndef CPP_PROJECTS_REACTOR_H
#define CPP_PROJECTS_REACTOR_H


class Reactor {
public:
	void Update(float DeltaTime);

	void UpdateControlRodPosition(float Position);

	float GetPressure();

	float GetHeatOutput();

	float GetTemp();

private:
	float controlRodPosition;
	float temp;
	float pressure;
	float heatOutput;
};


#endif //CPP_PROJECTS_REACTOR_H
