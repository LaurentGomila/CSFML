////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/System/Clock.h>
#include <CSFML/System/ClockStruct.hpp>

#include <SFML/System/Time.hpp>


////////////////////////////////////////////////////////////
sfClock* sfClock_create()
{
    return new sfClock;
}


////////////////////////////////////////////////////////////
sfClock* sfClock_copy(const sfClock* clock)
{
    assert(clock);
    return new sfClock(*clock);
}


////////////////////////////////////////////////////////////
void sfClock_destroy(const sfClock* clock)
{
    delete clock;
}


////////////////////////////////////////////////////////////
sfTime sfClock_getElapsedTime(const sfClock* clock)
{
    assert(clock);
    return {clock->This.getElapsedTime().asMicroseconds()};
}


////////////////////////////////////////////////////////////
bool sfClock_isRunning(const sfClock* clock)
{
    assert(clock);
    return clock->This.isRunning();
}


////////////////////////////////////////////////////////////
void sfClock_start(sfClock* clock)
{
    assert(clock);
    clock->This.start();
}


////////////////////////////////////////////////////////////
void sfClock_stop(sfClock* clock)
{
    assert(clock);
    clock->This.stop();
}


////////////////////////////////////////////////////////////
sfTime sfClock_restart(sfClock* clock)
{
    assert(clock);
    return {clock->This.restart().asMicroseconds()};
}


////////////////////////////////////////////////////////////
sfTime sfClock_reset(sfClock* clock)
{
    assert(clock);
    return {clock->This.reset().asMicroseconds()};
}
