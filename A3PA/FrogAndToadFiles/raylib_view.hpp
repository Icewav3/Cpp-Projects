#pragma once
#include "interfaces.hpp"
#include "raylib.h"

namespace FrogToad {
	class RaylibView : public IView {
	public:
		void init();

		void draw(const BoardModel &m) override;

		int windowW() const;

		int windowH() const;

	private:
		Texture2D frogTexture;
		Texture2D toadTexture;
	};
};
