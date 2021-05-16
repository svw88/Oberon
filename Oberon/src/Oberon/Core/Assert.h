#pragma once

#include "Oberon/Core/Base.h"
#include "Oberon/Core/Log.h"
#include <filesystem>

#ifdef OB_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define OB_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { OB##type##ERROR(msg, __VA_ARGS__); OB_DEBUGBREAK(); } }
#define OB_INTERNAL_ASSERT_WITH_MSG(type, check, ...) OB_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define OB_INTERNAL_ASSERT_NO_MSG(type, check) OB_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", OB_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define OB_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define OB_INTERNAL_ASSERT_GET_MACRO(...) OB_EXPAND_MACRO( OB_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, OB_INTERNAL_ASSERT_WITH_MSG, OB_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define OB_ASSERT(...) OB_EXPAND_MACRO( OB_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define OB_CORE_ASSERT(...) OB_EXPAND_MACRO( OB_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define OB_ASSERT(...)
#define OB_CORE_ASSERT(...)
#endif