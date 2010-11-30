/*=============================================================================

  Library: CTK

  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/


#ifndef CTKQTMOBILITYSERVICEFACTORY_P_H
#define CTKQTMOBILITYSERVICEFACTORY_P_H

#include <ctkServiceFactory.h>

#include <QServiceInterfaceDescriptor>

class ctkQtMobilityServiceRuntime;

using namespace QtMobility;

class ctkQtMobilityServiceFactory : public ctkServiceFactory
{

public:

  ctkQtMobilityServiceFactory(const QServiceInterfaceDescriptor& descr,
                              ctkQtMobilityServiceRuntime* sr, QSharedPointer<ctkPlugin> plugin);

  QObject* getService(QSharedPointer<ctkPlugin> usingPlugin, ctkServiceRegistration* registration);
  void ungetService(QSharedPointer<ctkPlugin> usingPlugin, ctkServiceRegistration* registration, QObject* service);

private:

  int activeCount;

  QServiceInterfaceDescriptor serviceDescriptor;
  ctkQtMobilityServiceRuntime* sr;
  QSharedPointer<ctkPlugin> servicePlugin;
};

#endif // CTKQTMOBILITYSERVICEFACTORY_P_H
