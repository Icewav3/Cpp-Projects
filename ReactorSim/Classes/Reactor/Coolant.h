#ifndef CPP_PROJECTS_COOLANT_H
#define CPP_PROJECTS_COOLANT_H


class Coolant {
public:
	explicit Coolant(float maxFlow);

	void Update(float DeltaTime);

	void UpdateCoolantValve(float Input);

	float GetCoolantThermalTransfer();

	float GetCoolantFlowRate();

	float GetCoolantTempIn();

	float GetCoolantTempOut();

private:
	float FlowRate;
	float TempIn;
	float TempOut;
	float ThermalTransfer;
	float MaxFlow;

	float calculateThermalTransfer();
};


#endif //CPP_PROJECTS_COOLANT_H
