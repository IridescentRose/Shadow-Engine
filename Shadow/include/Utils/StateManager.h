#pragma once
#include <vector>

namespace Shadow
{
	namespace Utils
	{

		class GameState;


		class StateManager
		{
		public:

			void ChangeState(GameState* state);
			void PushState(GameState* state);
			void PopState();

			void Update();
			void Draw();

		private:
			std::vector<GameState*> states;
		};
	}
}
