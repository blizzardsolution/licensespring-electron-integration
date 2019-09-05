#pragma once

#include "LicenseSpringExp.h"
#include <string>

namespace licensespring
{
    class LICENSESPRING_EXP LicenseType
    {
    public:
        enum EType
        {
            Perpetual,
            Subscription,
            TimeLimited,
            Consumption,
            Unknown = 100
        };

        static LicenseType fromString( const std::string& str );

        LicenseType();
        LicenseType( int type );
        LicenseType( EType type );

        bool operator == ( EType t ) const;
        bool operator != ( EType t ) const;
        bool operator == ( LicenseType t ) const;
        bool operator != ( LicenseType t ) const;
        operator EType() const;
        operator int() const;

        std::string toString() const;
        std::string toFormattedString() const;

    private:
        EType m_type;
    };
}
