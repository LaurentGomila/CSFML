////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2023 Laurent Gomila (laurent@sfml-dev.org)
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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Config.h>

#include <SFML/System/String.hpp>

#include <string.h>


////////////////////////////////////////////////////////////
// Ensure char32_t has the same size as sfChar32 (uint32_t)
// Identical alignment and size is required because we're type punning
// when doing sfChar32* <-> char32_t* casts
////////////////////////////////////////////////////////////
static_assert(sizeof(sfChar32) == sizeof(char32_t));
static_assert(alignof(sfChar32) == alignof(char32_t));


////////////////////////////////////////////////////////////
// Define utils to copy from / to sfChar32 and sf::String
////////////////////////////////////////////////////////////
inline sfChar32* copyToChar32(const sf::String& str)
{
    std::size_t byteCount = sizeof(sfChar32) * str.getSize();
    sfChar32*   utf32     = static_cast<sfChar32*>(malloc(byteCount + sizeof(sfChar32)));
    memcpy(utf32, str.getData(), byteCount);
    utf32[str.getSize()] = 0;

    return utf32;
}
