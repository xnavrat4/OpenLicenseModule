#include "openlicensemodule.h"

#include <QStringLiteral>
#include <QUrl>

OpenLicenseModule::OpenLicenseModule(const QString &applicationName, QObject *parent):
    QObject(parent),
    m_applicationName(applicationName)
{
    m_communicator = new ServiceCommunicator(QUrl(QString(m_serviceAddress)));
    connect(m_communicator, &ServiceCommunicator::signalLicenseValidated, this, &OpenLicenseModule::signalLicenseValidated);
    connect(m_communicator, &ServiceCommunicator::signalError, this, &OpenLicenseModule::signalError);
}

void OpenLicenseModule::validate(const QString &licenseKey)
{
    m_communicator->sendValidate(m_applicationName, licenseKey);
}
