/*!********************************************************************

 Audacity: A Digital Audio Editor

 @file SentryRequestBuilder.h
 @brief Define a class to generate the requests to Sentry.

 Dmitry Vedenko
 **********************************************************************/

#include "SentryRequestBuilder.h"

#include <chrono>

namespace audacity
{
namespace sentry
{

const SentryRequestBuilder& audacity::sentry::SentryRequestBuilder::Get()
{
   static SentryRequestBuilder builder;

   return builder;
}

network_manager::Request SentryRequestBuilder::CreateRequest() const
{
    using namespace std::chrono;

   const std::string sentryAuth =
       std::string("\0");

   network_manager::Request request(mUrl);

//    request.setHeader("Content-Type", "application/json");
//    request.setHeader("X-Sentry-Auth", sentryAuth);

   return request;
}

SentryRequestBuilder::SentryRequestBuilder()
{
   mUrl = std::string("https://");
}

} // namespace sentry
} // namespace audacity
