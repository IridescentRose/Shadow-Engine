#include <Audio/AudioClip.h>

namespace Shadow {
	namespace Audio {
		AudioClip::AudioClip(std::string path, bool b)
		{
			snd = oslLoadSoundFile(path.c_str(), b ? OSL_FMT_STREAM : OSL_FMT_NONE);
		}
		AudioClip::~AudioClip()
		{
			oslDeleteSound(snd);
		}

		void AudioClip::Play(AudioChannels channel)
		{
			oslPlaySound(snd, channel);
		}
		void AudioClip::Pause()
		{
			oslPauseSound(snd, -1);
		}
		void AudioClip::Stop()
		{
			oslStopSound(snd);
		}
	}
}