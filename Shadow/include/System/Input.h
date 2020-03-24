#pragma once

#include <malloc.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <psputility.h>
#include <string.h>

namespace Shadow {
	namespace System {
		namespace Input {

			/**
			* Scans for changes
			*/
			void InputUpdate();

			/**
			* Gets if a button was pressed
			*/
			bool KeyPressed(PspCtrlButtons button);

			/**
			* Gets if a button is being held
			*/
			bool KeyHold(PspCtrlButtons button);

			/**
			* Gets the analog X from -1.0 to 1.0
			*/
			float GetAnalogX();

			/**
			* Gets the analog Y from -1.0 to 1.0
			*/
			float GetAnalogY();
		}
	}
}