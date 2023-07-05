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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Export.h>


typedef void (*sfVulkanFunctionPointer)();

////////////////////////////////////////////////////////////
/// \brief Tell whether or not the system supports Vulkan
///
/// This function should always be called before using
/// the Vulkan features. If it returns false, then
/// any attempt to use Vulkan will fail.
///
/// If only compute is required, set \a requireGraphics
/// to false to skip checking for the extensions necessary
/// for graphics rendering.
///
/// \param requireGraphics
///
/// \return True if Vulkan is supported, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfBool sfVulkan_isAvailable(sfBool requireGraphics);

////////////////////////////////////////////////////////////
/// \brief Get the address of a Vulkan function
///
/// \param name Name of the function to get the address of
///
/// \return Address of the Vulkan function, 0 on failure
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfVulkanFunctionPointer sfVulkan_getFunction(const char* name);

////////////////////////////////////////////////////////////
/// \brief Get Vulkan instance extensions required for graphics
///
/// \return Vulkan instance extensions required for graphics
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API const char* const* sfVulkan_getGraphicsRequiredInstanceExtensions();
