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
#include <CSFML/CallbackStream.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/ImageStruct.hpp>
#include <CSFML/Graphics/RenderWindowStruct.hpp>
#include <CSFML/Graphics/Texture.h>
#include <CSFML/Graphics/TextureStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/Window/WindowStruct.hpp>


////////////////////////////////////////////////////////////
sfTexture* sfTexture_create(sfVector2u size)
{
    auto* texture = new sfTexture;

    if (!texture->This->resize(convertVector2(size)))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}


////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromFile(const char* filename, const sfIntRect* area)
{
    auto* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromFile(filename, false, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromFile(const char* filename, const sfIntRect* area)
{
    auto* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromFile(filename, true, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area)
{
    auto* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromMemory(data, sizeInBytes, false, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area)
{
    auto* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromMemory(data, sizeInBytes, true, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}


////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromStream(sfInputStream* stream, const sfIntRect* area)
{
    assert(stream);

    auto* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    CallbackStream sfmlStream(stream);
    if (!texture->This->loadFromStream(sfmlStream, false, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromStream(sfInputStream* stream, const sfIntRect* area)
{
    assert(stream);

    auto* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    CallbackStream sfmlStream(stream);
    if (!texture->This->loadFromStream(sfmlStream, true, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}


////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromImage(const sfImage* image, const sfIntRect* area)
{
    assert(image);

    auto* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromImage(image->This, false, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromImage(const sfImage* image, const sfIntRect* area)
{
    assert(image);

    auto* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromImage(image->This, true, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_copy(const sfTexture* texture)
{
    assert(texture);
    return new sfTexture(*texture);
}


////////////////////////////////////////////////////////////
void sfTexture_destroy(const sfTexture* texture)
{
    delete texture;
}


////////////////////////////////////////////////////////////
sfVector2u sfTexture_getSize(const sfTexture* texture)
{
    assert(texture);
    return convertVector2(texture->This->getSize());
}


////////////////////////////////////////////////////////////
sfImage* sfTexture_copyToImage(const sfTexture* texture)
{
    assert(texture);
    assert(texture->This);
    return new sfImage{texture->This->copyToImage()};
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromPixels(sfTexture* texture, const uint8_t* pixels, sfVector2u size, sfVector2u offset)
{
    assert(texture);
    texture->This->update(pixels, convertVector2(size), convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromTexture(sfTexture* destination, const sfTexture* texture, sfVector2u offset)
{
    assert(destination);
    assert(texture);
    assert(texture->This);
    destination->This->update(*texture->This, convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromImage(sfTexture* texture, const sfImage* image, sfVector2u offset)
{
    assert(texture);
    assert(image);
    texture->This->update(image->This, convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromWindow(sfTexture* texture, const sfWindow* window, sfVector2u offset)
{
    assert(texture);
    assert(window);
    texture->This->update(window->This, convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromRenderWindow(sfTexture* texture, const sfRenderWindow* renderWindow, sfVector2u offset)
{
    assert(texture);
    assert(renderWindow);
    texture->This->update(renderWindow->This, convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfTexture_setSmooth(sfTexture* texture, bool smooth)
{
    assert(texture);
    texture->This->setSmooth(smooth);
}


////////////////////////////////////////////////////////////
bool sfTexture_isSmooth(const sfTexture* texture)
{
    assert(texture);
    assert(texture->This);
    return texture->This->isSmooth();
}

////////////////////////////////////////////////////////////
bool sfTexture_isSrgb(const sfTexture* texture)
{
    assert(texture);
    return texture->This->isSrgb();
}


////////////////////////////////////////////////////////////
void sfTexture_setRepeated(sfTexture* texture, bool repeated)
{
    assert(texture);
    texture->This->setRepeated(repeated);
}


////////////////////////////////////////////////////////////
bool sfTexture_isRepeated(const sfTexture* texture)
{
    assert(texture);
    assert(texture->This);
    return texture->This->isRepeated();
}


////////////////////////////////////////////////////////////
bool sfTexture_generateMipmap(sfTexture* texture)
{
    assert(texture);
    return texture->This->generateMipmap();
}


////////////////////////////////////////////////////////////
void sfTexture_swap(sfTexture* left, sfTexture* right)
{
    assert(left);
    assert(right);
    left->This->swap(*right->This);
}


////////////////////////////////////////////////////////////
unsigned int sfTexture_getNativeHandle(const sfTexture* texture)
{
    assert(texture);
    return texture->This->getNativeHandle();
}


////////////////////////////////////////////////////////////
void sfTexture_bind(const sfTexture* texture, sfTextureCoordinateType type)
{
    sf::Texture::bind(texture ? texture->This : nullptr, static_cast<sf::CoordinateType>(type));
}


////////////////////////////////////////////////////////////
unsigned int sfTexture_getMaximumSize()
{
    return sf::Texture::getMaximumSize();
}
