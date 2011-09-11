////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_SOUNDSTREAM_H
#define SFML_SOUNDSTREAM_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>


////////////////////////////////////////////////////////////
/// \brief defines the data to fill by the OnGetData callback
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfInt16*     Samples;   ///< Pointer to the audio samples
    unsigned int NbSamples; ///< Number of samples pointed by Samples
} sfSoundStreamChunk;

typedef sfBool (*sfSoundStreamGetDataCallback)(sfSoundStreamChunk*, void*); ///< Type of the callback used to get a sound stream data
typedef void   (*sfSoundStreamSeekCallback)(sfUint32, void*);               ///< Type of the callback used to seek in a sound stream


////////////////////////////////////////////////////////////
/// \brief Create a new sound stream
///
/// \param onGetData     Function called when the stream needs more data (can't be NULL)
/// \param onSeek        Function called when the stream seeks (can't be NULL)
/// \param channelsCount Number of channels to use (1 = mono, 2 = stereo)
/// \param sampleRate    Sample rate of the sound (44100 = CD quality)
/// \param userData      Data to pass to the callback functions
///
/// \return A new sfSoundStream object
///
////////////////////////////////////////////////////////////
CSFML_API sfSoundStream* sfSoundStream_Create(sfSoundStreamGetDataCallback onGetData,
                                              sfSoundStreamSeekCallback    onSeek,
                                              unsigned int                 channelsCount,
                                              unsigned int                 sampleRate,
                                              void*                        userData);

////////////////////////////////////////////////////////////
/// \brief Destroy a sound stream
///
/// \param soundStream Sound stream to destroy
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_Destroy(sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Start or resume playing a sound stream
///
/// This function starts the stream if it was stopped, resumes
/// it if it was paused, and restarts it from beginning if it
/// was it already playing.
/// This function uses its own thread so that it doesn't block
/// the rest of the program while the music is played.
///
/// \param soundStream Sound stream object
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_Play(sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Pause a sound stream
///
/// This function pauses the stream if it was playing,
/// otherwise (stream already paused or stopped) it has no effect.
///
/// \param soundStream Sound stream object
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_Pause(sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Stop playing a sound stream
///
/// This function stops the stream if it was playing or paused,
/// and does nothing if it was already stopped.
/// It also resets the playing position (unlike sfSoundStream_Pause).
///
/// \param soundStream Sound stream object
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_Stop(sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the current status of a sound stream (stopped, paused, playing)
///
/// \param soundStream Sound stream object
///
/// \return Current status
///
////////////////////////////////////////////////////////////
CSFML_API sfSoundStatus sfSoundStream_GetStatus(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Return the number of channels of a sound stream
///
/// 1 channel means a mono sound, 2 means stereo, etc.
///
/// \param soundStream Sound stream object
///
/// \return Number of channels
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfSoundStream_GetChannelsCount(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the sample rate of a sound stream
///
/// The sample rate is the number of audio samples played per
/// second. The higher, the better the quality.
///
/// \param soundStream Sound stream object
///
/// \return Sample rate, in number of samples per second
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfSoundStream_GetSampleRate(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Set the pitch of a sound stream
///
/// The pitch represents the perceived fundamental frequency
/// of a sound; thus you can make a stream more acute or grave
/// by changing its pitch. A side effect of changing the pitch
/// is to modify the playing speed of the stream as well.
/// The default value for the pitch is 1.
///
/// \param soundStream Sound stream object
/// \param pitch       New pitch to apply to the stream
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_SetPitch(sfSoundStream* soundStream, float pitch);

////////////////////////////////////////////////////////////
/// \brief Set the volume of a sound stream
///
/// The volume is a value between 0 (mute) and 100 (full volume).
/// The default value for the volume is 100.
///
/// \param soundStream Sound stream object
/// \param volume      Volume of the stream
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_SetVolume(sfSoundStream* soundStream, float volume);

////////////////////////////////////////////////////////////
/// \brief Set the 3D position of a sound stream in the audio scene
///
/// Only streams with one channel (mono streams) can be
/// spatialized.
/// The default position of a stream is (0, 0, 0).
///
/// \param soundStream Sound stream object
/// \param x           X coordinate of the position of the stream in the scene
/// \param y           Y coordinate of the position of the stream in the scene
/// \param z           Z coordinate of the position of the stream in the scene
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_SetPosition(sfSoundStream* soundStream, float x, float y, float z);

////////////////////////////////////////////////////////////
/// \brief Make a sound stream's position relative to the listener or absolute
///
/// Making a stream relative to the listener will ensure that it will always
/// be played the same way regardless the position of the listener.
/// This can be useful for non-spatialized streams, streams that are
/// produced by the listener, or streams attached to it.
/// The default value is false (position is absolute).
///
/// \param soundStream Sound stream object
/// \param relative    sfTrue to set the position relative, sfFalse to set it absolute
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_SetRelativeToListener(sfSoundStream* soundStream, sfBool relative);

////////////////////////////////////////////////////////////
/// \brief Set the minimum distance of a sound stream
///
/// The "minimum distance" of a stream is the maximum
/// distance at which it is heard at its maximum volume. Further
/// than the minimum distance, it will start to fade out according
/// to its attenuation factor. A value of 0 ("inside the head
/// of the listener") is an invalid value and is forbidden.
/// The default value of the minimum distance is 1.
///
/// \param soundStream Sound stream object
/// \param distance    New minimum distance of the stream
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_SetMinDistance(sfSoundStream* soundStream, float distance);

////////////////////////////////////////////////////////////
/// \brief Set the attenuation factor of a sound stream
///
/// The attenuation is a multiplicative factor which makes
/// the stream more or less loud according to its distance
/// from the listener. An attenuation of 0 will produce a
/// non-attenuated stream, i.e. its volume will always be the same
/// whether it is heard from near or from far. On the other hand,
/// an attenuation value such as 100 will make the stream fade out
/// very quickly as it gets further from the listener.
/// The default value of the attenuation is 1.
///
/// \param soundStream Sound stream object
/// \param attenuation New attenuation factor of the stream
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_SetAttenuation(sfSoundStream* soundStream, float attenuation);

////////////////////////////////////////////////////////////
/// \brief Change the current playing position of a sound stream
///
/// The playing position can be changed when the stream is
/// either paused or playing.
///
/// \param soundStream Sound stream object
/// \param timeOffset  New playing position, in milliseconds
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_SetPlayingOffset(sfSoundStream* soundStream, sfUint32 timeOffset);

////////////////////////////////////////////////////////////
/// \brief Set whether or not a sound stream should loop after reaching the end
///
/// If set, the stream will restart from beginning after
/// reaching the end and so on, until it is stopped or
/// sfSoundStream_SetLoop(stream, sfFalse) is called.
/// The default looping state for sound streams is false.
///
/// \param soundStream Sound stream object
/// \param loop        sfTrue to play in loop, sfFalse to play once
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_SetLoop(sfSoundStream* soundStream, sfBool loop);

////////////////////////////////////////////////////////////
/// \brief Get the pitch of a sound stream
///
/// \param soundStream Sound stream object
///
/// \return Pitch of the stream
///
////////////////////////////////////////////////////////////
CSFML_API float sfSoundStream_GetPitch(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the volume of a sound stream
///
/// \param soundStream Sound stream object
///
/// \return Volume of the stream, in the range [0, 100]
///
////////////////////////////////////////////////////////////
CSFML_API float sfSoundStream_GetVolume(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the 3D position of a sound stream in the audio scene
///
/// \param soundStream Sound stream object
/// \param x           X position of the stream in the world
/// \param y           Y position of the stream in the world
/// \param z           Z position of the stream in the world
///
////////////////////////////////////////////////////////////
CSFML_API void sfSoundStream_GetPosition(const sfSoundStream* soundStream, float* x, float* y, float* z);

////////////////////////////////////////////////////////////
/// \brief Tell whether a sound stream's position is relative to the
///        listener or is absolute
///
/// \param soundStream Sound stream object
///
/// \return sfTrue if the position is relative, sfFalse if it's absolute
///
////////////////////////////////////////////////////////////
CSFML_API sfBool sfSoundStream_IsRelativeToListener(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the minimum distance of a sound stream
///
/// \param soundStream Sound stream object
///
/// \return Minimum distance of the stream
///
////////////////////////////////////////////////////////////
CSFML_API float sfSoundStream_GetMinDistance(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the attenuation factor of a sound stream
///
/// \param soundStream Sound stream object
///
/// \return Attenuation factor of the stream
///
////////////////////////////////////////////////////////////
CSFML_API float sfSoundStream_GetAttenuation(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Tell whether or not a sound stream is in loop mode
///
/// \param soundStream Sound stream object
///
/// \return sfTrue if the music is looping, sfFalse otherwise
///
////////////////////////////////////////////////////////////
CSFML_API sfBool sfSoundStream_GetLoop(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the current playing position of a sound stream
///
/// \param soundStream Sound stream object
///
/// \return Current playing position, in milliseconds
///
////////////////////////////////////////////////////////////
CSFML_API sfUint32 sfSoundStream_GetPlayingOffset(const sfSoundStream* soundStream);


#endif // SFML_SOUNDSTREAM_H