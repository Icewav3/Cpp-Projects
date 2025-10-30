#ifndef CPP_PROJECTS_COOLANT_H
#define CPP_PROJECTS_COOLANT_H


class Coolant {
public:
	explicit Coolant(float maxFlow);
	void Update(float DeltaTime);
	void UpdateCoolantValve(float Input);

private:
	float FlowRate;
	float TempIn;
	float TempOut;
	float ThermalTransfer;
	float MaxFlow;
};


#endif //CPP_PROJECTS_COOLANT_H
