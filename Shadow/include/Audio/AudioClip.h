#pragma once
#include <Audio/sound_utils/audio.h>
#include <string>

namespace Shadow{
	namespace Audio {

		enum AudioChannels {
			AUDIO_CHANNEL_USER0 = 0,
			AUDIO_CHANNEL_USER1 = 1,
			AUDIO_CHANNEL_USER2 = 2,
			AUDIO_CHANNEL_USER3 = 3,
			AUDIO_CHANNEL_USER4 = 4,
			AUDIO_CHANNEL_USER5 = 5,
			AUDIO_CHANNEL_USER6 = 6,
			AUDIO_CHANNEL_MUSIC = 7,
		};

		class AudioClip {
		public:
			AudioClip(std::string path, bool stream = false);
			~AudioClip();

			void Play(AudioChannels channel = AUDIO_CHANNEL_USER0);
			void Pause();
			void Stop();

		private:
			OSL_SOUND* snd;
		};
	}
}