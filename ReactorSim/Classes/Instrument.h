#ifndef CPP_PROJECTS_INSTRUMENT_H
#define CPP_PROJECTS_INSTRUMENT_H

class Instrument {
public:
	virtual ~Instrument() = default;

	Instrument(float xpos, float ypos, float length, float width)
		: IsBroken(false),
		  xpos_(xpos),
		  ypos_(ypos),
		  length_(length),
		  width_(width) {
	}

	virtual void Update(float DeltaTime) = 0;

	bool IsBroken;

protected:
	virtual void Draw();

	float xpos_;
	float ypos_;
	float length_;
	float width_;
};

#endif //CPP_PROJECTS_INSTRUMENT_H
