/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkTestWrappedVTKQInvokable_h
#define __ctkTestWrappedVTKQInvokable_h

// Qt includes
#include <QObject>

// VTK includes
#include <vtkTable.h>

class ctkTestWrappedVTKQInvokable : public QObject
{
  Q_OBJECT
public:

  ctkTestWrappedVTKQInvokable(QObject * newParent = 0) : QObject(newParent)
    {
    this->MyTable = vtkTable::New();
    }
    
  virtual ~ctkTestWrappedVTKQInvokable()
    {
    this->MyTable->Delete();
    }

  /// Example of 'invokable' returning a VTK object
  /// Declaring a method as invokable allows to add it to the MetaObject system
  /// \note When a method returns a value, we tend to use Q_INVOKABLE
  /// instead of declaring a slot.
  Q_INVOKABLE vtkTable * getTable() const
    {
    return this->MyTable;
    }

  /// Example of 'invokable' accepting a VTK object as parameter
  Q_INVOKABLE void setTable(vtkTable * newTable)
    {
    this->MyTable = newTable;
    }

private:
  vtkTable * MyTable;
};

#endif
