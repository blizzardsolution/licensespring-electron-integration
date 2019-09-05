{
   "targets": [
       {
           "target_name": "license-cpp-sdk",
           "sources": [
               "license-cpp-sdk/LicenseSpringSample.cpp",
               "license-cpp-sdk/config.cpp"
            ],
           "include_dirs": [
               "license-cpp-sdk",
               "license-cpp-sdk/include",
               "license-cpp-sdk/include/InstallationFile.h",
               "license-cpp-sdk/include/License.h",
               "license-cpp-sdk/include/LicenseSpringConfiguration.h",
               "license-cpp-sdk/include/LicenseSpringExceptions.h",
               "license-cpp-sdk/include/LicenseSpringExp.h",
               "license-cpp-sdk/include/LicenseType.h",
               "license-cpp-sdk/config.h"
            ],
            'link_settings': {
                "libraries" : [
                    'C:/Users/vadim/Documents/LicenseSpring/licensespring-electron-integration/license-cpp-sdk/bin/x64/dynamic/LicenseSpring.dll',
                    'C:/Users/vadim/Documents/LicenseSpring/licensespring-electron-integration/license-cpp-sdk/bin/x64/dynamic/LicenseSpring.lib',
                ]
            }
       }
   ]
}