#pragma once

#include "LicenseSpringConfiguration.h"

extern const char* apiKey; // your LicenseSpring API key
extern const char* sharedKey; // your LicenseSpring Shared key
extern const char* productCode; // product code that you specified in LicenseSpring for your application

// optionally you can provide full path where license file will be stored, hardwareID and other options
// see LicenseSpringConfiguration.h for details
licensespring::LicenseSpringExtendedOptions CreateExtendedOptions();
