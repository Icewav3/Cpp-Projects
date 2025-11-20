#ifndef CPP_PROJECTS_TURBINE_H
#define CPP_PROJECTS_TURBINE_H


class Turbine {
public:
	Turbine(int maxRPM, int maxElectricityOut, float RPMtoElectricCharge, float minRPMToGenerate);

	void Update(float DeltaTime, float heatInput);

	float GetRPM();

	float GetPowerOut();

private:
	float RPM;
	float PowerOut;
	int MaxRPM;
	float MinRPMToGenerate;
	int MaxElectricityOut;
	float RPMtoElectricCharge;
	float CurrentHeatInput;

	void CalculateRPM(float deltaTime);

	void CalculatePowerOut();
};


#endif //CPP_PROJECTS_TURBINE_H
