#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "lib/etlbase.h"

class OutputNumericalResultNotification_model: public IPropertyNotification
{
public:
    OutputNumericalResultNotification_model();
    void OnPropertyChanged(const std::string& str);
};

#endif // NOTIFICATION_H
