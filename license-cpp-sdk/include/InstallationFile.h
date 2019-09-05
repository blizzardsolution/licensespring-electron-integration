#pragma once

#include <string>
#include <memory>
#include "LicenseSpringExp.h"

#pragma warning( push )
#pragma warning( disable: 4251 )

namespace licensespring
{
    class LICENSESPRING_EXP InstallationFile
    {
    public:
        using ptr_t = std::shared_ptr<InstallationFile>;

        InstallationFile( const std::string& url, const std::string& version, const std::string& md5hash )
            : m_url( url ), m_version( version ), m_md5hash( md5hash ) 
        {};

        const std::string& getVersion() const { return m_version; }

        const std::string& getUrl() const { return m_url; }

        const std::string& getMd5Hash() const { return m_md5hash; };

    private:
        std::string m_url;
        std::string m_version;
        std::string m_md5hash;
    };
}

#pragma warning( pop )
