#pragma once

#include "License.h"
#include "LicenseSpringConfiguration.h"
#include "InstallationFile.h"

#pragma warning( push )
#pragma warning( disable : 4251 )

namespace licensespring
{
    class LicenseService;

    class LICENSESPRING_EXP LicenseManager
    {
    public:
        using ptr_t = std::shared_ptr<LicenseManager>;

        static LicenseManager::ptr_t getInstance();

        void initialize( LicenseSpringConfiguration::ptr_t pConfiguration );

        bool isInitialized() const;

        void deinitialize(); // deinitialize and free up resources, if it wasn't called than resources will be automatically freed at end of app execution

        std::string getTrialKey( const std::string& email = std::string() );

        const License::ptr_t activateLicense( const std::string& licenseKey );

        const License::ptr_t activateLicenseOffline( const std::wstring& activationResponseFile = std::wstring() );

        std::vector<std::string> getAllVersions( const std::string& licenseKey );

        InstallationFile::ptr_t getInstallationFile( const std::string& licenseKey, const std::string& version = std::string() );

        const License::ptr_t getCurrentLicense();

        void clearLocalStorage(); // remove license file and folders created by LicenseSpring, typically should be called at app uninstallation

        std::wstring getOfflineActivationFile( const std::string& licenseKey, const std::wstring& activationRequestFile = std::wstring() );

        ~LicenseManager();
        LicenseManager( const LicenseManager& ) = delete;
        LicenseManager& operator =( const LicenseManager& ) = delete;

    private:
        LicenseManager();

        LicenseService* m_pLicenseService;
        License::ptr_t m_currentLicense;

        void checkInitialization() const;
    };
}

#pragma warning( pop )
