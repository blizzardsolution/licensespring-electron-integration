#pragma once

#include "LicenseSpringExp.h"
#include <string>

namespace licensespring
{
    class LICENSESPRING_EXP LicenseStatus
    {
    public:
        enum EStatus
        {
            Active,
            Inactive,
            Expired,
            Disabled,
            Unknown
        };

        LicenseStatus();
        LicenseStatus( int status );
        LicenseStatus( EStatus status );

        std::string toString() const;

        bool operator == ( EStatus t ) const;
        bool operator != ( EStatus t ) const;
        bool operator == ( LicenseStatus t ) const;
        bool operator != ( LicenseStatus t ) const;
        operator EStatus() const;
        operator int() const;

    private:
        EStatus m_status;
    };
}
