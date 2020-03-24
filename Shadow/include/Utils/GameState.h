#pragma once

#include <Utils/StateManager.h>

namespace Shadow
{
	namespace Utils
	{


		/**
		* Defines a game state
		*/
		class GameState
		{
		public:
			/**
			* Initializes value and loads.
			*/
			virtual void Init() = 0;
			/**
			* Cleans up and frees memory
			*/
			virtual void CleanUp() = 0;

			/**
			* Executes what is needed on first run
			*/
			virtual void Enter() = 0;

			/**
			* Stops execution
			*/
			virtual void Pause() = 0;

			/**
			* Resumes from paused state
			*/
			virtual void Resume() = 0;

			/**
			* Updates a scene
			*/
			virtual void Update(StateManager* sManager) = 0;
			/**
			* Draws scenes to the screen
			*/
			virtual void Draw(StateManager* sManager) = 0;

			/**
			* Forces a change in state to the next state
			*/
			void ChangeState(StateManager* sManager, GameState* state)
			{
				sManager->ChangeState(state);
			}


		protected:
			GameState() { }
		};
	}
}
