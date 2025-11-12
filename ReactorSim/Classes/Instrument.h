#ifndef CPP_PROJECTS_INSTRUMENT_H
#define CPP_PROJECTS_INSTRUMENT_H

class Instrument {
public:
	virtual ~Instrument() = default;

	Instrument(float xpos, float ypos, float length, float height)
		: IsBroken(false),
		  xpos_(xpos),
		  ypos_(ypos),
		  length_(length),
		  height_(height) {
	}

	virtual void Update(float DeltaTime) = 0;

	bool IsBroken;

protected:
	virtual void Draw() = 0;

	float xpos_;
	float ypos_;
	float length_;
	float height_;
};

#endif //CPP_PROJECTS_INSTRUMENT_H
