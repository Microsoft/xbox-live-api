// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifdef USING_TAEF

#define DEFINE_TEST_CASE_TAEF(TestCaseMethodName)  \
    BEGIN_TEST_METHOD(TestCaseMethodName) \
    END_TEST_METHOD()

#define DEFINE_TEST_CASE_WITH_DESC(TestCaseMethodName, TestCaseDescription)  \
    BEGIN_TEST_METHOD(TestCaseMethodName) \
    END_TEST_METHOD()

#define DEFINE_TEST_CASE_PROPERTIES_TAEF() \
        BEGIN_TEST_METHOD_PROPERTIES() \
            TEST_METHOD_PROPERTY(L"Setup", L"1") \
        END_TEST_METHOD_PROPERTIES() \

#define DEFINE_TEST_CASE_PROPERTIES_TAEF_IGNORE() \
        BEGIN_TEST_METHOD_PROPERTIES() \
            TEST_METHOD_PROPERTY(L"Setup", L"1") \
            TEST_METHOD_PROPERTY(L"Ignore", L"1") \
        END_TEST_METHOD_PROPERTIES()

#define DEFINE_TEST_CASE_PROPERTIES_TAEF_FOCUS() \
        BEGIN_TEST_METHOD_PROPERTIES() \
            TEST_METHOD_PROPERTY(L"Setup", L"1") \
            TEST_METHOD_PROPERTY(L"Focus", L"1") \
        END_TEST_METHOD_PROPERTIES()

#define DEFINE_TEST_CASE_PROPERTIES_TAEF_FAILING() \
        BEGIN_TEST_METHOD_PROPERTIES() \
            TEST_METHOD_PROPERTY(L"Setup", L"1") \
            TEST_METHOD_PROPERTY(L"Failing", L"1") \
        END_TEST_METHOD_PROPERTIES()

#define DEFINE_TEST_CASE_WITH_DATA(TestCaseMethodName,TestCaseDataName,TestCaseDataValues)  \
    BEGIN_TEST_METHOD(TestCaseMethodName) \
        TEST_METHOD_PROPERTY(TestCaseDataName,TestCaseDataValues) \
    END_TEST_METHOD()

    void VERIFY_ARE_EQUAL_STR(std::wstring expected, std::wstring actual);

    #define DEFINE_TEST_CLASS(x) class x
    #define DEFINE_TEST_CLASS_PROPS(x) TEST_CLASS(x);\
        TEST_CLASS_SETUP(TestClassSetup) { return true; } \
        TEST_CLASS_CLEANUP(TestClassCleanup) { return true; }
    #define DEFINE_TEST_CASE(x) TEST_METHOD(x)
    #define DEFINE_TEST_CASE_PROPERTIES() DEFINE_TEST_CASE_PROPERTIES_TAEF()
    #define DEFINE_TEST_CASE_PROPERTIES_IGNORE() DEFINE_TEST_CASE_PROPERTIES_TAEF_IGNORE()
    #define DEFINE_TEST_CASE_PROPERTIES_FOCUS() DEFINE_TEST_CASE_PROPERTIES_TAEF_FOCUS()
    #define DEFINE_TEST_CASE_PROPERTIES_FAILING() DEFINE_TEST_CASE_PROPERTIES_TAEF_FAILING()
    #define VERIFY_ARE_EQUAL_INT(x, y) VERIFY_ARE_EQUAL(static_cast<int64_t>(x), static_cast<int64_t>(y))
    #define VERIFY_ARE_EQUAL_UINT(x, y) VERIFY_ARE_EQUAL(static_cast<uint64_t>(x), static_cast<uint64_t>(y))
    #define VERIFY_ARE_EQUAL_DOUBLE(x, y) VERIFY_ARE_EQUAL(static_cast<double>(x), static_cast<double>(y))
    #define VERIFY_ARE_EQUAL_STR_IGNORE_CASE(x, y) VERIFY_ARE_EQUAL_STRING_IGNORE_CASE(x, y)
    #define TEST_LOG(x) LogFormatString(x)
    #define ENABLE_SCREEN_LOGGING 1

    void VerifyEqualStr(const char* expected, const char* actual, std::wstring actualName, const WEX::TestExecution::ErrorInfo& errorInfo);
    void VerifyEqualStr(const std::string& expected, const std::string& actual, std::wstring actualName, const WEX::TestExecution::ErrorInfo& errorInfo);
    void VerifyEqualStr(std::wstring expected, std::wstring actual, std::wstring actualName, const WEX::TestExecution::ErrorInfo& errorInfo);
    void VerifyEqualStr(std::string expected, std::wstring actual, std::wstring actualName, const WEX::TestExecution::ErrorInfo& errorInfo);
    void VerifyEqualStr(xsapi_internal_string expected, xsapi_internal_string actual, std::wstring actualName, const WEX::TestExecution::ErrorInfo& errorInfo);
#define VERIFY_ARE_EQUAL_STR(__expected, __actual) VerifyEqualStr((__expected), (__actual), (L#__actual), PRIVATE_VERIFY_ERROR_INFO)
#else
    #define DEFINE_TEST_CLASS(x) TEST_CLASS(x)
    #define DEFINE_TEST_CLASS_PROPS(x)
    #define DEFINE_TEST_CASE(x) TEST_METHOD(x)
    #define DEFINE_TEST_CASE_PROPERTIES()
    #define DEFINE_TEST_CASE_PROPERTIES_IGNORE()
    #define DEFINE_TEST_CASE_PROPERTIES_FOCUS()
    #define DEFINE_TEST_CASE_PROPERTIES_FAILING()
    #define TEST_LOG(x) Logger::WriteMessage(x)
    #define VERIFY_ARE_NOT_EQUAL(expected, actual) Assert::AreNotEqual(expected, actual)
    #define VERIFY_IS_NOT_NULL(x) Assert::IsNotNull(x)
#endif



