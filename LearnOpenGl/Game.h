#pragma once

namespace Core {
	class Game
	{
	public:
		static Game* GetInstance() {
			if (instance == nullptr) {
				instance = new Game();
			}

			return instance;
		}

		void Tick(long time);

	private:
		static Game* instance;
	};
}

