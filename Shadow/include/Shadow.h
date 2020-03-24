#pragma once
#include <Audio/AudioClip.h>
#include <Utils/Logger.h>
#include <Graphics/RenderManager.h>
#include <Utils/common.h>

namespace Shadow {
	/**
	* Initializes everything (including callbacks)
	*/
	inline void Init() {
		SetupCallbacks();

		Utils::g_Logger = new Utils::Logger("CORE");
		Utils::g_Logger->log("Starting!");

		VirtualFileInit();
		oslInitAudio();

		Graphics::g_RenderManager.Init();
		Graphics::g_RenderManager.InitDebugFont();
	}

	/**
	* Cleans up the game engine
	*/
	inline void Cleanup() {
		sceGuTerm();
		oslDeinitAudio();
		sceKernelExitGame();
	}
}