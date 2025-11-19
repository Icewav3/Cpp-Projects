#ifndef CPP_PROJECTS_COOLANT_H
#define CPP_PROJECTS_COOLANT_H


class Coolant {
public:
	explicit Coolant(float maxFlow, float heatCapacity);

	void Update(float DeltaTime);

	void UpdateCoolantValve(float Input);

	float GetCoolantThermalTransfer();

	float GetCoolantFlowRate();

	float GetCoolantTempIn();

	float GetCoolantTempOut();

private:
	float MaxFlow;
	float HeatCapacity;
	float FlowRate;
	float TempIn;
	float TempOut;
	float ThermalTransfer;

	float calculateThermalTransfer(float deltaTime);
};


#endif //CPP_PROJECTS_COOLANT_H
