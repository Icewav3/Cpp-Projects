#ifndef CPP_PROJECTS_COOLANT_H
#define CPP_PROJECTS_COOLANT_H


class Coolant {
public:
	explicit Coolant(float maxFlow, float heatCapacity);

	void Update(float DeltaTime, float reactorTemp);

	void UpdateCoolantValve(float Input);

	float GetCoolantThermalTransfer();

	float GetCoolantFlowRate();

	float GetCoolantTempIn();

	float GetCoolantTempOut();

	float GetHeatExtracted() const;

private:
	float MaxFlow;
	float HeatCapacity;
	float FlowRate;
	float TempIn;
	float TempOut;
	float ThermalTransfer;
	float HeatExtracted; // Heat removed from reactor

	void calculateThermalTransfer(float deltaTime, float reactorTemp);
};


#endif //CPP_PROJECTS_COOLANT_H
