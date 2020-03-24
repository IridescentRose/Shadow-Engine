#pragma once
#include <Audio/sound_utils/audio.h>
#include <string>
/** \addtogroup audioclip Audio Library
 *  @{
 */
namespace Shadow{
	namespace Audio {

		/**
		* Valid audio channels. Each channel is a corresponding sound that can be played at once.
		* Only 8 sounds can be played at once.
		* This is due to the PSP's hardware.
		*/
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

		/**
		* AudioClips are playable sound clips. They are loaded from the disk (streaming or full RAM load)
		*/
		class AudioClip {
		public:
			/**
			* AudioClip constructor loads the sound from the specified path.
			*
			* @param path - The path of the playable audio clip (supports WAV, BGM, and MOD)
			* @param stream - Whether or not to load intermittently (saves RAM, increases CPU load)
			*/
			AudioClip(std::string path, bool stream = false);

			/**
			* Destroys the AudioClip and restores all memory from the loaded sound. Also stops sound playing.
			*/
			~AudioClip();

			/**
			* Plays a single sound on the AUDIO_CHANNEL_USER0 channel by default
			* @param channel - Can be used to specify what channel (defaults to 0)
			*/
			void Play(AudioChannels channel = AUDIO_CHANNEL_USER0);

			/**
			* Toggles the sound playing, still occupies the channel when paused.
			*/
			void Pause();

			/**
			* Completely stops the sound from playing on the channel.
			*/
			void Stop();

		private:
			OSL_SOUND* snd;
		};
	}
}
/** @} */