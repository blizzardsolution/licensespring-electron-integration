#pragma once

#include <string>
#include "LicenseSpringExp.h"

#pragma warning( push )
#pragma warning( disable : 4275 )

namespace licensespring
{
    class LICENSESPRING_EXP LicenseSpringException : public std::runtime_error
    {
    public:
        LicenseSpringException( const std::string& message ) : std::runtime_error( message.c_str() ) {}
    };


    class LICENSESPRING_EXP LicenseSpringNoInternetException : public LicenseSpringException
    {
    public:
        LicenseSpringNoInternetException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    class LICENSESPRING_EXP NetworkTimeoutException : public LicenseSpringException
    {
    public:
        NetworkTimeoutException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    class LICENSESPRING_EXP LicenseConfigurationException : public LicenseSpringException
    {
    public:
        LicenseConfigurationException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    class LICENSESPRING_EXP LicenseStateException : public LicenseSpringException
    {
    public:
        LicenseStateException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    // Computer hardware configuration has been changed or license does not belong to this computer
    class LICENSESPRING_EXP DeviceNotLicensedException : public LicenseSpringException
    {
    public:
        DeviceNotLicensedException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    class LICENSESPRING_EXP LicenseNotFoundException : public LicenseSpringException
    {
    public:
        LicenseNotFoundException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    class LICENSESPRING_EXP LicenseExpiredException : public LicenseSpringException
    {
    public:
        LicenseExpiredException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    class LICENSESPRING_EXP ProductNotFoundException : public LicenseSpringException
    {
    public:
        ProductNotFoundException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    class LICENSESPRING_EXP LicensedProductVersionException : public LicenseSpringException
    {
    public:
        LicensedProductVersionException( const std::string& message ) : LicenseSpringException(message) {}
    };


    class LICENSESPRING_EXP LicenseActivationException : public LicenseSpringException
    {
    public:
        LicenseActivationException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    class LICENSESPRING_EXP LicenseServerException : public LicenseSpringException
    {
    public:
        LicenseServerException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    class LICENSESPRING_EXP NotEnoughConsumptionException : public LicenseSpringException
    {
    public:
        NotEnoughConsumptionException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    // License product code doesn't correspond to configuration product code
    class LICENSESPRING_EXP ProductMismatchException : public LicenseSpringException
    {
    public:
        ProductMismatchException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    // In case signature returned by LicenseSpring server is not valid
    class LICENSESPRING_EXP SignatureMismatchException : public LicenseSpringException
    {
    public:
        SignatureMismatchException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    // Could not read/write file
    class LICENSESPRING_EXP LicenseFileException : public LicenseSpringException
    {
    public:
        LicenseFileException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    // Detected that system clock has been set back
    class LICENSESPRING_EXP DateTimeCheatingException : public LicenseSpringException
    {
    public:
        DateTimeCheatingException( const std::string& message ) : LicenseSpringException( message ) {}
    };


    // Please, contact support if you got this exception. Normally should never happen.
    class LICENSESPRING_EXP LicenseSpringInternalException : public LicenseSpringException
    {
    public:
        LicenseSpringInternalException( const std::string& message ) : LicenseSpringException( message ) {}
    };

}

#pragma warning( pop )
