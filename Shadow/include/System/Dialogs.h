#pragma once
#include <malloc.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <psputility.h>
#include <string.h>
#include <Graphics/RenderManager.h>

namespace Shadow{
	namespace System {
		namespace Dialogs {
			/**
			* Configures the dialog
			*/
			void ConfigureDialog(pspUtilityMsgDialogParams* dialog, size_t dialog_size);

			/**
			* Shows a message
			*/
			void ShowMessage(const char* message);

			/**
			* Shows an error code
			*/
			void ShowMessageError(const char* message, int error);

			/**
			* Gives an integer result of yes or no
			*/
			int ShowMessageYesNo(const char* message);

			/**
			* Shows the On-Screen Keyboard
			*/
			int ShowOSK(unsigned short* descritpion, unsigned short* outtext, int maxtextinput);

			/**
			* Shows the network dialog
			*/
			bool ShowNetworkDialog();
		}
	}
}