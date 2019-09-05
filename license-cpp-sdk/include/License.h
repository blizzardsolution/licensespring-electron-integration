#pragma once

#include "LicenseType.h"
#include "LicenseStatus.h"
#include "InstallationFile.h"
#include <vector>

#pragma push_macro("check") // Workaround for Unreal Engine
#undef check

namespace licensespring
{
    // Interface for License API
    class LICENSESPRING_EXP License
    {
    public:
        using ptr_t = std::shared_ptr<License>;

        virtual ~License() {};

        virtual const std::string& key() const = 0;

        virtual const std::string& signature() const = 0;

        virtual const LicenseType& type() const = 0;

        virtual const LicenseStatus& status() const = 0;

        virtual bool isActive() const = 0; // equivalent to status() == LicenseStatus::Active

        virtual bool isTrial() const = 0;

        virtual bool isOfflineActivated() const = 0;

        virtual const tm validityPeriod() const = 0;

        virtual const tm& validityPeriodUtc() const = 0;

        virtual const tm maintenancePeriod() const = 0;

        virtual const tm& maintenancePeriodUtc() const = 0;

        virtual const tm& lastCheckDate() const = 0; // in local time

        virtual std::vector<std::string> features() const = 0;

        virtual uint32_t totalConsumption() const = 0;

        virtual uint32_t maxConsumption() const = 0;

        virtual void increaseConsumptionCounter( uint32_t value = 1 ) = 0;

        // Local checks
        virtual bool isExpired() const = 0; // compare system date time with license validity date time

        virtual int daysRemaining() const = 0; // how many days remaining till license expires

        virtual int daysPassedSinceLastCheck() const = 0; // how many days passed from last online check

        virtual void localCheck() = 0; // may throw exceptions

        // Requests to LicenseSpring server
        virtual bool deActivate() = 0; // may throw exceptions

        virtual InstallationFile::ptr_t check() = 0; // may throw exceptions

        virtual void updateConsumptionLicense() = 0; // sync Consumption license with the server

        // Creates offline deactivation file request
        // deactivationRequestFile - deactivation request file path, empty means use default path (Desktop)
        virtual std::wstring deActivateOffline( const std::wstring& deactivationRequestFile = std::wstring() ) = 0;
    };
}

#pragma pop_macro("check")
