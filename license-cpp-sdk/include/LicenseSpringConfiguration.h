#pragma once

#include <string>
#include <memory>
#include "LicenseSpringExp.h"

#pragma warning( push )
#pragma warning( disable : 4251 )

namespace licensespring
{
    struct LICENSESPRING_EXP ProxySettings
    {
        ProxySettings() = default;
        ProxySettings( const std::string& proxy, const std::string& user, const std::string& password );
        bool isValid() const;

        std::string proxyUri; // e.g. "http://local.example.com:1080"
        std::string user;
        std::string password;
    };

    struct LICENSESPRING_EXP LicenseSpringExtendedOptions
    {
        LicenseSpringExtendedOptions();
        LicenseSpringExtendedOptions( const std::wstring& licenseFilePath );
        LicenseSpringExtendedOptions( const std::wstring& licenseFilePath,
                                      const std::string& hardwareID,
                                      const ProxySettings& proxy = ProxySettings() );

        std::wstring  licenseFilePath;
        std::string   hardwareID;
        bool          collectHostNameAndLocalIP;
        long          networkTimeout; // in seconds, default is 5 seconds
        ProxySettings proxySettings;
        std::string   serviceURL;
    };

    class LICENSESPRING_EXP LicenseSpringConfiguration
    {
    public:
        using ptr_t = std::shared_ptr<LicenseSpringConfiguration>;

        static ptr_t Create( const std::string& apiKey,
                             const std::string& sharedKey,
                             const std::string& productCode,
                             const std::string& appName,
                             const std::string& appVersion,
                             const LicenseSpringExtendedOptions& extendedOptions = LicenseSpringExtendedOptions() );

        const std::string& getApiKey() const;

        const std::string& getSharedKey() const;

        const std::string& getProductCode() const;

        const std::string& getAppName() const;

        const std::string& getAppVersion() const;

        const std::wstring& getLicenseFilePath() const;

        const std::string& getServiceUrl() const;

        const std::string& getHardwareID() const;

        bool getCollectHostAndIpAdress() const;

        long getNetworkTimeout() const;

        void setNetworkTimeout( long timeoutValue ); // in seconds, 0 means no timeout

        const ProxySettings& getProxySettings() const;

        std::string getSdkVersion() const;

        std::string getOsVersion() const;

        std::string getHostName() const;

        std::string getIP() const;

    private:
        LicenseSpringConfiguration() = default;
        std::string m_apiKey;
        std::string m_sharedKey;
        std::string m_productCode;
        std::string m_appName;
        std::string m_appVersion;
        LicenseSpringExtendedOptions m_extOptions;
    };
}

#pragma warning( pop )
