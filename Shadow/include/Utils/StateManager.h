#pragma once
#include <vector>

namespace Shadow
{
	namespace Utils
	{

		class GameState;

		/**
		* A simple state management tool
		*/
		class StateManager
		{
		public:

			/**
			* Starts a new state
			* @param state - The new state to use.
			*/
			void ChangeState(GameState* state);

			/**
			* Adds a new state and suspends the old state
			* @param state - The new state to use.
			*/
			void PushState(GameState* state);

			/**
			* Ends the old state and goes back to the original state (if there is one)
			*/
			void PopState();

			/**
			* Calls the state update.
			*/
			void Update();

			/**
			* Calls the state draw.
			*/
			void Draw();

		private:
			std::vector<GameState*> states;
		};

		extern StateManager g_StateManager;
	}
}
