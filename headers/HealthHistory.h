#ifndef HEALTHHISTORY_H
#define HEALTHHISTORY_H

#include <QString>

struct HealthHistory {
    QString donorId;
    QString date;
    float weight;
    QString bloodPressure;
    float sugarLevel;
    QString startTime;
    QString endTime;
};

#endif // HEALTHHISTORY_H
