#ifndef OPENLICENSEMODULE_H
#define OPENLICENSEMODULE_H

#include "OpenLicenseCommunication/servicecommunicator.h"
#include "OpenLicenseCommunication/obfuscate.h"
#include <QObject>
#include <QUuid>

class OpenLicenseModule: public QObject
{
    Q_OBJECT

    QString m_applicationName;
    ServiceCommunicator* m_communicator;
    /**
     * @brief m_serviceAddress is a obfuscated address and a port number of the license service
     */
    char* m_serviceAddress = AY_OBFUSCATE("ws://localhost:15679");

public:
    /**
     * @brief OpenLicenseModule class is for integrating the Open License solution into a C++ application
     * @param applicationName is an application name of the running application
     * @param parent is a parent object
     */
    OpenLicenseModule(const QString& applicationName, QObject* parent = nullptr);
    /**
     * @brief validate method is for requesting a validation of a license key. It does not return anything. Instead, the result is returned by signalLicenseValidated signal asynchronously.
     * @param licenseKey is the license key of the application
     */
    void validate(const QString& licenseKey);

signals:
    /**
     * @brief signalLicenseValidated is a signal returned by the Open License Module after the license is validated.
     * @param valid determines whether the license is valid or not
     * @param params are parameters that the application can run with
     * @param message is an error message displayed in case the license is not valid
     */
    void signalLicenseValidated(bool valid, QString params, QString message);

    /**
     * @brief signalError is a signal that informs the application that the license object verificaion failed or the service has disconnected. It is intended to represent an critical error that should result in closing the application.
     * @param message is informing the user about the cause of the error
     */
    void signalError(QString message);
};

#endif // OPENLICENSEMODULE_H
