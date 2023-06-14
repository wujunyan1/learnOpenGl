#ifndef CPR_CURL_OPTION_H
#define CPR_CURL_OPTION_H

#include <curl/curl.h>
#include <functional>

namespace cpr {
	class CurlOption
	{
	public:
		std::function<void(CURL*)> apply;

		template<typename T>
		CurlOption(CURLoption option, T value)
			: apply([=](CURL* handle) { curl_easy_setopt(handle, option, value); }) {}
	};
}

#endif // !CPR_CURL_OPTION_H