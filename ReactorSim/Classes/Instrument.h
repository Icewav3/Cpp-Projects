//
// Created by cdorman on 10/23/2025.
//

#ifndef CPP_PROJECTS_INSTRUMENT_H
#define CPP_PROJECTS_INSTRUMENT_H


class Instrument {
public:
    Instrument(float xpos, float ypos, float length, float width);

    virtual void Update(float DeltaTime) = 0;
    virtual void Draw();
};


#endif //CPP_PROJECTS_INSTRUMENT_H