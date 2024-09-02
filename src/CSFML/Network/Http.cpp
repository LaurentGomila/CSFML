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
#include <CSFML/Network/Http.h>
#include <CSFML/Network/HttpStruct.hpp>


////////////////////////////////////////////////////////////
sfHttpRequest* sfHttpRequest_create()
{
    return new sfHttpRequest;
}


////////////////////////////////////////////////////////////
void sfHttpRequest_destroy(sfHttpRequest* httpRequest)
{
    delete httpRequest;
}


////////////////////////////////////////////////////////////
void sfHttpRequest_setField(sfHttpRequest* httpRequest, const char* field, const char* value)
{
    assert(httpRequest);
    if (field)
        httpRequest->This.setField(field, value);
}


////////////////////////////////////////////////////////////
void sfHttpRequest_setMethod(sfHttpRequest* httpRequest, sfHttpMethod method)
{
    assert(httpRequest);
    httpRequest->This.setMethod(static_cast<sf::Http::Request::Method>(method));
}


////////////////////////////////////////////////////////////
void sfHttpRequest_setUri(sfHttpRequest* httpRequest, const char* uri)
{
    assert(httpRequest);
    httpRequest->This.setUri(uri ? uri : "");
}


////////////////////////////////////////////////////////////
void sfHttpRequest_setHttpVersion(sfHttpRequest* httpRequest, unsigned int major, unsigned int minor)
{
    assert(httpRequest);
    httpRequest->This.setHttpVersion(major, minor);
}


////////////////////////////////////////////////////////////
void sfHttpRequest_setBody(sfHttpRequest* httpRequest, const char* body)
{
    assert(httpRequest);
    httpRequest->This.setBody(body ? body : "");
}


////////////////////////////////////////////////////////////
void sfHttpResponse_destroy(sfHttpResponse* httpResponse)
{
    delete httpResponse;
}


////////////////////////////////////////////////////////////
const char* sfHttpResponse_getField(const sfHttpResponse* httpResponse, const char* field)
{
    assert(httpResponse);
    if (!field)
        return nullptr;

    return httpResponse->This.getField(field).c_str();
}


////////////////////////////////////////////////////////////
sfHttpStatus sfHttpResponse_getStatus(const sfHttpResponse* httpResponse)
{
    assert(httpResponse);
    return static_cast<sfHttpStatus>(httpResponse->This.getStatus());
}


////////////////////////////////////////////////////////////
unsigned int sfHttpResponse_getMajorVersion(const sfHttpResponse* httpResponse)
{
    assert(httpResponse);
    return httpResponse->This.getMajorHttpVersion();
}


////////////////////////////////////////////////////////////
unsigned int sfHttpResponse_getMinorVersion(const sfHttpResponse* httpResponse)
{
    assert(httpResponse);
    return httpResponse->This.getMinorHttpVersion();
}


////////////////////////////////////////////////////////////
const char* sfHttpResponse_getBody(const sfHttpResponse* httpResponse)
{
    assert(httpResponse);
    return httpResponse->This.getBody().c_str();
}


////////////////////////////////////////////////////////////
sfHttp* sfHttp_create()
{
    return new sfHttp;
}


////////////////////////////////////////////////////////////
void sfHttp_destroy(sfHttp* http)
{
    delete http;
}


////////////////////////////////////////////////////////////
void sfHttp_setHost(sfHttp* http, const char* host, unsigned short port)
{
    assert(http);
    http->This.setHost(host ? host : "", port);
}


////////////////////////////////////////////////////////////
sfHttpResponse* sfHttp_sendRequest(sfHttp* http, const sfHttpRequest* request, sfTime timeout)
{
    assert(http);
    assert(request);

    sfHttpResponse* response = new sfHttpResponse;
    response->This           = http->This.sendRequest(request->This, sf::microseconds(timeout.microseconds));

    return response;
}
