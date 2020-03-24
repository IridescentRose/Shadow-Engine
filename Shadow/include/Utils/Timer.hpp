#pragma once


#include <psptypes.h>
#include <stdio.h>
#include <psprtc.h>

/** \defgroup Util Library
 *  @{
 */
namespace Shadow {
	namespace Utils {

		/**
		* A simple utility timer
		*/
		class Timer {
		public:
			/**
			* Starts a timer upon instantiation
			*/
			Timer();

			/**
			* Kills the timer
			*/
			virtual ~Timer();

			/**
			* Gets the current time from last call (also updates elapsed!!!)
			*/
			float deltaTime(void);

			/**
			* Gets the elapsed time (make sure to call deltaTime to continue updating this)
			*/
			float elapsed();

			/**
			* Reset the timer to 0
			*/
			void reset();

		private:
			double dt;
			double total;

			u64 timeCurrent;
			u64 timeLast;

			u32 tickResolution;
		};
	}
}
/** @} */