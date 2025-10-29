#ifndef CPP_PROJECTS_TURBINE_H
#define CPP_PROJECTS_TURBINE_H


class Turbine {
public:
	Turbine(int maxRPM, int maxElectricityOut, float RPMtoElectricCharge);
	void Update(float DeltaTime);

private:
	float RPM;
	float PowerOut;
	int MaxRPM;
	int MaxElectricityOut;
	float RPMtoElectricCharge;

	void CalculateRPM();
	void CalculatePowerOut();
};


#endif //CPP_PROJECTS_TURBINE_H
