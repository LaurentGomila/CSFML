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
#include <CSFML/Graphics/Export.h>

#include <CSFML/System/Vector2.h>


////////////////////////////////////////////////////////////
/// sfFloatRect and sfIntRect are utility classes for
/// manipulating rectangles.
////////////////////////////////////////////////////////////
typedef struct
{
    sfVector2f position;
    sfVector2f size;
} sfFloatRect;

typedef struct
{
    sfVector2i position;
    sfVector2i size;
} sfIntRect;

////////////////////////////////////////////////////////////
/// \brief Check if a point is inside a rectangle's area
///
/// \param rect  Rectangle to test
/// \param point Coordinates of the point to test
///
/// \return true if the point is inside
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfFloatRect_contains(const sfFloatRect* rect, sfVector2f point);
CSFML_GRAPHICS_API bool sfIntRect_contains(const sfIntRect* rect, sfVector2i point);

////////////////////////////////////////////////////////////
/// \brief Check intersection between two rectangles
///
/// \param rect1        First rectangle to test
/// \param rect2        Second rectangle to test
/// \param intersection Rectangle to be filled with overlapping rect (can be NULL)
///
/// \return true if rectangles overlap
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfFloatRect_intersects(const sfFloatRect* rect1, const sfFloatRect* rect2, sfFloatRect* intersection);
CSFML_GRAPHICS_API bool sfIntRect_intersects(const sfIntRect* rect1, const sfIntRect* rect2, sfIntRect* intersection);
