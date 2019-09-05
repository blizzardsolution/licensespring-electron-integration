#include <node.h>
#include <iostream>
#include <ctime>
#include <cstdio>

#include "License.h"
#include "LicenseManager.h"
#include "LicenseSpringExceptions.h"
#include "config.h"

using namespace v8;
using namespace std;
using namespace licensespring;

void HelloWorld(const FunctionCallbackInfo<Value> &args)
{
    cout << "Hello, world!" << endl;
}

void Initialize(Local<Object> exports)
{
    NODE_SET_METHOD(exports, "helloWorld", HelloWorld);
}

NODE_MODULE(addon, Initialize);

void DisplayLicenseInfo(const License::ptr_t pLicense);

int main()
{
    const string appName = "Cpp Sample"; // you can provide any app name and version
    const string appVersion = "1.2";

    // if you want to check some license key just assign it to this variable, leave it empty to check trial
    string licenseKey = "";

    const bool shouldDeactivateKey = false;        // set it to true for deactivating license
    const bool shouldRemoveLicenseStorage = false; // set it to true for removing license file and folders created by LicenseSpring
    const bool useOfflineMode = false;             // set it to true for checking offline activation/deactivation

    try
    {
        auto pConfiguration = LicenseSpringConfiguration::Create(apiKey, sharedKey, productCode,
                                                                 appName, appVersion, CreateExtendedOptions());

        cout << "LicenseSpring C++ Sample\n";
        cout << "LicenseSpring SDK version: " << pConfiguration->getSdkVersion() << endl;
        cout << "Detected OS version: " << pConfiguration->getOsVersion() << endl
             << endl;

        auto pLicenseManager = LicenseManager::getInstance();
        pLicenseManager->initialize(pConfiguration);

        auto pLicense = pLicenseManager->getCurrentLicense();

        if (pLicense)
        {
            cout << "License successfully loaded\n";
            cout << "License file path:\n";
            wcout << pConfiguration->getLicenseFilePath() << endl
                  << endl;
            // it's highly recommended to perform a localCheck (offline check) on every startup
            // to be ensure that license file wasn't copied from another PC and license in a valid state
            cout << "Performing local check of the license..." << endl;
            pLicense->localCheck(); // may throw exceptions
            cout << "Local validation successful" << endl
                 << endl;
        }
        else
        {
            if (licenseKey.empty())
            {
                cout << "Requesting trial license key from server...\n";
                licenseKey = pLicenseManager->getTrialKey();
                if (licenseKey.empty())
                {
                    // usually control should never enter here
                    cout << "Got an empty trial key!\n";
                    return -1;
                }
                else
                    cout << "Got trial key: " << licenseKey << endl
                         << endl;
            }

            if (useOfflineMode)
            {
                // You can provide here path to offline activation response file,
                // or use default desktop loaction and file name ls_activation.lic
                pLicense = pLicenseManager->activateLicenseOffline();
                if (pLicense == nullptr)
                {
                    // License activation response file not found
                    cout << "Creating offline activation request file...\n";
                    auto filePath = pLicenseManager->getOfflineActivationFile(licenseKey);
                    cout << "File created:\n";
                    wcout << filePath;
                    cout << "\nPlease upload that request file to the LicenseSpring portal to get response file.\n";
                    return 0;
                }
                else
                    cout << "Offline activation succeeded" << endl
                         << endl;
            }
            else
            {
                cout << "Activating " << licenseKey << " license key...\n";
                pLicense = pLicenseManager->activateLicense(licenseKey);
                cout << "License activated successfully" << endl
                     << endl;
            }
        }

        if (pLicense->type() == LicenseType::Consumption)
        {
            pLicense->increaseConsumptionCounter();
            // sync consumption license with the server, you can omit this as sync will be done within license online check
            pLicense->updateConsumptionLicense();
        }

        cout << "Checking license online...\n";
        pLicense->check(); // note, exceptions may be thrown from here (e.g. LicenseExpiredException, LicenseServerException)
        cout << "License successfully checked\n\n";

        DisplayLicenseInfo(pLicense);

        auto availableVersionsList = pLicenseManager->getAllVersions(pLicense->key());
        if (!availableVersionsList.empty())
        {
            cout << "Available application versions:\n";
            for (const auto &version : availableVersionsList)
                cout << version << endl;
        }

        auto pSetupFile = pLicenseManager->getInstallationFile(pLicense->key());
        if (!pSetupFile->getUrl().empty())
        {
            cout << "\nInstallation file for version " << pSetupFile->getVersion() << ":\n";
            cout << "Download link: " << pSetupFile->getUrl() << endl;
            cout << "MD5 hash: " << pSetupFile->getMd5Hash() << endl
                 << endl;
        }

        if (shouldDeactivateKey)
        {
            cout << "Deactivating license...\n";
            if (useOfflineMode)
            {
                auto filePath = pLicense->deActivateOffline();
                cout << "To finish deactivation process please upload deactivation request file to the LicenseSpring portal.\n";
                cout << "File path:\n";
                wcout << filePath;
            }
            else
            {
                if (pLicense->deActivate())
                    cout << "License deactivated successfully!";
                else
                    cout << "Could not deactivate license!";
                cout << "\n\n";
                cout << "License status: " << pLicense->status().toString() << endl;
            }
            // this call causes an exception, it's here to demonstrate exception handling
            // pLicense->check();
        }

        if (shouldRemoveLicenseStorage)
            pLicenseManager->clearLocalStorage(); // typically this can be used in app uninstaller

        pLicenseManager->deinitialize(); // this call is not necessary and can be omitted
    }
    catch (const LicenseConfigurationException &e)
    {
        cout << "Failed to create configuration: " << e.what() << endl;
    }
    catch (const LicenseSpringException &e)
    {
        cout << "LicenseSpring exception encountered: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << "Standard exception encountered: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown exception!\n";
    }

    return 0;
}

void DisplayLicenseInfo(const License::ptr_t pLicense)
{
    auto TmToStr = [](const tm &dateTime) {
        const int strSize = 100;
        char dateTimeStr[strSize];
        strftime(dateTimeStr, strSize, "%c", &dateTime);
        return string(dateTimeStr);
    };

    cout << "-----License information-----" << endl;
    cout << "License key: " << pLicense->key() << endl;
    cout << "License type: " << pLicense->type().toFormattedString() << endl;
    cout << "License status: " << pLicense->status().toString() << endl;
    cout << "Is trial: " << (pLicense->isTrial() ? "Yes" : "No") << endl;
    auto features = pLicense->features();
    if (!features.empty())
    {
        cout << "Features available for this license:" << endl;
        for (const auto &featureCode : features)
            cout << featureCode << endl;
    }
    cout << "Validity period: " << TmToStr(pLicense->validityPeriod()) << endl;
    cout << "Validity period UTC: " << TmToStr(pLicense->validityPeriodUtc()) << endl;
    cout << "Maintenance period: " << TmToStr(pLicense->maintenancePeriod()) << endl;
    cout << "Maintenance period UTC: " << TmToStr(pLicense->maintenancePeriodUtc()) << endl;
    cout << "Last online check date: " << TmToStr(pLicense->lastCheckDate()) << endl;
    if (pLicense->type() == LicenseType::Consumption)
    {
        cout << "Total consumption: " << to_string(pLicense->totalConsumption()) << endl;
        cout << "Max consumption: " << to_string(pLicense->maxConsumption()) << endl;
    }
    cout << "-----------------------------" << endl
         << endl;
}
